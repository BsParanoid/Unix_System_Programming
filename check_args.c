/*
** check_agrs.c for  in /home/duttoo_e/tech2/starter_strace/etape2/save_main/Projet_started
** 
** Made by Duttoo Ervin
** Login   <duttoo_e@epitech.net>
** 
** Started on  Wed Apr  6 22:24:44 2016 Duttoo Ervin
** Last update Sun Apr 10 18:48:19 2016 Duttoo Ervin
*/

#include "strace.h"

int     check_pid(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      if ((str[i] >= '0' && str[i] <= '9') ||
          (str[i] >= '9' && str[i] <= '0'))
        return (1);
      else
        return (-1);
      i++;
    }
  return (-1);
}

int    usage(int ac, char **av)
{
  t_inc ptr;

  if (ac < 2)
    {
      printf("Usage : ./strace [-s] [-p <pid>|<command>]\n");
    }
  if (ac <= 2)
    {
      check_args(ac, av);
      return (0);
    }
  option_p(ac, av, &ptr);
  option_s(ac, av, &ptr);
  return (0);
}
