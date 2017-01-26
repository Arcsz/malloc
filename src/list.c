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

void	push_back(t_list *list, t_node *block)
{
  if (!list->head)
    {
      list->head = block;
      list->last = block;
    }
  else
    {
      list->last->next = block;
      block->prev = list->last;
      list->last = block;
    }
}
