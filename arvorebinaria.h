#ifndef ARVOREBINARIA_H
#define	ARVOREBINARIA_H

#define FILHO_ESQ 0
#define FILHO_DIR 1

typedef struct arvore_binaria ARVORE_BINARIA;
typedef struct nob NOB;

struct nob {
    int chave;
    int dado;

    NOB *pFilhoEsq;
    NOB *pFilhoDir;
};

struct arvore_binaria {
    NOB *pRaiz;
};

ARVORE_BINARIA *AB_CriarArvore();
NOB *AB_CriarRaiz(ARVORE_BINARIA *, int, int);
int AB_RemoverNo(ARVORE_BINARIA *, int);
void AB_ApagarArvore(ARVORE_BINARIA **);
NOB *AB_InserirNO(ARVORE_BINARIA *, int, int);
int AB_Vazia(ARVORE_BINARIA *);
void AB_ImprimirEmOrdem(ARVORE_BINARIA *);
void AB_ImprimirPreOrdem(ARVORE_BINARIA *);
void AB_ImprimirPosOrdem(ARVORE_BINARIA *);
void AB_ImprimirLabelledBracketing(ARVORE_BINARIA *);
int AB_AlturaArvore(ARVORE_BINARIA *);
int AB_AlturaNo(NOB *);
NOB *AB_BuscarElemento(NOB *, int);

#endif

