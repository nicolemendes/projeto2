/* 
 * File:   main.c
 * Author: Nicole Mendes Flores
 * N USP: 9312599
 * Created on 27 de Outubro de 2015, 23:31
 */

#include "arvorebinaria.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * Metodo que aloca uma arvore binaria
 * 
 * @return arvore binaria
 */
ARVORE_BINARIA *AB_CriarArvore() {
    ARVORE_BINARIA *ab = malloc(sizeof (ARVORE_BINARIA));

    if (ab) {
        ab->pRaiz = NULL;
    }

    return ab;
}

/**
 * Metodo que aloca o no raiz da arvore
 * @param pArvore
 * @param chave
 * @param dado
 * @return no raiz
 */
NOB *AB_CriarRaiz(ARVORE_BINARIA *pArvore, int chave, int dado) {
    NOB *no = malloc(sizeof (NOB));

    if (no) {
        no->pFilhoDir = NULL;
        no->pFilhoEsq = NULL;

        no->chave = chave;
        no->dado = dado;

        pArvore->pRaiz = no;
    }

    return no;
}

/**
 * Metodo que insere um no novo na arvore
 * @param iFilho
 * @param pNo
 * @param chave
 * @param dado
 * @return no inserido
 */
NOB *AB_InserirFilho(int iFilho, NOB *pNo, int chave, int dado) {
    NOB *no = malloc(sizeof (NOB));

    if (no) {
        no->dado = dado;
        no->chave = chave;
        no->pFilhoDir = NULL;
        no->pFilhoEsq = NULL;

        if (iFilho == FILHO_DIR) {
            pNo->pFilhoDir = no;
        } else {
            pNo->pFilhoEsq = no;
        }
    }

    return no;
}

/**
 * Remove um no dado uma chave
 * @param pArvore
 * @param chave
 * @return 1 true, 0 false
 */
int AB_RemoverNo(ARVORE_BINARIA *pArvore, int chave) {
    NOB *p = pArvore->pRaiz;
    NOB *pai = NULL;

    while (p != NULL && p->chave != chave) {
        pai = p;
        if (p->chave >= chave) {
            p = p->pFilhoEsq;
        } else {
            p = p->pFilhoDir;
        }
    }
    if (p == NULL) {
        return 0;
    }

    NOB *m = p->pFilhoDir;

    while (m != NULL && m->pFilhoEsq != NULL) {
        m = m->pFilhoEsq;
    }

    NOB *n;
    if (m != NULL) {
        m -> pFilhoEsq = p -> pFilhoEsq;
        n = p->pFilhoDir;
    } else {
        n = p->pFilhoEsq;
    }
    if (pai->chave < chave) {
        pai->pFilhoDir = n;
    } else {
        pai->pFilhoEsq = n;
    }
    free(p);

    return (1);
}

/**
 * Desaloca a arvore a partir de um no raiz
 * @param raiz da arvore
 */
void apagar_arvore_aux(NOB *raiz) {
    if (raiz) {

        NOB *esq = raiz->pFilhoEsq;
        NOB *dir = raiz->pFilhoDir;

        raiz->pFilhoDir = NULL;
        raiz->pFilhoEsq = NULL;


        free(raiz);

        apagar_arvore_aux(esq);
        apagar_arvore_aux(dir);

    }

    return;
}

/**
 * Desaloca a arvore
 * @param pArvore
 */
void AB_ApagarArvore(ARVORE_BINARIA **pArvore) {
    apagar_arvore_aux((*pArvore)->pRaiz);
    free(*pArvore);
    *pArvore = NULL;

}

/**
 * Insere um novo no na arvore
 * @param pArvore
 * @param chave
 * @param dado
 * @return no alocado
 */
NOB *AB_InserirNO(ARVORE_BINARIA *pArvore, int chave, int dado) {
    if (pArvore->pRaiz) {
        NOB *p = pArvore->pRaiz;
        NOB *pai = NULL;

        int iFilho = 0;

        while (p != NULL) {
            pai = p;
            if (p->chave >= chave) {
                p = p->pFilhoEsq;
                iFilho = FILHO_ESQ;

            } else {
                p = p->pFilhoDir;
                iFilho = FILHO_DIR;
            }
        }

        return AB_InserirFilho(iFilho, pai, chave, dado);

    } else {
        return AB_CriarRaiz(pArvore, chave, dado);
    }

    return NULL;
}

/**
 * Verifica se a arvore esta vazia
 * @param pArvore
 * @return != 0 true, 0/NULL false
 */
int AB_Vazia(ARVORE_BINARIA *pArvore) {
    return (pArvore->pRaiz == NULL);
}

/**
 * Imprime a arvoe EM ORDEM
 * @param pRaiz
 */
void AB_ImprimirEmOrdem_Aux(NOB *pRaiz) {
    if (pRaiz != NULL) {
        AB_ImprimirEmOrdem_Aux(pRaiz->pFilhoEsq);

        printf("[%d][%d]->", pRaiz->chave, pRaiz->dado);

        AB_ImprimirEmOrdem_Aux(pRaiz->pFilhoDir);
    }

    return;
}

/**
 * Imprime a arvore em ORDEM
 * @param pArvore
 */
void AB_ImprimirEmOrdem(ARVORE_BINARIA *pArvore) {
    AB_ImprimirEmOrdem_Aux(pArvore->pRaiz);

    return;
}

/**
 * Imprime a arvore em PRE ORDEM
 * @param pRaiz
 */
void AB_ImprimirPreOrdem_Aux(NOB *pRaiz) {
    if (pRaiz != NULL) {
        printf("[%d][%d]->", pRaiz->chave, pRaiz->dado);
        AB_ImprimirPreOrdem_Aux(pRaiz->pFilhoEsq);
        AB_ImprimirPreOrdem_Aux(pRaiz->pFilhoDir);
    }

    return;
}

/**
 * Imprime a arvore em PRE ORDEM
 * @param pArvore
 */
void AB_ImprimirPreOrdem(ARVORE_BINARIA *pArvore) {
    AB_ImprimirPreOrdem_Aux(pArvore->pRaiz);

    return;
}

/**
 * Imprime a arvore em POS ORDEM
 * @param pRaiz
 */
void AB_ImprimirPosOrdem_Aux(NOB *pRaiz) {
    if (pRaiz != NULL) {
        AB_ImprimirPosOrdem_Aux(pRaiz->pFilhoEsq);
        AB_ImprimirPosOrdem_Aux(pRaiz->pFilhoDir);
        printf("[%d][%d]->", pRaiz->chave, pRaiz->dado);
    }

    return;
}

/**
 * Imprime a arvore em POS ORDEM
 * @param pArvore
 */
void AB_ImprimirPosOrdem(ARVORE_BINARIA *pArvore) {
    AB_ImprimirPosOrdem_Aux(pArvore->pRaiz);

    return;
}

/**
 * Calcula a altura da arvore
 * @param pRaiz
 * @return altura
 */
int AB_AlturaArvore_Aux(NOB *pRaiz) {
    if (pRaiz == NULL) {
        return -1;
    } else {
        int esq = AB_AlturaArvore_Aux(pRaiz->pFilhoEsq);
        int dir = AB_AlturaArvore_Aux(pRaiz->pFilhoDir);
        return ((esq > dir) ? esq : dir) + 1;
    }
}

/**
 * Calcula a altura da arvore
 * @param pArvore
 * @return altura
 */
int AB_AlturaArvore(ARVORE_BINARIA *pArvore) {
    return AB_AlturaArvore_Aux(pArvore->pRaiz);
}

/**
 * Imprime a arvore em Labelled Bracketing
 * @param pRaiz
 */
void AB_ImprimirLabelledBracketing_Aux(NOB *pRaiz) {
    printf("[");

    if (pRaiz != NULL) {
        printf("%d", pRaiz->dado);

        AB_ImprimirLabelledBracketing_Aux(pRaiz->pFilhoEsq);
        AB_ImprimirLabelledBracketing_Aux(pRaiz->pFilhoDir);
    }

    printf(" ]");

    return;
}

/**
 * Imprime a arvore em Labelled Bracketing
 * @param pArvore
 */
void AB_ImprimirLabelledBracketing(ARVORE_BINARIA *pArvore) {
    return AB_ImprimirLabelledBracketing_Aux(pArvore->pRaiz);
}

/**
 * 
 * @param pRaiz
 * @param chave
 * @return 
 */
NOB *AB_BuscarElemento(NOB *pRaiz, int chave) {
    if (pRaiz != NULL) {
        if (pRaiz->chave == chave) {
            return pRaiz;
        } else if (chave < pRaiz->chave) {
            return AB_BuscarElemento(pRaiz->pFilhoEsq, chave);
        } else {
            return AB_BuscarElemento(pRaiz->pFilhoDir, chave);
        }
    }
    return NULL;
}