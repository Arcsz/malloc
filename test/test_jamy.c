#include <stdio.h>
#include <stdlib.h>
#include "./include/malloc.h"

int	main(void)
{
  char	*str;
  char	*str2;
  int	*nb;
  char	*str3;

  str = malloc(sizeof(char) * 56);
  str2 = malloc(sizeof(char) * 42);
  nb = malloc(sizeof(int) * 84);
  free(str2);
  str3 = malloc(sizeof(char) * 3);
  /* if (str == NULL) */
  /*   printf("%s\n", "Malloc failed"); */
  /* else */
  /*   printf("%s\n", "Malloc OK"); */
  show_alloc_mem();
  return (0);
}
