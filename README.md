Projeto 1 – Processos e Threads

Trabalho desenvolvido para a disciplina de Sistemas Operacionais, com o objetivo de demonstrar, na prática, conceitos de concorrência por meio da utilização de threads e processos em linguagem C.

Arquivos do projeto:
projeto_final.c
- Criação de threads utilizando a biblioteca pthread
- Implementação do problema produtor-consumidor
- Uso de mecanismos de sincronização com mutex
- Demonstração da condição de corrida e sua correção

fork_pipe.c
- Criação de processos utilizando fork()
- Comunicação entre processos com pipe()

Compilação:
gcc projeto_final.c -o projeto_final -pthread
gcc fork_pipe.c -o fork_pipe

Execução:
./projeto_final
./fork_pipe

Os arquivos foram separados com o objetivo de facilitar a organização e a análise individual de cada conceito abordado.
