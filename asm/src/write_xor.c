/*
** write_xor.c for corewar in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sun Mar 27 15:23:24 2016 Iulian Rotaru
** Last update Sun Mar 27 18:02:58 2016 Iulian Rotaru
*/

#include <unistd.h>
#include "asm.h"

int	write_xor(t_op_stock *tmp, t_op_stock *start, int fd)
{
  int	i;
  char	lab;

  lab = 8;
  write(fd, &lab, sizeof(char));
  write(fd, &tmp->codage, sizeof(char));
  if (tmp->label == 0)
    {
      if (tmp->nb != 4)
	return (1);
      i = 1;
      while ((unsigned int)i < tmp->nb)
	{
	  if (write_param_nb(tmp, i, start, fd) == 1)
	    return (1);
	  i++;
	}
    }
  return (write_xor_label(tmp, start, fd));
}

int	write_zjmp(t_op_stock *tmp, t_op_stock *start, int fd)
{
  char	lab;
  int	param_idx;
  int	out;

  lab = 9;
  write(fd, &lab, sizeof(char));
  if (tmp->label == 1)
    param_idx = 2;
  else
    param_idx = 1;
  if ((tmp->command[param_idx][0] == DIRECT_CHAR
       && tmp->command[param_idx][1] == LABEL_CHAR)
      && (my_strlen(tmp->command[param_idx]) > 2))
    {
      if ((out = check_if_dir_label
	   (tmp->command[param_idx] + 2, start, tmp->idx)) == 0)
	return (1);
    }
  else if ((tmp->command[param_idx][0] == DIRECT_CHAR)
	   && (is_it_num(tmp->command[param_idx] + 1) == 0))
    out = my_getnbr(tmp->command[param_idx] + 1);
  write_short(out, fd);
  return (0);
}

int	write_ldi_label(t_op_stock *tmp, t_op_stock *start, int fd)
{
  int	i;

  if (tmp->label == 1)
    {
      if (tmp->nb != 5)
	return (1);
      i = 2;
      while ((unsigned int)i < tmp->nb)
	{
	  if (write_param_nb_spe(tmp, i - 1, start, fd) == 1)
	    return (1);
	  i++;
	}
    }
  return (0);
}

int	write_ldi(t_op_stock *tmp, t_op_stock *start, int fd)
{
  int	i;
  char	lab;

  lab = 10;
  write(fd, &lab, sizeof(char));
  write(fd, &tmp->codage, sizeof(char));
  if (tmp->label == 0)
    {
      if (tmp->nb != 4)
	return (1);
      i = 1;
      while ((unsigned int)i < tmp->nb)
	{
	  if (write_param_nb_spe(tmp, i, start, fd) == 1)
	    return (1);
	  i++;
	}
    }
  return (write_ldi_label(tmp, start, fd));
}

int	write_lldi_label(t_op_stock *tmp, t_op_stock *start, int fd)
{
  int	i;

  if (tmp->label == 1)
    {
      if (tmp->nb != 5)
	return (1);
      i = 2;
      while ((unsigned int)i < tmp->nb)
	{
	  if (write_param_nb_spe(tmp, i - 1, start, fd) == 1)
	    return (1);
	  i++;
	}
    }
  return (0);
}
