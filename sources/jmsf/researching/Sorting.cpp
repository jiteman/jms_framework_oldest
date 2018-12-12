#include "Sorting.h"


void quicksort_two_way( Item a[], int l, int r ) {
	if ( r <= l ) return;

	int i = l - 1
	int j = r;
	Item v = a[ r ];	
	
	for ( ;; ) {
		while ( a[ ++i ] < v );
		
		while ( v < a[ --j ] ) {
			if ( j == l ) break;
		}
		
		if ( i >= j ) break;
		
		exch( a[ i ], a[ j ] );
	}
	
	exch( a[ i ], a[ r ] );	
	quicksort_two_way( a, l, i - 1 );
	quicksort_two_way( a, i + 1, r );
}

void quicksort_three_way( Item a[], int l, int r ) {
	if ( r <= l ) return;

	int i = l - 1;
	int j = r;
	int p = l - 1;
	int q = r;
	Item v = a[ r ];	
	
	for ( ;; ) {
		while ( a[ ++i ] < v );
		
		while ( v < a[ --j ] ) {
			if ( j == l ) break;
		}
		
		if ( i >= j ) break;
		
		exch( a[ i ], a[ j ] );
		
		if ( a[ i ] == v ) {
			p++;
			exch( a[ p ], a[ i ] );
		}
		
		if ( v == a[ j ] ) {
			q--;
			exch( a[ j ], a[ q ] );
		}
	}
	
	exch( a[ i ], a[ r ] );
	j = i - 1;
	i = i + 1;
	
	for ( int k = l; k < p; k++, j-- ) {
		exch( a[ k ], a[ j ] );
	}
	
	for ( int k = r - 1; k > q; k--, i++ ) {
		exch( a[ i ], a[ k ] );
	}
	
	quicksort_three_way( a, l, j );
	quicksort_three_way( a, i, r );
}