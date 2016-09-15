/*
** storage.c for vm in /home/alif_m/tek1/CPE/CPE_2015_corewar
**
** Made by Alif Matthias
** Login   <alif_m@epitech.net>
**
** Started on  Mon Mar 21 18:35:25 2016 Alif Matthias
** Last update Sun Mar 27 18:57:43 2016 Alif Matthias
*/

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "vm.h"

void	store_in_mem(t_vm *vm, t_ch *ch)
{
  int	nb;
  int	i;
  t_ch	*tmp;

  tmp = ch;
  nb = 0;
  while (tmp->next)
    {
      i = 0;
      tmp->op = -1;
      tmp->pc = nb * (MEM_SIZE / (vm->nb_progs));
      tmp->r[1] = tmp->nb + 1;
      while ((read(tmp->fd,
		   &vm->mem[nb * (MEM_SIZE /
				  (vm->nb_progs)) + i++], 1)) == 1 &&
	     i < MEM_SIZE);
      close(tmp->fd);
      tmp = tmp->next;
      nb++;
      i++;
    }
}

int	read_files(char **av, t_vm *vm, t_ch *ch)
{
  int	i;
  t_ch	*tmp;

  vm->nb_progs = 0;
  i = 0;
  tmp = ch;
  while (av[vm->nb_progs + 1] &&
	 (vm->fd[vm->nb_progs] = open(av[vm->nb_progs + 1], O_RDONLY)))
    {
      i = 0;
      if ((read(vm->fd[vm->nb_progs], &tmp->head,
		sizeof(t_header))) != sizeof(t_header))
	return (-1);
      while (i < REG_NUMBER + 1)
	tmp->r[i++] = 0;
      tmp->r[1] = tmp->nb;
      if ((tmp->next = malloc(sizeof(t_ch))) == NULL)
	return (-1);
      tmp = tmp->next;
      close(vm->fd[vm->nb_progs++]);
    }
  if (vm->nb_progs == 0)
    return (-1);
  store_in_mem(vm, ch);
  return (0);
}
