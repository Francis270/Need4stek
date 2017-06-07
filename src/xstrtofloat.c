/*
** xstrtofloat.c for n4s in /home/francis/Documents/TEK1/CPE/CPE_2016_n4s/src/
**
** Made by Francois Caicedo
** Login   <francois.caicedo@epitech.eu@epitech.eu>
**
** Started on  Tue May 23 10:37:30 2017 Francois Caicedo
** Last update Tue May 30 11:26:28 2017 Francois Caicedo
*/

#include <string.h>
#include "n4s.h"

float		xstrtofloat(const char *str, const unsigned int where)
{
  unsigned int	nb;
  size_t	len;
  float		is_float;

  nb = 0;
  len = -1;
  is_float = 0.0;
  while (nb < where)
    {
      if (str[++len] == ':')
	nb++;
    }
  while (str[++len] != '.' && str[len] >= '0' && str[len] <= '9')
    is_float = is_float * 10.0 - '0' + str[len];
  return (is_float);
}
