#ifndef PROJETO_3_CONTATOS_H
#define PROJETO_3_CONTATOS_H

#define MAX_CONTATOS 255
#define MAX_NOME 15
#define MAX_SOBRENOME 15
#define MAX_EMAIL 50
#define MAX_TELEFONE 12 

int *Contador_tarefas;

typedef struct{
    char nome[MAX_NOME];
    char sobrenome[MAX_NOME];
    char email[MAX_EMAIL];
    char telefone[MAX_TELEFONE];
} lista_contatos;

int Adicionar_contatos(lista_contatos Lista[], int *Contador_tarefas);
int Listar_contatos(lista_contatos Lista[], int *Contador_tarefas);
int Deletar_contatos(lista_contatos Lista[], int *Contador_tarefas);
int Salvar_contatos(lista_contatos Lista[], int *Contador_tarefas);
int Carregar_contatos(lista_contatos Lista[], int *Contador_tarefas);

#endif //PROJETO_3_CONTATOS_H