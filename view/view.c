#include "view.h"
#include <stdio.h>
#include <string.h>

void display_process_status(pid_t pid, int running, int nice_value, int is_zombie) {
    if (!running) printf("Такого процесса нет \n");
    else {
      printf("Процесс %d \n", pid);
      printf("NI: %d\n", nice_value);
      if (is_zombie) printf("%d - зомби-процесс\n", pid);
      else printf("%d - НЕ зомби-процесс\n", pid);
    }
}

void display_nice_change(pid_t pid, int nice_value) {
    printf("Уступчивость процесса %d изменена на %d\n", pid, nice_value);
}

void prompt_user_input(char *action, pid_t *pid, int *nice_value) {
    printf("Выберите (начать процесс-1/проверить-2/уступчивость-3/выйти-4): ");
    scanf("%s", action);

    if (strcmp(action, "2") == 0 || strcmp(action, "3") == 0) {
        printf("Введите PID процесса: ");
        scanf("%d", pid);
    }

    if (strcmp(action, "3") == 0) {
        printf("Введите новое значение NI: ");
        scanf("%d", nice_value);
    }
}
