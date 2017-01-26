/*
** calloc.c for calloc in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Wed Jan 25 17:23:50 2017 David Zeng
** Last update Wed Jan 25 17:23:50 2017 David Zeng
*/

#include "malloc.h"

//TODO REMOVE CALLOC

void	*calloc(size_t nmemb, size_t size)
{
  void	*ptr;

  ptr = malloc(size * nmemb);
  memset(ptr, 0, size * nmemb);
  return (ptr);
}
