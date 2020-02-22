#ifndef __SORT_BY_BITS_H__
#define __SORT_BY_BITS_H__

#include "utils.h"

namespace sort_by_bits {

   typedef struct sort_by_bits_s {
      int val;
      int popcount;
   } sort_by_bits_t;

   void print( const char* prefix, const sort_by_bits_t* sbb );
   void print( const char* prefix, const sort_by_bits_t* sbb_array, const int num_vals ); 
   
   // Assumes pointers are to an array of sort_by_bits
   void swap( sort_by_bits_t* left, sort_by_bits_t* right );

   void gen( sort_by_bits_t* sbb_array, const int upper, const int lower, const int num_vals );

   int get_partition_index( sort_by_bits_t* sbb_array, int low_index, int high_index );

   void quicksort( sort_by_bits_t* sbb_array, int low_index, int high_index );
}
#endif // end of #ifndef __SORT_BY_BITS_H__
