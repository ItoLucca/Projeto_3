#include <stdio.h>
#include "projeto_3.h"

int Adicionar_contatos(lista_contatos Lista[], int *Contador_tarefas){
    if(*Contador_tarefas < MAX_CONTATOS){
        printf("digite o seu nome: \n");
        scanf("%s", Lista[*Contador_tarefas].nome);

        printf("digite o seu sobrenome: \n");
        scanf("%s", Lista[*Contador_tarefas].sobrenome);

        printf("digite o seu email: \n");
        scanf("%s", Lista[*Contador_tarefas].email);

        printf("digite o seu telefone: \n");
        scanf("%s", Lista[*Contador_tarefas].telefone);

        printf("____Contato salvo com sucesso!!____ \n");

        *Contador_tarefas = *Contador_tarefas + 1;
        return 1;
    }
}

int Listar_contatos(lista_contatos Lista[], int *Contador_tarefas){
    if(*Contador_tarefas > 0){
        printf("--> Lista de tarefas: \n");

        for(int i = 0 ; i <= *Contador_tarefas ; i++){
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

int Deletar_contatos(lista_contatos Lista[], int *Contador_tarefas){
    char telefone_deletar[MAX_TELEFONE];
    
    if(*Contador_tarefas > 0){
        printf("Digite o telefone referente a conta a ser deletada: \n");
        scanf("%s", &telefone_deletar);
        
        for(int i = 0 ; i < *Contador_tarefas ; i++){
            if(strcmp(telefone_deletar, Lista[i].telefone) == 0){
                for (int j = i; j < *Contador_tarefas - 1; j++) {
                    Lista[j] = Lista[j + 1];
                }
                printf("-____-Contato deletado com sucesso!!-____-\n");
                (*Contador_tarefas)--;
                break;
            }
        }
    }
    else{
        printf("A lista está vazia!! \n");
    }
}

int Salvar_contatos(lista_contatos Lista[], int *Contador_tarefas){
    FILE *f = fopen("Agenda.bin", "wb");
    if(f == NULL){
        return 1;
    }
    else{
        fwrite(Lista, sizeof(lista_contatos), *Contador_tarefas, f);
        fclose(f);
    }
    return 0;
}

int Carregar_contatos(lista_contatos Lista[], int *Contador_tarefas){
    FILE *f = fopen("Lista.bin", "rb");
    if(f == NULL){
        return 1;
    }
    else{
        fread(Lista, sizeof(lista_contatos), MAX_CONTATOS, f);
        fclose(f);
    }
    return 0;
}
