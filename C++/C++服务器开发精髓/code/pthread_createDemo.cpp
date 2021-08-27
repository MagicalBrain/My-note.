#include <stdio.h>

#include <pthread.h>

#include <unistd.h>

void* threadfunc(void* args) {
    while (1) {
        sleep(1);

        printf("I am a New Thread!\n");
    }
    return NULL;
}

int main() {
    pthread_t threaddid;
    pthread_create(&threaddid, NULL, threadfunc, NULL);

    while (1) {
        
    }
    return 0;
}
