#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2];
    pid_t pid;
    char mensagem[] = "Mensagem do processo pai";
    char buffer[100];


    if (pipe(fd) == -1) {
        perror("Erro no pipe");
        exit(1);
    }


    pid = fork();

    if (pid < 0) {
        perror("Erro no fork");
        exit(1);
    }

    if (pid > 0) {

        close(fd[0]);
        write(fd[1], mensagem, strlen(mensagem) + 1);
        close(fd[1]);
        printf("Pai enviou: %s\n", mensagem);
    } else {

        close(fd[1]);
        read(fd[0], buffer, sizeof(buffer));
        printf("Filho recebeu: %s\n", buffer);
        close(fd[0]);
    }

    return 0;
}
