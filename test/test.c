/*
** test.c for test in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Thu Jan 26 11:21:19 2017 David Zeng
** Last update Thu Jan 26 11:21:19 2017 David Zeng
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char buf[10000];

  /* if (argc != 2) */
  /*   return printf("1 args pls"); */
  strcpy(buf, "LD_LIBRARY_PATH=./ LD_PRELOAD=libmy_malloc.so ls");
  /* strcat(buf, argv[1]); */
  system(buf);
  return 0;
}
