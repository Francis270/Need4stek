/*
** my_reallocs.c for lib in /home/francis/Documents/new_project/src/lib/
**
** Made by Francois Caicedo
** Login   <francois.caicedo@epitech.eu@epitech.eu>
**
** Started on  Tue Mar 28 15:28:01 2017 Francois Caicedo
** Last update Thu May 11 16:08:01 2017 Francois Caicedo
*/

#include "lib.h"

int		*my_realloc_1di(int *ptr, size_t size)
{
  int		*new_mem;
  int		i;
  size_t	reajust;

  i = -1;
  reajust = 0;
  if (size == 0 && ptr)
    return (free(ptr), NULL);
  if (ptr == NULL)
    {
      if ((new_mem = malloc(sizeof(int) * (size))) == NULL)
	return (NULL);
      new_mem[size - 1] = -1;
      return (new_mem);
    }
  while (ptr[reajust++] != -1);
  if (size < reajust)
    size = reajust + 2;
  if ((new_mem = malloc(sizeof(int) * (size))) == NULL)
    return (NULL);
  new_mem[size - 1] = -1;
  while (ptr[++i] != -1)
    new_mem[i] = ptr[i];
  return (free(ptr), new_mem);
}

char		*my_realloc_1dc(char *ptr, size_t size)
{
  char		*new_mem;

  new_mem = NULL;
  if (size == 0 && ptr)
    return (free(ptr), NULL);
  if (ptr == NULL)
    {
      if ((new_mem = malloc(sizeof(char) * (size))) == NULL)
	return (NULL);
      return (new_mem);
    }
  if ((new_mem = malloc(sizeof(char) * (size))) == NULL)
    return (NULL);
  my_strcpy(new_mem, ptr);
  return (free(ptr), new_mem);
}

char		**my_realloc_2dc(char **ptr, size_t size)
{
  char		**new_mem;
  int		len;

  len = -1;
  if (size == 0 && ptr)
    return (my_free_2dc(ptr), NULL);
  if (ptr == NULL)
    {
      if ((new_mem = malloc(sizeof(char *) * (size))) == NULL)
	return (NULL);
      new_mem[size - 1] = NULL;
      return (new_mem);
    }
  if ((new_mem = malloc(sizeof(char *) * (size))) == NULL)
    return (NULL);
  while (ptr[++len])
    {
      if ((new_mem[len] = my_strdup(ptr[len])) == NULL)
	return (NULL);
    }
  new_mem[size - 1] = NULL;
  if (ptr)
    my_free_2dc(ptr);
  return (new_mem);
}
