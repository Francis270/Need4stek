/*
** speed.c for n4s in /home/francis/Documents/TEK1/CPE/CPE_2016_n4s/src/
**
** Made by Francois Caicedo
** Login   <francois.caicedo@epitech.eu@epitech.eu>
**
** Started on  Mon May 22 17:56:09 2017 Francois Caicedo
** Last update Thu Jun  1 16:27:19 2017 Francois Caicedo
*/

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "n4s.h"
#include "lib.h"

static float	get_speed(const float angle)
{
  float 	speed[TAB_SIZE];
  float		front[TAB_SIZE];
  int		i;

  i = -1;
  front[++i] = 2000;
  speed[i] = 1.0;
  front[++i] = 1700;
  speed[i] = 0.9;
  front[++i] = 1500;
  speed[i] = 0.8;
  front[++i] = 1300;
  speed[i] = 0.7;
  front[++i] = 1000;
  speed[i] = 0.6;
  front[++i] = 600;
  speed[i] = 0.5;
  front[++i] = 400;
  speed[i] = 0.4;
  i = -1;
  while (angle < front[++i] && i != TAB_SIZE);
  return (speed[i]);
}

bool		change_speed(const t_nfs *nfs)
{
  char		command_buffer[BUFFER];
  float		speed;

  speed = 0.0;
  speed = get_speed(nfs->front);
  if (nfs->front > 2000)
    speed = 1.0;
  else if (nfs->front < 400)
    speed = 0.1;
  sprintf(command_buffer, "%s%f\n", N4S_FORWARD, speed);
  if (write(1, (char *)command_buffer, strlen((char *)command_buffer)) == -1)
    return (false);
  return (true);
}
