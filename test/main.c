/*
** main.c for main in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Mon Jan 23 17:57:49 2017 David Zeng
** Last update Mon Jan 23 17:57:49 2017 David Zeng
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/malloc.h"

int     main()
{
  void *tab[100];
  int i;
  int j;
  int size;

  for (i = 0; i < 100; i++)
    tab[i] = NULL;
  for (i = 0; i < 1000; i++) {
    j = rand() % 100;
    if (tab[j] == NULL) {
      tab[j] = malloc(size = rand() % 1000);
      printf("malloc : tab[%d] <- %d\n", j, size);
    } else {
      printf("free : tab[%d]\n", j);
      free(tab[j]);
      tab[j] = NULL;
    }
  }
  /* show_alloc_mem(); */
  return 0;
}
