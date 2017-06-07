/*
** direction.c for n4s in /home/francis/Documents/TEK1/CPE/CPE_2016_n4s/src/
**
** Made by Francois Caicedo
** Login   <francois.caicedo@epitech.eu@epitech.eu>
**
** Started on  Mon May 22 18:58:41 2017 Francois Caicedo
** Last update Thu Jun  1 16:42:08 2017 Francois Caicedo
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "n4s.h"
#include "lib.h"

static float	get_dir(const float angle)
{
  float 	dir[TAB_SIZE];
  float		front[TAB_SIZE];
  int		i;

  i = -1;
  front[++i] = 1500;
  dir[i] = 0.005;
  front[++i] = 1300;
  dir[i] = 0.01;
  front[++i] = 1000;
  dir[i] = 0.05;
  front[++i] = 800;
  dir[i] = 0.075;
  front[++i] = 600;
  dir[i] = 0.1;
  front[++i] = 400;
  dir[i] = 0.2;
  front[++i] = 200;
  dir[i] = 0.3;
  i = -1;
  while (angle < front[++i] && i != TAB_SIZE);
  return (dir[i]);
}

bool		change_dir(const t_nfs *nfs)
{
  char          command_buffer[BUFFER];
  float         dir;
  float         sign;

  sign = 1.0;
  dir = 0.0;
  if (xstrtofloat(nfs->to_treat, 3) - xstrtofloat(nfs->to_treat, 34) < 0.0)
    sign = -1.0;
  dir = get_dir(nfs->front);
  if (nfs->front > 1500)
    dir = 0.005;
  else if (nfs->front < 200)
    dir = 0.4;
  dir *= sign;
  sprintf(command_buffer, "%s%f\n", N4S_WHEELS, dir);
  if (write(1, (char *)command_buffer, strlen((char *)command_buffer)) == -1)
    return (false);
  return (true);
}
