#ifndef MODEL_H
#define MODEL_H

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/resource.h>

pid_t create_process(void);
int is_process_running(pid_t pid);
int get_process_nice_value(pid_t pid);
int is_zombie_process(pid_t pid);
int set_process_nice_value(pid_t pid, int nice_value);

#endif
