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

static void	split_block(t_node *block, size_t block_real_size)
{
  t_node	*new_block;

  //get new block address
  new_block = (t_node*)((char*)(block + 1) + block_real_size + MIN_BLOCK_SIZE);
  new_block->size = block->size - block_real_size;
  new_block->is_free = true;
  new_block->next = block->next;
  new_block->prev = block;
  //set current block to real size
  block->size = block_real_size;
  block->next = new_block;
  // TODO ADD TO FREE LIST
}

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
	  // split block
	  if (node->size - size >= HEADER_SIZE + MIN_BLOCK_SIZE)
	    split_block(node, size);
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

  // increment break with size + meta
  block = sbrk(size + sizeof(t_node));
  if (block == SBRK_FAILED)
    return (NULL);
  block->size = size;
  block->is_free = false;
  block->next = NULL;
  block->prev = NULL;
  if (!block || !push_back(&allocated_blocks, block))
    return (NULL);
  // add sizeof(t_node) to block with + 1
  return (block + 1);
}

/**
 * Malloc function
 */
void	*malloc(size_t size)
{
  void	*ptr;

  // check if size is okay
  if (size == 0)
    return (NULL);
  // get next power of 2
  size = (size + 3) & ~3;
  // lock thread
  pthread_mutex_lock(&lock);
  // get block from free list or new one
  ptr = get_free_block(size);
  if (!ptr)
    ptr = get_new_block(size);
  // unlock thread
  pthread_mutex_unlock(&lock);
  return (ptr);
}
