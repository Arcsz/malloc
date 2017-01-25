/*
** malloc.c for malloc in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Tue Jan 24 21:09:17 2017 David Zeng
** Last update Tue Jan 24 21:09:17 2017 David Zeng
*/

#include <stdio.h>
#include "malloc.h"

t_list allocated_blocks = {NULL, NULL};
/* t_list free_blocks = {NULL, NULL}; */
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

// TODO REMOVE COMMENTS

/**
 * Get a block from free_blocks
 */
static void	*get_free_block(size_t size)
{
  t_node	*node;

  node = allocated_blocks.head;
  while (node)
    {
      if (node->is_free && node->size >= size)
	{
	  node->is_free = false;
	  return (node + 1);
	}
      node = node->next;
    }
  return (NULL);
}

/**
 * Create a new block and add it to allocated_blocks
 */
static void	*get_new_block(size_t size)
{
  t_node	*block;

  block = create_block(size);
  if (!block)
    return (NULL);
  if (push_back(&allocated_blocks, block))
    {
      // add sizeof(t_node) to block with + 1
      return (block + 1);
    }
  return (NULL);
}

/**
 * Malloc function
 */
void	*malloc(size_t size)
{
  write(1, "yo", 2);
  void	*ptr;

  // check if size is okay
  if (size == 0)
    return (NULL);
  // lock thread
  pthread_mutex_lock(&lock);
  // get block from free list or new one
  ptr = get_free_block(size);
  if (!ptr)
    ptr = get_new_block(size);
  // unlock thread
  pthread_mutex_unlock(&lock);
  printf("%ld\n", (long int)ptr);
  return (ptr);
}
