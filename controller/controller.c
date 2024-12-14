#include "controller.h"
#include "model.h"
#include "view.h"

void start_process(void) {
    pid_t pid = create_process();
    display_process_status(pid, 1, get_process_nice_value(pid), is_zombie_process(pid));
}

void check_process_status(pid_t pid) {
    int running = is_process_running(pid);
    int nice_value = get_process_nice_value(pid);
    int is_zombie = is_zombie_process(pid);
    display_process_status(pid, running, nice_value, is_zombie);
}

void change_process_nice_value(pid_t pid, int nice_value) {
    if (set_process_nice_value(pid, nice_value)==0) display_nice_change(pid, nice_value);
}
