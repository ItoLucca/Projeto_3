#include <stdio.h>
#include <string.h>
#include "projeto_3.h"

int main(){
    lista_contatos Lista[MAX_CONTATOS];
    int opcao;
    int cod;

    cod = Carregar_Tarefa(Lista, &Contador_tarefas);  //utiliza da funcao "Carregar_Tarefa" para carregar as tarefas feitas dentro do programa.
    if(cod == 1){  //a condicao so sera realizada quando o "cod" for igual a "1".
        Contador_tarefas = 0;
    }

    do{
        printf("Bem vindo a sua agenda de Contatos!! \n");
        printf("Digite uma das opcoes abaixo: \n");

        printf("\n ---> 1. Adicionar Contatos\n");
        printf("\n ---> 2. Listar os Contatos\n");
        printf("\n ---> 3. Deletar Contato\n");
        printf("\n ---> 0. Finalizar programa\n");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                Adicionar_contatos(Lista, &Contador_tarefas);
                break;

            case 2:
                Listar_contatos(Lista, &Contador_tarefas);
                break;

            case 3:
                Deletar_contatos(Lista, &Contador_tarefas);
                break;

            case 0:
                cod = Salvar_Tarefa(Lista, &Contador_tarefas);
                if (cod != 0) {
                    printf("Erro ao salvar as tarefas.\n");
                }
                printf("u");
            break;
        }

    }while(opcao = 0);


    return 0;
}