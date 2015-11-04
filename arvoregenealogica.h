#ifndef ARVOREGENEALOGICA_H
#define	ARVOREGENEALOGICA_H

#include "arvorebinaria.h"


typedef struct arvore_genealogica ARVORE_GENEALOGICA;
typedef struct nog NOG;

struct nog {
    char *nome;

    NOG *pMae;
    NOG *pPai;
};

struct arvore_genealogica {
    NOG *pRaiz;
};

ARVORE_GENEALOGICA *AG_CriarArvore();
NOG *AG_CriarRaiz(ARVORE_GENEALOGICA *, char*, char*, char*);
NOG *AG_InserirNO(ARVORE_GENEALOGICA *, char*, char*, char*);
int AG_Vazia(ARVORE_GENEALOGICA *);
NOG *AG_Buscar(NOG *, char *);
void AG_ApagarArvore(ARVORE_GENEALOGICA **);
void AG_ImprimirLabelledBracketing(ARVORE_GENEALOGICA *);
void AG_ImprimirGeracao(ARVORE_GENEALOGICA *);
int AG_AlturaArvore_Aux(NOG *pRaiz);
int AG_AlturaArvore(ARVORE_GENEALOGICA *);
int AG_AlturaNo(NOG *pNo);
int AG_ProfundidadeNo(NOG *, NOG *);
void AG_ImprimirAntepassados(ARVORE_GENEALOGICA *, char *);
int AG_CalcularGrauParentesco(ARVORE_GENEALOGICA *, char *, char *);


#endif	/* ARVOREGENEALOGICA_H */

