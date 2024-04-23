#ifndef PROJETO_3_CONTATOS_H
#define PROJETO_3_CONTATOS_H

#define MAX_CONTATOS 255
#define MAX_NOME 30
#define MAX_SOBRENOME 30
#define MAX_EMAIL 50
#define MAX_TELEFONE 15 

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