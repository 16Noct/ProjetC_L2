#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dictionnary.h"
#define MAX_LONGUEUR_LIGNE 1000
#define MAX_LIGNES 100

t_tree createBaseTree(){
    t_tree mytree;
    mytree.root = createLetterNode('0');
    return mytree;
}

FILE* importFile(char* dictionnaryName){
    FILE* dictionnaryFile = fopen(dictionnaryName,"r");
    return dictionnaryFile;
}

void createListFromFile(p_tree mytree,FILE * monFichier){
    char * line = (char *) malloc(300*sizeof(char));
    while (fgets(line,120,monFichier)) {
        // On parse les différents éléments de chaque ligne
        char * arrowed = (char *) malloc(300*sizeof(char));
        char * radical = (char *) malloc(300*sizeof(char));
        char * forms = (char *) malloc(300*sizeof(char));
        strcpy(arrowed,strtok(line,"\t"));
        strcpy(radical,strtok(NULL,"\t"));
        strcpy(forms,strtok(NULL,"\n"));
        //On insère les différents éléments sous forme de noeud de l'arbre
        printf("A: %s R : %s F : %s\n",arrowed,radical,forms);
        p_letter_node tmp = mytree->root;
        for(int i = 0; i < strlen(radical); i++){
            if(isForbiddenChar(radical[i]) == 0) {
                p_cell ptr_cell = tmp->sons.head; // On se met sur la tête de la liste des fils
                int hasFound = 0;
                while(ptr_cell != NULL && hasFound != 1){
                    if(radical[i] == ptr_cell->son->letter){
                        tmp = ptr_cell->son;
                        hasFound = 1;
                    }else{
                        ptr_cell = ptr_cell->next;
                    }
                }

                if(hasFound == 0){
                    //p_letter_node myNewNode = createLetterNode(radical[i]);
                    p_cell mycell = createCell(radical[i]);
                    if(tmp->sons.head == NULL){
                        tmp->sons.head = mycell;
                        tmp = mycell->son;
                    }else{
                        p_cell tmp_cell = tmp->sons.head;
                        while(tmp_cell->next != NULL){
                            tmp_cell = tmp_cell->next;
                        }
                        tmp_cell->next = mycell;
                    }
                }
            }

        }


        free(arrowed);
        free(radical);
        free(forms);
    }

    free(line);
    fclose(monFichier);
}
