#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    int populacao;
    float area;
    float pib;
    float densidade;
} Pais;

void mostrarMenu(int ignorar) {
    printf("\nEscolha um atributo:\n");

    if (ignorar != 1) printf("1 - População\n");
    if (ignorar != 2) printf("2 - Área\n");
    if (ignorar != 3) printf("3 - PIB\n");
    if (ignorar != 4) printf("4 - Densidade Demográfica\n");
}

float obterValor(Pais p, int atributo) {
    switch (atributo) {
        case 1: return p.populacao;
        case 2: return p.area;
        case 3: return p.pib;
        case 4: return p.densidade;
        default: return 0;
    }
}

int main() {
    Pais carta1 = {"Brasil", 214000000, 8515767, 1.92, 25.1};
    Pais carta2 = {"Canadá", 38000000, 9984670, 2.14, 4.0};

    int atributo1, atributo2;

    printf("=== SUPER TRUNFO - COMPARAÇÃO AVANÇADA ===\n");
    printf("\nCartas em jogo:\n");
    printf("1 - %s\n", carta1.nome);
    printf("2 - %s\n", carta2.nome);

    // Primeiro atributo
    mostrarMenu(0);
    printf("Escolha o primeiro atributo: ");
    scanf("%d", &atributo1);

    if (atributo1 < 1 || atributo1 > 4) {
        printf("Opção inválida!\n");
        return 1;
    }

    // Segundo atributo (menu dinâmico)
    mostrarMenu(atributo1);
    printf("Escolha o segundo atributo: ");
    scanf("%d", &atributo2);

    if (atributo2 < 1 || atributo2 > 4 || atributo2 == atributo1) {
        printf("Opção inválida!\n");
        return 1;
    }

    float valor1_c1 = obterValor(carta1, atributo1);
    float valor1_c2 = obterValor(carta2, atributo1);

    float valor2_c1 = obterValor(carta1, atributo2);
    float valor2_c2 = obterValor(carta2, atributo2);

    // Comparação individual (ternário)
    int ponto1 = (atributo1 == 4)
        ? (valor1_c1 < valor1_c2)
        : (valor1_c1 > valor1_c2);

    int ponto2 = (atributo2 == 4)
        ? (valor2_c1 < valor2_c2)
        : (valor2_c1 > valor2_c2);

    float soma1 = valor1_c1 + valor2_c1;
    float soma2 = valor1_c2 + valor2_c2;

    printf("\n=== RESULTADO ===\n");
    printf("\n%s:\n", carta1.nome);
    printf("Atributo 1: %.2f\n", valor1_c1);
    printf("Atributo 2: %.2f\n", valor2_c1);
    printf("Soma: %.2f\n", soma1);

    printf("\n%s:\n", carta2.nome);
    printf("Atributo 1: %.2f\n", valor1_c2);
    printf("Atributo 2: %.2f\n", valor2_c2);
    printf("Soma: %.2f\n", soma2);

    printf("\nResultado final: ");
    if (soma1 > soma2)
        printf("%s venceu!\n", carta1.nome);
    else if (soma2 > soma1)
        printf("%s venceu!\n", carta2.nome);
    else
        printf("Empate!\n");

    return 0;
}
