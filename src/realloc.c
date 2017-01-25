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

void		*realloc(void* ptr, size_t size)
{
  void		*new_ptr;
  t_node	*node;

  if (!ptr)
    return (malloc(size));
  node = ptr_to_block(ptr);
  if (node->size >= size)
    return (ptr);
  new_ptr = malloc(size);
  if (new_ptr)
    {
      memcpy(new_ptr, ptr, node->size);
      free(ptr);
    }
  return (new_ptr);
}
