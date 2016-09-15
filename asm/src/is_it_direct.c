/*
** is_it_direct.c for corewar in /home/rotaru_i
**
** Made by Iulian Rotaru
** Login   <rotaru_i@epitech.net>
**
** Started on  Sun Mar 27 23:11:08 2016 Iulian Rotaru
** Last update Sun Mar 27 23:15:08 2016 Iulian Rotaru
*/

#include "asm.h"

int	classic_strlen(char *str)
{
  int	i;

  i = 0;
  while (*(str + i))
    i++;
  return (i);
}

int	is_it_direct_end(char *str)
{
  if (is_it_num(str + 1) == 1 && *(str + 1) != LABEL_CHAR)
    return (1);
  return (0);
}
