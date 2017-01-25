/*
** list.c for list in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Wed Jan 25 13:47:08 2017 David Zeng
** Last update Wed Jan 25 13:47:08 2017 David Zeng
*/

#include "malloc.h"

void		*create_block(size_t size)
{
  t_node	*ptr;

  // increment break with size + meta
  ptr = sbrk(size + sizeof(t_node));
  if (ptr == (void*)-1)
    return (NULL);
  ptr->size = size;
  ptr->is_free = false;
  ptr->next = NULL;
  /* ptr->prev = NULL; */
  return (ptr);
}

bool	push_back(t_list *list, t_node *block)
{
  if (!block)
    return (false);
  if (!list->head)
    {
      list->head = block;
      list->last = block;
    }
  else
    {
      list->last->next = block;
      /* block->prev = list->last; */
      list->last = block;
    }
  return (true);
}
