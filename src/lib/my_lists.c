/*
** list.c for list in /home/francis/Documents/CPE/CPE_2016_Lemin/src/lib/
**
** Made by Francois Caicedo
** Login   <francois.caicedo@epitech.eu@epitech.eu>
**
** Started on  Thu Apr  6 10:20:14 2017 Francois Caicedo
** Last update Mon May  1 16:31:31 2017 Francois Caicedo
*/

#include "lib.h"

void		xfree_list(t_list *list)
{
  t_node	*del;
  t_node	*tmp;

  if (list)
    {
      tmp = list->p_head;
      while (tmp)
	{
	  del = tmp;
	  tmp = tmp->p_next;
	  xfree(del);
	}
    }
  xfree(list);
}

void		show_list(t_list *list)
{
  t_node	*tmp;
  int		i;

  tmp = list->p_head;
  i = -1;
  while (tmp)
    {
      my_printf("(%d)\n", 1, ++i);
      tmp = tmp->p_next;
    }
}

void		add_node_list(t_list *list, t_node *node)
{
  if (list)
    {
      node->p_next = NULL;
      if (list->p_tail == NULL)
	{
	  node->p_prev = NULL;
	  list->p_head = node;
	  list->p_tail = node;
	}
      else
	{
	  list->p_tail->p_next = node;
	  node->p_prev = list->p_tail;
	  list->p_tail = node;
	}
      list->lenght++;
    }
}

t_node		*init_node()
{
  t_node	*new;

  if ((new = malloc(sizeof *new)) == NULL)
    return (NULL);
  new->p_prev = NULL;
  new->p_next = NULL;
  return (new);
}

t_list		*init_list()
{
  t_list	*new;

  if ((new = malloc(sizeof *new)) == NULL)
    return (NULL);
  new->lenght = 0;
  new->p_head = NULL;
  new->p_tail = NULL;
  return (new);
}
