// C++ File for sort_by_bits

#include <iostream>
#include <stdlib.h>

#include "sort_by_bits.h"

void sort_by_bits::print( const char* prefix, const sort_by_bits_t* sbb ) {
   if ( prefix ) {
      printf( "%s", prefix );
   }
   printf( "Val: %d, Popcount: %d\n", sbb->val, sbb->popcount );
}


void sort_by_bits::print( const char* prefix, const sort_by_bits_t* sbb_array, const int num_vals ) {
   if ( prefix ) {
      printf( "%s:\n", prefix );
   }
   for( int index = 0; index < num_vals; index++ ) {
      std::string index_str = std::to_string(index) + ") ";
      sort_by_bits::print( index_str.c_str(), &(sbb_array[index]) );
   }
   printf( "\n" );
}


void sort_by_bits::swap( sort_by_bits_t* left, sort_by_bits_t* right ) {
   // left->val         ^= right->val;
   // left->popcount    ^= right->popcount;
   //
   // right->val        ^= left->val;
   // right->popcount   ^= left->popcount;
   //
   // left->val         ^= right->val;
   // left->popcount    ^= right->popcount;
   sort_by_bits_t temp;
   temp.val =        left->val;
   temp.popcount =   left->popcount;

   left->val =       right->val;
   left->popcount =  right->popcount;

   right->val =      temp.val;
   right->popcount = temp.popcount;
}


int sort_by_bits::get_partition_index( sort_by_bits_t* sbb_array, int low_index, int high_index ) {
   int pivot_popcount = sbb_array[high_index].popcount;

   int smaller_val_index = low_index - 1;

   for ( int index = low_index; index < high_index; index++ ) {
      if ( sbb_array[index].popcount < pivot_popcount ) {
         smaller_val_index++;
         swap( &(sbb_array[smaller_val_index]), &(sbb_array[index]) );
      }
   }
   swap( &(sbb_array[smaller_val_index + 1]), &(sbb_array[high_index]) );
   return (smaller_val_index + 1);
}


void sort_by_bits::quicksort( sort_by_bits_t* sbb_array, int low_index, int high_index ) {
   if ( low_index < high_index ) {
      int partition_index = get_partition_index( &(sbb_array[0]), low_index, high_index );

      quicksort( &(sbb_array[0]), low_index, partition_index - 1 );
      quicksort( &(sbb_array[0]), partition_index + 1, high_index );
   }
}


void sort_by_bits::gen( sort_by_bits_t* sbb_array, const int upper, const int lower, const int num_vals ) {
   int range = upper - lower + 1;
   for ( int index = 0; index < num_vals; index++ ) {
      int val = int(rand() % range) + lower;
      sbb_array[index].val = val;
      sbb_array[index].popcount = hd_popcount(val);
   }
}

// end of C++ file for sort_by_bits
