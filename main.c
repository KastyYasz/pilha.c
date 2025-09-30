#include <stdio.h>

#define TAM 5

void clear_input(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void pause_enter(void) {
    printf("Pressione ENTER para continuar...");
    fflush(stdout);
    clear_input();
}

int main(void) {
    int pilha[TAM];
    int topo = -1;
    int op = 0;

    do {
        printf("\n==== MENU ====\n");
        printf("1 - Push (inserir)\n");
        printf("2 - Pop  (remover)\n");
        printf("3 - Imprimir pilha\n");
        printf("9 - Sair\n");
        printf("Escolha: ");
        if (scanf("%d", &op) != 1) {
            // entrada inválida (ex: letra). Limpa e continua.
            clear_input();
            printf("Opcao invalida\n");
            continue;
        }
        clear_input(); // limpa o '\n' após o número

        switch (op) {
            case 1: {
                int elemento;
                printf("Digite o valor a ser inserido na pilha: ");
                if (scanf("%d", &elemento) != 1) {
                    clear_input();
                    printf("Entrada invalida\n");
                    break;
                }
                clear_input();
                if (topo < TAM - 1) {
                    pilha[++topo] = elemento;
                    printf("Valor inserido com sucesso\n");
                } else {
                    printf("Pilha cheia (overflow)\n");
                }
                pause_enter();
            } break;

            case 2:
                if (topo >= 0) {
                    // opcional: int removido = pilha[topo];
                    topo--;
                    printf("Elemento removido com sucesso\n");
                } else {
                    printf("Pilha vazia (underflow)\n");
                }
                pause_enter();
                break;

            case 3:
                if (topo >= 0) {
                    printf("Pilha (topo -> base): ");
                    for (int i = topo; i >= 0; i--) {
                        printf("%d ", pilha[i]);
                    }
                    printf("\n");
                } else {
                    printf("Pilha vazia\n");
                }
                pause_enter();
                break;

            case 9:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida\n");
                pause_enter();
                break;
        }
    } while (op != 9);

    return 0;
}
