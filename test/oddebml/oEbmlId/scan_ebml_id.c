#include "clingo/io/write.h"
#include "clingo/lang/expect.h"
#include "oddebml/oEbmlId.h"

TEMP_SLICE_C_(
   test,
   {
      cBytes inp;
      uint32_t exp;
   }
)
#define t_( ... ) ((test){__VA_ARGS__})

int main( void )
{
   init_tap_c_();

   testSlice tests = slice_c_( test,
      t_( slice_c_( cByte, 0x1a, 0x45, 0xdf, 0xa3, 0x00 ), 0x1a45dfa3 ),
      t_( slice_c_( cByte, 0x3e, 0x83, 0xbb, 0x00 ), 0x3e83bb ),
      t_( slice_c_( cByte, 0x42, 0x86, 0x00 ), 0x4286 ),
      t_( slice_c_( cByte, 0xfa, 0x00 ), 0xfa )
   );

   for_each_c_( test const*, t, tests )
   {
      cScanner* sca = &make_scanner_c_( t->inp.s, t->inp.v );
      oEbmlId id;
      bool res = scan_ebml_id_o( sca, &id );
      res &= eq_c( cmp_ebml_id_o( id, ebml_id_o( t->exp ) ) );

      cRecorder* rec = &recorder_c_( 64 );
      write_c_( rec, "expected {u32:x}, got {u32:x}", t->exp, id.raw );
      tap_desc_c( res, turn_into_cstr_c( rec ) );
   }

   return finish_tap_c_();
}