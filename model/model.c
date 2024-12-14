#include "model.h"
#include <errno.h>

pid_t create_process(void) {
    pid_t pid = fork();
    if (pid == 0) {
        execlp("sleep", "sleep", "5", NULL);
        perror("execlp failed");
        _exit(1);
    }
    return pid;
}

int is_process_running(pid_t pid) {
    return kill(pid, 0) == 0;
}

int get_process_nice_value(pid_t pid) {
    errno = 0;
    int nice_value = getpriority(PRIO_PROCESS, pid);
    if (errno != 0) {
        perror("get priority failed");
        return -1;
    }
    return nice_value;
}

int is_zombie_process(pid_t pid) {
    char proc_path[256];
    snprintf(proc_path, sizeof(proc_path), "/proc/%d/status", pid);
    FILE *file = fopen(proc_path, "r");
    if (!file) return 0;

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "State:", 6) == 0) {
            fclose(file);
            if (strstr(line, "Z")) {
                return 1;
            } else {
                return 0;
            }
        }
    }
    fclose(file);
    return 0;
}

int set_process_nice_value(pid_t pid, int nice_value) {
    if (setpriority(PRIO_PROCESS, pid, nice_value) < 0) {
        perror("set priority failed");
        return -1;
    }
    return 0;
}
