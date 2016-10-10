// This file is an example of my intended use-case for this simple vector class.
//
///////////////////////////
// Supa-lightweight implementation of an vector array of int elements
//
// A vector array is a dynamically-sized data structure that grows to accomodate
// its contents. Unlike the linked list, a vector's data can be accessed
// using pointer arithmetic.
//
// This implementation is meant for quick stdin processing. There is no built-in
// support for deleting elements. Nobody is perfect...
//
// (C) 2016 Hugh Young, Tuning Fork Productions
// This code is made freely available under the WTFPL: http://wtfpl.net

#include "vector-int.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char ** argv)
{
  vector_int * v = vector_int_init();
  char * input = malloc(sizeof(char) * 9);

  printf("Input numbers seperated by newlines.\nPress Control-D (EOF) to finish.\n");

  // Input: Simply push stdin data as vector entries
  while ( fgets(input, 9, stdin) != NULL )
  {
    vector_int_push(v, atoi(input));
  }

  // EOF: Output stats
  printf("Assembled a vector of size %i, capacity %i, with elements:\n",
          v->size, v->capacity);

  for (int i = 0; i < v->size; i++) {
    printf("%i\n", v->data[i]);
  }
  printf("\n");
  vector_int_free(v);
}