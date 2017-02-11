/*
** realloc.c for realloc in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Wed Jan 25 16:22:02 2017 David Zeng
** Last update Wed Jan 25 16:22:02 2017 David Zeng
*/

#include "malloc.h"

static bool	realloc_free_space(t_node *block, size_t size)
{
  t_node	*next;

  pthread_mutex_lock(&g_lock);
  next = get_block_at(block, block->size);
  if (next->is_free && block->size + next->size + HEADER_SIZE >= size)
    {
      if (next->prev)
	next->prev->next = next->next;
      if (next->next)
	next->next->prev = next->prev;
      if (next == g_free_blocks)
	g_free_blocks = NULL;
      block->size = next->size + block->size + HEADER_SIZE;
      pthread_mutex_unlock(&g_lock);
      return (true);
    }
  pthread_mutex_unlock(&g_lock);
  return (false);
}

static t_node	*get_prev_free(t_node *block)
{
  t_node	*node;

  node = g_free_blocks;
  while (node && node->next && node->next < block)
    {
      node = node->next;
    }
  return (node);
}

static void	create_new_block(t_node *block, size_t size)
{
  t_node	*new_block;
  t_node	*prev;
  t_node	*next;

  pthread_mutex_lock(&g_lock);
  prev = get_prev_free(block);
  next = (prev) ? prev->next : NULL;
  new_block = get_block_at(block, size);
  new_block->size = block->size - size - HEADER_SIZE;
  new_block->prev = prev;
  new_block->next = next;
  new_block->is_free = true;
  if (prev)
    prev->next = new_block;
  if (next)
    next->prev = new_block;
  if (!g_free_blocks)
    g_free_blocks = new_block;
  block->size = size;
  pthread_mutex_unlock(&g_lock);
}

void		*realloc(void* ptr, size_t size)
{
  void		*new_ptr;
  t_node	*node;

  size = next_pow2(size);
  if (!ptr)
    return (malloc(size));
  node = ptr_to_block(ptr);
  if (node->size >= size)
    {
      if (node->size - size >= HEADER_SIZE + MIN_BLOCK_SIZE)
	create_new_block(node, size);
      return (ptr);
    }
  if (realloc_free_space(node, size))
    new_ptr = ptr;
  else
    new_ptr = malloc(size);
  if (new_ptr && new_ptr != ptr)
    {
      memcpy(new_ptr, ptr, node->size);
      free(ptr);
    }
  return (new_ptr);
}
