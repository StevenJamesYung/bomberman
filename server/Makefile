##
## Makefile<2> for bomberman in /Users/stevenyung/workspace/current/bomberman
##
## Made by YUNG Steven
## Login   <yung_s@etna-alternance.net>
##
## Started on  Tue Sep  6 22:13:33 2016 YUNG Steven
## Last update Thu Sep  8 22:21:04 2016 YUNG Steven
##

CC= gcc
CFLAGS= -W -Wall -Werror -Wextra
DFLAGS= -g
NAME= bomberman-server
SRC=	commands.c \
	command_functions.c \
	map_functions.c \
	map.c \
	player.c \
	server.c \
	server_functions.c \
	second_server_functions.c
DEBUG= gdb
DFLAGS= -g
OBJ= $(SRC:%.c=%.o)
	RM= rm -rf

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(SDL)

all: $(NAME)

clean:
	$(RM) *.o

fclean:clean
	$(RM) $(NAME)
	$(RM) *~

re: fclean all

debug:
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(DFLAGS)
	$(DEBUG) $(NAME)

dev: $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(DFLAGS)

mrproper:clean
	rm -rf $(NAME)

.PHONY: clean mrproper
