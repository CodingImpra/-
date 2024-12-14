#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <sys/types.h>

void start_process(void);
void check_process_status(pid_t pid);
void change_process_nice_value(pid_t pid, int nice_value);

#endif
