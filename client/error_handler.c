/*
** client.h for bomberman in /Users/stevenyung/workspace/current/bomberman
** 
** Made by YUNG Steven
** Login   <yung_s@etna-alternance.net>
** 
** Started on  Tue Sep  6 22:12:04 2016 YUNG Steven
** Last update Thu Sep  8 21:53:56 2016 YUNG Steven
*/

#include "error_handler.h"

void handle_error(int error)
{
  char *error_msg[NB_ERRORS];

  error_msg[0] = "The server is full";
  error_msg[1] = "Failed to create socket";
  error_msg[2] = "Failed to connect to the server";
  error_msg[3] = "Failed to malloc in ask_connection";
  error_msg[4] = "Failed to send the connection request";
  error_msg[5] = "set_conio_terminal_mode failed";
  error_msg[6] = "select failed";

  if (error == 2)
    printf("%s", error_msg[0]);
  else
    {
      printf("%s", error_msg[error * -1]);
      printf(", program will close now.\n\n");
    }
}
