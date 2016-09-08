##
## Makefile for bomberman in /Users/stevenyung/workspace/current/bomberman
##
## Made by YUNG Steven
## Login   <yung_s@etna-alternance.net>
##
## Started on  Tue Sep  6 22:11:11 2016 YUNG Steven
## Last update Thu Sep  8 22:03:04 2016 YUNG Steven
##

CC= gcc
CFLAGS= -W -Wall -Werror -Wextra
DFLAGS= -g
WFLAGS= -Wno-unknown-pragmas `sdl-config --cflags --libs`
NAME= bomberman-client
SRC= 	client.c \
	keyboard.c \
	fmap.c \
	connection.c \
	error_handler.c \
	my_recv.c
OBJ= $(SRC:%.c=%.o)
RM= rm -rf

$(NAME): $(OBJ)
$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(WFLAGS)

all: $(NAME)

clean:
$(RM) *.o

fclean:clean
$(RM) $(NAME)
$(RM) *~

re: fclean 
all

mrproper:clean
rm -rf $(NAME)

install:
sudo apt-get install libsdl1.2-dev libsdl-image1.2-dev libsdl-mixer1.2-dev libsdl-ttf2.0-dev

dev: $(OBJ)
$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(DFLAGS) $(WFLAGS)

.PHONY:clean mrproper
