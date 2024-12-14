#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "controller.h"
#include "view.h"

int main(int argc, char *argv[]) {
    char action[10];
    pid_t pid = 0;
    int nice_value = 0;

    if (argc > 1) {
        pid = atoi(argv[1]);
    }
    if (argc > 2) {
        nice_value = atoi(argv[2]);
    }

    if (argc > 1) {
        change_process_nice_value(pid, nice_value);
        return 0;
    }

    while (1) {
        prompt_user_input(action, &pid, &nice_value);

        if (strcmp(action, "1") == 0) {
            start_process();
        } else if (strcmp(action, "2") == 0) {
            check_process_status(pid);
        } else if (strcmp(action, "3") == 0) {
            change_process_nice_value(pid, nice_value);
        } else if (strcmp(action, "4") == 0) {
            break;
        } else {
            printf("Неверное действие.\n");
        }
    }

    return 0;
