CC= gcc
CFLAGS= -W -Wall -Werror -Wextra -g
NAME= bomberman-client
SRC= client.c\
		 keyboard.c
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
