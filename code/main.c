#include "slist.h"

int main(){

    //Teste das Funcoes.

    SList l;
    
    SList_Create(&l);

    SList_InsertHead(&l,3);
    SList_InsertHead(&l,2);
    SList_InsertHead(&l,1);
    SList_InsertFinalList(&l,4);
    SList_InsertFinalList(&l,5);
    SList_InsertFinalList(&l,6);
    SList_InsertFinalList(&l,7);

    SList_PrintSList(&l);  

    puts("---> REMOVE ELEMENTO 1\n");
    SList_RemoveNode(&l,1);
    SList_PrintSList(&l);
    puts("---> REMOVE ELEMENTO 4\n");
    SList_RemoveNode(&l,4);
    SList_PrintSList(&l);
    puts("---> REMOVE ELEMENTO 7\n");
    SList_RemoveNode(&l,7);
    SList_PrintSList(&l);

    SList_RemoveNode(&l,14);

    SList_DestroySList(&l);

    return 0;
}

