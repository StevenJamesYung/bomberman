CC= gcc
CFLAGS= -W -Wall -Werror -Wextra
NAME= bomberman-server
SRC= commands.c \
		 command_functions.c \
		 global.c \
		 map.c \
		 player.c \
		 server.c \
		 server_functions.c		 
DEBUG= gdb
DFLAGS= -g
OBJ= $(SRC:%.c=%.o)
	RM= rm -rf

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

all: $(NAME)

clean:
	$(RM) *.o

fclean:clean
	$(RM) $(NAME)
	$(RM) *~

debug:
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(DFLAGS)
	$(DEBUG) $(NAME)
