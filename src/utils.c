/*
** utils.c for utils in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Thu Jan 26 10:49:07 2017 David Zeng
** Last update Thu Jan 26 10:49:07 2017 David Zeng
*/

#include "malloc.h"

t_node	*ptr_to_block(void *ptr)
{
  return ((t_node*)ptr - 1);
}
