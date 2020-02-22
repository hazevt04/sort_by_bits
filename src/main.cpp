// C++ File for main

#include <cstdio>
#include <stdlib.h>

#include "sort_by_bits.h"

typedef sort_by_bits::sort_by_bits_t sbb_t;

int main( int argc, char* argv[] ) {
  
   int num_vals = 256;
   int upper = 32767;
   int lower = 1;

   sbb_t sbb_array[num_vals];
   
   sort_by_bits::gen( &(sbb_array[0]), upper, lower, num_vals );
   sort_by_bits::print( "sbb_array Before Sort", &(sbb_array[0]), num_vals );
   
   sort_by_bits::quicksort( &(sbb_array[0]), 0, (num_vals-1) );
   sort_by_bits::print( "sbb_array After Sort", &(sbb_array[0]), num_vals );
   return 0;
}

// end of C++ file for main
