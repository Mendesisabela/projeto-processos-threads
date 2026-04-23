#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int contador = 0;
pthread_mutex_t mutex;

void* incrementar(void* arg) {
    for (int i = 0; i < 1000000; i++) {

        pthread_mutex_lock(&mutex);
        contador++;
        pthread_mutex_unlock(&mutex);

    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    pthread_mutex_init(&mutex, NULL);

    pthread_create(&t1, NULL, incrementar, NULL);
    pthread_create(&t2, NULL, incrementar, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&mutex);

    printf("Valor final: %d\n", contador);

    return 0;
}
