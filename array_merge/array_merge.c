#include <stdlib.h>
#include <stdio.h>

#include "array_merge.h"


int* array_merge(int num_arrays, int* sizes, int** values){
  int i, j;
  int max = 0;
  int sizesSum = 0;
  int count = 0;

  for(i = 0; i < num_arrays; ++i) {
    sizesSum += sizes[i];
  }

  int* result = calloc(sizesSum + 1, sizeof(int));
 
  if (num_arrays == 0) {
    return result;
  }
  
  for(i = 0; i < num_arrays; i++) {
    for(j = 0; j < sizes[i]; j++) {
      result[count] = values[i][j];
      if(values[i][j] > max) {
	max = values[i][j];
      }
      count++;
    }
  }

  int* counts = calloc(max, sizeof(int));

  for(i = 0; i < sizesSum; i++) {
    counts[result[i]]++;
  }

  count = 1;

  for(i = 0; i <= max; i++) {
    if(counts[i] > 0) {
      result[count] = i;
      count++;
    }
  }

  free(counts);
  result[0] = count-1;
  return result;
}
