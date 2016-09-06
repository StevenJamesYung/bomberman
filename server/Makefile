CC= gcc
CFLAGS= -W -Wall -Werror -Wextra -g
NAME= bomberman-server
SRC= commands.c \
		 global.c \
		 map.c \
		 player.c \
		 server.c
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
