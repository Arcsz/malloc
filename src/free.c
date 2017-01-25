/*
** free.c for free in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Wed Jan 25 00:48:00 2017 David Zeng
** Last update Wed Jan 25 00:48:00 2017 David Zeng
*/

#include <stdio.h>
#include "malloc.h"

t_node	*ptr_to_block(void *ptr)
{
  return ((t_node*)ptr - 1);
}

void		free(void *ptr)
{
  t_node	*node;

  if (ptr)
    {
      pthread_mutex_lock(&lock);
      node = ptr_to_block(ptr);
      assert(node->is_free == false);
      node->is_free = true;
      pthread_mutex_unlock(&lock);
    }
}
