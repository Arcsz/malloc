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
/*   if (block->prev && block->prev->is_free) */
/*     { */
/*       block->prev->size += sizeof(t_node) + block->size; */
/*       block->prev->next = block->next; */
/*       block = block->prev; */
/*     } */
/*   if (block->next &&  block->next->is_free) */
/*     { */
/*       block->size += sizeof(t_node) + block->next->size; */
/*       block->next = block->next->next; */
/*     } */
/* } */

/* void		insert_sort(t_node *block) */
/* { */
/*   t_node	*node; */

/*   node = free_blocks; */

/*   if (!node) */
/*     { */
/*       free_blocks = block; */
/*       return ; */
/*     } */
/*   while (node->next) */
/*     { */
/*       if (node > block) */
/* 	{ */
/* 	  block->next = node; */
/* 	  block->prev = node->prev; */
/* 	  node->prev = block; */
/* 	  return ; */
/* 	} */
/*       node = node->next; */
/*     } */
/*   node->next = block; */
/* } */

void		free(void *ptr)
{
  t_node	*block;

  if (ptr)
    {
      pthread_mutex_lock(&lock);

      block = ptr_to_block(ptr);
      block->is_free = true;
      /* insert_sort(block); */
      /* merge_free_blocks(block); */

      pthread_mutex_unlock(&lock);
    }
}
