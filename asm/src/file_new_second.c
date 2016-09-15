/*
** file_new_second.c for corewar in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sun Mar 27 15:29:50 2016 Iulian Rotaru
** Last update Sun Mar 27 17:02:37 2016 Iulian Rotaru
*/

#include <unistd.h>
#include "asm.h"

void	file_new_second(int *i, t_op_stock *start, char *end)
{
  if (*i != 0)
    {
      *(i + 1) = 0;
      while (*(end + *(i + 1)))
	{
	  *(start->file_new + *i + *(i + 1)) = *(end + *(i + 1));
	  *(i + 1) += 1;
	}
      *(start->file_new + *i + *(i + 1)) = 0;
    }
}

void	file_new_first(int *i, char *str, t_op_stock *start, char *end)
{
  *i = 0;
  while (*(str + *i))
    {
      *(start->file_new + *i) = *(str + *i);
      *i += 1;
    }
  *(str + *i) = 0;
  while (*i > 0 && *(start->file_new + *i) != '.')
    *i -= 1;
  if (*i == 0)
    {
      *i = my_strlen(start->file_new);
      *(i + 1) = 0;
      while (*(end + *(i + 1)))
	{
	  *(start->file_new + *i + *(i + 1)) = *(end + *(i + 1));
	  *(i + 1) += 1;
	}
      *(start->file_new + *i + *(i + 1)) = 0;
    }
  file_new_second(i, start, end);
}

int	file_new_end(int *i, t_op_stock *start)
{
  *i = 0;
  *(i + 1) = 0;
  if (is_it_far(start->file_new) == 1)
    {
      while (*(start->file_new + *i))
	{
	  if (*(start->file_new + *i) == '/' && *(start->file_new + *i + 1))
	    *(i + 1) = *i;
	  *i += 1;
	}
      *(i + 1) += 1;
      *i = 0;
      while (*(start->file_new + *(i + 1) + *i))
	{
	  *(start->file_new + *i) = *(start->file_new + *i + *(i + 1));
	  *i += 1;
	}
      *(start->file_new + *i) = 0;
    }
  return (0);
}

int	handle_endian(t_header *stamp, u_intochar *conv)
{
  conv[0].in = stamp->magic;
  conv[1].out[0] = conv[0].out[3];
  conv[1].out[1] = conv[0].out[2];
  conv[1].out[2] = conv[0].out[1];
  conv[1].out[3] = conv[0].out[0];
  stamp->magic = conv[1].in;
  conv[0].in = stamp->prog_size;
  conv[1].out[0] = conv[0].out[3];
  conv[1].out[1] = conv[0].out[2];
  conv[1].out[2] = conv[0].out[1];
  conv[1].out[3] = conv[0].out[0];
  stamp->prog_size = conv[1].in;
  return (0);
}

int	end_it(t_op_stock *start, t_header *stamp, int *new)
{
  write(*new, stamp, sizeof(t_header));
  if (write_code(start, *new) == 1)
    return (1);
  return (0);
}
