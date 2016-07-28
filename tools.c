/*
** tools.c for  in /home/duttoo_e/tech2/starter_strace/etape2/save_main/Projet_started
** 
** Made by Duttoo Ervin
** Login   <duttoo_e@epitech.net>
** 
** Started on  Thu Apr  7 12:47:43 2016 Duttoo Ervin
** Last update Thu Apr  7 23:08:14 2016 Duttoo Ervin
*/

#include "strace.h"

int     check_error(int ret)
{
  if (ret == -1)
    {
      perror("PTRACE_ERROR");
      return (-1);
    }
  return (0);
}

void    loop(char *ptr[])
{
  int   i;
  int   y;

  i = 0;
  y = 0;
  while (i < y)
    {
      ptr[y] = NULL;
      y++;
      i++;
    }
}
