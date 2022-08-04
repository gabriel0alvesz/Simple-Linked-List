#include "slist.h"

void SList_Create(SList *sl){

    sl->first = (SNode*) malloc(sizeof(SNode)); //Aloca a cabeça da lista
    sl->last = sl->first;
    sl->first->prox = NULL;
    sl->tam = 0;
    //Cabeca da lista criada - Lista vazia
}

SNode *SList_CreateNode(int val){

    SNode *novo = (SNode*)malloc(sizeof(SNode));
    novo->val = val;
    novo->prox = NULL; //Cria novo nó

    return novo;
}

bool SList_isEmpty(SList *sl){
   return sl->tam == 0;
}

void SList_InsertHead(SList *sl, int val){

    SNode *elem = SList_CreateNode(val);
    
    if(SList_isEmpty(sl) == true){

        sl->first->prox = elem; // O novo nó passa a ser o primeiro elemento da lista;
        sl->last = elem; // E como a lista esta vazia, tambem passa a ser o ultimo elemento      
    
    }else{

        //Faz Swap
        SNode *aux = sl->first->prox; //Recebe o endereço do primeiro elemento.
        elem->prox = aux; // O novo no aponta agora para o antigo primeiro elemento que agora é segundo nó.
        sl->first->prox = elem; // A cabeça agora aponta para o elemento criado, que agora é o primeiro nó.
        //printf("tam = %d\n",sl->tam);
    }

     sl->tam++; 

}

void SList_InsertFinalList(SList *sl, int val){

    SNode *elem = SList_CreateNode(val);

    if(SList_isEmpty(sl) == true){

        sl->first->prox = elem; // O novo nó passa a ser o primeiro elemento da lista;
        sl->last = elem; // E como a lista esta vazia, tambem passa a ser o ultimo elemento

    }else{

        sl->last->prox = elem;
        sl->last = sl->last->prox;
        sl->last->prox = NULL;
        
    }

    sl->tam++;

}

void SList_PrintSList(SList *sl){

    SNode *aux = sl->first->prox;

    printf("\nLista => ");

    while(aux != NULL){

        printf("%d -> ", aux->val);
        aux = aux->prox; // Percorre a Lista.

    }

    puts("NULL\n");
    printf("Tamanho da Lista = %d\n\n",sl->tam);
    
    printf("Primeiro elemento = %d\nUltimo elemento = %d\nlast->prox = NULL? %d\n\n",sl->first->prox->val, sl->last->val, sl->last->prox == NULL);
    
}

void SList_RemoveNode(SList *sl, int val){
    
    if(!SList_isEmpty(sl)){

        SNode *ant = NULL; //Ponteiro que apontará para as posicoes anteriores.
        SNode *pos = sl->first->prox; //Ponteiro que irá percorrer a lista.

        //Até encontrar um valor ou percorrer toda a Lista
        while(pos != NULL && pos->val !=val){

            //Atualiza os Ponteiros.
            ant = pos;
            pos = pos->prox;

        }
        
        //Neste caso foi encontrado um nó com o valor procurado.
        if(pos != NULL){

            //Se o elemento procurado for o ultimo nó da lista
            if(sl->last == pos){
                
                sl->last = ant;

            }

            //Se o elemento procurado for o primeiro nó da lista
            if(sl->first->prox == pos){

                sl->first->prox = pos->prox;

            }else{  //Se o elemento estiver entre o primeiro e o ultimo nó da lista.

                ant->prox = pos->prox;

            }

            free(pos);
            sl->tam--;
        
        }else{

            puts("---> Valor procurado não encontrado!\n\n");

        }

    }else{

        puts("---> Lista Vazia!\n\n");

    }
}

void SList_DestroySList(SList *sl){
    
    SNode *aux = NULL;
    SNode *pos = sl->first->prox;
    SNode *f = sl->first;
    
    while(pos != NULL){

        aux = pos;
        pos = pos->prox;
        free(aux);
        
    }
    free(pos);
    sl = NULL;
    puts("----> Lista Desalocada!\n");
    //printf("sl is Null? %d", sl == NULL);

}


