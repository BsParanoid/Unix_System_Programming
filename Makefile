##
## Makefile for  in /home/duttoo_e/tech2/starter_strace/etape2/save_main/Projet_started
## 
## Made by Duttoo Ervin
## Login   <duttoo_e@epitech.net>
## 
## Started on  Wed Apr  6 14:58:41 2016 Duttoo Ervin
## Last update Fri Apr  8 12:29:31 2016 Duttoo Ervin
##

SRC	= main.c \
	  check_args.c \
	  check_options.c \
	  tools.c \
	  trace.c \
	  check_binary.c

RM	= rm -f

OBJ	= $(SRC:.c=.o)

NAME	= strace

CFLAGS	+= -Wall -Wextra

all	: $(NAME)

$(NAME)	: $(OBJ)
	cc -o $(NAME) $(OBJ)

clean	:
	$(RM) $(OBJ)

fclean	: clean
	$(RM) $(NAME)

re	: fclean all

.PHONY	: all clean fclean re
