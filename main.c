#include <stdio.h>
#include <stdlib.h>
#include "arvore_bin.h"

int main() {

    Arv_bin *arv_bin;
    Arv_bin *test;

    arv_bin = arv_cria( arv_cria_no('a',  arv_cria_no('b', NULL,  arv_cria_no('d', NULL, NULL)),
            arv_cria_no('c',  arv_cria_no('e',  NULL, NULL),  arv_cria_no('f', NULL, NULL))));

    inprime_escolhendo_ordem(arv_bin);

    int tam = tamanho_arv(arv_bin);

    printf("\nAltura = %d", altura_arv(arv_bin));
    printf("\nTamanho = %d", tam);

    arv_libera(arv_bin);

    return 0;
}