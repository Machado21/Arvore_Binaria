//
// Created by Gabriel Machado on 23/03/2019.
//

#ifndef ARVORE_BINARIA_STRUCTS_H
#define ARVORE_BINARIA_STRUCTS_H

#endif //ARVORE_BINARIA_STRUCTS_H

typedef struct no {
    char infor;
    struct no *esq;
    struct no *dir;
} Nodo;

typedef struct arv_bin {
    Nodo *raiz;
} Arv_bin;

typedef struct fila {
    struct elemento *inicio;
    struct elemento *final;
} Fila;

typedef struct elemento {
    Nodo nodo;
    struct elemento *prox;
} Elemento;

Fila *fila;