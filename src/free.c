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

/**
 * Merge freed block
 */
/* void		merge_free_blocks(t_node *block) */
/* { */

/* } */

/* void		insert_sort(t_node *block) */
/* { */
/*   t_node	*node; */

/*   node = free_blocks; */
/*   while (node) */
/*     { */

/*       node = node->next; */
/*     } */
/* } */

void		free(void *ptr)
{
  t_node	*block;

  if (ptr)
    {
      pthread_mutex_lock(&lock);

      block = ptr_to_block(ptr);
      block->is_free = true;

      pthread_mutex_unlock(&lock);
    }
}
