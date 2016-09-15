/*
** write_and_label.c for corewar in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sun Mar 27 15:22:00 2016 Iulian Rotaru
** Last update Sun Mar 27 15:54:01 2016 Iulian Rotaru
*/

#include <unistd.h>
#include "asm.h"

int	write_and_label(t_op_stock *tmp, t_op_stock *start, int fd)
{
  int	i;

  if (tmp->label == 1)
    {
      if (tmp->nb != 5)
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

int	write_and(t_op_stock *tmp, t_op_stock *start, int fd)
{
  int	i;
  char	lab;

  lab = 6;
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
  return (write_and_label(tmp, start, fd));
}

int	write_or_label(t_op_stock *tmp, t_op_stock *start, int fd)
{
  int	i;

  if (tmp->label == 1)
    {
      if (tmp->nb != 5)
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

int	write_or(t_op_stock *tmp, t_op_stock *start, int fd)
{
  int	i;
  char	lab;

  lab = 7;
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
  return (write_or_label(tmp, start, fd));
}

int	write_xor_label(t_op_stock *tmp, t_op_stock *start, int fd)
{
  int	i;

  if (tmp->label == 1)
    {
      if (tmp->nb != 5)
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
