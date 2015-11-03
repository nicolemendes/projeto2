/* 
 * File:   main.c
 * Author: Nicole Mendes Flores
 * N USP: 9312599
 * Created on 27 de Outubro de 2015, 23:31
 */

#include "arvoregenealogica.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

ARVORE_GENEALOGICA *AG_CriarArvore() {
    ARVORE_GENEALOGICA *ab = malloc(sizeof (ARVORE_GENEALOGICA));

    if (ab) {
        ab->pRaiz = NULL;
    }

    return ab;
}

NOG *AG_CriarRaiz(ARVORE_GENEALOGICA *pArvore, char* filho, char* pai, char* mae) {
    NOG *no = malloc(sizeof (NOG));
    NOG *noPai = malloc(sizeof (NOG));
    NOG *noMae = malloc(sizeof (NOG));

    if (no && noPai && noMae) {

        noPai->nome = pai;
        noPai->pMae = NULL;
        noPai->pPai = NULL;

        noMae->nome = mae;
        noMae->pMae = NULL;
        noMae->pPai = NULL;

        no->nome = filho;

        no->pPai = noPai;
        no->pMae = noMae;

        pArvore->pRaiz = no;
    }

    return no;
}

NOG *AG_InserirNO(ARVORE_GENEALOGICA *pArvore, char* filho, char* pai, char* mae) {
    if (pArvore->pRaiz) {

        NOG * no = AG_Buscar(pArvore->pRaiz, filho);

        NOG *noPai = malloc(sizeof (NOG));
        NOG *noMae = malloc(sizeof (NOG));

        if (no && noPai && noMae) {


            noPai->nome = pai;
            noPai->pMae = NULL;
            noPai->pPai = NULL;

            noMae->nome = mae;
            noMae->pMae = NULL;
            noMae->pPai = NULL;

            no->nome = filho;

            no->pPai = noPai;
            no->pMae = noMae;

        }

        return no;


    } else {
        return AG_CriarRaiz(pArvore, filho, pai, mae);
    }
}

int AG_Vazia(ARVORE_GENEALOGICA *pArvore) {
    return (pArvore->pRaiz == NULL);
}

NOG *AG_Buscar(NOG *pRaiz, char *nome) {
    if (pRaiz != NULL) {
        if (strcmp(pRaiz->nome, nome) == 0) {
            return pRaiz;
        } else {
            NOG *noPai = AG_Buscar(pRaiz->pPai, nome);
            NOG *noMae = AG_Buscar(pRaiz->pMae, nome);

            return (noPai != NULL ? noPai : noMae);
        }
    }
    return NULL;
}

void AG_Apagar_Arvore_Aux(NOG *raiz) {
    if (raiz) {

        NOG *pai = raiz->pPai;
        NOG *mae = raiz->pMae;

        raiz->pPai = NULL;
        raiz->pMae = NULL;


        free(raiz);

        apagar_arvore_aux(pai);
        apagar_arvore_aux(mae);

    }

    return;
}

void AG_ApagarArvore(ARVORE_GENEALOGICA **pArvore) {
    apagar_arvore_aux((*pArvore)->pRaiz);
    free(*pArvore);
    *pArvore = NULL;

    return;
}

void AG_ImprimirLabelledBracketing_Aux(NOG *pRaiz) {
    printf("[");

    if (pRaiz != NULL) {
        printf("%s", pRaiz->nome);

        AG_ImprimirLabelledBracketing_Aux(pRaiz->pPai);
        AG_ImprimirLabelledBracketing_Aux(pRaiz->pMae);
    }

    printf(" ]");

    return;
}

void AG_ImprimirLabelledBracketing(ARVORE_GENEALOGICA *pArvore) {
    AG_ImprimirLabelledBracketing_Aux(pArvore->pRaiz);

    return;
}

int AG_AlturaArvore_Aux(NOG *pRaiz) {
    if (pRaiz == NULL) {
        return -1;
    } else {
        int pai = AB_AlturaArvore_Aux(pRaiz->pPai);
        int mae = AB_AlturaArvore_Aux(pRaiz->pMae);
        return ((pai > mae) ? pai : mae) + 1;
    }
}

int AG_AlturaArvore(ARVORE_GENEALOGICA *pArvore) {
    return AB_AlturaArvore_Aux(pArvore->pRaiz);
}

int AG_AlturaNo(NOG *pNo) {
    return AG_AlturaArvore_Aux(pNo);
}

int AG_ProfundidadeNO_Aux(NOG *pRaiz, NOG *pNo, int i) {
    if (pRaiz == NULL) {
        return -1;
    } else if (pRaiz == pNo) {
        return i;
    } else {
        int pai = AB_ProfundidadeNO_Aux(pRaiz->pPai, pNo, i + 1);
        int mae = AB_ProfundidadeNO_Aux(pRaiz->pMae, pNo, i + 1);
        return (pai > mae ? pai : mae);
    }
}

int AG_ProfundidadeNo(NOG *pRaiz, NOG *pNo) {
    if (pRaiz == NULL) {
        return -1;
    } else {
        return AG_ProfundidadeNO_Aux(pRaiz, pNo, 0);
    }
}

void AG_ImprimirGeracao_Aux(NOG *noRaiz, NOG *no, int i) {
    if (no) {
        int profundidade = AG_ProfundidadeNO_Aux(noRaiz, no, 0);

        if (profundidade == i) {
            printf("%s ", no->nome);
        }

        AG_ImprimirGeracao_Aux(noRaiz, no->pPai, i);
        AG_ImprimirGeracao_Aux(noRaiz, no->pMae, i);

    }

    return;
}

void AG_ImprimirGeracao(ARVORE_GENEALOGICA *pArvore) {
    //descobre a altura maxima da arvore
    int altura = AG_AlturaArvore(pArvore);

    int i;
    for (i = 0; i <= altura; i++) {
        //imprimpe por altura
        AG_ImprimirGeracao_Aux(pArvore->pRaiz, pArvore->pRaiz, i);
        printf("\n");
    }

    return;
}

void AG_ImprimirAntepassados(ARVORE_GENEALOGICA *pArvore, char *nome) {
    NOG *no = AG_Buscar(pArvore->pRaiz, nome);

    if (no) {
        ARVORE_GENEALOGICA *pAux = AG_CriarArvore();
        pAux->pRaiz = no;

        AG_ImprimirGeracao(pAux);
    } else {
        printf("\nNao Localizado\n");
    }
}

int AG_CalcularGrauParentesco(ARVORE_GENEALOGICA *pArvore, char *individuo1, char *individuo2) {
    NOG *no1 = AG_Buscar(pArvore->pRaiz, individuo1);
    NOG *no2 = AG_Buscar(pArvore->pRaiz, individuo2);

    if (no1 && no2) {
        int grau = AG_ProfundidadeNo(no1, no2);

        return (grau > 0 ? grau : 0);
    } else {
        return 0;
    }
}