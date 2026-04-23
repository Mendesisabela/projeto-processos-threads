#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define TAM 5

// ================= BUFFER =================

int buffer[TAM];
int count = 0;

pthread_mutex_t mutex;

// ================= PRODUTOR =================

void* produtor(void* arg) {
    for (int i = 0; i < 5; i++) {
        int valor = rand() % 100;

        pthread_mutex_lock(&mutex);

        if (count < TAM) {
            buffer[count++] = valor;
            printf("Produziu: %d\n", valor);
        }

        pthread_mutex_unlock(&mutex);

        usleep(200000);
    }
    return NULL;
}

// ================= CONSUMIDOR =================

void* consumidor(void* arg) {
    for (int i = 0; i < 5; i++) {

        pthread_mutex_lock(&mutex);

        if (count > 0) {
            int valor = buffer[--count];
            printf("Consumiu: %d\n", valor);
        }

        pthread_mutex_unlock(&mutex);

        usleep(200000);
    }
    return NULL;
}

// ================= TESTE SEM MUTEX =================

int contador_sem_mutex = 0;

void* incremento_sem_mutex(void* arg) {
    for (int i = 0; i < 1000000; i++) {
        contador_sem_mutex++;
    }
    return NULL;
}

// ================= TESTE COM MUTEX =================

int contador_com_mutex = 0;
pthread_mutex_t mutex2;

void* incremento_com_mutex(void* arg) {
    for (int i = 0; i < 1000000; i++) {

        pthread_mutex_lock(&mutex2);
        contador_com_mutex++;
        pthread_mutex_unlock(&mutex2);

    }
    return NULL;
}

// ================= MAIN =================

int main() {

    printf("\n===== PRODUTOR/CONSUMIDOR =====\n");

    pthread_t t1, t2;

    pthread_mutex_init(&mutex, NULL);

    pthread_create(&t1, NULL, produtor, NULL);
    pthread_create(&t2, NULL, consumidor, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&mutex);

    // ================= TESTE SEM MUTEX =================
    
    printf("\n===== TESTE SEM MUTEX =====\n");

    pthread_t t3, t4;

    pthread_create(&t3, NULL, incremento_sem_mutex, NULL);
    pthread_create(&t4, NULL, incremento_sem_mutex, NULL);

    pthread_join(t3, NULL);
    pthread_join(t4, NULL);

    printf("\nValor final: %d\n", contador_sem_mutex);

    // ================= TESTE COM MUTEX =================
    
    printf("\n===== TESTE COM MUTEX =====\n");

    pthread_t t5, t6;

    pthread_mutex_init(&mutex2, NULL);

    pthread_create(&t5, NULL, incremento_com_mutex, NULL);
    pthread_create(&t6, NULL, incremento_com_mutex, NULL);

    pthread_join(t5, NULL);
    pthread_join(t6, NULL);

    pthread_mutex_destroy(&mutex2);

    printf("\nValor final: %d\n", contador_com_mutex);

    return 0;
}
