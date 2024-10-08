#ifndef ODDEBML_OEBMLID_H
#define ODDEBML_OEBMLID_H

#include "clingo/clingo.h"
#include "oddebml/apidecl.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 
*******************************************************************************/

struct oEbmlId {
   uint32_t raw;
};
typedef struct oEbmlId oEbmlId;

/*******************************************************************************
 generated
*******************************************************************************/

SLICES_C_(
   oEbmlId,          // Type
   oEbmlIdSlice,     // SliceType
   oVarEbmlIdSlice   // VarSliceType
)

/*******************************************************************************

*******************************************************************************/

ODDEBML_API extern int32_t const O_MaxEbmlId;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************
 init
*******************************************************************************/

ODDEBML_API inline oEbmlId ebml_id_o( uint32_t raw )
{
   return (oEbmlId){ .raw = raw };
}

ODDEBML_API oEbmlId encode_ebml_id_o( int32_t val );

/*******************************************************************************
 overall
*******************************************************************************/

ODDEBML_API inline int cmp_ebml_id_o( oEbmlId id, oEbmlId oth )
{
   return cmp_uint32_c( id.raw, oth.raw );
}

ODDEBML_API int32_t decode_ebml_id_o( oEbmlId id );

ODDEBML_API int8_t ebml_id_length_o( oEbmlId id );

ODDEBML_API bool ebml_id_is_valid_o( oEbmlId id );

ODDEBML_API bool eq_ebml_id_o( oEbmlId id, oEbmlId oth );

ODDEBML_API oEbmlId invalid_ebml_id_o( void );

/*******************************************************************************
 io
*******************************************************************************/

ODDEBML_API
bool fscan_ebml_id_o( FILE* f, oEbmlId id[static 1], cErrorStack es[static 1] );

ODDEBML_API
bool frecord_ebml_id_o( FILE* f, oEbmlId id, cErrorStack es[static 1] );

ODDEBML_API bool on_ebml_id_o( cScanner sca[static 1], oEbmlId id );

ODDEBML_API bool record_ebml_id_o( cRecorder rec[static 1], oEbmlId id );

ODDEBML_API bool scan_ebml_id_o( cScanner sca[static 1], oEbmlId id[static 1] );

ODDEBML_API bool write_ebml_id_o( cRecorder rec[static 1],
                                  oEbmlId id,
                                  char const fmt[static 1] );

#endif