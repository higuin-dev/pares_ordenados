#ifndef TRABALHO_PRATICO_H
#define TRABALHO_PRATICO_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct{
    int *x;
    int *y;
} parOrdenado;

void lerConjuntoA(int *conjuntoA, int *tamanhoA, FILE *arquivo);
int lerParesOrdenados(parOrdenado *p, FILE *arquivo);
void imprimirParesOrdenados(parOrdenado *p, int numParesOrdenados);
bool acharParOrdenado(parOrdenado *p, parOrdenado busca, int numParesOrdenados);
bool ehReflexiva(int *conjuntoA, parOrdenado *p, int tamanhoA, int numParesOrdenados);
bool ehIrreflexiva(int *conjuntoA, parOrdenado *p, int tamanhoA, int numParesOrdenados);
bool ehSimetrica(parOrdenado *p, int numParesOrdenados);
bool ehAntisimetrica(parOrdenado *p, int numParesOrdenados);
bool ehAssimetrico(parOrdenado *p, int numParesOrdenados);

//relacoes

bool relacaoDeEquivalencia(bool reflexividade, bool simetria, bool transitividade);
bool ordemParcial(bool reflexividade, bool antisimetria, bool transitividade);

//imprimir fecho

void printFechoReflexivo(int *conjuntoA, parOrdenado *p, int tamanhoA, int numParesOrdenados);
void printFechoIrreflexivo(parOrdenado *p, int numParesOrdenados);
void printFechoSimetrico(parOrdenado *p, int numParesOrdenados);
void printFechoAssimetrico(parOrdenado *p, int numParesOrdenados);
void printFechoAntisimetrico(parOrdenado *p, int numParesOrdenados);
void printFechoTransitivo(parOrdenado *p, int numParesOrdenados);

void liberarMemoria(parOrdenado *p);

bool ehTransitiva(parOrdenado *p, int numParesOrdenados);
#endif //TRABALHO_PRATICO_H
