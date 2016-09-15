/*
** write_param_nb_spe_end.c for corewar in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sun Mar 27 15:18:30 2016 Iulian Rotaru
** Last update Sun Mar 27 23:37:41 2016 Iulian Rotaru
*/

#include <unistd.h>
#include "asm.h"

int	write_param_nb_spe_end(t_op_stock *tmp,
			       int param,
			       t_op_stock *start,
			       int fd)
{
  if (!(1 << (2 * (4 - param) + 1) & tmp->codage)
      && (1 << (2 * (4 - param)) & tmp->codage))
    if (write_reg(tmp, start, fd, param) == 1)
      return (1);
  return (0);
}

int	write_param_nb_spe(t_op_stock *tmp,
			   int param,
			   t_op_stock *start,
			   int fd)
{
  if ((1 << (2 * (4 - param) + 1) & tmp->codage)
      && !(1 << (2 * (4 - param)) & tmp->codage))
    if (write_direct_spe(tmp, start, fd, param) == 1)
      return (1);
  if ((1 << (2 * (4 - param) + 1) & tmp->codage)
      && (1 << (2 * (4 - param)) & tmp->codage))
    if (write_indi(tmp, start, fd, param) == 1)
      return (1);
  return (write_param_nb_spe_end(tmp, param, start, fd));
}

int	write_ld_label(t_op_stock *tmp, t_op_stock *start, int fd)
{
  int	i;

  if (tmp->label == 1)
    {
      if (tmp->nb != 4)
	return (1);
      i = 2;
      while ((unsigned int)i < tmp->nb)
	{
	  write_param_nb(tmp, i - 1, start, fd);
	  i++;
	}
    }
  return (0);
}

int	write_ld(t_op_stock *tmp, t_op_stock *start, int fd)
{
  int	i;
  char	lab;

  lab = 2;
  write(fd, &lab, sizeof(char));
  write(fd, &tmp->codage, sizeof(char));
  if (tmp->label == 0)
    {
      if (tmp->nb != 3)
	return (1);
      i = 1;
      while ((unsigned int)i < tmp->nb)
	{
	  write_param_nb(tmp, i, start, fd);
	  i++;
	}
    }
  return (write_ld_label(tmp, start, fd));
}

int	write_st_label(t_op_stock *tmp, t_op_stock *start, int fd)
{
  int	i;

  if (tmp->label == 1)
    {
      if (tmp->nb != 4)
	return (1);
      i = 2;
      while ((unsigned int)i < tmp->nb)
	{
	  write_param_nb(tmp, i - 1, start, fd);
	  i++;
	}
    }
  return (0);
}
