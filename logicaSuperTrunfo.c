#include <stdio.h>
#include <string.h>

//estado, código da carta, nome da cidade, população, área, PIB e número de pontos turísticos.
typedef struct 
{
    char nomeDaCidade[50];
    char estado[50];
    int codigo;
    long int populacao;
    long int area;
    double pib;
    int pontosTuristicos;
    long int densidadeDemografica;
} Cartas ;



void capturarDados(Cartas * cartas) {
    printf("Digite o nome da cidade: ");    
    scanf("%[^\n]", &cartas ->nomeDaCidade);
    
    printf("Digite o nome do Estado: ");
    scanf("%[^\n]", &cartas ->estado);
    
    printf("Digite o codigo da cidade: ");
    scanf("%d", &cartas ->codigo );

    printf("Digite a população da cidade: ");
    scanf("%ld", &cartas -> populacao);

    printf("Digite a area da cidade: ");
    scanf("%ld", &cartas -> area);

    printf("Digite o pib da cidade: ");
    scanf("%lf", &cartas ->pib);

    printf("Digite os pontos turisticos da cidade: ");
    scanf("%d", cartas->pontosTuristicos);

}


void exibirCartas(Cartas * cartas) {

    printf("-----Cartas %d------%s", cartas->codigo, cartas->nomeDaCidade);
    printf("Estado: %s", cartas->estado);
    printf("Codigo: %d", cartas ->codigo);
    printf("População: %ld", cartas ->populacao);
    printf("Area: %ld ", &cartas -> area);
    printf("PIB: %lf", &cartas -> pib );
    printf("Pontos Turisticos: %d", &cartas ->pontosTuristicos);
}



double desidadeDemografica(Cartas * c) {
    if(c ->area  != 0 && c -> populacao != 0) {
         c-> densidadeDemografica = c -> populacao / c -> area;
    } else {
         c -> densidadeDemografica = 0;
    }
    return c -> densidadeDemografica;
}

void compararCartas (Cartas * cartas1, Cartas * cartas2, int atributo) {
    switch (atributo)
    {
    //populaçao    
    switch (atributo) {
        case 1: // População
            if (cartas1 ->populacao > cartas2 ->populacao)
                printf("Vencedor: %s (População: %ld)\n", cartas1->nomeDaCidade, cartas1 ->populacao);
            else if (cartas1 ->populacao < cartas2 ->populacao)
                printf("Vencedor: %s (População: %ld)\n", cartas2 ->nomeDaCidade, cartas2 ->populacao);
            else
                printf("Empate! Ambas têm a mesma população.\n");
            break;

        case 2: // Área
            if (cartas1 -> area > cartas2 -> area)
                printf("Vencedor: %s (Área: %.2f km²)\n", cartas1 ->nomeDaCidade, cartas1 ->area);
            else if (cartas1 ->  area < cartas2 ->area)
                printf("Vencedor: %s (Área: %.2f km²)\n", cartas2 -> nomeDaCidade, cartas2 ->area);
            else
                printf("Empate! Ambas têm a mesma área.\n");
            break;

        case 3: // PIB
            if (cartas1 ->pib > cartas2 -> pib)
                printf("Vencedor: %s (PIB: %.2f bilhões)\n", cartas1 ->nomeDaCidade, cartas1 ->pib);
            else if (cartas1->pib < cartas2 ->pib)
                printf("Vencedor: %s (PIB: %.2f bilhões)\n", cartas2 -> nomeDaCidade, cartas2 ->pib);
            else
                printf("Empate! Ambas têm o mesmo PIB.\n");
            break;

        case 4: // Pontos turísticos
            if (cartas1 ->pontosTuristicos > cartas2 ->pontosTuristicos)
                printf("Vencedor: %s (Pontos turísticos: %d)\n", cartas1 ->nomeDaCidade, cartas1 ->pontosTuristicos);
            else if (cartas1 ->pontosTuristicos < cartas2 ->pontosTuristicos)
                printf("Vencedor: %s (Pontos turísticos: %d)\n", cartas2 -> nomeDaCidade, cartas2 ->pontosTuristicos);
            else
                printf("Empate! Ambas têm o mesmo número de pontos turísticos.\n");
            break;
        case 5:  // desidade demografica
            if(desidadeDemografica(cartas1) < desidadeDemografica(cartas2)) {
                printf("Vencedor: %s densidade demografica : %d\n", cartas1 -> nomeDaCidade, cartas1 ->codigo);
            } else if(desidadeDemografica(cartas2) < desidadeDemografica(cartas1)) {
                printf("Vencedor: %s, densidade demografica %d\n");
            } else {
                printf("Empate\n");
            }

    default:
        printf("Opção inválida");
        break;
    
  }
}


int main();
{

    Cartas cartas1, cartas2;
    int atributo;


    printf("Cadastrar carta 1:");
    capturarDados(&cartas1);
    printf("Cadastro da carta 2");
    capturarDados(&cartas2);

    printf("------Digite uma das opçoes: ");
    printf("\nEscolha o atributo para comparar:\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Pontos turísticos\n");
    printf("5. Densidade populacional\n");
    printf("Opção: ");   
    scanf("%d", &atributo);

    exibirCartas(&cartas1);
    exibirCartas(&cartas2);

    compararCartas(&cartas1, &cartas2, atributo);

    return 0;
}
