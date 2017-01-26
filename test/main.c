/*
** main.c for main in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Mon Jan 23 17:57:49 2017 David Zeng
** Last update Mon Jan 23 17:57:49 2017 David Zeng
*/

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
  void *test1 = malloc(100);
  void *test2 = malloc(100);
  void *test3 = malloc(100);
  free(test2);
  void *test4 = malloc(10);
  free(test1);
  free(test3);
  free(test4);
  return (0);
}
