//
// Created by Gabriel Machado on 23/03/2019.
//

#ifndef ARVORE_BINARIA_FILAEST_H
#define ARVORE_BINARIA_FILAEST_H

#endif //ARVORE_BINARIA_FILAEST_H

#include "Structs.h"

Fila *cria_fila();

void libera_fila(Fila *fila);

int tamanho_fila(Fila *fila);

int insere_fila(Fila *fila, Nodo nodo);

int remove_fila(Fila *fila);

int condulta_fila(Fila *fila, Nodo *nodo);

int fila_cheia(Fila fila);

int fila_vazia(Fila *fila);


