#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dictionnary.h"
#define MAX_LONGUEUR_LIGNE 1000
#define MAX_LIGNES 100

FILE* importFile(char* dictionnaryName){
    FILE* dictionnaryFile = fopen(dictionnaryName,"r");
    return dictionnaryFile;
}


p_word_cell createWordCell(/*char * arrowed,char * radical,char * forms*/)
{
    p_word_cell p_res;

    p_res = (p_word_cell) malloc(sizeof(p_word_cell));
    p_res->word = (p_word) malloc(sizeof(p_word));

    p_res->word->arrowed = (char *) malloc(100*sizeof(char));
    p_res->word->radical = (char *) malloc(100*sizeof(char));
    p_res->word->forms = (char *) malloc(100*sizeof(char));
    p_res->next = NULL;

    return p_res;
}

void createListFromFile(t_word_list * mylist,FILE * monFichier){
    char * line;
    p_word_cell newCell;
    p_word_cell prev;
    while (fgets(line,300000,monFichier) != NULL) {
        newCell = createCellFromLine(line);
        if(mylist->head == NULL){
            mylist->head = newCell;
            prev = mylist->head;
        }else{
            prev->next = newCell;
            prev = newCell;
        }
    }
    fclose(monFichier);
}

p_word_cell createCellFromLine(char * myLine){
    p_word_cell newCell = createWordCell();
    char * item = (char*) malloc(100*sizeof(char));
    strcpy(newCell->word->arrowed,strtok(myLine,"\t"));
    strcpy(newCell->word->radical,strtok(NULL,"\t"));
    strcpy(newCell->word->forms,strtok(NULL,"\n"));
    return newCell;
}

void printList(t_word_list * mylist){
    p_word_cell tmp = mylist->head;
    while(tmp != NULL){
        printf("A : %s R : %s F : %s\n",tmp->word->arrowed,tmp->word->radical,tmp->word->forms);
        tmp = tmp->next;
    }
}

/*
 *
 * void getLinesFromFile(t_word_list * mylist,FILE * monFichier){
    char * line;
    char * item;
    p_word_cell prev = mylist->head;

    while (fgets(line,120,monFichier)) {
        p_word_cell newCell = createWordCell("","","");

        item = strtok(line,"\t");
        newCell->word->arrowed = item;

        item = strtok(NULL,"\t");
        newCell->word->radical = item;

        item = strtok(NULL,"\n");
        newCell->word->forms = item;

        if(mylist->head == NULL){
            mylist->head = newCell;
            prev = newCell;
        }else{
            prev->next = newCell;
            prev = newCell;
        }
    }

    fclose(monFichier);
}

 *
 *
 *
 */
/*
 * OLD CODE FOR THIS FUNCTION
 *
 * while(!feof(monFichier)){
    char * myChain;
    fgets(myChain,1000,monFichier);
    char * arrowed = strtok(myChain,"\t");
    newCell = createWordCell(arrowed,"","");
    char * radical = strtok(NULL,"\t");
    newCell->word->radical = radical;


}*/

//newCell->word->arrowed = arrowed;
//newCell->word->radical = radical;
//newCell->word->forms = forms;
//int lineNumber = 0;
/*while(fgets(myChain,1000,monFichier) != NULL){
    printf("%s",myChain);
    lineNumber += 1;
}*/

/* 1.
 * Grande liste chainée pour stocker chaque mot du dictionnaire
 *          -> liste qui contient une structure de maillon spéciale
 *              maillon
 *                  char* arrowed;
 *                  char* normal;
 *                  char* forms;
 *                  p_cell next;
 *
 * 2. Créer un algorithme pour créer un arbre à partir de la liste chainée
 *           -> On créer un arbre qui a d'office 26 fils à chaque noeuds
 *           -> On créer un arbre N-air, donc chaque noeud doit pouvoir stocker plusieurs fils
 *           noeud de structure = letter_node
 *                  -> On va stocker ces fils dans un tableau/une liste
 *
 *
*/