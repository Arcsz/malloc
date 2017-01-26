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

extern char etext, edata, end;

int	main(int argc, char *argv[])
{
malloc(1000);
printf("%d\n", etext);
  printf("%d\n", edata);
  printf("%d\n", end);
  return (0);
}
