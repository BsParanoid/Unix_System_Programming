/*
** check_options.c for  in /home/duttoo_e/tech2/starter_strace/etape2/save_main/Projet_started
** 
** Made by Duttoo Ervin
** Login   <duttoo_e@epitech.net>
** 
** Started on  Wed Apr  6 19:42:41 2016 Duttoo Ervin
** Last update Sat Apr  9 23:18:56 2016 Duttoo Ervin
*/

#include "strace.h"

t_inc	ptr;

int      option_p(int ac, char **av, t_inc *ptr)
{
  ptr->i = 1;
  ptr->j = 0;
  while (ptr->i != ac)
    {
      if (strcmp(av[ptr->i], "-p") == 0)
        {
          ptr->j = 2;
          while (ptr->j != ac)
            {
	      if (check_pid(av[ptr->j]) == 1)
		{
		  printf("ok OPTION PPPPPPPPP\n");
		  fork_it(av);
		  return (-1);
		}
	      else
		fprintf(stderr, "PID error : No such process\n");
	      ptr->j++;
            }
        }
      ptr->i++;
    }
  return (-1);
}

int      option_s(int ac, char **av, t_inc *ptr)
{
  ptr->i = 1;
  ptr->j = 0;
  while (ptr->i != ac)
    {
      if (strcmp(av[ptr->i], "-s") == 0)
        {
          ptr->j = 1;
          while (ptr->j != ac)
            {
              printf("ok OPTION SSSSSSSSSS\n");
	      fork_it(av);
              return (-1);
            }
          ptr->j++;
        }
      ptr->i++;
    }
  return (-1);
}
