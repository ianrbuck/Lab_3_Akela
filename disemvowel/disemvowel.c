#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "disemvowel.h"

char* disemvowel(char* str) {
  int i, j, vcount, len;
  len = strlen(str);
  
  for (i=0; i<len; ++i) {
    if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u' || str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U'){
      ++vcount;
    }
  }
  char *result;
  result = calloc(len-vcount+1, sizeof(char));
  j=0;
  for (i=0; i<len; ++i) {
    if(!(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u' || str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U')){
      result[j] = str[i];
      ++j;
    }
  }
  result[j] = '\0';
  return result;
}
