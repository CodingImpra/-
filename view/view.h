#ifndef VIEW_H
#define VIEW_H

#include <sys/types.h>

void display_process_status(pid_t pid, int running, int nice_value, int is_zombie);
void display_nice_change(pid_t pid, int nice_value);
void prompt_user_input(char *action, pid_t *pid, int *nice_value);

#endif
