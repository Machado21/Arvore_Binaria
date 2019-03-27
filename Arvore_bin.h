//
// Created by Gabriel Machado on 13/03/2019.
//


#ifndef ARVORE_BINARIA_ARVORE_BIN_H
#define ARVORE_BINARIA_ARVORE_BIN_H

#endif //ARVORE_BINARIA_ARVORE_BIN_H


typedef struct no {
    char infor;
    struct no *esq;
    struct no *dir;
} Nodo;

typedef struct arv_bin {
    struct no *raiz;
} Arv_bin;


Arv_bin *arv_cria(Nodo *raiz);

Nodo *arv_cria_no(char infor, Nodo *esq, Nodo *dir);

void arv_libera(Arv_bin *raiz);

void no_libera(Nodo *no);

int arv_pertence(Arv_bin *arv, char valor);

int no_pertence(Nodo *raiz, char valor);

Arv_bin *arv_busca(Arv_bin *arv, char valor);

Nodo *no_busca(Nodo *no, char valor);

int altura_arv(Arv_bin *raiz);

int altura_no(Nodo *no);

int maior(int esq, int dir);

int tamanho_arv(Arv_bin *arv);

int tamanho(Nodo *no);

//void largura(Nodo *arv, struct fila *fila);

void inprime_escolhendo_ordem(Arv_bin *arv);

void pre(Nodo *no);

void in(Nodo *no);

void pos(Nodo *no);

void arv_imprime_formatado(Arv_bin *arv);

void arv_imprime_formatado_no(Nodo *raiz);