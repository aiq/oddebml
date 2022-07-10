#ifndef ODDEBML_EBML_TRAV_H
#define ODDEBML_EBML_TRAV_H

#include "oddebml/apidecl.h"
#include "oddebml/oEbmlMarker.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 
*******************************************************************************/

struct oEbmlTrav
{
   FILE* file;
   oEbmlMarker marker;
};
typedef struct oEbmlTrav oEbmlTrav;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

#define start_ebml_trav_o_( File )                                             \
(                                                                              \
   (oEbmlTrav){                                                                \
      .file=(File),                                                            \
      .marker=(oEbmlMarker){                                                   \
         .id=O_EbmlRoot.id,                                                    \
         .pos=0                                                                \
      }                                                                        \
   }                                                                           \
)

ODDEBML_API bool visit_adj_ebml_marker_o( oEbmlTrav trav[static 1],
                                         cErrorStack es[static 1] );

ODDEBML_API bool visit_next_ebml_marker_o( oEbmlTrav trav[static 1],
                                           cErrorStack es[static 1] );

/*******************************************************************************

*******************************************************************************/

ODDEBML_API bool visit_ebml_child_o( oEbmlTrav const master[static 1],
                                     oEbmlTrav child[static 1],
                                     cErrorStack es[static 1] );

/*******************************************************************************

*******************************************************************************/

ODDEBML_API bool fread_ebml_bytes_o( oEbmlTrav trav[static 1],
                                     cVarBytes buf[static 1] );

ODDEBML_API bool fread_ebml_int_o( oEbmlTrav trav[static 1],
                                   int64_t val[static 1] );

ODDEBML_API bool fread_ebml_uint_o( oEbmlTrav trav[static 1],
                                    uint64_t val[static 1] );

ODDEBML_API bool fread_ebml_float_o( oEbmlTrav trav[static 1],
                                     double val[static 1] );

ODDEBML_API bool fread_ebml_string_o( oEbmlTrav trav[static 1],
                                      cVarChars val[static 1] );

ODDEBML_API bool fread_ebml_utf8_o( oEbmlTrav trav[static 1],
                                    cVarChars val[static 1] );

ODDEBML_API bool fread_ebml_date_o( oEbmlTrav trav[static 1],
                                    oEbmlDate date[static 1] );

#endif