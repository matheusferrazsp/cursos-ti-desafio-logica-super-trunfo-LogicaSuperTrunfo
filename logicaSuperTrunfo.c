#include <stdio.h>
#include <string.h>

// Função para limpar o buffer de entrada
void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    char letra_inicial[2];
    char codigo_da_carta[2][10];
    char nome_da_cidade[2][50];
    unsigned long int populacao[2];
    float kms_quadrados[2];
    float pib[2];
    int pontos_turisticos[2];

    // Cidade 1
    printf("\n--- Cadastro da Cidade 1 ---\n");

    printf("Digite uma letra de 'A' a 'H': ");
    scanf(" %c", &letra_inicial[0]);
    limpar_buffer(); 

    printf("A letra do estado seguida de um número de 01 a 04 (ex: A01, B03): ");
    scanf("%9s", codigo_da_carta[0]);
    limpar_buffer(); 

    printf("Digite o nome da cidade: ");
    fgets(nome_da_cidade[0], sizeof(nome_da_cidade[0]), stdin);
    nome_da_cidade[0][strcspn(nome_da_cidade[0], "\n")] = '\0';

    printf("Digite a população da cidade: ");
    scanf("%lu", &populacao[0]);

    printf("Digite a área em quilômetros quadrados da cidade: ");
    scanf("%f", &kms_quadrados[0]);

    printf("Digite o PIB da cidade: ");
    scanf("%f", &pib[0]);

    printf("Digite o número de pontos turísticos da cidade: ");
    scanf("%d", &pontos_turisticos[0]);

    limpar_buffer(); 

    // Cidade 2
    printf("\n--- Cadastro da Cidade 2 ---\n");

    printf("Digite uma letra de 'A' a 'H': ");
    scanf(" %c", &letra_inicial[1]);
    limpar_buffer();

    printf("A letra do estado seguida de um número de 01 a 04 (ex: A01, B03): ");
    scanf("%9s", codigo_da_carta[1]);
    limpar_buffer();

    printf("Digite o nome da cidade: ");
    fgets(nome_da_cidade[1], sizeof(nome_da_cidade[1]), stdin);
    nome_da_cidade[1][strcspn(nome_da_cidade[1], "\n")] = '\0';

    printf("Digite a população da cidade: ");
    scanf("%lu", &populacao[1]);

    printf("Digite a área em quilômetros quadrados da cidade: ");
    scanf("%f", &kms_quadrados[1]); 

    printf("Digite o PIB da cidade em bilhões de reais (Ex: 50): ");
    scanf("%f", &pib[1]);

    printf("Digite o número de pontos turísticos da cidade: ");
    scanf("%d", &pontos_turisticos[1]);
    limpar_buffer();

    // Cálculos
    float densidade_1;
    float calculo_pib_1;

    if (kms_quadrados[0] != 0) { densidade_1 = (float)populacao[0] / kms_quadrados[0];
    } else { densidade_1 = 0.0F; 
}

    if (populacao[0] != 0) {
        calculo_pib_1 = (pib[0] * 1000000000.0) / (float)populacao[0];
    } else {
        calculo_pib_1 = 0.0F;
    }

    float densidade_2;
    if (kms_quadrados[1] != 0) {
        densidade_2 = (float)populacao[1] / kms_quadrados[1];
    } else {
        densidade_2 = 0.0F;
    }
    
    float calculo_pib_2;
    if (populacao[1] != 0) {
        calculo_pib_2 = (pib[1] * 1000000000.0) / (float)populacao[1];
    } else {
        calculo_pib_2 = 0.0F;
    }

    // Impressão
    printf("\n\n===== Informações das Cidades =====\n");

    printf("\n--- Cidade 1 ---\n");
    printf("Letra da carta: %c\n", letra_inicial[0]);
    printf("Código da carta: %s\n", codigo_da_carta[0]);
    printf("Nome da cidade: %s\n", nome_da_cidade[0]);
    printf("População da cidade: %lu\n", populacao[2]);
    printf("Área da cidade: %.2f km²\n", kms_quadrados[0]);
    printf("PIB da cidade: %.2f bilhões de reais\n", pib[0]);
    printf("Pontos turísticos: %d\n", pontos_turisticos[0]);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade_1);
    printf("PIB per Capita: R$  %.2f\n", calculo_pib_1);

    printf("\n--- Cidade 2 ---\n");
    printf("Letra da carta: %c\n", letra_inicial[1]);
    printf("Código da carta: %s\n", codigo_da_carta[1]);
    printf("Nome da cidade: %s\n", nome_da_cidade[1]);
    printf("População da cidade: %lu\n", populacao[1]);
    printf("Área da cidade: %.2f km²\n", kms_quadrados[1]);
    printf("PIB da cidade: %.2f bilhões de reais\n", pib[1]);
    printf("Pontos turísticos: %d\n", pontos_turisticos[1]);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade_2);
    printf("PIB per Capita: R$ %.2f\n", calculo_pib_2);

    

    // Carta Vencedora
    printf("\n--- Comparação das cartas ---\n");

    printf("Comparando as cartas...\n");

    printf("Digite qual atributo deseja comparar:\n");
    printf("1 - População\n");
    printf("2 - Área em km²\n");
    printf("3 - PIB (em bilhões de reais)\n");
    printf("4 - Pontos turísticos\n");
    printf("5 - Densidade Populacional (hab/km²)\n");
    printf("6 - PIB per Capita (R$)\n");
    printf("Digite o atributo escolhido: ");

    int atributo_escolhido;
    scanf("%d", &atributo_escolhido);

    switch (atributo_escolhido) {
        case 1:
        if (populacao[0] > populacao[1]) {
            printf("A carta vencedora é: %s com população de %lu\n", nome_da_cidade[0], populacao[0]);
        } else if (populacao[0] < populacao[1]) {
            printf("A carta vencedora é: %s com população de %lu\n", nome_da_cidade[1], populacao[1]);
        } else {
            printf("Empate! Ambas as cidades têm a mesma população de %lu\n", populacao[0]);
        }
        break;
        case 2:
        if (kms_quadrados[0] > kms_quadrados[1]) {
            printf("A carta vencedora é: %s com área de %.2f km²\n", nome_da_cidade[0], kms_quadrados[0]);
        } else if (kms_quadrados[0] < kms_quadrados[1]) {
            printf("A carta vencedora é: %s com área de %.2f km²\n", nome_da_cidade[1], kms_quadrados[1]);
        } else {
            printf("Empate! Ambas as cidades têm a mesma área de %.2f km²\n", kms_quadrados[0]);
        }
        break;
        case 3:
        if (pib[0] > pib[1]) {
            printf("A carta vencedora é: %s com PIB de %.2f bilhões de reais\n", nome_da_cidade[0], pib[0]);
        } else if (pib[0] < pib[1]) {            
            printf("A carta vencedora é: %s (Cidade 2) com PIB de %.2f bilhões de reais\n", nome_da_cidade[1], pib[1]);
        } else {
            printf("Empate! Ambas as cidades têm o mesmo PIB de %.2f bilhões de reais\n", pib[0]);
        }
        break;
        case 4:
        if (pontos_turisticos[0] > pontos_turisticos[1]) {
            printf("A carta vencedora é: %s com %d pontos turísticos\n", nome_da_cidade[0], pontos_turisticos[0]);
        } else if (pontos_turisticos[0] < pontos_turisticos[1]) {
            printf("A carta vencedora é: %s com %d pontos turísticos\n", nome_da_cidade[1], pontos_turisticos[1]);
        } else {
            printf("Empate! Ambas as cidades têm o mesmo número de pontos turísticos: %d\n", pontos_turisticos[0]);
        }
        break;
        case 5:
        if (densidade_1 < densidade_2) {
            printf("A carta vencedora é: %s com densidade populacional de %.2f hab/km²\n", nome_da_cidade[0], densidade_1);
        } else if (densidade_1 > densidade_2) {
            printf("A carta vencedora é: %s com densidade populacional de %.2f hab/km²\n", nome_da_cidade[1], densidade_2);
        } else {
            printf("Empate! Ambas as cidades têm a mesma densidade populacional de %.2f hab/km²\n", densidade_1);
        }
        break;
        case 6:
        if (calculo_pib_1 > calculo_pib_2) {
            printf("A carta vencedora é: %s com PIB per capita de R$ %.2f\n", nome_da_cidade[0], calculo_pib_1);
        } else if (calculo_pib_1 < calculo_pib_2) {
            printf("A carta vencedora é: %s com PIB per capita de R$ %.2f\n", nome_da_cidade[1], calculo_pib_2);
        } else {
            printf("Empate! Ambas as cidades têm o mesmo PIB per capita de R$ %.2f\n", calculo_pib_1);
        }
        break;
        default:
        printf("Opção inválida!\n");
    }
    return 0;
}