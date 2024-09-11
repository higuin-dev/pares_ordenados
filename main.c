#include "trabalho_pratico.h"

int main(){

    //ler o arquivo de entradas.txt
    
    FILE *arquivo = fopen("entradas.txt", "r");
    if (arquivo == NULL) {
        printf("Dados nao encontrados.\n");
        return 1;
    }

    //declarar variaveis

    int conjuntoA[50];
    int tamanhoA;

    lerConjuntoA(conjuntoA, &tamanhoA, arquivo);

    parOrdenado p;

    int numParesOrdenados = lerParesOrdenados(&p, arquivo);
    
    imprimirParesOrdenados(&p, numParesOrdenados);

    /*parOrdenado busca;
    busca.x = 3;
    busca.y = 3;

    if(acharParOrdenado(&p, busca, numParesOrdenados) == true ){
      printf("achou\n");
    } */

    bool reflexividade = ehReflexiva(conjuntoA, &p, tamanhoA-1, numParesOrdenados);// eh reflexiva passar o parametro tamanho a -1 pra contar com o indice 0 do vetor
    bool irreflexividade = ehIrreflexiva(conjuntoA, &p, tamanhoA-1, numParesOrdenados); 
    bool simetria = ehSimetrica(&p, numParesOrdenados);
    bool antisimetria = ehAntisimetrica(&p, numParesOrdenados);
    bool assimetria = ehAssimetrico(&p, numParesOrdenados);
    bool transitividade = ehTransitiva(&p, numParesOrdenados);

    printf("\n");

    relacaoDeEquivalencia(reflexividade, simetria, transitividade);
    ordemParcial(reflexividade, antisimetria, transitividade);

    printf("\n");

    if (reflexividade == true) printFechoReflexivo(conjuntoA, &p, tamanhoA, numParesOrdenados);
    if (irreflexividade == true) printFechoIrreflexivo(&p, numParesOrdenados);
    if (simetria == true) printFechoSimetrico(&p, numParesOrdenados);
    if (antisimetria == true) printFechoAntisimetrico(&p, numParesOrdenados);
    if (assimetria == true) printFechoAssimetrico(&p, numParesOrdenados);
    if (transitividade == true) printFechoTransitivo(&p, numParesOrdenados);

    //--------------------------------------------------

    liberarMemoria(&p);

    fclose(arquivo);

    return 0;
}