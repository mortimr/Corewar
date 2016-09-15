/*
** my_getnbr.c for my_getnbr in /home/alif_m/tests
**
** Made by Matthias alif
** Login   <alif_m@epitech.net>
**
** Started on  Thu Oct  1 20:52:01 2015 Matthias alif
** Last update Sun Mar 27 16:52:14 2016 Alif Matthias
*/

long	put_int(int sign, int start, int end, char *str)
{
  int	i;
  long	nb;

  nb = 0;
  if (end - start > 10)
    return (0);
  i = start;
  while (i <= end)
    {
      nb = nb + (str[i] - 48);
      nb = 10 * nb;
      i = i + 1;
    }
  return (sign * nb / 10);
}

int	signs(int start, char *str, int *sign)
{
  int	plus_minus;
  int	i;

  i = 0;
  plus_minus = 0;
  if (start == -1)
    return (0);
  while (i != start)
    {
      if (str[i] != '+' && str[i] != '-')
	plus_minus = 0;
      if (str[i] == '-')
	plus_minus = plus_minus + 1;
      i = i + 1;
    }
  if (plus_minus - (plus_minus / 2) != plus_minus / 2)
    *sign = (-1);
  return (0);
}

int	auto_detect(char *str, int *start, int *end)
{
  int	i;
  int	j;

  i = -1;
  j = 0;
  while (str[i++ + 1] != '\0')
    {
      if (str[i] > 47 && str[i] < 58)
	{
	  if (j == 0)
	    *start = i;
	  j = j + 1;
	  if ((str[i + 1]) < 48 || (str[i + 1] > 57))
	    {
	      *end = i;
	      return (0);
	    }
	}
      else if (str[i] != '-' && str[i] != '+')
	{
	  *start = -1;
	  return (-1);
	}
    }
  return (0);
}

int	scan(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if ((str[i] < 48 || str[i] > 57) && str[i] != '\n')
	return (-1);
      i++;
    }
  return (0);
}

int	my_getnbr(char *str)
{
  int	start;
  int	end;
  int	sign;
  long	nb;

  sign = 1;
  start = 0;
  end = 0;
  if (scan(str) == -1)
    return (-1);
  auto_detect(str, &start, &end);
  signs(start, str, &sign);
  if (start == -1)
    return (-1);
  nb = put_int(sign, start, end, str);
  if (nb > 2147483647 || nb < -2147483648 || start == -1)
    return (-1);
  return (nb);
}
