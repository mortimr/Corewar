/*
** parse.c for corewar in /home/alif_m/tek1/CPE/CPE_2015_corewar
**
** Made by Alif Matthias
** Login   <alif_m@epitech.net>
**
** Started on  Sun Mar 27 08:34:57 2016 Alif Matthias
** Last update Sun Mar 27 22:51:49 2016 Alif Matthias
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "vm.h"
#include "op.h"

int	my_strcmp(char *str, char *cmp)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] != cmp[i])
	return (0);
      i++;
    }
  if (!cmp[i])
    return (1);
  return (0);
}

int		check_magic(t_header *head)
{
  u_intochar	cnv;
  u_intochar	tmp;
  int		i;

  i = 0;
  cnv.in = COREWAR_EXEC_MAGIC;
  tmp.in = head->magic;
  while (i < 4)
    {
      tmp.out[i] = cnv.out[i];
      i++;
    }
  if (tmp.in == COREWAR_EXEC_MAGIC)
    return (1);
  return (0);
}

int	get_file(char *av, t_ch *ch)
{
  char	buff;

  if ((ch->fd = open(av, O_RDONLY)) < 0)
    return (-1);
  if ((read(ch->fd, &ch->head, sizeof(t_header))) != sizeof(t_header))
    return (-1);
  if ((read(ch->fd, &buff, 1)) != 1 || buff < 0 || buff > 16 ||
      (check_magic(&ch->head)) == 0)
    return (-1);
  else
    {
      close(ch->fd);
      if (((ch->fd = open(av, O_RDONLY)) < 0) ||
	  ((read(ch->fd, &ch->head, sizeof(t_header))) != sizeof(t_header)))
	return (-1);
    }
  return (0);
}

int	get_champ(t_vm *vm, char **av, int *y, t_ch *ch)
{
  int	nb;

  nb = vm->nb_progs + 1;
  if (!av[*y])
    return (0);
  if ((get_file(av[*y], ch)) == -1)
    return (-1);
  ch->nb = nb;
  return (0);
}

int	parse_args(char **av, t_vm *vm, t_ch *ch)
{
  int	y;
  t_ch	*tmp;

  y = 0;
  tmp = ch;
  while (av[++y])
    {
      if ((get_champ(vm, av, &y, tmp)) == -1)
	return (-1);
      else if ((tmp->next = malloc(sizeof(t_ch))) == NULL)
	return (-1);
      tmp = tmp->next;
      vm->nb_progs++;
    }
  store_in_mem(vm, ch);
  return (0);
}
