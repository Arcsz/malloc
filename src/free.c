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
static void	merge_free_blocks(t_node *block)
{
  if (block->prev && block->prev->is_free &&
      get_block_at(block->prev, block->prev->size) == block)
    {
      block->prev->size += HEADER_SIZE + block->size;
      block->prev->next = block->next;
      if (block->next)
	block->next->prev = block->prev;
      block = block->prev;
    }
  if (block->next && block->next->is_free &&
      get_block_at(block, block->size) == block->next)
    {
      block->size += HEADER_SIZE + block->next->size;
      if (block->next->next)
  	block->next->next->prev = block;
      block->next = block->next->next;
    }
}

static void	insert_sort(t_node *block)
{
  t_node	*node;

  if (!free_blocks || free_blocks > block)
    {
      block->next = free_blocks;
      block->prev = NULL;
      if (free_blocks)
	free_blocks->prev = block;
      free_blocks = block;
      return;
    }
  node = free_blocks;
  while (node->next && node->next < block)
    node = node->next;
  block->next = node->next;
  block->prev = node;
  if (node->next)
    node->next->prev = block;
  node->next = block;
}

void		free(void *ptr)
{
  t_node	*block;

  if (ptr)
    {
      pthread_mutex_lock(&lock);
      block = ptr_to_block(ptr);
      insert_sort(block);
      merge_free_blocks(block);
      block->is_free = true;
      pthread_mutex_unlock(&lock);
    }
}
