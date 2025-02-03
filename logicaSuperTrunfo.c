#include <stdio.h>

typedef struct {
printf("Desfio super trunfo países")
    char estado[50];
    int codigo;
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional; // calculada
    float pib_per_capita;         // calculado
} Carta;

// Função para cadastrar uma carta
void cadastrarCarta(Carta *c) {
    printf("Digite o estado: ");
    scanf(" %[^\n]", c->estado);

    printf("Digite o código da carta: ");
    scanf("%d", &c->codigo);

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", c->nome);

    printf("Digite a população: ");
    scanf("%d", &c->populacao);

    printf("Digite a área (em km²): ");
    scanf("%f", &c->area);

    printf("Digite o PIB (em milhões): ");
    scanf("%f", &c->pib);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &c->pontos_turisticos);

    // Cálculo da densidade populacional e PIB per capita
    c->densidade_populacional = c->populacao / c->area;
    c->pib_per_capita = c->pib / c->populacao;
}

// Função para exibir os dados de uma carta
void exibirCarta(Carta c) {
    printf("\n--- Carta ---\n");
    printf("Estado: %s\n", c.estado);
    printf("Código: %d\n", c.codigo);
    printf("Cidade: %s\n", c.nome);
    printf("População: %d\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: %.2f milhões\n", c.pib);
    printf("Pontos turísticos: %d\n", c.pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", c.densidade_populacional);
    printf("PIB per capita: %.2f milhões\n", c.pib_per_capita);
}

// Função para comparar duas cartas com base em um atributo
void compararCartas(Carta c1, Carta c2, int opcao) {
    float valor1, valor2;

    switch (opcao) {
        case 1: // População
            valor1 = c1.populacao;
            valor2 = c2.populacao;
            break;
        case 2: // Área
            valor1 = c1.area;
            valor2 = c2.area;
            break;
        case 3: // PIB
            valor1 = c1.pib;
            valor2 = c2.pib;
            break;
        case 4: // Densidade populacional (menor vence)
            valor1 = c1.densidade_populacional;
            valor2 = c2.densidade_populacional;
            if (valor1 < valor2) {
                printf("\nA cidade vencedora é: %s\n", c1.nome);
            } else if (valor2 < valor1) {
                printf("\nA cidade vencedora é: %s\n", c2.nome);
            } else {
                printf("\nEmpate!\n");
            }
            return;
        case 5: // PIB per capita
            valor1 = c1.pib_per_capita;
            valor2 = c2.pib_per_capita;
            break;
        default:
            printf("Opção inválida!\n");
            return;
    }

    if (valor1 > valor2) {
        printf("\nA cidade vencedora é: %s\n", c1.nome);
    } else if (valor2 > valor1) {
        printf("\nA cidade vencedora é: %s\n", c2.nome);
    } else {
        printf("\nEmpate!\n");
    }
}

int main() {
    Carta carta1, carta2;
    int opcao;

    printf("Cadastro da primeira cidade:\n");
    cadastrarCarta(&carta1);
    exibirCarta(carta1);

    printf("\nCadastro da segunda cidade:\n");
    cadastrarCarta(&carta2);
    exibirCarta(carta2);

    printf("\nEscolha o atributo para a comparação:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Densidade Populacional (menor vence)\n");
    printf("5 - PIB per capita\n");
    printf("Digite a opção: ");
    scanf("%d", &opcao);

    compararCartas(carta1, carta2, opcao);

    return 0;
}
