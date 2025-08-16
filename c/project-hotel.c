#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cadastro {
    char nome[50];
    int tipoquarto;
    int diaria;
    int cama;
    long long int cpf, telefone;
    float total_servicos;
    int numeroquarto;
};

void cadastrarhospedes(struct cadastro hospedes[], int *i, int *quartos_disponiveis) {
    int servico;
    float executivo = 150;
    float deluxe = 250;
    int continuar = 1;
    int opcao_servico;
    float alimentacao = 30;
    float wifi = 10;
    float limpeza = 20;
    float lazer = 100;
    float bar = 50;
    float turismo = 80;
    float carro_particula = 100;
    float passeios_personalizados = 150;
    float experiencia_culinaria = 250;

    if (*quartos_disponiveis > 0) {
        printf("---Cadastro Hospedes:--- [%d]\n", *i + 1);
        printf("--------------------------------\n");
        printf("Informe seu nome:\n");
        fgets(hospedes[*i].nome, 50, stdin);
        hospedes[*i].nome[strcspn(hospedes[*i].nome, "\n")] = '\0';

        printf("Informe seu CPF:\n");
        scanf("%lld", &hospedes[*i].cpf);

        printf("Informe seu numero de celular:\n");
        scanf("%lld", &hospedes[*i].telefone);
        printf("\n");

        printf("Informe a categoria do seu quarto:\n");
        printf("----------------------------------------\n");
        printf("1-Executivo R$[%.2f]\n", executivo);
        printf("2-Deluxe R$[%.2f]\n", deluxe);
        printf("3-Executivo + Deluxe R$[%.2f]\n", executivo + deluxe);
        printf("Informe abaixo:\n");
        scanf("%d", &hospedes[*i].tipoquarto);
        getchar();
        printf("\n");

        switch (hospedes[*i].tipoquarto) {
            case 1:
                printf("Selecionou Executivo:\n");
                printf("Informe numero do Quarto:\n");
                scanf("%d",&hospedes[*i].numeroquarto);
                printf("Informe seu tipo de cama:\n");
                printf("1-Solteiro\n");
                printf("2-Casal\n");
                printf("Informe Abaixo:\n");
                scanf("%d", &hospedes[*i].cama);
                
                printf("Informe quantos dias de diaria:\n");
                scanf("%d", &hospedes[*i].diaria);
                hospedes[*i].total_servicos = 0;

                printf("Deseja um servico adicional? 1-Sim / 2-Nao\n");
                scanf("%d", &servico);
                printf("\n\n");

                if (servico == 1) {
                    while (continuar) {
                        printf("Servicos Disponiveis:\n");
                        printf("--------------------------------------------\n");
                        printf("1- Cafe da Manha / Almoço / Jantar R$ [%.2f]\n", alimentacao);
                        printf("2- Limpeza de Quarto R$ [%.2f]\n", limpeza);
                        printf("3- Wifi R$ [%.2f]\n", wifi);
                        printf("4- Finalizar Escolha de Servicos\n");
                        printf("Informe abaixo:\n");
                        scanf("%d", &opcao_servico);

                        switch (opcao_servico) {
                            case 1:
                                printf("Escolheu Cafe da Manha / Almoço / Jantar. Preco: R$ [%.2f]\n", alimentacao);
                                hospedes[*i].total_servicos += alimentacao;
                                printf("Adicionado ao total: %.2f R$\n\n", hospedes[*i].total_servicos);
                                printf("\n");
                                break;
                            case 2:
                                printf("Escolheu Limpeza de Quarto. Preco: R$ [%.2f]\n", limpeza);
                                hospedes[*i].total_servicos += limpeza;
                                printf("Adicionado ao total: %.2f R$\n\n", hospedes[*i].total_servicos);
                                printf("\n");
                                break;
                            case 3:
                                printf("Escolheu Wifi. Preco: R$[%.2f]\n", wifi);
                                hospedes[*i].total_servicos += wifi;
                                printf("Adicionado ao total: %.2f R$\n\n", hospedes[*i].total_servicos);
                                printf("\n");
                                break;
                            case 4:
                                continuar = 0;
                                break;
                            default:
                                printf("Opcao invalida.\n");
                        }
                    }
                }
                break;

            case 2:
                printf("Selecionou Deluxe:\n");
                printf("Informe numero do Quarto:\n");
                scanf("%d",&hospedes[*i].numeroquarto);
                printf("Informe seu tipo de cama:\n"); 
                printf("1-Solteiro\n");
                printf("2-Casal\n");
                printf("Informe Abaixo:\n");
                scanf("%d", &hospedes[*i].cama);
                
                printf("Informe quantos dias de diaria:\n");
                scanf("%d", &hospedes[*i].diaria);
                hospedes[*i].total_servicos = 0;

                printf("Deseja um servico adicional? 1-Sim / 2-Nao\n");
                scanf("%d", &servico);
                printf("\n\n");

                if (servico == 1) {
                    while (continuar) {
                        printf("Servicos Disponiveis:\n");
                        printf("--------------------------------------------\n");
                        printf("Alimentação / Wifi / Limpeza de Quarto - Inclusos no Pacote\n");
                        printf("1- Academia / Spa / Sauna / Piscina R$ [%.2f]\n", lazer);
                        printf("2- Bar R$ [%.2f]\n", bar);
                        printf("3- Guia Turismo R$ [%.2f]\n", turismo);
                        printf("4- Finalizar Escolha de Servicos\n");
                        printf("Informe abaixo:\n");
                        scanf("%d", &opcao_servico);

                        switch (opcao_servico) {
                            case 1:
                                printf("Escolheu Academia / Spa / Sauna / Piscina. Preco: R$ [%.2f]\n", lazer);
                                hospedes[*i].total_servicos += lazer;
                                printf("Adicionado ao total: %.2f R$\n\n", hospedes[*i].total_servicos);
                                printf("\n");
                                break;
                            case 2:
                                printf("Escolheu Bar. Preco: R$ [%.2f]\n", bar);
                                hospedes[*i].total_servicos += bar;
                                printf("Adicionado ao total: %.2f R$\n\n", hospedes[*i].total_servicos);
                                printf("\n");
                                break;
                            case 3:
                                printf("Escolheu Guia Turismo. Preco: R$[%.2f]\n", turismo);
                                hospedes[*i].total_servicos += turismo;
                                printf("Adicionado ao total: %.2f R$\n\n", hospedes[*i].total_servicos);
                                printf("\n");
                                break;
                            case 4:
                                continuar = 0;
                                break;
                            default:
                                printf("Opcao invalida.\n");
                        }
                    }
                }
                break;

            case 3:
                printf("Selecionou Executivo + Deluxe:\n");
                printf("Informe Numero do Quarto:\n");
                scanf("%d",&hospedes[*i].numeroquarto);
                printf("Informe seu tipo de cama:\n");
                printf("1-Solteiro\n");
                printf("2-Casal\n");
                printf("Informe Abaixo:\n");
                scanf("%d", &hospedes[*i].cama);

                printf("Informe quantos dias de diaria:\n");
                scanf("%d", &hospedes[*i].diaria);
                hospedes[*i].total_servicos = 0;

                printf("Deseja um servico adicional? 1-Sim / 2-Nao\n");
                scanf("%d", &servico);
                printf("\n\n");

                if (servico == 1) {
                    while (continuar) {
                        printf("Servicos Disponiveis:\n");
                        printf("--------------------------------------------\n");
                        printf("Alimentação / Wifi / Limpeza de Quarto - Inclusos no Pacote\n");
                        printf("Incluso Pacote de Lazer - Bar / Guia Turismo - Incluso no Pacote\n");
                        printf("1- Carro Particula R$ [%.2f]\n",carro_particula);
                        printf("2- Passeios Personalizados R$ [%.2f]\n",passeios_personalizados);
                        printf("3- Experiencia Culinaria R$ [%.2f]\n", experiencia_culinaria);
                        printf("4- Finalizar Escolha de Servicos\n");
                        printf("Informe abaixo:\n");
                        scanf("%d", &opcao_servico);

                        switch (opcao_servico) {
                            case 1:
                                printf("Escolheu Carro Particula. Preco: R$[%.2f]\n",carro_particula);
                                hospedes[*i].total_servicos += carro_particula;
                                printf("Adicionado ao total: %.2f R$\n\n", hospedes[*i].total_servicos);
                                printf("\n");
                                break;
                            case 2:
                                printf("Escolheu Passeios Personalizados. Preco: R$[%.2f]\n",passeios_personalizados);
                                hospedes[*i].total_servicos += passeios_personalizados;
                                printf("Adicionado ao total: %.2f R$\n\n", hospedes[*i].total_servicos);
                                printf("\n");
                                break;
                            case 3:
                                printf("Escolheu Experiencia Culinaria. Preco: R$[%.2f]\n",experiencia_culinaria);
                                hospedes[*i].total_servicos += experiencia_culinaria;
                                printf("Adicionado ao total: %.2f R$\n\n", hospedes[*i].total_servicos);
                                printf("\n");
                                break;
                            case 4:
                                continuar = 0;
                                break;
                            default:
                                printf("Opcao invalida.\n");
                        }
                    }
                }
                break;

            default:
                printf("Opcao invalida.\n");
                return;
        }

        (*i)++;
        (*quartos_disponiveis)--;
    } else {
        printf("Limite de Hospedes cadastrados atingido!\n");
    }
}

void listar_hospedes(struct cadastro hospedes[], int i) {
    if (i == 0) {
        printf("Nenhum hospede cadastrado.\n\n");
        return;
    }

    printf("---Lista de Hospedes---\n");
    printf("--------------------------------\n");
    for (int j = 0; j < i; j++) {
        float preco_quarto = (hospedes[j].tipoquarto == 1) ? 150 : (hospedes[j].tipoquarto == 2) ? 250 : (150 + 250);
        printf("Hospede- Quarto[%d]\n", hospedes[j].numeroquarto);
        printf("Nome: %s\n", hospedes[j].nome);
        printf("CPF: %lld\n", hospedes[j].cpf);
        printf("Telefone: %lld\n", hospedes[j].telefone);

        printf("Tipo de Quarto: ");
        if (hospedes[j].tipoquarto == 1)
            printf("Executivo\n");
        else if (hospedes[j].tipoquarto == 2)
            printf("Deluxe\n");
        else
            printf("Executivo + Deluxe\n");

        printf("Diarias: %d\n", hospedes[j].diaria);

        printf("Cama: ");
        if (hospedes[j].cama == 1)
            printf("Solteiro\n");
        else
            printf("Casal\n");

        printf("Servicos Adicionais: R$ %.2f\n", hospedes[j].total_servicos);
        printf("Total a Pagar: R$ %.2f\n", hospedes[j].diaria * preco_quarto + hospedes[j].total_servicos);
        printf("--------------------------------\n\n");
    }
}

void desocupar_quarto(struct cadastro hospedes[], int *i, int *quartos_disponiveis) {
    long long int cpf;
    int encontrado = 0;

    printf("Informe o CPF do hospede para desocupar o quarto:\n");
    scanf("%lld", &cpf);

    for (int j = 0; j < *i; j++) {
        if (hospedes[j].cpf == cpf) {
            printf("Quarto do hospede %s foi desocupado.\n", hospedes[j].nome);
            printf("\n");
            hospedes[j] = hospedes[*i - 1];

            (*i)--;
            (*quartos_disponiveis)++;
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Hospede com CPF %lld nao encontrado.\n", cpf);
    }
}

void localizar_quarto(struct cadastro hospedes[], int i) {
    int procurar_quarto;
    int encontrado = 0;

    printf("Informe o numero do quarto do hospede para localizar:\n");
    scanf("%d", &procurar_quarto);
    printf("\n");

    for (int j = 0; j < i; j++) {
        if (hospedes[j].numeroquarto == procurar_quarto) {
            printf("Procurando... Hospede:\n");
            printf("------------------------------\n");
            printf("Hospede encontrado:\n");
            printf("Nome: %s\n", hospedes[j].nome);
            printf("Telefone: %lld\n", hospedes[j].telefone);
            
            printf("Tipo de Quarto: ");
        if (hospedes[j].tipoquarto == 1)
            printf("Executivo\n");
        else if (hospedes[j].tipoquarto == 2)
            printf("Deluxe\n");
        else
            printf("Executivo + Deluxe\n");

            printf("Numero de Diarias: %d\n", hospedes[j].diaria);
            printf("Tipo de Cama: %d\n", hospedes[j].cama);
            printf("Total de Servicos: R$ %.2f\n", hospedes[j].total_servicos);
            printf("-----------------------------------------------------------\n");
            encontrado = 1;
            
        }
    }

    if (!encontrado) {
        printf("Procurando....Hospede do quarto %d nao encontrado.\n", procurar_quarto);
    }
}

int main() {
    struct cadastro hospedes[25];
    int opcao;
    int i = 0;
    int quartos_disponiveis = 25;

    do {
        printf("\n");
        printf("-----HOTEL FASANO-----: Menu\n");
        printf("1-Cadastro de Hospedes - [%d] - Quartos Disponiveis[%d]\n", i, quartos_disponiveis);
        printf("2-Lista de Clientes\n");
        printf("3-Desocupar Quarto\n");
        printf("4-Localizar Hospedes\n");
        printf("5-Sair\n");
        printf("Informe a opcao:\n");
        scanf("%d", &opcao);
        getchar();
        printf("\n");
        
        while(opcao>5){
            printf("Por Favor. Informe um numero de 1 a 5\n\n");
            printf("\n");
            printf("-----HOTEL FASANO-----: Menu\n");
            printf("1-Cadastro de Hospedes - [%d] - Quartos Disponiveis[%d]\n", i, quartos_disponiveis);
            printf("2-Lista de Clientes\n");
            printf("3-Desocupar Quarto\n");
            printf("4-Localizar Hospedes\n");
            printf("5-Sair\n");
            printf("Informe a opcao:\n");
            scanf("%d", &opcao);
            getchar();
            printf("\n");
        }

        switch (opcao) {
            case 1:
                cadastrarhospedes(hospedes, &i, &quartos_disponiveis);
                break;
            case 2:
                listar_hospedes(hospedes, i);
                break;
            case 3:
                desocupar_quarto(hospedes, &i, &quartos_disponiveis);
                break;
            case 4:
                localizar_quarto(hospedes,i);
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 5);

    return 0;
}
