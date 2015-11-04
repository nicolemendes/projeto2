/* 
 * File:   main.c
 * Author: Nicole Mendes Flores
 * N USP: 9312599
 * Created on 27 de Outubro de 2015, 23:31
 */

//https://www.dropbox.com/s/gyn6u4e96kfjdq2/arv2.c?dl=0

//https://docs.google.com/document/d/1sg7KwIPM7TLtAaEfVqCzp3fW8t2WZno9z9plfWqKcbM/edit#

#include <stdio.h>
#include <stdlib.h>

#include "arvorebinaria.h"
#include "arvoregenealogica.h"

/*
 * 
 */

/**
 * Funcao resposanvel pela execucao do Exercicio 1
 */
void programa_arvore_binaria() {
    printf("\n\n\n Bem vindo ao programa de gerenciamento de Arvore Binaria!\n");

    ARVORE_BINARIA *pArvore = AB_CriarArvore();

    int opcab = -1;

    while (opcab != 0) {

        printf("\n0 - Sair\n1 - Inserir\n2 - Remover\n3 - Buscar\n4 - Impressao em Pre Ordem\n5 - Impressao em  Pos Ordem\n6 - Impressao em  Em Ordem\n7 - Impressao em Labelled Bracketing\n");
        scanf("%d", &opcab);

        switch (opcab) {
            case 0:
            {//remove a arvore da memoria e fecha a funcao
                AB_ApagarArvore(&pArvore);
                break;
            }
            case 1:
            {//Insere um novo no na arvore com chave e valor
                int chave, valor;
                printf("\nDigite a chave e o valor\n");
                scanf("%d %d", &chave, &valor);

                AB_InserirNO(pArvore, chave, valor);

                break;
            }
            case 2:
            {//Remove um no dado uma chave
                int chave;
                printf("\nDigite a chave para exclusao\n");
                scanf("%d", &chave);

                if (AB_RemoverNo(pArvore, chave)) {
                    printf("\nExcluido com Sucesso!!!\n");
                } else {
                    printf("\nERRO: Chave nao encontrada!!!\n");
                }
                break;
            }
            case 3:
            {//Busca um no dado uma chave
                int chave;
                printf("\nDigite a chave para busca\n");
                scanf("%d", &chave);

                NOB *no = AB_BuscarElemento(pArvore->pRaiz, chave);

                if (no != NULL) {
                    printf("\nChave Localizada valor = %d\n", no->dado);
                } else {
                    printf("\nChave nao localizada\n");
                }

                break;
            }
            case 4:
            {//Imprime a arvore em Pre Ordem
                AB_ImprimirPreOrdem(pArvore);

                break;
            }
            case 5:
            {//Imprime a arvore em Pos Ordem
                AB_ImprimirPosOrdem(pArvore);

                break;
            }
            case 6:
            {//IMprime a arvore Em Ordem
                AB_ImprimirEmOrdem(pArvore);

                break;
            }
            case 7:
            {//Imprime a arovre em Labelled Bracketing
                AB_ImprimirLabelledBracketing(pArvore);

                break;
            }
            default:
            {
                printf("\nOPCAO INVALIDA");
                break;
            }
        }

    }


    return;
}

/**
 * Funcao responsavel pelo Exercicio 2
 */
void programa_arvore_genealogica() {

    printf("\n\n\n Bem vindo ao programa de gerenciamento de Arvore Genealogica!\n");

    ARVORE_GENEALOGICA *pArvore = AG_CriarArvore();

    int opcag = -1;

    while (opcag != 0) {

        printf("\n0 - Sair\n1 - Inserir\n2 - Imprimir membros de uma familia por geracao\n3 - Imprimir os Antepassados\n4 - Imprimir em Labelled Bracketing\n5 - Calcular Grau de Parentesco\n");
        scanf("%d", &opcag);

        switch (opcag) {
            case 0:
            {//apaga a arvore da memoria e fecha a funcao
                AG_ApagarArvore(&pArvore);

                printf("\nAte mais!!!");

                break;
            }
            case 1:
            {//insere um novo conjundo filho, pai, mae

                //deve-se alocar um ponteiro a cada nome recebido para nao sobrescrever
                char *filho = malloc(50 * sizeof (char));
                char *pai = malloc(50 * sizeof (char));
                char *mae = malloc(50 * sizeof (char));

                printf("\nDigite o nome de Filho, Pai e Mae respectivamente\n");

                scanf(" %s %s %s", filho, pai, mae);

                NOG *noInsert = AG_InserirNO(pArvore, filho, pai, mae);

                //caso de erro ao inserir mostra msg
                if (!noInsert) {
                    printf("\nErro: Filho nao localizado\n");
                }

                break;
            }
            case 2:
            {//Imprimir membros de uma familia por geracao
                AG_ImprimirGeracao(pArvore);

                break;
            }
            case 3:
            {//Imprimir os Antepassados dado o nome de um individuo
                char *filhoPesquisa = malloc(50 * sizeof (char));

                printf("\nDigite o nome do individuo\n");
                scanf(" %[^\n]", filhoPesquisa);

                AG_ImprimirAntepassados(pArvore, filhoPesquisa);

                break;
            }
            case 4:
            {//Imprime a arvore em Labelled Bracketing
                AG_ImprimirLabelledBracketing(pArvore);
                break;
            }
            case 5:
            {//Calcular Grau de Parentesco de dois individuos

                char *individuo1 = malloc(50 * sizeof (char));
                char *individuo2 = malloc(50 * sizeof (char));

                printf("Digite o nome do individuo 1 e 2 (*um por linha)\n");
                scanf(" %[^\n]", individuo1);
                scanf(" %[^\n]", individuo2);

                int grau = AG_CalcularGrauParentesco(pArvore, individuo1, individuo2);

                printf("\nGrau = %d\n", grau);

                break;
            }
            default:
            {
                printf("\nOPCAO INVALIDA");
                break;
            }
        }
    }

    return;
}

void main() {


    int opc = -1;

    while (opc != 0) {
        printf("\n--------------------------------Bem vindo ao Menu Principal--------------------------------\n");
        printf("\n[0] - Sair\n[1] - Arvore Binaria\n[2] - Arvore Genealogica\n;");
        scanf("%d", &opc);

        switch (opc) {
            case 0:
            {
                printf("\nAte mais!!!");
                break;
            }
            case 1:
            {


                programa_arvore_binaria();

                break;
            }
            case 2:
            {

                programa_arvore_genealogica();

                break;
            }
            default:
            {
                printf("\nOPCAO INVALIDA");
                break;
            }
        }

    }


    return;
}
