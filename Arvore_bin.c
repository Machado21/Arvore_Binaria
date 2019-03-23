//
// Created by Gabriel Machado on 13/03/2019.
//

#include "Arvore_bin.h"
#include <stdlib.h>
#include <stdio.h>

Arv_bin *arv_cria(Nodo *raiz) {
    Arv_bin *arv = (Arv_bin *) malloc(sizeof(Arv_bin));
    arv->raiz = raiz;
    return arv;
}

Nodo *arv_cria_no(char infor, Nodo *esq, Nodo *dir) {
    Nodo *nodo = (Nodo *) malloc(sizeof(Nodo));
    nodo->esq = esq;
    nodo->dir = dir;
    nodo->infor = infor;
    return nodo;
}

void arv_libera(Arv_bin *raiz) {
    if (raiz) {
        no_libera(raiz->raiz);
        free(raiz);
    }
}

void no_libera(Nodo *no) {
    if (no) {
        no_libera(no->esq);
        no_libera(no->dir);
        free(no);
    }
}

/**Retorna 1 ou 0 se pertence ou nao na arvore
 * @param arv
 * @param valor
 * @return
 * */
int arv_pertence(Arv_bin *arv, char valor) {
    return no_pertence(arv->raiz, valor);
}

int no_pertence(Nodo *raiz, char valor) {
    if (raiz == NULL) {
        return 0;
    }
    if (valor == raiz->infor) {
        return 1;
    }
    if (no_pertence(raiz->esq, valor)) {
        return 1;
    }
    return no_pertence(raiz->dir, valor);
}

Arv_bin *arv_busca(Arv_bin *arv, char valor) {
    return no_busca(arv->raiz, valor);
}

Nodo *no_busca(Nodo *no, char valor) {
    if (no == NULL) {
        return NULL;
    } else if (no->infor == valor) {
        return no;
    } else {
        Nodo *nodo;
        if (nodo = no_busca(no->esq, valor)) {
            return nodo;
        } else {
            return no_busca(no->dir, valor);
        }
    }
}

/**Retorna a altura da Arvore
 * @param raiz
 * @return int
 * */
int altura_arv(Arv_bin *raiz) {
    return altura_no(raiz->raiz);
}

int altura_no(Nodo *no) {
    if (no == NULL) {
        return -1;
    }
    int esq = 1 + altura_no(no->esq);
    int dir = 1 + altura_no(no->dir);
    return maior(esq, dir);
}

int maior(int esq, int dir) {
    return esq > dir ? esq : dir;
}

int tamanho_arv(Arv_bin *arv){
    return tamanho(arv->raiz);
}

int tamanho(Nodo *no){
    if (no != NULL){
        return 1 + tamanho(no->esq) +tamanho(no->dir);
    } else {
        return 0;
    }
}

void alrgura(Arv_bin *arv){

}

void inprime_escolhendo_ordem(Arv_bin *arv) {
    int ordem;
    printf("1 - Imprime PreOrden. \n2 - Imprime InOrdem. \n3 - Imprime PosOrdem.\n");
    scanf_s("%d", &ordem);
    do {
        switch (ordem) {
            case 1 :
                pre(arv->raiz);
                break;
            case 2 :
                in(arv->raiz);
                break;
            case 3 :
                pos(arv->raiz);
                break;
            default:
                printf("Opcao invalida, Tente de 1 a 3 : ");
                break;
        }
    } while (ordem < 1 || ordem > 3);

}

void pre(Nodo *no) {
    if (no) {
        printf("%c ", no->infor);
        pre(no->esq);
        pre(no->dir);
    }
}

void in(Nodo *no) {
    if (no) {
        in(no->esq);
        printf("%c ", no->infor);
        in(no->dir);
    }
}

void pos(Nodo *no) {
    if (no) {
        pos(no->esq);
        pos(no->dir);
        printf("%c ", no->infor);
    }
}
