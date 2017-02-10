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

pthread_mutex_t	g_lock = PTHREAD_MUTEX_INITIALIZER;
t_node		*g_head = NULL;
t_node		*g_last = NULL;
t_node		*g_free_blocks = NULL;

static void	split_block(t_node *block, size_t size)
{
  t_node	*new_block;

  new_block = get_block_at(block, size);
  new_block->size = block->size - size - HEADER_SIZE;
  new_block->next = block->next;
  new_block->prev = block->prev;
  new_block->is_free = true;
  if (block->prev)
    block->prev->next = new_block;
  if (block->next)
    block->next->prev = new_block;
  if (block == g_free_blocks)
    g_free_blocks = new_block;
  block->size = size;
}

static void	*get_free_block(size_t size)
{
  t_node	*node;

  node = g_free_blocks;
  while (node)
    {
      if (node->size >= size)
	{
	  if (node->size - size >= HEADER_SIZE + MIN_BLOCK_SIZE)
	    split_block(node, size);
	  else
	    {
	      if (node->prev)
	      	node->prev->next = node->next;
	      if (node->next)
	      	node->next->prev = node->prev;
	      if (node == g_free_blocks)
		g_free_blocks = NULL;
	    }
	  node->is_free = false;
	  return (node + 1);
	}
      node = node->next;
    }
  return (NULL);
}

static void	*get_internal_memory(size_t size)
{
  static size_t	page_nb = PAGE_NUMBER;
  static size_t	cur_size = 0;
  static void	*cur_ptr = NULL;
  size_t	old_size;

  if (cur_ptr + cur_size != sbrk(0))
    {
      cur_ptr = sbrk(0);
      cur_size = 0;
    }
  if (cur_size < size)
    {
      old_size = cur_size;
      while (cur_size < size)
	cur_size += getpagesize() * page_nb;
      page_nb = (page_nb >= PAGE_MAX) ? page_nb : page_nb * 2;
      old_size = cur_size - old_size;
      if (!cur_ptr && (cur_ptr = sbrk(old_size)) == SBRK_FAILED)
	return (NULL);
      else if (sbrk(old_size) == SBRK_FAILED)
	return (NULL);
    }
  cur_size -= size;
  cur_ptr = (char*)cur_ptr + size;
  return ((char*)cur_ptr - size);
}

static void	*get_new_block(size_t size)
{
  t_node	*block;

  block = get_internal_memory(size + HEADER_SIZE);
  if (!block)
    return (NULL);
  if (!g_head)
    g_head = block;
  block->size = size;
  block->next = NULL;
  block->prev = NULL;
  block->is_free = false;
  g_last = block;
  return (block + 1);
}

void	*malloc(size_t size)
{
  void	*ptr;

  if ((int)size < 0)
    return (NULL);
  size = next_pow2(size);
  pthread_mutex_lock(&g_lock);
  ptr = get_free_block(size);
  if (!ptr)
    ptr = get_new_block(size);
  pthread_mutex_unlock(&g_lock);
  return (ptr);
}
