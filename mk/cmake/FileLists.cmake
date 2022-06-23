################################################################################
# INC_FILES
################################################################################
set( INC_FILES
   ${INC_DIR}/oddebml/apidecl.h

   ${INC_DIR}/oddebml/error.h
   ${INC_DIR}/oddebml/o_EbmlType.h
   ${INC_DIR}/oddebml/OEbmlBuilder.h
   ${INC_DIR}/oddebml/oEbmlDate.h
   ${INC_DIR}/oddebml/oEbmlDecl.h
   ${INC_DIR}/oddebml/oEbmlElement.h
   ${INC_DIR}/oddebml/oEbmlHeader.h
   ${INC_DIR}/oddebml/oEbmlId.h
   ${INC_DIR}/oddebml/OEbmlParser.h
   ${INC_DIR}/oddebml/OEbmlSchema.h
   ${INC_DIR}/oddebml/oEbmlSize.h
)

################################################################################
# SRC_FILES
################################################################################
set( SRC_FILES
   ${SRC_DIR}/_/misc.c
   ${SRC_DIR}/_/oEbmlElementStack.c
   ${SRC_DIR}/_/oEbmlMarker.c
   ${SRC_DIR}/_/OEbmlSchemaMisc.c

   ${SRC_DIR}/oddebml/error.c
   ${SRC_DIR}/oddebml/o_EbmlType.c
   ${SRC_DIR}/oddebml/OEbmlBuilder.c
   ${SRC_DIR}/oddebml/oEbmlDate.c
   ${SRC_DIR}/oddebml/oEbmlDecl.c
   ${SRC_DIR}/oddebml/oEbmlElement.c
   ${SRC_DIR}/oddebml/oEbmlHeader.c
   ${SRC_DIR}/oddebml/oEbmlId.c
   ${SRC_DIR}/oddebml/OEbmlParser.c
   ${SRC_DIR}/oddebml/OEbmlSchema.c
   ${SRC_DIR}/oddebml/oEbmlSize.c
)

################################################################################
# TEST_FILES
################################################################################
set( TEST_FILES
   # oEbmlBuilder
   ${TEST_DIR}/oddebml/oEbmlBuilder/OEbmlBuilder-overview.c
   # oEbmlDate
   ${TEST_DIR}/oddebml/oEbmlDate/as_ebml_date.c
   # oEbmlId
   ${TEST_DIR}/oddebml/oEbmlId/decode_ebml_id.c
   ${TEST_DIR}/oddebml/oEbmlId/ebml_id_is_valid.c
   ${TEST_DIR}/oddebml/oEbmlId/ebml_id_length.c
   ${TEST_DIR}/oddebml/oEbmlId/encode_ebml_id.c
   ${TEST_DIR}/oddebml/oEbmlId/record_ebml_id.c
   ${TEST_DIR}/oddebml/oEbmlId/scan_ebml_id.c
   # OEbmlSchema
   ${TEST_DIR}/oddebml/OEbmlSchema/iterate_ebml_schema.c
   # oEbmlSize
   ${TEST_DIR}/oddebml/oEbmlSize/decode_ebml_size.c
   ${TEST_DIR}/oddebml/oEbmlSize/ebml_size_is_unknown.c
   ${TEST_DIR}/oddebml/oEbmlSize/ebml_size_length.c
   ${TEST_DIR}/oddebml/oEbmlSize/encode_ebml_size.c
   ${TEST_DIR}/oddebml/oEbmlSize/record_ebml_size.c
   ${TEST_DIR}/oddebml/oEbmlSize/scan_ebml_size.c
)
