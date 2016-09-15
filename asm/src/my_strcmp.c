/*
** my_strcmp.c for corewar in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sat Mar 26 13:58:50 2016 Iulian Rotaru
** Last update Tue May 10 17:00:29 2016 Alif Matthias
*/

#include "asm.h"

int	my_strcmp(char *one, char *two)
{
  int	i;

  if (my_strlen(one) == 0 || my_strlen(two) == 0)
    return (1);
  i = 0;
  while (*(one + i) == *(two + i) && *(one + i) && *(two + ++i));
  if (*(one + i) == 0 && *(two + i) == 0)
    return (0);
  return (1);
}

int	power(int nb, int pow)
{
  int	i;
  int	tmp;

  i = 1;
  if (pow == 0)
    return (1);
  tmp = nb;
  while (i < pow)
    {
      tmp *= nb;
      i++;
    }
  return (tmp);
}

int	ret_index(char c, char *str)
{
  int	i;

  i = 0;
  while (*(str + i))
    {
      if (c == *(str + i))
	return (i);
      i++;
    }
  return (0);
}

int	my_gethexa(char *nb)
{
  int	i;
  char	*hexa;
  int	out;
  int	multi;

  if (my_strlen(nb) <= 2)
    return (-1);
  out = 0;
  multi = 1;
  hexa = "0123456789ABCDEF";
  i = my_strlen(nb) - 1;
  while (i > 1)
    {
      out += ret_index(*(nb + i), hexa) * multi;
      multi *= 16;
      i--;
    }
  return (out);
}

int	my_getnbr(char *nb)
{
  int	i;
  int	out;
  int	sign;
  int	multi;

  i = 0;
  sign = 0;
  if (*nb == '0' && *(nb + 1) == 'x')
    return (my_gethexa(nb));
  if (*nb == '-')
    {
      sign = 1;
      i = 1;
    }
  out = 0;
  multi = power(10, my_strlen(nb + i) - 1);
  while (*(nb + i))
    {
      out += multi * (*(nb + i) - 48);
      multi = multi / 10;
      i++;
    }
  return (sign == 1 ? - out : out);
}
