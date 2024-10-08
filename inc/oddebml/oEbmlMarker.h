#ifndef ODDEBML_OEBMLMARKER_H
#define ODDEBML_OEBMLMARKER_H

#include "clingo/clingo.h"
#include "oddebml/apidecl.h"
#include "oddebml/oEbmlDate.h"
#include "oddebml/oEbmlId.h"
#include "oddebml/oEbmlSize.h"

/*******************************************************************************
********************************************************* Types and Definitions
********************************************************************************
 
*******************************************************************************/

struct oEbmlMarker
{
   oEbmlId id;
   int64_t size;
   fpos_t pos;
};
typedef struct oEbmlMarker oEbmlMarker;

struct oEbmlMarkerSlice
{
   int64_t s;
   oEbmlMarker const* v;
};
typedef struct oEbmlMarkerSlice oEbmlMarkerSlice;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

ODDEBML_API int cmp_ebml_marker_o( oEbmlMarker const a[static 1],
                                   oEbmlMarker const b[static 1] );

ODDEBML_API bool ebml_marker_covers_o( oEbmlMarker const marker[static 1],
                                       oEbmlMarker const oth[static 1] );

ODDEBML_API bool fscan_ebml_marker_o( FILE* f,
                                      oEbmlMarker marker[static 1],
                                      cErrorStack es[static 1] );

#endif