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

int	main(int argc, char *argv[])
{
  void *test = malloc(-1);
  printf("%p\n", test);
  printf("%lu\n", (size_t)-1);
  return (0);
}
