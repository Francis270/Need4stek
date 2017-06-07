/*
** main.c for n4s in /home/francis/Documents/CPE/CPE_2016_n4s/src/
**
** Made by Francois Caicedo
** Login   <francois.caicedo@epitech.eu@epitech.eu>
**
** Started on  Wed May  3 14:01:48 2017 Francois Caicedo
** Last update Tue May 30 14:26:30 2017 Francois Caicedo
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "n4s.h"
#include "lib.h"

static bool	track_is_cleared(t_nfs *nfs)
{
  char		*add_infos;
  size_t	len;
  size_t	len2;

  add_infos = NULL;
  len = strlen(nfs->to_treat);
  len2 = -1;
  if ((add_infos = calloc(strlen(nfs->to_treat) + 1, sizeof(char))) == NULL)
    return (false);
  while (nfs->to_treat[--len] != ':');
  while (nfs->to_treat[--len] != ':');
  while (nfs->to_treat[++len] != ':')
    add_infos[++len2] = nfs->to_treat[len];
  add_infos[++len2] = nfs->to_treat[len];
  add_infos[len2] = 0;
  if (strcmp(N4S_TRACKCLEAR, add_infos) == 0)
    nfs->exit = true;
  xfree(add_infos);
  return (true);
}

static bool	need_for_speed(t_nfs *nfs, char *cut)
{
  if (write(1, N4S_START, strlen(N4S_START)) == -1 ||
      (cut = get_next_line(0, 0)) == NULL || xfree(cut) != 1)
    return (false);
  while (nfs->exit == false)
    {
      if (write(1, N4S_GETINFO, strlen(N4S_GETINFO)) == -1 ||
	  (nfs->to_treat = get_next_line(0, 0)) == NULL ||
	  track_is_cleared(nfs) == false)
	return (false);
      if (nfs->exit == true)
	break;
      nfs->front = xstrtofloat(nfs->to_treat, 18);
      if (need_go_back(nfs) == false || change_speed(nfs) == false ||
	  (cut = get_next_line(0, 0)) == NULL || xfree(cut) != 1 ||
	  change_dir(nfs) == false || (cut = get_next_line(0, 0)) == NULL ||
	  xfree(cut) != 1)
	return (false);
      xfree(nfs->to_treat);
    }
  if (write(1, N4S_STOP, strlen(N4S_STOP)) == -1)
    return (false);
  return (true);
}

int		main()
{
  t_nfs		nfs;

  memset(&nfs, 0, sizeof(nfs));
  if (need_for_speed(&nfs, NULL) == false)
    return (84);
  return (0);
}
