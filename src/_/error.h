#ifndef ODDJSON_INTERN_ERROR_H
#define ODDJSON_INTERN_ERROR_H

#include "oddebml/error.h"

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

static inline bool push_ebml_error_o( cErrorStack es[static 1] )
{
   return push_error_c_( es, &O_EbmlError );
}

static inline bool push_ebml_lit_error_o( cErrorStack es[static 1],
                                          char const str[static 1] )
{
   return push_lit_error_c( es, str ) || push_ebml_error_o( es );
}

#endif