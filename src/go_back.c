/*
** go_back.c for n4S in /home/francis/Documents/TEK1/CPE/CPE_2016_n4s/src/
**
** Made by Francois Caicedo
** Login   <francois.caicedo@epitech.eu@epitech.eu>
**
** Started on  Tue May 30 11:23:14 2017 Francois Caicedo
** Last update Sun Jun  4 22:26:45 2017 Francis
*/

#include <unistd.h>
#include <string.h>
#include "n4s.h"
#include "lib.h"

bool		need_go_back(const t_nfs *nfs)
{
  char		*cut;

  cut = NULL;
  if (xstrtofloat(nfs->to_treat, 34) > 8 &&
      xstrtofloat(nfs->to_treat, 18) > 8 &&
      xstrtofloat(nfs->to_treat, 3) > 8)
    return (true);
  if (write(1, N4S_WHEELS, strlen(N4S_WHEELS)) == -1)
    return (false);
  if (xstrtofloat(nfs->to_treat, 3) -
      xstrtofloat(nfs->to_treat, 34) > 0.0 &&
      (write(1, "-", 1) == -1))
    return (false);
  if (write(1, "0.3\n", 4) == -1 || (cut = get_next_line(0, 0)) == NULL ||
      xfree(cut) != 1 || write(1, "CAR_BACKWARDS:0.4\n", 18) == -1 ||
      (cut = get_next_line(0, 0)) == NULL || xfree(cut) != 1)
    return (false);
  sleep(2);
  return (true);
}
