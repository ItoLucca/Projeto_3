#include <string.h>
#include <stdio.h>
#include "projeto_3.h"

int Adicionar_contatos(lista_contatos Lista[], int *contador_tarefas){
    if(*contador_tarefas < MAX_CONTATOS){
        printf("\nDigite o seu nome: \n");
        scanf("%s", Lista[*contador_tarefas].nome);

        printf("digite o seu sobrenome: \n");
        scanf("%s", Lista[*contador_tarefas].sobrenome);

        printf("digite o seu email: \n");
        scanf("%s", Lista[*contador_tarefas].email);

        printf("digite novamente seu email: \n");
        scanf("%s", Lista[*contador_tarefas].revalida);        

        if(strcmp(Lista[*contador_tarefas].email, Lista[*contador_tarefas].revalida) == 0){
            printf("digite o seu telefone: \n");
            scanf("%s", Lista[*contador_tarefas].telefone);

            
            for(int i = 0; i < *contador_tarefas; i++){
                if(strcmp(Lista[*contador_tarefas].telefone, Lista[i].telefone) == 0){
                    printf("\nEste telefone ja esta sendo usado.. \n");
                    return 0; 
                }
            }

            
            printf("____Contato salvo com sucesso!!____ \n");
            (*contador_tarefas)++;
            return 1;

        } else {
            printf("\nOs emails nao correspondem.. \n");
        }

    } else {
        printf("\nA lista esta cheia.. \n");
    }
    return 0;
}

int Listar_contatos(lista_contatos Lista[], int *contador_tarefas){
    if(*contador_tarefas > 0){
        printf("\n--> Lista de tarefas: \n");

        for(int i = 0 ; i < *contador_tarefas ; i++){
            printf("\n Tarefa: %d\n", i + 1);
            printf(" --> Nome: %s\n", Lista[i].nome);
            printf(" --> Sobreome: %s\n", Lista[i].nome);
            printf(" --> Email: %s\n", Lista[i].email);
            printf(" --> Telefone: %s\n", Lista[i].telefone);
        }
    }
    else{
        printf("A lista está vazia.. \n");
        printf("\n");
        return 0;
    }
}

int Deletar_contatos(lista_contatos Lista[], int *contador_tarefas){
    char telefone_deletar[MAX_TELEFONE];
    
    if(*contador_tarefas > 0){
        printf("Digite o telefone referente a conta a ser deletada: \n");
        scanf("%s", telefone_deletar);
        
        for (int i = 0; i < *contador_tarefas; i++) {
            if (strcmp(telefone_deletar, Lista[i].telefone) == 0) {
                for (int j = i; j < *contador_tarefas - 1; j++) {
                    Lista[j] = Lista[j + 1];
                }
                (*contador_tarefas)--;
                printf("____Contato deletado com sucesso!!____\n");
                return 1;
            }
            else{
                printf("\nO telefone inserido nao bate com nenhum numero no sistema.. \n");
                return 0;
            }
        }
    }
    else{
        printf("\nA lista está vazia!! \n");
    }
}


int Alterar_contatos(lista_contatos Lista[], int *contador_tarefas){
    char email_alterar[MAX_EMAIL];
    char telefone_alterar[MAX_TELEFONE];

    if(*contador_tarefas > 0){
        printf("\nDigite as suas informacoes para realizarmos a alteracao desejada: ");

        printf("\nDigite seu email: ");
        scanf("%s", email_alterar);

        printf("\nDigite seu telefone: ");
        scanf("%s", telefone_alterar);

        for(int i = 0 ; i < *contador_tarefas ; i ++){
            if(strcmp(email_alterar, Lista[i].email) == 0 && strcmp(telefone_alterar, Lista[i].telefone) == 0){
                
                printf("\nDigite o novo nome: ");
                scanf("%s", Lista[i].nome);

                printf("\nDigite o novo sobrenome: ");
                scanf("%s", Lista[i].sobrenome);

                printf("\nDigite o novo email: ");
                scanf("%s", Lista[i].email);

                printf("\nDigite o novo telefone: ");
                scanf("%s", Lista[i].telefone);

                for(int j = 0 ; j < *contador_tarefas ; j++){
                     
                }

            }
        }

    }
}


int Salvar_contatos(lista_contatos Lista[], int *contador_tarefas){
    FILE *f = fopen("Agenda.bin", "wb");
    if(f == NULL){
        return 1;
    }
    else{
        fwrite(&contador_tarefas, sizeof(int), 1, f); 
        fwrite(Lista, sizeof(lista_contatos), (size_t) contador_tarefas, f);
        fclose(f);
    }
    return 0;
}

int Carregar_contatos(lista_contatos Lista[], int *contador_tarefas){
    FILE *f = fopen("Agenda.bin", "rb");
    if(f == NULL){
        printf("\nA lista esta vazia..  \n");
        return 1;
    }
    else{
        fread(contador_tarefas, sizeof(int), 1, f);  
        fread(Lista, sizeof(lista_contatos), (size_t) *contador_tarefas, f);        
        fclose(f);
    }
    return 0;
}

