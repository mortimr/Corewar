/*
** is_it_indi_warn.c for corewar in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sat Mar 26 14:05:12 2016 Iulian Rotaru
** Last update Sun Mar 27 23:33:41 2016 Iulian Rotaru
*/

#include "asm.h"

int	is_it_indi_warn(char *str)
{
  int	i;

  if ((my_strlen(str) > 1)
      && (*(str) == LABEL_CHAR))
    {
      i = 0;
      while (*(str + 1 + i))
	{
	  if (is_it_in(*(str + 1 + i), LABEL_CHARS) == 1)
	    return (1);
	  i++;
	}
      return (0);
    }
  else if (is_it_num(str) == 1)
    return (1);
  if (my_getnbr(str) > IDX_MOD)
    {
      my_putstr("Warning Indirection to far : ");
      my_putstr(str);
      my_putstr("\n");
    }
  return (0);
}

int	is_it_indi(char *str)
{
  int	i;

  if ((my_strlen(str) > 1)
      && (*str == LABEL_CHAR))
    {
      i = 0;
      while (*(str + 1 + i))
	{
	  if (is_it_in(*(str + 1 + i), LABEL_CHARS) == 1)
	    return (1);
	  i++;
	}
      return (0);
    }
  else if (is_it_num(str) == 1)
    {
      return (1);
    }
  return (0);
}

int	is_it_reg(char *str)
{
  if (my_strlen(str) < 2)
    return (1);
  if (*str != 'r')
    return (1);
  if ((my_getnbr(str + 1) < 0)
      || (my_getnbr(str + 1) > REG_NUMBER))
    return (1);
  return (0);
}

int	is_it_direct(char *str)
{
  int	i;

  if (my_strlen(str) < 2)
    return (1);
  if (*str != DIRECT_CHAR)
    return (1);
  if (*(str + 1) == LABEL_CHAR)
    {
      if (!*(str + 2))
	return (1);
      i = 2;
      while (*(str + i))
	{
	  if (is_it_in(*(str + i), LABEL_CHARS) == 1)
	    return (1);
	  i++;
	}
    }
  return (is_it_direct_end(str));
}

int	is_it_num_deci(char *str)
{
  int	i;

  i = 0;
  while (*(str + i))
    {
      if ((i == 0) &&
	  (*(str + i) < '0' || *(str + i) > '9') &&
	  (*(str + i) != '-'))
	return (1);
      if ((i != 0) &&
	  (*(str + i) < '0' || *(str + i) > '9'))
	return (1);
      i++;
    }
  return (0);
}
