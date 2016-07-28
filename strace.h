/*
** strace.h for  in /home/duttoo_e/tech2/starter_strace/etape2/save_main/Projet_started
** 
** Made by Duttoo Ervin
** Login   <duttoo_e@epitech.net>
** 
** Started on  Wed Apr  6 14:57:49 2016 Duttoo Ervin
** Last update Sun Apr 10 12:44:03 2016 Duttoo Ervin
*/

#ifndef STRACE_H_
#define STRACE_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <sys/ptrace.h>
#include <sys/resource.h>
#include <signal.h>
#include <sys/user.h>
#include <unistd.h>
#include <sys/stat.h>
#include <elf.h>
#include <fcntl.h>
#include <sys/mman.h>
# define STRACE_ERROR "strace: Can't stat \'%s\': No such file or directory\n"

typedef struct  s_inc
{
  int	i;
  int	j;
}               t_inc;

typedef struct  s_elf
{
  int   fd;
  void  *data;
  void  *elf_holder;
  char	*str;
}               t_elf;

int	check_pid(char *str);
int	usage(int ac, char **av);
int	option_p(int ac, char **av, t_inc *ptr);
int	option_s(int ac, char **av, t_inc *ptr);
int     check_error(int ret);
void    loop(char *ptr[]);
int     fork_it(char **av);
int     check_header(Elf64_Ehdr *data);
void	check_file(char **av, t_elf *ptr);
int	check_args(int ac, char **av);
int     fork_next(char **av, pid_t pid);

#endif /* !STRACE_H_ */
