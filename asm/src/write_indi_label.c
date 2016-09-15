/*
** write_indi_label.c for corewar in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sun Mar 27 15:16:39 2016 Iulian Rotaru
** Last update Sun Mar 27 17:59:58 2016 Iulian Rotaru
*/

#include <unistd.h>
#include "asm.h"

void	write_indi_label(t_op_stock *tmp,
			 t_op_stock *start,
			 int param,
			 u_shortochar *hey)
{
  if (tmp->label == 1)
    {
      if (tmp->command[param + 1][0] == LABEL_CHAR)
	hey->in =
	  check_if_dir_label(tmp->command[param + 1] + 1, start, tmp->idx);
      else if (is_it_num(tmp->command[param + 1]) == 0)
	hey->in =
	  my_getnbr(tmp->command[param + 1]);
    }
}

int		write_indi(t_op_stock *tmp,
			   t_op_stock *start,
			   int fd,
			   int param)
{
  u_shortochar	hey;

  if (tmp->label == 0)
    {
      if (tmp->command[param][0] == LABEL_CHAR)
	hey.in =
	  check_if_dir_label(tmp->command[param] + 1, start, tmp->idx);
      else if (is_it_num(tmp->command[param]) == 0)
	hey.in =
	  my_getnbr(tmp->command[param]);
    }
  write_indi_label(tmp, start, param, &hey);
  write(fd, &hey.out[1], sizeof(char));
  write(fd, &hey.out[0], sizeof(char));
  return (0);
}

int	write_reg(t_op_stock *tmp, t_op_stock *start, int fd, int param)
{
  char	hey;

  (void)start;
  if (tmp->label == 1)
    {
      if (tmp->command[param + 1][0] == 'r'
	  && my_strlen(tmp->command[param + 1]) > 1)
	hey = my_getnbr(tmp->command[param + 1] + 1);
    }
  else if (tmp->label == 0)
    {
      if (tmp->command[param][0] == 'r' && my_strlen(tmp->command[param]) > 1)
	hey = my_getnbr(tmp->command[param] + 1);
    }
  write(fd, &hey, sizeof(char));
  return (0);
}

int	write_param_nb_end(t_op_stock *tmp, int param, t_op_stock *start, int fd)
{
  if (!(1 << (2 * (4 - param) + 1) & tmp->codage)
      && (1 << (2 * (4 - param)) & tmp->codage))
    if (write_reg(tmp, start, fd, param) == 1)
      return (1);
  return (0);
}

int	write_param_nb(t_op_stock *tmp, int param, t_op_stock *start, int fd)
{
  if ((1 << (2 * (4 - param) + 1) & tmp->codage)
      && !(1 << (2 * (4 - param)) & tmp->codage))
    if (write_direct(tmp, start, fd, param) == 1)
      return (1);
  if ((1 << (2 * (4 - param) + 1) & tmp->codage)
      && (1 << (2 * (4 - param)) & tmp->codage))
    if (write_indi(tmp, start, fd, param) == 1)
      return (1);
  return (write_param_nb_end(tmp, param, start, fd));
}
