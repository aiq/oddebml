#include "clingo/io/write.h"
#include "clingo/lang/expect.h"
#include "oddebml/oEbmlSize.h"

TEMP_SLICE_C_(
   test,
   {
      uint64_t raw;
      cBytes exp;
   }
)
#define t_( ... ) ((test){__VA_ARGS__})

int main( void )
{
   init_tap_c_();

   testSlice tests = slice_c_( test,
      t_(
         0x01ffffffffffffff,
         slice_c_( cByte, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff )
      ),
      t_( 0x1a45dfa3, slice_c_( cByte, 0x1a, 0x45, 0xdf, 0xa3 ) ),
      t_( 0x3e83bb, slice_c_( cByte, 0x3e, 0x83, 0xbb ) ),
      t_( 0x4286, slice_c_( cByte, 0x42, 0x86 ) ),
      t_( 0xfa, slice_c_( cByte, 0xfa ) )
   );

   for_each_c_( test const*, t, tests )
   {
      cRecorder* buf = &recorder_c_( 64 );
      bool res = record_ebml_size_o( buf, ebml_size_o( t->raw ) );
      res &= eq_c( cmp_bytes_c( recorded_bytes_c( buf ), t->exp ) );

      cRecorder* rec = &recorder_c_( 64 );
      write_c_( rec, "expected {bs:X/c/8}, got {bs:X/c/8}", t->exp, recorded_bytes_c( buf ) );
      tap_desc_c( res, turn_into_cstr_c( rec ) );
   }

   return finish_tap_c_();
}