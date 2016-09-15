/*
** write_lldi.c for corewar in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sun Mar 27 15:24:53 2016 Iulian Rotaru
** Last update Sun Mar 27 15:49:02 2016 Iulian Rotaru
*/

#include <unistd.h>
#include "asm.h"

int	write_lldi(t_op_stock *tmp, t_op_stock *start, int fd)
{
  int	i;
  char	lab;

  lab = 14;
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
  return (write_lldi_label(tmp, start, fd));
}

int	write_sti_label(t_op_stock *tmp, t_op_stock *start, int fd)
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

int	write_sti(t_op_stock *tmp, t_op_stock *start, int fd)
{
  int	i;
  char	lab;

  lab = 11;
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
  return (write_sti_label(tmp, start, fd));
}

int	write_aff_label(t_op_stock *tmp, t_op_stock *start, int fd)
{
  int	i;

  if (tmp->label == 1)
    {
      if (tmp->nb != 3)
	return (1);
      i = 2;
      while ((unsigned int)i < tmp->nb)
	{
	  if (write_param_nb(tmp, i - 1, start, fd) == 1)
	    return (1);
	  i++;
	}
    }
  return (0);
}

int	write_aff(t_op_stock *tmp, t_op_stock *start, int fd)
{
  int	i;
  char	lab;

  lab = 16;
  write(fd, &lab, sizeof(char));
  write(fd, &tmp->codage, sizeof(char));
  if (tmp->label == 0)
    {
      if (tmp->nb != 2)
	return (1);
      i = 1;
      while ((unsigned int)i < tmp->nb)
	{
	  if (write_param_nb(tmp, i, start, fd) == 1)
	    return (1);
	  i++;
	}
    }
  return (write_aff_label(tmp, start, fd));
}
