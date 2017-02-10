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

void		*realloc(void* ptr, size_t size)
{
  void		*new_ptr;
  t_node	*node;

  if (!ptr)
    return (malloc(size));
  node = ptr_to_block(ptr);
  if (node->size >= size)
    return (ptr);
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
