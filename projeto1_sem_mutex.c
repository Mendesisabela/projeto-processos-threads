#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int contador = 0;

void* incrementar(void* arg) {
    for (int i = 0; i < 1000000; i++) {
        contador++; // PROBLEMA AQUI
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    pthread_create(&t1, NULL, incrementar, NULL);
    pthread_create(&t2, NULL, incrementar, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Valor final: %d\n", contador);

    return 0;
}
