#include <stdarg.h>
#include <setjmp.h>
#include <stdlib.h>

#include "../include/cmockery.h"
#include "disemvowel.h"

void test_empty_str(void) {
  char* dis = disemvowel("");
  assert_string_equal("", dis);
  free(dis);
}

void test_no_vowels(void) {
  char* dis = disemvowel("pqrst");
  assert_string_equal("pqrst", dis);
  free(dis);
}

void test_only_vowels(void) {
  char* dis = disemvowel("aeiouAEIOUOIEAuoiea");
  assert_string_equal("", dis);
  free(dis);
}

void test_my_name(void) {
  char* dis = disemvowel("Nicholas Freitag McPhee");
  assert_string_equal("Nchls Frtg McPh", dis);
  free(dis);
}

void test_punctuation(void) {
  char* dis = disemvowel("An (Unexplained) Elephant!");
  assert_string_equal("n (nxplnd) lphnt!", dis);
  free(dis);
}

void test_long_string(void) {
  char* str;
  int size;
  int i;

  size = 50000;
  str = calloc(size, sizeof(char));
  str[0] = 'x';
  str[1] = 'y';
  str[2] = 'z';
  for (i = 3; i < size-1; ++i) {
    str[i] = 'a';
  }
  str[size-1] = '\0';
  char* dis = disemvowel(str);
  assert_string_equal("xyz", dis);
  free(str);
  free(dis);
}

int main(int argc, char* argv[]) {
  UnitTest tests[] = {
    unit_test(test_empty_str),
    unit_test(test_no_vowels),
    unit_test(test_only_vowels),
    unit_test(test_my_name),
    unit_test(test_punctuation),
    unit_test(test_long_string)
  };
  return run_tests(tests);
}
