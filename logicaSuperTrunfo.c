#include <stdio.h>
#include <string.h>

// Estrutura representando as cartas do jogo.
typedef struct
{
    char nomeDaCidade[50];
    char estado[50];
    int codigo;
    long int populacao;
    long int area;
    double pib;
    int pontosTuristicos;
    double densidadeDemografica;
} Cartas;

// Função para capturar os dados de uma carta.
void capturarDados(Cartas *cartas)
{
    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", cartas->nomeDaCidade);

    printf("Digite o estado: ");
    scanf(" %[^\n]", cartas->estado);

    printf("Digite o código da cidade: ");
    scanf("%d", &cartas->codigo);

    printf("Digite a população da cidade: ");
    scanf("%ld", &cartas->populacao);

    printf("Digite a área (em km²): ");
    scanf("%ld", &cartas->area);

    printf("Digite o PIB (em bilhões): ");
    scanf("%lf", &cartas->pib);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &cartas->pontosTuristicos);

    // Calcula a densidade demográfica ao capturar os dados.
    if (cartas->area != 0)
    {
        cartas->densidadeDemografica = (double)cartas->populacao / cartas->area;
    }
    else
    {
        cartas->densidadeDemografica = 0.0;
    }
}

// Função para exibir os dados de uma carta.
void exibirCartas(Cartas *cartas)
{
    printf("\n----- Carta %d ------\n", cartas->codigo);
    printf("Cidade: %s\n", cartas->nomeDaCidade);
    printf("Estado: %s\n", cartas->estado);
    printf("População: %ld\n", cartas->populacao);
    printf("Área: %ld km²\n", cartas->area);
    printf("PIB: %.2f bilhões\n", cartas->pib);
    printf("Pontos Turísticos: %d\n", cartas->pontosTuristicos);
    printf("Densidade Demográfica: %.2f hab/km²\n", cartas->densidadeDemografica);
}

// Função para comparar as cartas com base em um atributo.
void compararCartas(Cartas *cartas1, Cartas *cartas2, int atributo)
{
    switch (atributo)
    {
    case 1: // População
        if (cartas1->populacao > cartas2->populacao)
        {
            printf("\nVencedor: %s (População: %ld)\n", cartas1->nomeDaCidade, cartas1->populacao);
        }
        else if (cartas1->populacao < cartas2->populacao)
        {
            printf("\nVencedor: %s (População: %ld)\n", cartas2->nomeDaCidade, cartas2->populacao);
        }
        else
        {
            printf("\nEmpate! Ambas têm a mesma população.\n");
        }
        break;

    case 2: // Área
        if (cartas1->area > cartas2->area)
        {
            printf("\nVencedor: %s (Área: %ld km²)\n", cartas1->nomeDaCidade, cartas1->area);
        }
        else if (cartas1->area < cartas2->area)
        {
            printf("\nVencedor: %s (Área: %ld km²)\n", cartas2->nomeDaCidade, cartas2->area);
        }
        else
        {
            printf("\nEmpate! Ambas têm a mesma área.\n");
        }
        break;

    case 3: // PIB
        if (cartas1->pib > cartas2->pib)
        {
            printf("\nVencedor: %s (PIB: %.2f bilhões)\n", cartas1->nomeDaCidade, cartas1->pib);
        }
        else if (cartas1->pib < cartas2->pib)
        {
            printf("\nVencedor: %s (PIB: %.2f bilhões)\n", cartas2->nomeDaCidade, cartas2->pib);
        }
        else
        {
            printf("\nEmpate! Ambas têm o mesmo PIB.\n");
        }
        break;

    case 4: // Pontos turísticos
        if (cartas1->pontosTuristicos > cartas2->pontosTuristicos)
        {
            printf("\nVencedor: %s (Pontos turísticos: %d)\n", cartas1->nomeDaCidade, cartas1->pontosTuristicos);
        }
        else if (cartas1->pontosTuristicos < cartas2->pontosTuristicos)
        {
            printf("\nVencedor: %s (Pontos turísticos: %d)\n", cartas2->nomeDaCidade, cartas2->pontosTuristicos);
        }
        else
        {
            printf("\nEmpate! Ambas têm o mesmo número de pontos turísticos.\n");
        }
        break;

    case 5: // Densidade demográfica
        if (cartas1->densidadeDemografica > cartas2->densidadeDemografica)
        {
            printf("\nVencedor: %s (Densidade demográfica: %.2f hab/km²)\n", cartas1->nomeDaCidade, cartas1->densidadeDemografica);
        }
        else if (cartas1->densidadeDemografica < cartas2->densidadeDemografica)
        {
            printf("\nVencedor: %s (Densidade demográfica: %.2f hab/km²)\n", cartas2->nomeDaCidade, cartas2->densidadeDemografica);
        }
        else
        {
            printf("\nEmpate! Ambas têm a mesma densidade demográfica.\n");
        }
        break;

    case 0:
        printf("Saindo do programa ...\n");
        break;

    default:
        printf("\nOpção inválida! Escolha um atributo entre 1 e 5.\n");
        break;
    }
}

// Função principal.
int main()
{
    Cartas cartas1, cartas2;
    int atributo;

    printf("Cadastrar carta 1:\n");
    capturarDados(&cartas1);

    printf("\nCadastrar carta 2:\n");
    capturarDados(&cartas2);

    while (atributo != 0)
    {
        printf("\n------ Escolha o atributo para comparar ------\n");
        printf("1. População\n");
        printf("2. Área\n");
        printf("3. PIB\n");
        printf("4. Pontos turísticos\n");
        printf("5. Densidade populacional\n");
        printf("0 - sair do programa");
        printf("Opção: ");
        scanf("%d", &atributo);
        printf("\nCartas cadastradas:\n");
        exibirCartas(&cartas1);
        exibirCartas(&cartas2);

        compararCartas(&cartas1, &cartas2, atributo);
    }

    return 0;
}
