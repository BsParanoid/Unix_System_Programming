/*
** check_binary.c for  in /home/duttoo_e/tech2/starter_strace/etape2/save_main/Projet_started
** 
** Made by Duttoo Ervin
** Login   <duttoo_e@epitech.net>
** 
** Started on  Fri Apr  8 12:10:32 2016 Duttoo Ervin
** Last update Sun Apr 10 18:43:58 2016 Duttoo Ervin
*/

#include "strace.h"

int     check_header(Elf64_Ehdr *data)
{
  if (data->e_ident[EI_MAG0] != ELFMAG0 ||
      data->e_ident[EI_MAG1] != ELFMAG1 ||
      data->e_ident[EI_MAG2] != ELFMAG2 ||
      data->e_ident[EI_MAG3] != ELFMAG3)
    return (-1);

  if (data->e_ident[EI_CLASS] != ELFCLASS64)
    return (-1);

  return (0);
}

void             check_file(char **av, t_elf *ptr)
{
  struct stat   file_infos;

  ptr->str = av[1];
  if ((ptr->fd = open(ptr->str, O_RDONLY)) > 0)
    {
      if (fstat(ptr->fd, &file_infos))
        fprintf(stderr, "Error\n");
      else if ((ptr->data = mmap(0, file_infos.st_size, PROT_READ,
                                 MAP_SHARED, ptr->fd, 0)) == MAP_FAILED)
        fprintf(stderr, "This file \"%s\"is empty\n", ptr->str);
      else
        {
          if (!check_header((Elf64_Ehdr*)ptr->data))
            {
	      printf("e");
	      fork_it(av);
	    }
          else
            fprintf(stderr, STRACE_ERROR, ptr->str);
          munmap(ptr->data, file_infos.st_size);
        }
      close(ptr->fd);
    }
  else
    fprintf(stderr, STRACE_ERROR, ptr->str);
}

int             check_args(int ac, char **av)
{
  t_elf         point;
  int           i;

  i = 1;
  while (i < ac)
    {
      check_file(av, &point);
      i++;
    }
  return (0);
}
