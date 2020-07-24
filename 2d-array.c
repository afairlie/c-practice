#include <stdio.h>
#include <math.h>

int main(void) {
  char arr[2][2] = 
  {
    {'a', 'b'},
    {'c', 'd'}
  };

  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      printf("i: %i, j: %i\n", i, j);
      printf("%c\n", arr[i][j]);
    }
  }
  
}