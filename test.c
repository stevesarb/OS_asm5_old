#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void push_back(pid_t* pid_arr, pid_t pid) {
    int i = 0;
    while (i < 5) {
        if (pid_arr[i] == 0) {
            pid_arr[i] = pid;
            break;
        }
        ++i;
    }

    i = 0;
    while (i < 5) {
        printf("pid_arr[%d]: %d\n", i, pid_arr[i]);
        ++i;
    }
}

int main() {
    pid_t pid_arr[5] = {};
    push_back(pid_arr, 17);
    push_back(pid_arr, 23);

    int childExitMethod;
    pid_t termChild = waitpid(-5, &childExitMethod, WNOHANG);
    printf("termChild: %d\n", termChild);
    printf("WIFEXITED: %d\n", WIFEXITED(childExitMethod));
    

    return 0;
}