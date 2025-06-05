

typedef struct
{
    char estado[50];
    int codigo;
    char nome[50];
    unsigned long int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade;
    float pib_per_capita;
    float super_poder;
} Carta;

float calcular_densidade(unsigned long int populacao, float area)
{
    return populacao / area;
}

float calcular_pib_per_capita(float pib, unsigned long int populacao)
{
    return pib / populacao;
}

float calcular_super_poder(Carta carta)
{
    float inverso_densidade = 1 / carta.densidade;
    return (float)carta.populacao + carta.area + carta.pib +
           carta.pontos_turisticos + carta.pib_per_capita + inverso_densidade;
}

void comparar(const char *atributo, float valor1, float valor2, int menor_vence)
{
    int carta1_vence = (menor_vence) ? (valor1 < valor2) : (valor1 > valor2);
    printf("%s: Carta %d venceu (%d)\n", atributo, carta1_vence ? 1 : 2, carta1_vence);
}

int main()
{
    Carta carta1, carta2;

    printf("Digite os dados da Carta 1:\n");
    printf("Estado: ");
    scanf(" %[^\n]", carta1.estado);
    printf("Código: ");
    scanf("%d", &carta1.codigo);
    printf("Nome: ");
    scanf(" %[^\n]", carta1.nome);
    printf("População: ");
    scanf("%lu", &carta1.populacao);
    printf("Área: ");
    scanf("%f", &carta1.area);
    printf("PIB: ");
    scanf("%f", &carta1.pib);
    printf("Pontos turísticos: ");
    scanf("%d", &carta1.pontos_turisticos);

    printf("\nDigite os dados da Carta 2:\n");
    printf("Estado: ");
    scanf(" %[^\n]", carta2.estado);
    printf("Código: ");
    scanf("%d", &carta2.codigo);
    printf("Nome: ");
    scanf(" %[^\n]", carta2.nome);
    printf("População: ");
    scanf("%lu", &carta2.populacao);
    printf("Área: ");
    scanf("%f", &carta2.area);
    printf("PIB: ");
    scanf("%f", &carta2.pib);
    printf("Pontos turísticos: ");
    scanf("%d", &carta2.pontos_turisticos);

    carta1.densidade = calcular_densidade(carta1.populacao, carta1.area);
    carta2.densidade = calcular_densidade(carta2.populacao, carta2.area);

    carta1.pib_per_capita = calcular_pib_per_capita(carta1.pib, carta1.populacao);
    carta2.pib_per_capita = calcular_pib_per_capita(carta2.pib, carta2.populacao);

    carta1.super_poder = calcular_super_poder(carta1);
    carta2.super_poder = calcular_super_poder(carta2);

    printf("\nComparação de Cartas:\n\n");

    comparar("População", (float)carta1.populacao, (float)carta2.populacao, 0);
    comparar("Área", carta1.area, carta2.area, 0);
    comparar("PIB", carta1.pib, carta2.pib, 0);
    comparar("Pontos Turísticos", (float)carta1.pontos_turisticos, (float)carta2.pontos_turisticos, 0);
    comparar("Densidade Populacional", carta1.densidade, carta2.densidade, 1); // menor vence
    comparar("PIB per Capita", carta1.pib_per_capita, carta2.pib_per_capita, 0);
    comparar("Super Poder", carta1.super_poder, carta2.super_poder, 0);

    return 0;
}
