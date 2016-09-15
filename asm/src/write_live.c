/*
** write_live.c for corewar in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sun Mar 27 15:14:52 2016 Iulian Rotaru
** Last update Sun Mar 27 18:01:23 2016 Iulian Rotaru
*/

#include <unistd.h>
#include "asm.h"

int	write_live(t_op_stock *tmp, t_op_stock *start, int fd)
{
  char	one;
  int	param;

  one = tmp->opcode + 1;
  if (write(fd, &one, sizeof(char)) < 0)
    return (1);
  if (tmp->label == 0)
    {
      if (is_it_num(tmp->command[1] + 1) == 0)
	param = my_getnbr(tmp->command[1] + 1);
      else
	param = check_if_dir_label(tmp->command[1] + 2, start, tmp->idx);
      if (param == -1)
	return (1);
    }
  return (write_live_label(tmp, fd, start, &param));
}

void	write_direct_label(t_op_stock *tmp,
			   t_op_stock *start,
			   u_intochar *hey,
			   int param)
{
  if (tmp->label == 1)
    {
      if (tmp->command[param + 1][0] == DIRECT_CHAR
	  && tmp->command[param + 1][1] == LABEL_CHAR)
	hey->in =
	  check_if_dir_label(tmp->command[param + 1] + 2, start, tmp->idx);
      else if (tmp->command[param + 1][0] == DIRECT_CHAR
	       && is_it_num(tmp->command[param + 1] + 1) == 0)
	hey->in =
	  my_getnbr(tmp->command[param + 1] + 1);
    }
}

int		write_direct(t_op_stock *tmp,
			     t_op_stock *start,
			     int fd,
			     int param)
{
  u_intochar	hey;

  if (tmp->label == 0)
    {
      if (tmp->command[param][0] == DIRECT_CHAR
	  && tmp->command[param][1] == LABEL_CHAR)
	hey.in =
	  check_if_dir_label(tmp->command[param] + 2, start, tmp->idx);
      else if (tmp->command[param][0] == DIRECT_CHAR
	       && is_it_num(tmp->command[param] + 1) == 0)
	hey.in =
	  my_getnbr(tmp->command[param] + 1);
    }
  write_direct_label(tmp, start, &hey, param);
  write(fd, &hey.out[3], sizeof(char));
  write(fd, &hey.out[2], sizeof(char));
  write(fd, &hey.out[1], sizeof(char));
  write(fd, &hey.out[0], sizeof(char));
  return (0);
}

void	write_direct_spe_label(t_op_stock *tmp,
			       t_op_stock *start,
			       u_shortochar *hey,
			       int param)
{
  if (tmp->label == 1)
    {
      if (tmp->command[param + 1][0] == DIRECT_CHAR
	  && tmp->command[param + 1][1] == LABEL_CHAR)
	hey->in =
	  check_if_dir_label(tmp->command[param + 1] + 2, start, tmp->idx);
      else if (tmp->command[param + 1][0] == DIRECT_CHAR
	       && is_it_num(tmp->command[param + 1] + 1) == 0)
	hey->in =
	  my_getnbr(tmp->command[param + 1] + 1);
    }
}

int		write_direct_spe(t_op_stock *tmp,
				 t_op_stock *start,
				 int fd,
				 int param)
{
  u_shortochar	hey;

  if (tmp->label == 0)
    {
      if (tmp->command[param][0] == DIRECT_CHAR
	  && tmp->command[param][1] == LABEL_CHAR)
	hey.in =
	  check_if_dir_label(tmp->command[param] + 2, start, tmp->idx);
      else if (tmp->command[param][0] == DIRECT_CHAR
	       && is_it_num(tmp->command[param] + 1) == 0)
	hey.in =
	  my_getnbr(tmp->command[param] + 1);
    }
  write_direct_spe_label(tmp, start, &hey, param);
  write(fd, &hey.out[1], sizeof(char));
  write(fd, &hey.out[0], sizeof(char));
  return (0);
}
