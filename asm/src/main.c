/*
** main.c for asm in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Wed Mar 16 18:20:46 2016 Iulian Rotaru
** Last update Sun Mar 27 21:54:51 2016 Alif Matthias
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "asm.h"

void	mset(void *data, unsigned long int size)
{
  char	*str;
  int	i;

  i = 0;
  if (!(str = data))
    return ;
  while ((unsigned int)i < size)
    {
      *(str + i) = 0;
      i++;
    }
}

int		compile_it(char *str)
{
  int		fd;
  char		*end;
  int		i[2];
  int		new;
  u_intochar	conv[2];
  t_op_stock	start;
  t_header	stamp;

  mset(&stamp, sizeof(t_header));
  if ((fd = open(str, O_RDWR)) < 0)
    return (reterr("Error: Can't open file ", str, 1));
  if (preliminary_tests(&fd, &start, str, &stamp) == 1)
    return (1);
  empty_file_new(&start);
  end = ".cor";
  file_new_first(i, str, &start, end);
  file_new_end(i, &start);
  close(fd);
  if ((new = open(start.file_new, O_RDWR | O_CREAT,
		  S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) < 0)
    return (-1);
  fill_headsize(&start, &stamp);
  handle_endian(&stamp, conv);
  return (end_it(&start, &stamp, &new));
}

int	main(int argc, char **argv)
{
  int	i;

  if (argc < 2)
    {
      write(2, "Usage: ./asm file_name[.s] ...\n", 31);
      return (1);
    }
  i = 1;
  while (*(argv + i))
    {
      compile_it(*(argv + i));
      i++;
    }
  return (0);
}
