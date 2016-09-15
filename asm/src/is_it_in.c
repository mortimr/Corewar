/*
** is_it_in.c for corewar in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sat Mar 26 13:52:39 2016 Iulian Rotaru
** Last update Sun Mar 27 23:07:29 2016 Iulian Rotaru
*/

#include <unistd.h>
#include "asm.h"

int	is_it_in(char find, char *str)
{
  int	i;

  i = 0;
  while (*(str + i))
    {
      if (*(str + i) == find)
	return (0);
      i++;
    }
  return (1);
}

char	*my_strdup(char *str)
{
  char	*dest;
  int	i;

  if (str == NULL || my_strlen(str) == 0)
    return (NULL);
  if ((dest = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  i = 0;
  while ((*(dest + i) = *(str + i)) && *(str + ++i));
  *(dest + i) = 0;
  return (dest);
}

char	*get_term_line(int fd)
{
  char	s[1024];
  char	*out;
  char	buffer;
  int	i;

  buffer = - 1;
  i = 0;
  *s = 0;
  while (buffer != '\n' && buffer && read(fd, &buffer, 1) > 0)
    {
      if (i < 1000 && buffer != '\n' && buffer)
	*(s + i) = buffer;
      i++;
    }
  *(s + i - 1) = 0;
  if (i == 0)
    return (NULL);
  if ((out = my_strdup(s)) == NULL)
    return (NULL);
  return (out);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (*(str + ++i));
  return (i);
}

int	reterr(char *msg, char *file, int ret)
{
  write(2, msg, my_strlen(msg));
  write(2, file, my_strlen(file));
  write(2, "\n", 1);
  return (ret);
}
