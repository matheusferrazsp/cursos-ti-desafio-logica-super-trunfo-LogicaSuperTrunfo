#include <stdio.h>
#include <string.h>

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

float obter_valor_atributo(int indice_cidade, int atributo, float densidade_1, float densidade_2, float calculo_pib_1, float calculo_pib_2, unsigned long int populacao[], float kms_quadrados[], float pib[], int pontos_turisticos[]) {
    switch (atributo) {
        case 1:
            return (float)populacao[indice_cidade];
        case 2:
            return kms_quadrados[indice_cidade];
        case 3:
            return pib[indice_cidade];
        case 4:
            return (float)pontos_turisticos[indice_cidade];
        case 5:
            return (indice_cidade == 0) ? densidade_1 : densidade_2;
        case 6:
            return (indice_cidade == 0) ? calculo_pib_1 : calculo_pib_2;
        default:
            return 0.0F;
    }
}

const char* obter_nome_atributo(int atributo) {
    switch (atributo) {
        case 1: return "População";
        case 2: return "Área em km²";
        case 3: return "PIB (em bilhões de reais)";
        case 4: return "Pontos turísticos";
        case 5: return "Densidade Populacional (hab/km²)";
        case 6: return "PIB per Capita (R$)";
        default: return "Desconhecido";
    }
}

int main() {
    char letra_inicial[2];
    char codigo_da_carta[2][10];
    char nome_da_cidade[2][50];
    unsigned long int populacao[2];
    float kms_quadrados[2];
    float pib[2];
    int pontos_turisticos[2];

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

    printf("Digite o PIB da cidade em bilhões de reais (Ex: 50): ");
    scanf("%f", &pib[0]);

    printf("Digite o número de pontos turísticos da cidade: ");
    scanf("%d", &pontos_turisticos[0]);

    limpar_buffer();

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

    
    float densidade_1;
    if (kms_quadrados[0] != 0) { densidade_1 = (float)populacao[0] / kms_quadrados[0];
    } else { densidade_1 = 0.0F;
    }
    
    float calculo_pib_1;
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

    printf("\n\n===== Informações das Cidades =====\n");

    printf("\n--- Cidade 1 ---\n");
    printf("Letra da carta: %c\n", letra_inicial[0]);
    printf("Código da carta: %s\n", codigo_da_carta[0]);
    printf("Nome da cidade: %s\n", nome_da_cidade[0]);
    printf("População da cidade: %lu\n", populacao[0]);
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


    printf("\n--- Comparação das Cartas ---\n");

    printf("Digite quais atributos deseja comparar:\n");
    printf("1 - População\n");
    printf("2 - Área em km²\n");
    printf("3 - PIB (em bilhões de reais)\n");
    printf("4 - Pontos turísticos\n");
    printf("5 - Densidade Populacional (hab/km²)\n");
    printf("6 - PIB per Capita (R$)\n");

    int atributo_escolhido1;
    int atributo_escolhido2;
    int scan_result;

    do {
        printf("Digite o PRIMEIRO atributo escolhido (1-6): ");
        scan_result = scanf("%d", &atributo_escolhido1);

        if (scan_result != 1) {
            printf("\nERRO: Por favor, digite um valor numérico válido (1-6).\n");
            limpar_buffer();
            atributo_escolhido1 = 0;
            continue;
        }
        if (atributo_escolhido1 < 1 || atributo_escolhido1 > 6) {
            printf("\nERRO: Opção de atributo inválida. Escolha um número entre 1 e 6.\n");
        }

    } while (atributo_escolhido1 < 1 || atributo_escolhido1 > 6);

    do {
        printf("Digite o SEGUNDO atributo escolhido (1-6 e DIFERENTE de %d): ", atributo_escolhido1);
        limpar_buffer();
        scan_result = scanf("%d", &atributo_escolhido2);

        if (scan_result != 1) {
            printf("\nERRO: Por favor, digite um valor numérico válido (1-6).\n");
            limpar_buffer();
            atributo_escolhido2 = 0;
            continue;
        }
        if (atributo_escolhido2 < 1 || atributo_escolhido2 > 6) {
            printf("\nERRO: Opção de atributo inválida. Escolha um número entre 1 e 6.\n");
        } else if (atributo_escolhido1 == atributo_escolhido2) {
            printf("\nERRO: Você deve selecionar um atributo DIFERENTE do primeiro.\n");
        }

    } while (atributo_escolhido2 < 1 || atributo_escolhido2 > 6 || atributo_escolhido1 == atributo_escolhido2);

    float valor1_cidade1 = obter_valor_atributo(0, atributo_escolhido1, densidade_1, densidade_2, calculo_pib_1, calculo_pib_2, populacao, kms_quadrados, pib, pontos_turisticos);
    float valor1_cidade2 = obter_valor_atributo(1, atributo_escolhido1, densidade_1, densidade_2, calculo_pib_1, calculo_pib_2, populacao, kms_quadrados, pib, pontos_turisticos);

    float valor2_cidade1 = obter_valor_atributo(0, atributo_escolhido2, densidade_1, densidade_2, calculo_pib_1, calculo_pib_2, populacao, kms_quadrados, pib, pontos_turisticos);
    float valor2_cidade2 = obter_valor_atributo(1, atributo_escolhido2, densidade_1, densidade_2, calculo_pib_1, calculo_pib_2, populacao, kms_quadrados, pib, pontos_turisticos);

    float soma_cidade1 = valor1_cidade1 + valor2_cidade1;
    float soma_cidade2 = valor1_cidade2 + valor2_cidade2;

    printf("\n\n===== RESULTADO DA COMPARAÇÃO =====\n");
    printf("Atributo 1: %s\n", obter_nome_atributo(atributo_escolhido1));
    printf("Atributo 2: %s\n", obter_nome_atributo(atributo_escolhido2));
    printf("--------------------------------------\n");

    printf("Valores de %s (%s):\n", nome_da_cidade[0], codigo_da_carta[0]);
    printf("  - %s: %.2f\n", obter_nome_atributo(atributo_escolhido1), valor1_cidade1);
    printf("  - %s: %.2f\n", obter_nome_atributo(atributo_escolhido2), valor2_cidade1);
    printf("  - SOMA TOTAL: %.2f\n", soma_cidade1);
    printf("--------------------------------------\n");

    printf("Valores de %s (%s):\n", nome_da_cidade[1], codigo_da_carta[1]);
    printf("  - %s: %.2f\n", obter_nome_atributo(atributo_escolhido1), valor1_cidade2);
    printf("  - %s: %.2f\n", obter_nome_atributo(atributo_escolhido2), valor2_cidade2);
    printf("  - SOMA TOTAL: %.2f\n", soma_cidade2);
    printf("--------------------------------------\n");


    printf("\nRESULTADO FINAL:\n");
    if (soma_cidade1 > soma_cidade2) {
        printf("A carta vencedora é: %s com a SOMA de %.2f!\n", nome_da_cidade[0], soma_cidade1);
    } else if (soma_cidade2 > soma_cidade1) {
        printf("A carta vencedora é: %s com a SOMA de %.2f!\n", nome_da_cidade[1], soma_cidade2);
    } else {
        printf("Empate! Ambas as cidades têm a mesma soma de atributos: %.2f\n", soma_cidade1);
    }

    return 0;
}