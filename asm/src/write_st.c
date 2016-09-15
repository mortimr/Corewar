/*
** write_st.c for corewar in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sun Mar 27 15:20:31 2016 Iulian Rotaru
** Last update Sun Mar 27 15:55:31 2016 Iulian Rotaru
*/

#include <unistd.h>
#include "asm.h"

int	write_st(t_op_stock *tmp, t_op_stock *start, int fd)
{
  int	i;
  char	lab;

  lab = 3;
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
  return (write_st_label(tmp, start, fd));
}

int	write_add_label(t_op_stock *tmp, t_op_stock *start, int fd)
{
  int	i;

  if (tmp->label == 1)
    {
      if (tmp->nb != 5)
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

int	write_add(t_op_stock *tmp, t_op_stock *start, int fd)
{
  int	i;
  char	lab;

  lab = 4;
  write(fd, &lab, sizeof(char));
  write(fd, &tmp->codage, sizeof(char));
  if (tmp->label == 0)
    {
      if (tmp->nb != 4)
	return (1);
      i = 1;
      while ((unsigned int)i < tmp->nb)
	{
	  write_param_nb(tmp, i, start, fd);
	  i++;
	}
    }
  return (write_add_label(tmp, start, fd));
}

int	write_sub_label(t_op_stock *tmp, t_op_stock *start, int fd)
{
  int	i;

  if (tmp->label == 1)
    {
      if (tmp->nb != 5)
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

int	write_sub(t_op_stock *tmp, t_op_stock *start, int fd)
{
  int	i;
  char	lab;

  lab = 5;
  write(fd, &lab, sizeof(char));
  write(fd, &tmp->codage, sizeof(char));
  if (tmp->label == 0)
    {
      if (tmp->nb != 4)
	return (1);
      i = 1;
      while ((unsigned int)i < tmp->nb)
	{
	  write_param_nb(tmp, i, start, fd);
	  i++;
	}
    }
  return (write_sub_label(tmp, start, fd));
}
