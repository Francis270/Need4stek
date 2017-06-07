/*
** n4s.h for n4s in /home/francis/Documents/CPE/CPE_2016_n4s/include/
**
** Made by Francois Caicedo
** Login   <caiced_f@epitech.eu>
**
** Started on  Mon May  1 16:29:38 2017 Francois Caicedo
** Last update Tue May 30 14:26:35 2017 Francois Caicedo
*/

#ifndef N4S_H_
# define N4S_H_

# include <stdbool.h>

typedef	struct		s_nfs
{
  char			*to_treat;
  bool			exit;
  float			front;
}			t_nfs;

# define BUFFER		(128)
# define TAB_SIZE	(7)

# define N4S_START	("START_SIMULATION\n")
# define N4S_STOP	("STOP_SIMULATION\n")
# define N4S_GETINFO	("GET_INFO_LIDAR\n")
# define N4S_FORWARD	("CAR_FORWARD:")
# define N4S_WHEELS	("WHEELS_DIR:")
# define N4S_TRACKCLEAR	("Track Cleared")

float		xstrtofloat(const char *, const unsigned int);
bool		need_go_back(const t_nfs *nfs);
bool		change_speed(const t_nfs *);
bool		change_dir(const t_nfs *);

#endif /* !N4S_H_ */
