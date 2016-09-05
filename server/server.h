#ifndef __SERVER_H__
# define __SERVER_H__
# define _GNU_SOURCE

#include "../bomberman.h"
#include "global.h"
#include "map.h"
#include <netdb.h>
#include <sys/select.h>
#include "commands.h"
#include "command_functions.h"

int main_loop(int s);
int main();

# define MAX_CONNECTIONS 4
# define PORT 4242

#endif
