#ifndef SLIST_H
#define SLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct SNode{

    int val;
    struct SNode  *prox; // proximo nó;

}SNode;

typedef struct SList{
    
    SNode *first, *last;
    int tam;

}SList;

/**
 * @brief Cria a cabeça da Lista Simples (&sl) - Lista Vazia.
 */
void SList_Create(SList *sl);

/**
 * @brief Cria um nó.
 * 
 * @param val Valor no nó.
 * @return Retorna um nó.
 */
SNode *SList_CreateNode(int val);

/**
 * @brief Verifica se a lista esta vazia.
 * 
 * @param sl Lista Simples a ser verificada(&sl).
 */
bool SList_isEmpty(SList *sl);

/**
 * @brief Insere na cabeça da lista.
 * 
 * @param sl Endereço da lista(&sl).
 * @param val Valor do elemento.
 */
void SList_InsertHead(SList *sl, int val);

/**
 * @brief Insere no final da lista.
 * 
 * @param sl Endereço da lista(&sl).
 * @param val Valor do elemento.
 */
void SList_InsertFinalList(SList *sl, int val);

/**
 * @brief Imprime todos os elementos da lista.
 * 
 * @param sl Lista Simples a ser imprimida(&sl).
 */
void SList_PrintSList(SList *sl);

/**
 * @brief Remove o nó com o valor desejado.
 * 
 * @param sl Endereço da lista (&sl).
 * @param val Valor procurado para seu respetivo nó ser removido.
 */
void SList_RemoveNode(SList *sl, int val);

/**
 * @brief Desaloca uma Lista inteira.
 * 
 * @param sl Endereço da lista a ser desalocada.
 */
void SList_DestroySList(SList *sl);

#endif