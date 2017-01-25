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
  char	*test = calloc(7, sizeof(char));
  strcpy(test, "hello");
  test = realloc(test, 10);
  strcat(test, "AB");
  write(1, test, 8);
  free(test);
  return (0);
}
