/*
** my_2di_utils.c for lib in /home/francis/Documents/CPE/CPE_2016_Lemin/src/lib/
**
** Made by Francois Caicedo
** Login   <francois.caicedo@epitech.eu@epitech.eu>
**
** Started on  Thu Apr  6 16:21:11 2017 Francois Caicedo
** Last update Mon May 22 17:42:49 2017 Francois Caicedo
*/

#include "lib.h"

void		my_free_2di(int **ptr)
{
  int		i;

  i = -1;
  while (ptr[++i] != -1)
    free(ptr[i]);
  free(ptr);
}

void		my_show_2di(int **ptr)
{
  int		i;

  i = -1;
  while (ptr[++i] != -1)
    my_printf("%s\n", 1, ptr[i]);
}
