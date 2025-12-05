#include <stdio.h>
#include <string.h> // Incluído conforme solicitado

// // ### 1. Definição da Struct 'Territorio'
// A struct agrupa dados relacionados (nome, cor, tropas) sob um único tipo.
typedef struct {
    char nome[30];  // Nome do território (máx. 29 caracteres + '\0')
    char cor[10];   // Cor do exército (máx. 9 caracteres + '\0')
    int tropas;     // Quantidade de tropas
} Territorio;

int main() {
    // ### 2. Declaração do Vetor de Structs
    // Cria um vetor com capacidade para armazenar 5 estruturas do tipo Territorio.
    Territorio lista_territorios[5];
    int i;

    // --- Cadastro dos Dados ---
    printf("==========================================\n");
    printf("   CADASTRO DE 5 TERRITÓRIOS\n");
    printf("==========================================\n");

    // ### 3. Entrada dos Dados (Loop de Cadastro)
    // O laço 'for' itera 5 vezes para preencher os dados de cada território.
    for (i = 0; i < 5; i++) {
        printf("\n--- Território %d ---\n", i + 1);

        // **Requisito Não Funcional: Usabilidade (mensagens claras)**
        printf("Digite o NOME do território: ");
        // Usamos scanf("%s") para strings simples, pois fomos orientados a usá-lo com cuidado.
        // Ele lê até o primeiro espaço em branco, o que é aceitável para um nome de território.
        if (scanf("%s", lista_territorios[i].nome) != 1) {
            // Tratamento de erro básico
            fprintf(stderr, "Erro ao ler o nome.\n");
            break;
        }

        printf("Digite a COR do exército: ");
        if (scanf("%s", lista_territorios[i].cor) != 1) {
            fprintf(stderr, "Erro ao ler a cor.\n");
            break;
        }

        printf("Digite a QTD de tropas (número inteiro): ");
        if (scanf("%d", &lista_territorios[i].tropas) != 1) {
            fprintf(stderr, "Erro ao ler a quantidade de tropas.\n");
            // Limpa o buffer de entrada para evitar loop infinito em caso de entrada não-numérica
            while (getchar() != '\n'); 
            i--; // Tenta ler o mesmo território novamente
            continue;
        }
    }
    
    // --- Exibição dos Dados ---
    printf("\n==========================================\n");
    printf("   DADOS DOS TERRITÓRIOS CADASTRADOS\n");
    printf("==========================================\n");

    // ### 4. Exibição (Loop de Saída)
    // O laço 'for' percorre o vetor e exibe os dados de cada struct.
    for (i = 0; i < 5; i++) {
        printf("\nTerritório %d:\n", i + 1);
        printf("  Nome: %s\n", lista_territorios[i].nome);
        printf("  Cor: %s\n", lista_territorios[i].cor);
        printf("  Tropas: %d\n", lista_territorios[i].tropas);
    }

    printf("\nCadastro concluído e dados exibidos com sucesso.\n");

    return 0;
}
