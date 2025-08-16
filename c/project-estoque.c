#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <locale.h>

#include <ctype.h>

// Definições de constantes
#define MAX_ITENS 10 // Quantidade máxima de produtos
#define MAX_GASTO 12 // Quantidade maxima de gasto
#define MAX_FUNCIONARIO 50 //Quantidade maxima de funcionários

// Definições de salários
#define operario 2.400 
#define supervisor 6.400
#define gerente 9.600
#define diretor 12.800

// Estrutura para armazenar informações sobre o funcionário
struct Funcionario {
    char nome[50], cpf[12], RG[11], endereco[100], telefone[11], cargo_nome[10];
    int quant_filhos; // Quantidade de filhos
    int cargo; // Cargo do funcionário (índice que corresponde ao cargo)
};

// Estrutura para armazenar dados financeiros
struct finaceiro {
    float agua, luz, salarioF, impostosM;
    int quant_pallets; // Quantidade de pallets
    float totaldespesas; // Total de despesas
    float custoPorPallet; // Custo por pallet
};

// Estrutura para cadastrar produtos
struct cadastrar {
    int codigo; // Código do produto
    char nome[50]; // Nome do produto
    char dataFabricacao[11]; // Data de fabricação
    char fornecedor[50]; // Nome do fornecedor
    int quantidade; // Quantidade disponível
    float valorCompra; // Valor de compra do produto
    char endereco[50]; // Endereço de entrega
};

// Vetor de funcionários e número de funcionários cadastrados
struct Funcionario funcionario[50];
int funcionario_cadastrado = 0;

// Função que gerencia o menu de produtos
void setorproduto(struct cadastrar produto[], int * totalProdutos) {
    int continuar = 1; // Variável de controle para o loop do menu
    int codigoBusca, quantidadeNova; // Variáveis para buscar produtos e adicionar quantidades
    int encontrado, opcaosub; // Variáveis de controle de busca e opções adicionais
    int quantidadeP; // Quantidade para saída de mercadoria

    // Loop que continua até o usuário escolher sair
    while (continuar) {
        int opcao_menuP; // Variável para armazenar a opção escolhida pelo usuário
        printf("\n---[PRODUTO]: Menu ---\n");
        printf("1 - Cadastrar Produto\n");
        printf("2 - Lista de Produtos | Estoque\n");
        printf("3 - Buscar Produto\n");
        printf("4 - Acrescentar - QUANT - Produto\n");
        printf("5 - Saida de Mercadoria\n");
        printf("6 - Entrada de Mercadoria\n");
        printf("7 - Excluir Produto - Cadastrado\n");
        printf("8 - Voltar ao Menu Principal\n");
        printf("Informe a opção desejada:\n");
        scanf("%d", & opcao_menuP); // Lê a opção escolhida pelo usuário
        printf("\n");

        // Switch case para diferentes opções de menu
        switch (opcao_menuP) {
        case 1: // Cadastrar produto
            if ( * totalProdutos <= MAX_ITENS) // Verifica se o número de produtos não ultrapassou o limite
            {
                printf("\n----[ CADASTRAR PRODUTO [%d] ] ----\n", * totalProdutos + 1);
                printf("Digite o código do produto:\n");
                scanf("%d", & produto[ * totalProdutos].codigo); // Lê o código do produto
                printf("Digite o nome do produto:\n");
                scanf(" %49[^\n]", produto[ * totalProdutos].nome); // Lê o nome do produto
                printf("Digite a data de fabricação (dd/mm/yyyy):\n");
                scanf("%s", produto[ * totalProdutos].dataFabricacao); // Lê a data de fabricação
                printf("Digite o nome do fornecedor:\n");
                scanf("%s", produto[ * totalProdutos].fornecedor); // Lê o fornecedor
                printf("Digite a quantidade:\n");
                scanf("%d", & produto[ * totalProdutos].quantidade); // Lê a quantidade do produto
                printf("Digite o valor de compra:\n");
                scanf("%f", & produto[ * totalProdutos].valorCompra); // Lê o valor de compra

                ( * totalProdutos) ++; // Aumenta o número de produtos cadastrados
                printf("Produto cadastrado com sucesso!\n\n");
            } else {
                printf("[ERRO] Limite máximo de produtos atingido (%d). Não é possível cadastrar novos produtos.\n\n", MAX_ITENS);
            }
            break;

        case 2: // Listar produtos
            if ( * totalProdutos == 0) // Verifica se não há produtos cadastrados
            {
                printf("Nenhum produto cadastrado!\n\n");
            } else {
                // Loop que exibe as informações de todos os produtos cadastrados
                for (int i = 0; i < * totalProdutos; i++) {
                    printf("\n----[ PRODUTO [%d] ]----\n", i + 1);
                    printf("Código do Produto: %d\n", produto[i].codigo);
                    printf("Nome do Produto: %s\n", produto[i].nome);
                    printf("Data de Fabricação: %s\n", produto[i].dataFabricacao);
                    printf("Nome do Fornecedor: %s\n", produto[i].fornecedor);
                    printf("Quantidade: %d\n", produto[i].quantidade);
                    printf("Valor do Produto: %.2f\n", produto[i].valorCompra);
                    printf("-----------------------------\n\n");
                }
            }
            break;

        case 3: // Buscar produto
            if ( * totalProdutos == 0) // Verifica se não há produtos cadastrados
            {
                printf("Nenhum produto cadastrado para pesquisar.\n");
                break;
            }

            printf("Digite o código do produto que deseja localizar:\n");
            scanf("%d", & codigoBusca); // Lê o código do produto a ser pesquisado
            encontrado = 0; // Inicializa a variável de controle de produto encontrado

            // Loop para procurar o produto pelo código
            for (int i = 0; i < * totalProdutos; i++) {
                if (produto[i].codigo == codigoBusca) // Verifica se o código corresponde
                {
                    printf("Procurando....Produto...\n\n");
                    printf("\n----[PRODUTO ENCONTRADO]----\n");
                    printf("Código do Produto: %d\n", produto[i].codigo);
                    printf("Nome do Produto: %s\n", produto[i].nome);
                    printf("Data de Fabricação: %s\n", produto[i].dataFabricacao);
                    printf("Nome do Fornecedor: %s\n", produto[i].fornecedor);
                    printf("Quantidade: %d\n", produto[i].quantidade);
                    printf("Valor do Produto: %.2f\n", produto[i].valorCompra);
                    printf("-----------------------------\n\n");
                    encontrado = 1; // Marca que o produto foi encontrado
                    break;
                }
            }

            if (encontrado == 0) // Se o produto não foi encontrado
            {
                printf("Produto com código %d não encontrado.\n\n", codigoBusca);
            }
            break;

        case 4: // Acrescentar quantidade ao produto
            if ( * totalProdutos == 0) // Verifica se há produtos cadastrados
            {
                printf("Nenhum produto cadastrado para atualizar.\n");
                break;
            }

            printf("\nDigite o código do produto:\n");
            scanf("%d", & codigoBusca); // Lê o código do produto
            encontrado = 0; // Inicializa o controle de busca

            // Loop para buscar o produto
            for (int i = 0; i < * totalProdutos; i++) {
                if (produto[i].codigo == codigoBusca) // Verifica se o código corresponde
                {
                    printf("Procurando....Produto...\n\n");
                    printf("Produto com código %d encontrado.\n", codigoBusca);
                    printf("Digite a quantidade adicional para este produto:\n");
                    scanf("%d", & quantidadeNova); // Lê a quantidade a ser adicionada
                    produto[i].quantidade += quantidadeNova; // Atualiza a quantidade do produto
                    printf("Quantidade atualizada com sucesso! Nova quantidade: %d\n\n", produto[i].quantidade);
                    encontrado = 1; // Marca que o produto foi encontrado
                    break;
                }
            }

            if (encontrado == 0) // Se o produto não foi encontrado
            {
                printf("Produto com código %d não encontrado.\n\n", codigoBusca);
            }
            break;

        case 5: // Saida de Mercadoria
            if ( * totalProdutos == 0) // Verifica se não há produtos cadastrados
            {
                printf("Nenhum produto cadastrado para saida de mercadoria.\n");
                break;
            }

            printf("\nDigite o código do produto:\n");
            scanf("%d", & codigoBusca); // Lê o código do produto
            encontrado = 0; // Inicializa o controle de busca

            // Loop para buscar o produto
            for (int i = 0; i < * totalProdutos; i++) {
                if (produto[i].codigo == codigoBusca) // Verifica se o código corresponde
                {
                    encontrado = 1; // Marca que o produto foi encontrado
                    printf("Procurando....Produto...\n\n");
                    printf("Produto com código %d encontrado.\n", codigoBusca);
                    printf("Informe o endereço de envio do produto:\n");
                    scanf(" %49[^\n]", produto[i].endereco); // Lê o endereço de envio
                    printf("Informe a quantidade para saída:\n");
                    scanf("%d", & quantidadeP); // Lê a quantidade a ser enviada

                    if (quantidadeP > produto[i].quantidade) // Verifica se a quantidade é suficiente
                    {
                        printf("Quantidade informada não está disponível no estoque.\n");
                    } else {
                        produto[i].quantidade -= quantidadeP; // Atualiza a quantidade no estoque
                        printf("\n----[PRODUTO SAIDA-ENVIO]----\n");
                        printf("Código do Produto: %d\n", produto[i].codigo);
                        printf("Nome do Produto: %s\n", produto[i].nome);
                        printf("Data de Fabricação: %s\n", produto[i].dataFabricacao);
                        printf("Nome do Fornecedor: %s\n", produto[i].fornecedor);
                        printf("Quantidade para Envio: %d\n", quantidadeP);
                        printf("Quantidade Restante: %d\n", produto[i].quantidade);
                        printf("Valor do Produto: %.2f\n", produto[i].valorCompra * quantidadeP); // Valor total da saída
                        printf("Endereço de Entrega: %s\n", produto[i].endereco);
                        printf("-----------------------------\n\n");
                    }
                    break;
                }
            }

            if (encontrado == 0) // Se o produto não foi encontrado
            {
                printf("Produto com código %d não encontrado.\n\n", codigoBusca);
            }
            break;

        case 6: // Entrada Mercadoria
            if ( * totalProdutos == 0) // Verifica se não há produtos cadastrados
            {
                printf("Nenhum produto cadastrado para entrada de mercadoria\n");
                break;
            }

            printf("Digite o código do produto que deseja armazenar:\n");
            scanf("%d", & codigoBusca); // Lê o código do produto
            encontrado = 0; // Inicializa o controle de busca

            // Loop para buscar o produto
            for (int i = 0; i < * totalProdutos; i++) {
                if (produto[i].codigo == codigoBusca) // Verifica se o código corresponde
                {
                    encontrado = 1; // Marca que o produto foi encontrado
                    printf("Procurando....Produto...\n\n");
                    printf("Produto com código %d encontrado.\n", codigoBusca);
                    printf("\n----[PRODUTO ENTRADA MERCADORIA]----\n");
                    printf("Código do Produto: %d\n", produto[i].codigo);
                    printf("Nome do Produto: %s\n", produto[i].nome);
                    printf("Data de Fabricação: %s\n", produto[i].dataFabricacao);
                    printf("Nome do Fornecedor: %s\n", produto[i].fornecedor);
                    printf("Quantidade: %d\n", produto[i].quantidade);
                    printf("Valor do Produto: %.2f\n", produto[i].valorCompra);
                    printf("-----------------------------\n\n");
                    printf("Deseja aumentar a quantidade desse produto?: (%s) 1-SIM / 2-NAO\n", produto[i].nome);
                    scanf("%d", & opcaosub); // Pergunta se o usuário quer aumentar a quantidade
                    if (opcaosub == 1) // Se a resposta for sim
                    {
                        printf("Digite a quantidade adicional para este produto:\n");
                        scanf("%d", & quantidadeNova); // Lê a quantidade a ser adicionada
                        produto[i].quantidade += quantidadeNova; // Atualiza a quantidade
                        printf("Quantidade atualizada com sucesso! Nova quantidade: %d\n\n", produto[i].quantidade);
                    } else {
                        printf("Produto registrado com sucesso!\n\n");
                    }
                }
            }

            if (encontrado == 0) // Se o produto não foi encontrado
            {
                printf("Produto com código %d ainda não foi cadastrado.\n", codigoBusca);
                printf("Por favor. Cadastre primeiro o produto.\n\n");
            }
            break;

        case 7: // Excluir produto
            if ( * totalProdutos == 0) // Verifica se não há produtos cadastrados
            {
                printf("Nenhum produto cadastrado para excluir.\n");
                break;
            }

            printf("Digite o código do produto que deseja excluir:\n");
            scanf("%d", & codigoBusca); // Lê o código do produto a ser excluído
            encontrado = 0; // Inicializa o controle de busca

            // Loop para procurar o produto
            for (int i = 0; i < * totalProdutos; i++) {
                if (produto[i].codigo == codigoBusca) // Verifica se o código corresponde
                {
                    encontrado = 1; // Marca que o produto foi encontrado

                    // Remover o produto deslocando os itens seguintes
                    for (int j = i; j < * totalProdutos - 1; j++) {
                        produto[j] = produto[j + 1]; // Move os itens para "fechar" o espaço deixado
                    }

                    ( * totalProdutos) --; // Reduz o número de produtos
                    printf("Produto com código %d foi excluído com sucesso.\n", codigoBusca);
                    return;
                }
            }

            if (encontrado == 0) // Se o produto não foi encontrado
            {
                printf("Produto com código %d não encontrado.\n", codigoBusca);
            }
            break;

        case 8: // Voltar ao Menu Principal
            continuar = 0; // Encerra o loop
            break;

        default: // Caso o usuário escolha uma opção inválida
            printf("Opção inválida.\n");
        }
    }
}

// Função que gerencia o setor financeiro
void setorfinaceiro(struct finaceiro gasto[], int * mes) {
    int continuar = 1; // Controla a execução do menu
    while (continuar) {
        int opcao_menuF; // Variável para armazenar a opção do menu
        printf("----[SETOR FINACEIRO]: Menu----\n");
        printf("1 - Informar Valores\n");
        printf("2 - Exibir Gastos\n");
        printf("3 - Pesquisar Gastos de um Mês\n");
        printf("4 - Excluir Gasto de um Mês\n");
        printf("5 - Voltar ao Menu Principal\n");
        printf("Informe a opção desejada:\n");
        scanf("%d", & opcao_menuF); // Lê a opção do menu

        // Switch para selecionar a ação com base na opção escolhida
        switch (opcao_menuF) {
        case 1: // Informar valores dos gastos
            if ( * mes <= MAX_GASTO) // Verifica se ainda há espaço para registrar gastos
            {
                printf("\n----[ DESPESAS MES [%d] ]----\n", * mes + 1);
                // Lê os gastos do mês
                printf("Digite o gasto com agua:\n");
                scanf("%f", & gasto[ * mes].agua);
                printf("Digite o gasto com luz:\n");
                scanf("%f", & gasto[ * mes].luz);
                printf("Digite o gasto com salarios:\n");
                scanf("%f", & gasto[ * mes].salarioF);
                printf("Digite o gasto com impostos:\n");
                scanf("%f", & gasto[ * mes].impostosM);

                // Calcula o total das despesas fixas
                gasto[ * mes].totaldespesas = gasto[ * mes].agua + gasto[ * mes].luz + gasto[ * mes].salarioF + gasto[ * mes].impostosM;
                printf("\nTotal das despesas fixas: R$ %.2f\n\n", gasto[ * mes].totaldespesas);

                // Solicita a quantidade de pallets movimentados no mês
                printf("\nInforme a quantidade de pallets movimentados no mes:");
                scanf("%d", & gasto[ * mes].quant_pallets);

                // Calcula o custo operacional por pallet
                if (gasto[ * mes].quant_pallets > 0) {
                    gasto[ * mes].custoPorPallet = gasto[ * mes].totaldespesas / gasto[ * mes].quant_pallets;
                    printf("\nCusto operacional por pallet: R$ %.2f\n", gasto[ * mes].custoPorPallet);
                } else {
                    printf("Erro: Quantidade de pallets deve ser maior que 0.\n");
                }
                ( * mes) ++; // Avança para o próximo mês
                printf("Gasto do mes [%d] cadastrados!\n\n", * mes);
            } else {
                // Se o limite de gastos foi atingido
                printf("Limite de gastos cadastrados atingido! (%d)\n\n", MAX_GASTO);
            }
            break;

        case 2: // Exibir todos os gastos
            if ( * mes == 0) // Verifica se não há gastos registrados
            {
                printf("Nenhum gasto de mes registrado!\n\n");
            } else {
                // Exibe os gastos de todos os meses registrados
                for (int i = 0; i < * mes; i++) {
                    printf("\n----[ DESPESAS DO MES [%d] ]----\n", i + 1);
                    printf("Gasto com Agua R$: %.2f\n", gasto[i].agua);
                    printf("Gasto com Luz R$: %.2f\n", gasto[i].luz);
                    printf("Gasto com Salarios R$: %.2f\n", gasto[i].salarioF);
                    printf("Gasto com Impostos R$: %.2f\n", gasto[i].impostosM);
                    printf("Quantidade de Pallets: %d\n", gasto[i].quant_pallets);
                    printf("Total de Despesas: R$ %.2f\n", gasto[i].totaldespesas);
                    printf("Custo Operacional por Pallet: R$ %.2f\n", gasto[i].custoPorPallet);
                    printf("-----------------------------\n\n");
                }
            }
            break;

        case 3: // Pesquisar gastos de um mês específico
            if ( * mes == 0) // Se não houver registros
            {
                printf("Nenhum gasto foi registrado ainda.\n\n");
                break;
            }

            int mesBusca; // Variável para armazenar o mês a ser pesquisado
            printf("Digite o número do mês que deseja pesquisar (1 a %d): ", * mes);
            scanf("%d", & mesBusca);

            if (mesBusca < 1 || mesBusca > * mes) // Valida se o mês é válido
            {
                printf("Mês inválido. Escolha entre 1 e %d.\n\n", * mes);
            } else {
                // Exibe os gastos do mês específico
                printf("\n---[GASTOS DO MES] [%d] ---\n", mesBusca);
                printf("Água: R$ %.2f\n", gasto[mesBusca - 1].agua);
                printf("Luz: R$ %.2f\n", gasto[mesBusca - 1].luz);
                printf("Salários: R$ %.2f\n", gasto[mesBusca - 1].salarioF);
                printf("Impostos: R$ %.2f\n", gasto[mesBusca - 1].impostosM);
                printf("Pallets movimentados: %d\n", gasto[mesBusca - 1].quant_pallets);
                printf("Total de despesas: R$ %.2f\n", gasto[mesBusca - 1].totaldespesas);
                printf("Custo operacional por pallet: R$ %.2f\n\n", gasto[mesBusca - 1].custoPorPallet);
            }
            break;

        case 4: // Excluir gastos de um mês específico
            if ( * mes == 0) // Verifica se não há meses registrados
            {
                printf("Nenhum gasto registrado para excluir.\n");
                return;
            }

            printf("Digite o número do mês que deseja excluir (1 a %d):\n", * mes);
            scanf("%d", & mesBusca);

            if (mesBusca < 1 || mesBusca > * mes) // Valida se o mês é válido
            {
                printf("Mês inválido. Escolha entre 1 e %d.\n", * mes);
                return;
            }

            // Remove o gasto do mês especificado, deslocando os itens seguintes
            for (int i = mesBusca - 1; i < * mes - 1; i++) {
                gasto[i] = gasto[i + 1];
            }

            ( * mes) --; // Reduz o número de meses registrados
            printf("Gasto do mês %d foi excluído com sucesso.\n\n", mesBusca);
            break;

        case 5: // Voltar ao menu principal
            continuar = 0; // Finaliza o loop
            break;

        default: // Caso a opção seja inválida
            printf("Opção inválida.\n");
        }
    }
}

// Função para calcular a produção no setor operacional
void setoroperacional() {
    int uni_mes_atual = 10000; // Unidades produzidas no mês atual
    float percent_atual = 30.0; // Percentual de capacidade de produção utilizado
    float capacidade_total = (uni_mes_atual / percent_atual) * 100.0; // Calcula a capacidade total de produção
    float producao_diaria = capacidade_total / 30; // Produção diária com base na capacidade mensal
    float producao_anual = capacidade_total * 12; // Produção anual com base na capacidade mensal

    printf("----[SETOR OPERACIONAL]----\n");
    printf("Capacidade Total de Produção:\n\n");
    printf("Produção diária: %.2f unidades\n", producao_diaria);
    printf("Produção mensal: %.2f unidades\n", capacidade_total);
    printf("Produção anual: %.2f unidades\n", producao_anual);
    printf("--------------------------------\n\n");
}

// Função para calcular o salário de um funcionário com base nas horas extras
void calculo_salario(float salario_hrs, float salario_base) {
    float horas_extras, total_hora_extra = 0, valor_total_extra = 0; // Variáveis para horas extras e valores relacionados
    int dias, horas, minutos;

    printf("Quantos dias o funcionario fez hora extra? Se nao tiver feito, digite 0.\n");
    scanf("%d", & dias);

    if (dias <= 0) // Verifica se o funcionário fez horas extras
    {
        printf("Nao foi feita nenhuma hora extra\n\n");
        return;
    }

    // Loop para cada dia com hora extra
    for (int d = 0; d < dias; d++) {
        printf("-- %d DIA--\nInforme a quantidade de horas extras feitas. Digite somente a Hora.\nHora: ", d + 1);
        scanf("%d", & horas);
        printf("Agora, informe a quantidade em minutos. Se nao tiver, digite 0.\nMinutos: ");
        scanf("%d", & minutos);

        horas_extras = horas + (minutos / 60.0); // Calcula as horas extras em horas
        total_hora_extra += horas_extras; // Soma as horas extras

        // Verifica se a quantidade de horas extras é maior que 2 horas
        if (horas_extras > 2) {
            printf("A quantidade de hora extra foi mais do que 2H, solicite a supervisao para verificar se esta tudo correto!! Depois de ter confirmado com a Supervisao, continue!\n\n");
        }

        int opcao_horas;
        printf("Essa hora extra foi feita em feriado ou final de semana?\n1 - SIM\n2 - NAO\nOpcao: ");
        scanf("%d", & opcao_horas);

        float valor_horas;
        // Calcula o valor da hora extra dependendo de ser feriado ou final de semana
        if (opcao_horas == 1) {
            valor_horas = horas_extras * salario_hrs * 2; // Feriado dobra o valor
            valor_total_extra += valor_horas;
        } else if (opcao_horas == 2) {
            valor_horas = horas_extras * salario_hrs * 1.5; // Final de semana aumenta 50%
            valor_total_extra += valor_horas;
        } else {
            printf("Digite 1 ou 2.\nOpcao: ");
            while (getchar() != '\n') // Limpa o buffer de entrada
            ;
            continue;
        }
        // Exibe as horas extras feitas e o valor calculado para esse dia
        printf("QUANTIDADE DAS HORAS EXTRAS NESTE DIA FORAM: %.2fH\n", horas_extras);
        printf("VALOR DA HORA EXTRA DESTE DIA: R$ %.2f\n\n", valor_horas);
    }
    printf("QUANTIDADE TOTAL DE HORAS EXTRAS: %.2f H\n", total_hora_extra);
    printf("VALOR TOTAL DE HORAS EXTRAS: R$ %.2f\n", valor_total_extra);
    printf("SALARIO BRUTO: R$ %.3f\n", salario_base);

    // Calcula o desconto no salário base dependendo do tipo de funcionário
    if (salario_base == operario) {
        float desconto_salario = ((salario_base * 8) / 100);
        printf("DESCONTO DE SALARIO: R$ %.3f\n", desconto_salario);
        printf("SALARIO LIQUIDO: R$ %.3f\n", (salario_base + valor_total_extra) - desconto_salario);
    } else if (salario_base == supervisor) {
        float desconto_salario = ((salario_base * 15) / 100);
        printf("DESCONTO DE SALARIO: R$ %.3f\n", desconto_salario);
        printf("SALARIO LIQUIDO: R$ %.3f\n", (salario_base + valor_total_extra) - desconto_salario);
    }
}

// Função que exibe todos os funcionários cadastrados
void mostrar_funcionario() {
    // Loop que percorre todos os funcionários cadastrados
    for (int i = 0; i < funcionario_cadastrado; i++) {
        // Exibe as informações do funcionário (Nome, CPF, RG, etc.)
        printf("\n----- [FUNCIONARIO] [%d] ] ------\n", i + 1);
        printf("Nome: %s\n", funcionario[i].nome);
        printf("CPF: %s\n", funcionario[i].cpf);
        printf("RG: %s\n", funcionario[i].RG);
        printf("Endereco: %s\n", funcionario[i].endereco);
        printf("Telefone: %s\n", funcionario[i].telefone);
        printf("Quantidade de filhos: %d\n", funcionario[i].quant_filhos);

        // Exibe o cargo e o salário do funcionário conforme o tipo de cargo
        if (funcionario[i].cargo == 1) {
            printf("Cargo: Operario (R$ %.3f)\n\n", operario);
        } else if (funcionario[i].cargo == 2) {
            printf("Cargo: Supervisor (R$ %.3f)\n\n", supervisor);
        } else if (funcionario[i].cargo == 3) {
            printf("Cargo: Gerente (R$ %.3f)\n\n", gerente);
        } else if (funcionario[i].cargo == 4) {
            printf("Cargo: Diretor (R$ %.3f)\n\n", diretor);
        }
        printf("--------------------------------------\n");
    }
}

// Função que gerencia as opções para o menu de funcionários
void FUNCIONARIO() {
    int continuar = 1;
    int opcao;

    // Loop principal para gerenciar as opções do menu de funcionários
    while (continuar) {
        printf("\n");
        printf("----[SETOR RH]-----\n");
        printf("1 - Cadastrar Funcionario [%d]\n", funcionario_cadastrado);
        printf("2 - Salario do Funcionario\n");
        printf("3 - Lista Funcionario\n");
        printf("4 - Voltar ao Menu Principal\n");
        printf("Informe a opção desejada:\n");
        scanf("%d", & opcao);
        printf("\n");

        // Switch para tratar a escolha do usuário
        switch (opcao) {
        case 1:
            // Cadastro de novo funcionário
            for (int i = funcionario_cadastrado; i < MAX_FUNCIONARIO; i++) {
                setlocale(LC_ALL, "pt_BR.UTF-8");
                printf("======= ESTOQUE CERTO LTDA ======\n");
                printf("------[CADASTRO DE FUNCIONARIO]-----\n\n");
                printf("Digite o nome do funcionário\nNome: ");
                getchar(); // Limpa o buffer
                scanf("%[^\n]", funcionario[i].nome);

                // Cadastro do CPF com validação
                printf("\nDigite o CPF de %s (Digite sem os pontos e traços)\nCPF: ", funcionario[i].nome);
                while (scanf("%12s", funcionario[i].cpf)) {
                    int valido = 1;
                    // Verifica se o CPF contém apenas números
                    for (size_t j = 0; j < strlen(funcionario[i].cpf); j++) {
                        if (!isdigit(funcionario[i].cpf[j])) {
                            valido = 0;
                            break;
                        }
                    }
                    if (strlen(funcionario[i].cpf) != 11 || !valido) {
                        printf("CPF inválido. Digite um CPF com 11 números (sem pontos e traços)\nCPF: ");
                    } else {
                        break; // Se o CPF for válido, sai do loop
                    }
                }

                // Verifica se o CPF já está cadastrado
                for (int j = 0; j < funcionario_cadastrado; j++) {
                    while (strcmp(funcionario[i].cpf, funcionario[j].cpf) == 0) {
                        printf("ESTE CPF JA E DO FUNCIONARIO/A %s, POR FAVOR VERIFIQUE E TENTE NOVAMENTE!\n\n", funcionario[j].nome);
                        while (getchar() != '\n')
                        ;
                        printf("\nDigite o CPF de %s (Digite sem os pontos e traços)\nCPF: ", funcionario[i].nome);
                        scanf("%12s", funcionario[i].cpf);
                        continue;
                    }
                }

                // Cadastro do RG com validação
                printf("\nDigite o RG de %s (Digite sem os pontos e traco)\nRG: ", funcionario[i].nome);
                while (scanf("%11s", funcionario[i].RG)) {
                    int valido = 1;
                    for (size_t j = 0; j < strlen(funcionario[i].RG); j++) {
                        if (!isdigit(funcionario[i].RG[j])) {
                            valido = 0;
                            break;
                        }
                    }
                    if (strlen(funcionario[i].RG) != 10 || !valido) {
                        printf("RG inválido. Digite um RG com 10 números (sem pontos e traços)\nRG: ");
                    } else {
                        break;
                    }
                }

                // Verifica se o RG já está cadastrado
                for (int j = 0; j < funcionario_cadastrado; j++) {
                    while (strcmp(funcionario[i].RG, funcionario[j].RG) == 0) {
                        printf("ESTE RG JA E DO FUNCIONARIO/A %s, POR FAVOR VERIFIQUE E TENTE NOVAMENTE!\n\n", funcionario[j].nome);
                        while (getchar() != '\n')
                        ;
                        printf("\nDigite o RG de %s (Digite sem os pontos e traco)\nRG: ", funcionario[i].nome);
                        scanf("%11s", funcionario[i].RG);
                        continue;
                    }
                }

                // Cadastro de outros dados como endereço, telefone e quantidade de filhos
                printf("\nInforme o endereco que %s mora\nEndereco: ", funcionario[i].nome);
                getchar();
                scanf("%[^\n]", funcionario[i].endereco);
                printf("\nDigite o telefone de %s (Sem o traco. Com o DD e o 9 na frente)\nTelefone: ", funcionario[i].nome);
                while (scanf("%11s", funcionario[i].telefone)) {
                    int valido = 1;
                    for (size_t j = 0; j < strlen(funcionario[i].telefone); j++) {
                        if (!isdigit(funcionario[i].telefone[j])) {
                            valido = 0;
                            break;
                        }
                    }
                    if (strlen(funcionario[i].telefone) != 11 || !valido) {
                        printf("Telefone inválido. Digite um telefone com 11 números (sem traços, com o DD e o '9' na frente)\nTelefone: ");
                    } else {
                        break;
                    }
                }

                // Verifica se o telefone já está cadastrado
                for (int j = 0; j < funcionario_cadastrado; j++) {
                    while (strcmp(funcionario[i].telefone, funcionario[j].telefone) == 0) {
                        printf("ESTE TELEFONE JA E DO FUNCIONARIO/A %s, POR FAVOR VERIFIQUE E TENTE NOVAMENTE!\n\n", funcionario[j].nome);
                        while (getchar() != '\n')
                        ;
                        printf("\nDigite o telefone de %s (Sem o traco. Com o DD e o 9 na frente)\nTelefone: ", funcionario[i].nome);
                        scanf("%11s", funcionario[i].telefone);
                        continue;
                    }
                }

                // Cadastro da quantidade de filhos
                printf("\nInforme a quantidade de filhos que %s tem:\nFilhos: ", funcionario[i].nome);
                while (scanf("%d", & funcionario[i].quant_filhos) != 1) {
                    while (getchar() != '\n')
                    ;
                    printf("Digite em numeros a quantidade de filhos do/a %s\n\n", funcionario[i].nome);
                    printf("\nInforme a quantidade de filhos que %s tem:\nFilhos: ", funcionario[i].nome);
                    
                }

                // Cadastro do cargo
                printf("\n");
                printf("Qual sera o cargo de %s?\n", funcionario[i].nome);
                printf("1 - Operario\n2 - Supervisor\n3 - Gerente\n4 - Diretor\nOpcao: ");
                while (scanf("%d", & funcionario[i].cargo) != 1 || funcionario[i].cargo > 4 || funcionario[i].cargo < 1) {
                    while (getchar() != '\n')
                    ;
                    printf("Digite '1' para operario, '2' para Supervisor, '3' para Gerente e '4' para Diretor\n");
                    printf("1 - Operario\n2 - Supervisor\n3 - Gerente\n4 - Diretor\nOpcao: ");
                }

                printf("\n\n");
                // Exibe os dados do funcionário após o cadastro
                printf("Nome: %s\n", funcionario[i].nome);
                printf("CPF: %s\n", funcionario[i].cpf);
                printf("RG: %s\n", funcionario[i].RG);
                printf("Endereco: %s\n", funcionario[i].endereco);
                printf("Telefone: %s\n", funcionario[i].telefone);
                printf("Quantidade de filhos: %d\n", funcionario[i].quant_filhos);
                if (funcionario[i].cargo == 1) {
                    printf("Cargo: Operario (%.3f)\n\n", operario);
                } else if (funcionario[i].cargo == 2) {
                    printf("Cargo: Supervisor (%.3f)\n\n", supervisor);
                } else if (funcionario[i].cargo == 3) {
                    printf("Cargo: Gerente (%.3f)\n\n", gerente);
                } else if (funcionario[i].cargo == 4) {
                    printf("Cargo: Diretor (%.3f)\n\n", diretor);
                }
                printf("O Funcionario %s foi cadastrado com sucesso!!\n\n", funcionario[i].nome);

                funcionario_cadastrado++; // Incrementa o número de funcionários cadastrados
                break;
            }
            break;

        case 2:
            // Função que exibe o salário do funcionário com base no CPF informado
            if (funcionario_cadastrado == 0) {
                printf("Por Favor. Cadastre um funcionario!\n\n");
                break;
            }
            printf("------[SALARIO DOS FUNCIONARIOS]------\n\n");
            printf("Informe o CPF do funcionario\nCPF: ");
            char cpf_comparacao[12];
            while (scanf("%12s", cpf_comparacao)) // Verificar se o CPF esta sendo escrito corretamente
            {
                int valido = 1;
                for (size_t j = 0; j < strlen(cpf_comparacao); j++) {
                    if (!isdigit(cpf_comparacao[j])) {
                        valido = 0;
                        break;
                    }
                }
                if (strlen(cpf_comparacao) != 11 || !valido) {
                    printf("CPF inválido. Digite um CPF com 11 números (sem pontos e sem os tracos)\nCPF: ");
                } else {
                    break;
                }
            }
            for (int i = 0; i < funcionario_cadastrado; i++) {
                if (strcmp(funcionario[i].cpf, cpf_comparacao) == 0) {
                    printf("Nome: %s\nCPF: %s\n", funcionario[i].nome, funcionario[i].cpf);
                    // Aqui o cálculo do salário varia conforme o cargo do funcionário
                    if (funcionario[i].cargo == 1) // Operário
                    {
                        printf("Cargo: Operário (R$ %.3f)\n\n", operario);
                        calculo_salario(15.00, operario); // Calcula salário de Operário
                    } else if (funcionario[i].cargo == 2) // Supervisor
                    {
                        printf("Cargo: Supervisor (R$ %.3f)\n\n", supervisor);
                        calculo_salario(40.00, supervisor); // Calcula salário de Supervisor
                    } else if (funcionario[i].cargo == 3) // Gerente
                    {
                        printf("Cargo: Gerente (R$ %.3f)\n\n", gerente);
                        printf("Gerente nao tem direito a receber pelas horas extras!!\n\n");
                        printf("SALARIO BRUTO: R$ %.3f\n", gerente);
                        printf("DESCONTO DO SALARIO (15%%): R$ %.3f\n", ((gerente * 15) / 100));
                        printf("SALARIO LIQUIDO: R$ %.3f\n\n", gerente - ((gerente * 15) / 100));
                    } else if (funcionario[i].cargo == 4) // Diretor
                    {
                        printf("Cargo: Diretor (R$ %.3f)\n\n", diretor);
                        printf("Diretor nao tem direito a receber pelas horas extras!!\n\n");
                        printf("SALARIO BRUTO: R$ %.3f\n", diretor);
                        printf("DESCONTO DO SALARIO (15%%): R$ %.3f\n", ((diretor * 15) / 100));
                        printf("SALARIO LIQUIDO: R$ %.3f\n\n", diretor - ((diretor * 15) / 100));
                    }
                    break;
                } else {
                    printf("Nao ha funcionario com este CPF\n\n");
                    break;
                }
            }
            break;
        case 3:
            // Exibe a lista de funcionários cadastrados
            if (funcionario_cadastrado == 0) {
                printf("Nenhum funcionario cadastrado!\n\n");
            }
            mostrar_funcionario();
            break;
        case 4:
            continuar = 0; // Sai do loop
            break;
        default:
            printf("Opção inválida.\n");
            while (getchar() != '\n')
            ;
            break;
        }
    }
}

int main() {
    // Declaração das variáveis e estruturas
    struct finaceiro gasto[MAX_GASTO]; // Estrutura para armazenar informações do setor financeiro
    struct cadastrar produto[MAX_ITENS]; // Estrutura para armazenar informações dos produtos
    int totalProdutos = 0; // Variável para contar o número de produtos cadastrados
    int mes = 0; // Variável para representar o mês atual no setor financeiro
    int opcao; // Variável para armazenar a escolha do usuário
    setlocale(LC_ALL, "Portuguese"); // Define a localização para português

    // Loop principal que exibe o menu e permite interação contínua
    do {
        // Exibe o menu principal
        printf("\n--- Sistema Estoque Certo Ltda: Menu ---\n");
        printf("1 - Produtos : Cadastrar Produtos [%d] | Pesquisar Produtos | Entrada/Saida - Mercadoria | Estoque \n", totalProdutos);
        printf("2 - Setor Finaceiro\n");
        printf("3 - Setor Operacional\n");
        printf("4 - Setor RH | Funcionario\n");
        printf("5 - Sair Sistema\n");
        printf("Informe a opção desejada:\n");
        scanf("%d", & opcao); // Lê a opção escolhida pelo usuário
        printf("\n");

        // Verifica qual opção foi escolhida e executa o respectivo caso
        switch (opcao) {
        case 1:
            // Chama a função para gerenciar o setor de produtos
            setorproduto(produto, & totalProdutos);
            break;
        case 2:
            // Chama a função para gerenciar o setor financeiro
            setorfinaceiro(gasto, & mes);
            break;
        case 3:
            // Chama a função para gerenciar o setor operacional
            setoroperacional();
            break;
        case 4:
            // Chama a função para gerenciar o setor de funcionários
            FUNCIONARIO();
            break;
        case 5:
            // Caso o usuário escolha 5, o sistema será encerrado
            printf("Saindo do sistema...\n");
            break;
        default:
            // Caso o usuário insira uma opção inválida
            printf("Opção inválida.\n");
        }
    } while (opcao != 5); // O loop continua até que o usuário escolha a opção de sair (5)

    return 0; // Retorna 0, indicando que o programa terminou com sucesso
}