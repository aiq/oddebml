#ifndef EBML_NAVI_ENV_H
#define EBML_NAVI_ENV_H

#include "_/stack.h"
#include "clingo/container/map.h"
#include "clingo/io/FILE.h"
#include "oddebml/OEbmlDeclMap.h"

#include "mkv_decl.h"

STATIC_STACK_IMPL_C_(
   __attribute__((unused)),   // Attr
   oEbmlMarker,               // Type
   oEbmlMarkerStack,          // StackType
   ebml_marker_o,             // FuncSuffix
   ebml_marker_stack_o        // StackFuncSuffix
)

static uint64_t hash_ebml_marker_o( oEbmlMarker const m[static 1] )
{
   return uint64_c_( m->pos );
}

VAL_VAL_MAP_IMPL_C_(
   static __attribute__((unused)),  // Static
   ParentMarkerMap,     // MapType
   ParentMarkerMapRow,  // RowType
   oEbmlMarker,         // KeyType
   oEbmlMarker,         // ValType
   parent_marker_map_o, // FuncName
   ParentMarkerMapMeta, // Meta
   hash_ebml_marker_o,  // HashFunc
   cmp_ebml_marker_o,   // CmpFunc
   do_ref_c_            // DoRef
)

struct NaviCtx
{
   FILE* file;
   oEbmlMarkerStack history;
   OEbmlDeclMap* declMap;
   cErrorStack* es;
};
typedef struct NaviCtx NaviCtx;

void deref_ctx( NaviCtx ctx[static 1], cErrorStack es[static 1] )
{
   if ( ctx->file != NULL ) close_file_c( ctx->file, es );

   if ( ctx->history.v != NULL ) free_ebml_marker_stack_o( &(ctx->history) );

   if ( ctx->declMap != NULL ) release_c( ctx->declMap );
}

bool init_ctx( NaviCtx ctx[static 1], cChars filePath, cErrorStack es[static 1] )
{
   *ctx = (NaviCtx){0};
   ctx->file = ropen_file_c( filePath, es );
   if ( ctx->file == NULL )
   {
      deref_ctx( ctx, es );
      return false;
   }

   if ( not alloc_ebml_marker_stack_o( &(ctx->history), 24 ) )
   {
      push_errno_error_c( es, ENOMEM );
      push_lit_str_error_c( es, "not able to allocate ctx.markerStack" );
      deref_ctx( ctx, es );
      return false;
   }

   ctx->declMap = new_ebml_decl_map_o();
   if ( ctx->declMap == NULL )
   {
      push_errno_error_c( es, ENOMEM );
      push_lit_str_error_c( es, "not able to allocate ctx.declMap" );
      deref_ctx( ctx, es );
      return false;
   }

   oVarEbmlDeclSlice declBuf = structs_c_( 300, oEbmlDecl );
   fill_ebml_decl_map_o( ctx->declMap, get_ebml_header_decl_o( declBuf ) );
   fill_ebml_decl_map_o( ctx->declMap, get_ebml_mkv_decl( declBuf ) );

   ctx->es = es;

   return true;
}

#endif