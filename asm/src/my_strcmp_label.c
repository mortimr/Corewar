/*
** my_strcmp_label.c for corewar in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sun Mar 27 15:12:33 2016 Iulian Rotaru
** Last update Sun Mar 27 17:54:18 2016 Iulian Rotaru
*/

#include <unistd.h>
#include "asm.h"

int	my_strcmp_label(char *one, char *two)
{
  int	i;

  i = 0;
  while (*(one + i) && *(two + i))
    {
      if (*(one + i) != *(two + i))
	return (1);
      i++;
    }
  if (*(two + i) == LABEL_CHAR && *(one + i) == 0)
    return (0);
  return (1);
}

int		check_if_dir_label(char *str, t_op_stock *start, int idx)
{
  t_op_stock	*tmp;
  int		label[3];
  int		turn;

  if (my_strlen(str) == 0)
    return (-1);
  tmp = start;
  turn = 0;
  while (tmp->next)
    {
      if ((tmp->label == 1)
	  && (my_strcmp_label(str, tmp->command[0])) == 0)
	{
	  *label = idx;
	  *(label + 1) = tmp->idx;
	  *(label + 2) = *(label + 1) - *label;
	  turn++;
	}
      tmp = tmp->next;
    }
  if (turn > 1 || turn == 0)
    return (0);
  return (*(label + 2));
}

int		write_short(short in, int fd)
{
  u_shortochar	hey;

  hey.in = in;
  write(fd, &hey.out[1], 1);
  write(fd, &hey.out[0], 1);
  return (0);
}

int		write_int(int in, int fd)
{
  u_intochar	hey;

  hey.in = in;
  write(fd, &hey.out[3], 1);
  write(fd, &hey.out[2], 1);
  write(fd, &hey.out[1], 1);
  write(fd, &hey.out[0], 1);
  return (0);
}

int	write_live_label(t_op_stock *tmp,
			 int fd,
			 t_op_stock *start,
			 int *param)
{
  if (tmp->label == 1)
    {
      if (is_it_num(tmp->command[2] + 1) == 0)
	*param = my_getnbr(tmp->command[2] + 1);
      else
	*param = check_if_dir_label(tmp->command[2] + 2, start, tmp->idx);
      if (*param == -1)
	return (1);
    }
  if (write_int(*param, fd) == 1)
    return (1);
  return (0);
}
