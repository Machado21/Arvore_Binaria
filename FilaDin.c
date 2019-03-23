//
// Created by gabri on 23/03/2019.
//

#include <stdlib.h>
#include "FilaDin.h"

Fila *cria_fila() {
    Fila *fila = (Fila *) malloc(sizeof(Fila));
    if (fila != NULL) {
        fila->final = NULL;
        fila->inicio = NULL;
    }
    return fila;
}

void libera_fila(Fila *fila) {
    if (fila != NULL) {
        Elemento *no;
        while (fila->inicio != NULL) {
            no = fila->inicio;
            fila->inicio = fila->inicio->prox;
            free(no);
        }
        free(fila);
    }
}

int tamanho_fila(Fila *fila) {
    if (fila == NULL) return 0;
    int cont = 0;
    Elemento *no = fila->inicio;
    while (no != NULL) {
        cont++;
        no = no->prox;
    }
    return cont;
}

int insere_fila(Fila *fila, Nodo nodo) {
    if (fila == NULL) return 0; //A Fila não foi Criada.
    Elemento *no = (Elemento *) malloc(sizeof(Elemento));
    if (no == NULL) return 0; //Caso não seja possivel alocar um novo Nodo da fila.
    no->nodo = nodo;
    no->prox = NULL;

    if (fila->final == NULL) {
        fila->inicio = no;
    } else {
        fila->final->prox = no;
    }
    fila->final = no;
    return 1;
}

int remove_fila(Fila *fila) {
    if (fila == NULL) return 0;
    if (fila->inicio == NULL) return 0;

    Elemento *no = fila->inicio;
    fila->inicio = fila->inicio->prox;
    if (fila->inicio == NULL) {
        fila->final = NULL;
    }
    free(no);
    return 1;
}

int condulta_fila(Fila *fila, Nodo *nodo){
    if (fila == NULL) return 0;
    if (fila->inicio  == NULL) return 0;
    *nodo = fila->inicio->nodo;
    return 1;
}

int fila_cheia(Fila fila) {
    return 0;
}

int fila_vazia(Fila *fila) {
    if (fila == NULL) return 1;
    if (fila->inicio == NULL) return 1;
    return 0;
}
