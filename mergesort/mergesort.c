#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>
#include "mergesort.h"

int i;

void mergesort(int size, int values[]) {
  
  void mergeRanges(int values[], int startIndex, int midPoint, int endIndex) {
    int rangeSize = endIndex - startIndex;
    int destination[rangeSize];
    int firstIndex = startIndex;
    int secondIndex = midPoint;
    int copyIndex = 0;
    while (firstIndex < midPoint && secondIndex < endIndex) {
      if (values[firstIndex] < values[secondIndex]){
	destination[copyIndex] = values[firstIndex];
	++firstIndex;
      } else {
	destination[copyIndex] = values[secondIndex];
	++secondIndex;
      }
      ++copyIndex;
    }
    while (firstIndex < midPoint) {
      destination[copyIndex] = values[firstIndex];
      ++copyIndex;
      ++firstIndex;
    }
    while (secondIndex < endIndex) {
      destination[copyIndex] = values[secondIndex];
      ++copyIndex;
      ++secondIndex;
    }
    for (i = 0; i < rangeSize; ++i) {
      values[i + startIndex] = destination[i];
    }
  }

  void mergeSortRange(int values[], int startIndex, int endIndex) {
    int rangeSize = endIndex - startIndex;
    if(rangeSize >= 2) {
      int midPoint = (startIndex + endIndex)/2;
      mergeSortRange(values, startIndex, midPoint);
      mergeSortRange(values, midPoint, endIndex);
      mergeRanges(values, startIndex, midPoint, endIndex);
    }
  }

  mergeSortRange(values, 0, size);
}
