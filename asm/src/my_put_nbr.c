/*
** my_put_nbr.c for corewar in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sat Mar 26 13:55:05 2016 Iulian Rotaru
** Last update Sun Mar 27 23:34:20 2016 Iulian Rotaru
*/

#include <unistd.h>
#include "asm.h"

void	my_put_nbr(int nb, int fd)
{
  char	tmp;

  if (nb < 0)
    {
      nb = -nb;
      write(fd, "-", 1);
    }
  if (nb >= 10)
    my_put_nbr(nb / 10, fd);
  tmp = (nb % 10) + 48;
  write(fd, &tmp, 1);
}

int	reterrline(char *msg, int line, int ret)
{
  write(2, msg, my_strlen(msg));
  my_put_nbr(line, 2);
  write(2, "\n", 1);
  return (ret);
}

int	cache_cache(char *find, char *foret)
{
  int	i;
  int	j;

  i = 0;
  if (find == NULL || foret == NULL)
    return (1);
  while (*(foret + i))
    {
      j = 0;
      if (*(foret + i) == *(find + j))
	{
	  while (*(foret + j + i) == *(find + j)
		 && *(foret + j + i) && *(find + j))
	    j++;
	  if (*(find + j) == 0)
	    return (0);
	}
      i++;
    }
  return (1);
}

void	my_putstr_guill(char *str)
{
  int	i;

  if (*str != 34 || !*(str + 1))
    return;
  i = 1;
  while (*(str + i) != 34 && *(str + i))
    {
      write(1, str + i, 1);
      i++;
    }
}

void	empty_stamp(t_header *stamp)
{
  int	i;

  i = 0;
  while (i < PROG_NAME_LENGTH + 1)
    {
      *(stamp->prog_name + i) = 0;
      i++;
    }
  i = 0;
  while (i < COMMENT_LENGTH + 1)
    {
      *(stamp->comment + i) = 0;
      i++;
    }
}
