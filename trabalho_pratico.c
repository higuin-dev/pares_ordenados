#include "trabalho_pratico.h"

void lerConjuntoA(int *conjuntoA, int *tamanhoA, FILE *arquivo){

    fscanf(arquivo, "%d", tamanhoA);

    for (int i = 0; i < *tamanhoA; i++) {
        fscanf(arquivo, "%d", &conjuntoA[i]);
    }
}

int lerParesOrdenados(parOrdenado *p, FILE *arquivo){

    int numParesOrdenados = 0;
    int entradas = 10;

    // calloc aloca dinamicamente e inicializa em 0
    p->x = (int *)malloc(entradas * sizeof(int));
if (p->x == NULL) { printf("Erro de alocação de memória para p->x"); return 1; }
    p->y = (int *)malloc(entradas * sizeof(int));
if (p->y == NULL) { printf("Erro de alocação de memória para p->y"); return 1; }

    int i = 0;

    while(fscanf(arquivo, "%d %d", &p->x[i], &p->y[i]) != EOF){
        numParesOrdenados++;
        i++;

        // aloca mais espaço se precisar
        if(numParesOrdenados >= entradas){
            entradas *= 2; 
            int *temp_x = (int *)realloc(p->x, entradas * sizeof(int));
if (temp_x == NULL) { printf("Erro de realloc em p->x"); return 1; }
p->x = temp_x;
            int *temp_y = (int *)realloc(p->y, entradas * sizeof(int));
if (temp_y == NULL) { printf("Erro de realloc em p->y"); return 1; }
p->y = temp_y;

            // inicializa tudo com 0
            for (int j = numParesOrdenados; j < entradas; j++) {
                p->x[j] = 0;
                p->y[j] = 0;
            }
        }
    }

    return numParesOrdenados;
}


void imprimirParesOrdenados(parOrdenado *p, int numParesOrdenados){
    printf("Pares Ordenados lidos: \n");
    for (int i = 0; i < numParesOrdenados; i++)
    {
        printf("P%d = (%d, %d)\n", i, p->x[i], p->y[i]);
    }
}

bool acharParOrdenado(parOrdenado *p, parOrdenado busca, int numParesOrdenados){
    for (int i = 0; i < numParesOrdenados; i++){
        if(p->x[i] == *(busca.x) && p->y[i] == *(busca.y)){
            return true;
        }
    }
    return false;
}

bool ehReflexiva(int *conjuntoA, parOrdenado *p, int tamanhoA, int numParesOrdenados){

    printf("1. Reflexiva: ");

    //copiar o conjunto pra um aux
    parOrdenado aux;
aux.x = (int *)malloc(tamanhoA * sizeof(int));
aux.y = (int *)malloc(tamanhoA * sizeof(int));
if (aux.x == NULL || aux.y == NULL) {
    printf("Erro de alocação de memória.\n");
    return false;
}
    parOrdenado conjuntoAux[tamanhoA];

    int tamanhoConjuntoAux = 0;

    for (int i = 0; i <= tamanhoA; i++){
        *(aux.x) = conjuntoA[i];
        *(aux.y) = conjuntoA[i];
        if(acharParOrdenado(p, aux, numParesOrdenados) == true){
            continue;
        }
        else{
            conjuntoAux[tamanhoConjuntoAux].x = aux.x;
            conjuntoAux[tamanhoConjuntoAux].y = aux.y;
            tamanhoConjuntoAux++;
        }

    }

    if(tamanhoConjuntoAux == 0){
        printf("V\n");
        return true;
    } else{
        printf("F\n");
        for (int i = 0; i < tamanhoConjuntoAux; i++){
            printf("(%d ,%d); ", *(conjuntoAux[i].x), *(conjuntoAux[i].y));
        }
        printf("\n");
        return false;
    }
}

bool ehIrreflexiva(int *conjuntoA, parOrdenado *p, int tamanhoA, int numParesOrdenados){

    printf("2. Irreflexiva: ");

    //copiar o conjunto pra um aux
    parOrdenado aux;
aux.x = (int *)malloc(tamanhoA * sizeof(int));
aux.y = (int *)malloc(tamanhoA * sizeof(int));
if (aux.x == NULL || aux.y == NULL) {
    printf("Erro de alocação de memória.\n");
    return false;
}
    parOrdenado conjuntoAux[tamanhoA];

    int tamanhoConjuntoAux = 0;

    for (int i = 0; i <= tamanhoA; i++){
        *(aux.x) = conjuntoA[i];
        *(aux.y) = conjuntoA[i];
        if(acharParOrdenado(p, aux, numParesOrdenados) == true){
            conjuntoAux[tamanhoConjuntoAux].x = aux.x;
            conjuntoAux[tamanhoConjuntoAux].y = aux.y;
            tamanhoConjuntoAux++;
        }
        else{
            continue;
        }

    }

    if(tamanhoConjuntoAux == 0){
        printf("V\n");
        return true;
    } else{
        printf("F\n");
        for (int i = 0; i < tamanhoConjuntoAux; i++){
            printf("(%d ,%d); ", *(conjuntoAux[i].x), *(conjuntoAux[i].y));
        }
        printf("\n");
        return false;
    }
}

bool ehSimetrica(parOrdenado *p, int numParesOrdenados){
    //if x == y desconsidera
    //else par1 procura simetrico
        //achou --> prox par
        //nao achou --> nao e simetrico, guarda o par ordenado que nao achou

    printf("3. Simetrica: ");

    parOrdenado conjuntoAux[numParesOrdenados];
    int tamanhoConjuntoAux = 0;

    for (int i = 0; i < numParesOrdenados; i++) {
    //if x == y desconsidera
        if (p->x[i] == p->y[i]) {
            continue;
        }

    //par simétrico
    
        parOrdenado busca;
        busca.x = &(p->y[i]);
        busca.y = &(p->x[i]);

        //achou --> prox par
        if (acharParOrdenado(p, busca, numParesOrdenados) == true) {
            continue;
        }

        //nao achou --> nao e simetrico, guarda o par ordenado que nao achou
        conjuntoAux[tamanhoConjuntoAux].x = &(p->x[i]);
        conjuntoAux[tamanhoConjuntoAux].y = &(p->y[i]);
        tamanhoConjuntoAux++;
    }

    if (tamanhoConjuntoAux == 0) {
        printf("V\n"); // É simétrica
        return true;
    } else {
        printf("F\n"); // Não é simétrica
        // Imprime os pares que faltam para a simetria
        for (int i = 0; i < tamanhoConjuntoAux; i++) {
            printf("(%p, %p); ", conjuntoAux[i].x, conjuntoAux[i].y);
        }
        printf("\n");
        return false;
    }
}

bool ehAntisimetrica(parOrdenado *p, int numParesOrdenados){
    //if x == y desconsidera
    //else par1 procura simetrico
        //achou --> nao e ANTIsimetrico, guarda o par ordenado que achou
        //nao achou --> prox par

    printf("4. Anti-simetrica: ");

    parOrdenado conjuntoAux[numParesOrdenados];
    int tamanhoConjuntoAux = 0;

    for (int i = 0; i < numParesOrdenados; i++) {
    //if x == y desconsidera
        if (p->x[i] == p->y[i]) {
            continue;
        }

    //par simétrico
    
        parOrdenado busca;
        busca.x = &(p->y[i]);
        busca.y = &(p->x[i]);

        //achou --> nao e anti-simetrico, guarda o par ordenado que achou
        if (acharParOrdenado(p, busca, numParesOrdenados) == true) {
            conjuntoAux[tamanhoConjuntoAux].x = &(p->x[i]);
            conjuntoAux[tamanhoConjuntoAux].y = &(p->y[i]);
            tamanhoConjuntoAux++;
        }

        //nao achou --> nao faz nada
    }

    if (tamanhoConjuntoAux != 0) {
        printf("F\n"); // não é anti-simetrico
        for (int i = 0; i < tamanhoConjuntoAux; i++) {
            printf("(%p, %p); ", conjuntoAux[i].x, conjuntoAux[i].y);
        }
        printf("\n");
        return false;
    } else {
        printf("V\n"); // é anti-simetrico
        return true;
    }
}

bool ehAssimetrico(parOrdenado *p, int numParesOrdenados){

    printf("5. Assimetrico: ");

    parOrdenado conjuntoAux[numParesOrdenados];
    int tamanhoConjuntoAux = 0;

    for (int i = 0; i < numParesOrdenados; i++) {
        /*if (p->x[i] == p->y[i]) {
            continue;
        }*/

    //par simetrico
    
        parOrdenado busca;
        busca.x = &(p->y[i]);
        busca.y = &(p->x[i]);

        //achou --> nao e anti-simetrico, guarda o par ordenado que achou
        if (acharParOrdenado(p, busca, numParesOrdenados) == true || p->x[i] == p->y[i]) {
            conjuntoAux[tamanhoConjuntoAux].x = &(p->x[i]);
            conjuntoAux[tamanhoConjuntoAux].y = &(p->y[i]);
            tamanhoConjuntoAux++;
        }

        //nao achou --> nao faz nada
    }

    if (tamanhoConjuntoAux != 0) {
        printf("F\n"); // não é anti-simetrico
        for (int i = 0; i < tamanhoConjuntoAux; i++) {
            printf("(%p, %p); ", conjuntoAux[i].x, conjuntoAux[i].y);
        }
        printf("\n");
        return false;
    } else {
        printf("V\n"); // é anti-simetrico
        return true;
    }
}

bool ehTransitiva(parOrdenado *p, int numParesOrdenados) {

    printf("6. Transitiva: ");
    
    parOrdenado conjuntoAux[numParesOrdenados];
    int tamanhoConjuntoAux = 0;

    // pares (a, b)
    for (int i = 0; i < numParesOrdenados; i++) {
        for (int j = 0; j < numParesOrdenados; j++) {
            // (b, c) onde b é o mesmo do (a, b)
            if (p->y[i] == p->x[j]) {
                parOrdenado busca;
                busca.x = &(p->x[i]); // a
                busca.y = &(p->y[j]); // c
                
                // verificar o par (a, c) em R
                if (acharParOrdenado(p, busca, numParesOrdenados) == false) {
                    // não encontrou, então não é transitiva
                    conjuntoAux[tamanhoConjuntoAux].x = busca.x;
                    conjuntoAux[tamanhoConjuntoAux].y = busca.y;
                    tamanhoConjuntoAux++;
                }
            }
        }
    }

    if (tamanhoConjuntoAux == 0) {
        printf("V\n"); // é transitiva
        return true;
    } else {
        printf("F\n"); // não é transitiva
        for (int i = 0; i < tamanhoConjuntoAux; i++) {
            printf("(%p, %p); ", conjuntoAux[i].x, conjuntoAux[i].y);
        }
        printf("\n");
        return false;
    }
}

bool relacaoDeEquivalencia(bool reflexividade, bool simetria, bool transitividade){
    printf("Relacao de equivalencia: ");
    
    if(reflexividade == true && simetria == true && transitividade == true){
        printf("V\n");
        return true;
    } else{
        printf("F\n");
        return false;
    }
}

bool ordemParcial(bool reflexividade, bool antisimetria, bool transitividade) {
    printf("Relacao de ordem parcial: ");
    
    if(reflexividade == true && antisimetria == true && transitividade == true) {
        printf("V\n");
        return true;
    }
    else {
        printf("F\n");
        return false;
    }
}

void printFechoReflexivo(int *conjuntoA, parOrdenado *p, int tamanhoA, int numParesOrdenados) {
(void)conjuntoA;
(void)tamanhoA;
    printf("Fecho reflexivo da relacao: {");

    int first = 1; // vírgula
    for (int i = 0; i < numParesOrdenados; i++) {
        if (p->x[i] == p->y[i]) {
            if (!first) {
                printf(", ");
            }
            printf("(%d, %d)", p->x[i], p->y[i]);
            first = 0;
        }
    }
    printf("}\n");
}

void printFechoIrreflexivo(parOrdenado *p, int numParesOrdenados) {
    printf("Fecho irreflexivo da relacao: {");

    int first = 1; // vírgula
    for (int i = 0; i < numParesOrdenados; i++) {
        if (p->x[i] != p->y[i]) {
            if (!first) {
                printf(", ");
            }
            printf("(%d, %d)", p->x[i], p->y[i]);
            first = 0;
        }
    }
    printf("}\n");
}

void printFechoSimetrico(parOrdenado *p, int numParesOrdenados) {
    printf("Fecho simetrico da relacao: {");

    int first = 1; // vírgula
    for (int i = 0; i < numParesOrdenados; i++) {
        if (p->x[i] != p->y[i]) {
            parOrdenado busca;
            busca.x = &(p->y[i]);
            busca.y = &(p->x[i]);
            
            if (acharParOrdenado(p, busca, numParesOrdenados)) {
                if (!first) {
                    printf(", ");
                }
                printf("(%d, %d)", p->x[i], p->y[i]);
                first = 0;
            }
        }
    }
    printf("}\n");
}

void printFechoAssimetrico(parOrdenado *p, int numParesOrdenados) {
    printf("Fecho assimetrico da relacao: {");

    int first = 1; // vírgula
    for (int i = 0; i < numParesOrdenados; i++) {
        if (p->x[i] != p->y[i]) { // ignora os pares reflexivos
            parOrdenado busca;
            busca.x = &(p->y[i]);
            busca.y = &(p->x[i]);

            if (!acharParOrdenado(p, busca, numParesOrdenados)) {
                if (!first) {
                    printf(", ");
                }
                printf("(%d, %d)", p->x[i], p->y[i]);
                first = 0;
            }
        }
    }
    printf("}\n");
}

void printFechoAntisimetrico(parOrdenado *p, int numParesOrdenados) {
    printf("Fecho anti-simetrico da relacao: {");

    int first = 1; // Flag para controlar a vírgula
    for (int i = 0; i < numParesOrdenados; i++) {
        if (p->x[i] != p->y[i]) { // Ignora os pares reflexivos
            parOrdenado busca;
            busca.x = &(p->y[i]);
            busca.y = &(p->x[i]);

            if (!acharParOrdenado(p, busca, numParesOrdenados)) {
                if (!first) {
                    printf(", ");
                }
                printf("(%d, %d)", p->x[i], p->y[i]);
                first = 0;
            }
        }
    }
    printf("}\n");
}

void printFechoTransitivo(parOrdenado *p, int numParesOrdenados) {
    printf("Fecho transitivo da relacao: {");

    int first = 1; // vírgula
    for (int i = 0; i < numParesOrdenados; i++) {
        if (!first) {
            printf(", ");
        }
        printf("(%d, %d)", p->x[i], p->y[i]);
        first = 0;
    }
    printf("}\n");
}



void liberarMemoria(parOrdenado *p)
{
    free(p->x);
    free(p->y);
}

//retornar par ordenado




