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
#include <unistd.h>
#include <string.h>

int	main(int argc, char *argv[])
{
  char	*str;

  str = sbrk(0);
  printf("%d\n", brk(str + 6));
  strcpy(str, "hello");
  printf("%s\n", str);
  return (0);
}
