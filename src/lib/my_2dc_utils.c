/*
** my_2dc_utils.c for lib in /home/francis/Documents/new_project/src/lib/
**
** Made by Francois Caicedo
** Login   <francois.caicedo@epitech.eu@epitech.eu>
**
** Started on  Tue Mar 28 15:53:01 2017 Francois Caicedo
** Last update Mon May 22 17:51:32 2017 Francois Caicedo
*/

#include "lib.h"

void		my_free_2dc(char **ptr)
{
  int		i;

  i = -1;
  if (ptr)
    {
      while (ptr[++i])
	xfree(ptr[i]);
      xfree(ptr);
    }
}

void		my_show_2dc(char **ptr)
{
  int		i;

  i = 0;
  while (ptr[i])
    {
      my_printf("%s\n", 1, ptr[i]);
      i++;
    }
}

int		count_word(const char *str, const char n)
{
  unsigned int	nb;
  int		i;

  i = -1;
  nb = 0;
  while (str[++i])
    {
      if (str[i] == n)
	nb++;
    }
  return (nb);
}

int		word_len(const char *str, const char n, size_t len)
{
  unsigned int	nb;

  nb = 0;
  while (str[len] != n && str[len])
    {
      nb++;
      len++;
    }
  return (nb);
}

char		**my_str_to_wordtab(const char *s, const char n)
{
  char		**wordtab;
  size_t	i;
  size_t	j;
  size_t	k;

  i = 0;
  j = 0;
  if ((wordtab = malloc(sizeof(char *) * ((count_word(s, n) + 1)))) == NULL)
    return (NULL);
  while (s[i++] == n);
  while (s[i++])
    {
      k = 0;
      if ((wordtab[j] =
	   malloc(sizeof(char) * (word_len(s, n, i) + 1))) == NULL)
	return (NULL);
      while (s[i] != n && s[i])
	wordtab[j][k++] = s[i++];
      wordtab[j++][k] = 0;
    }
  wordtab[j] = NULL;
  return (wordtab);
}
