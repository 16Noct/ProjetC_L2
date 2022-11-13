#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dictionnary.h"

t_tree createBaseTree(){
    t_tree mytree;
    mytree.root = createLetterNode('0');
    return mytree;
}

FILE* importFile(char* dictionnaryName){
    FILE* dictionnaryFile = fopen(dictionnaryName,"r");
    return dictionnaryFile;
}

void createListFromFile(p_tree nameTree,p_tree verbsTree,p_tree adjTree,p_tree advTree,FILE * monFichier){
    char * line = (char *) malloc(300*sizeof(char));
    while (fgets(line,120,monFichier)) {
        // On parse les différents éléments de chaque ligne
        char * arrowed = calloc(strlen(line),sizeof(char)+1);
        char * radical = calloc(strlen(line),sizeof(char)+1);
        char * forms = calloc(strlen(line),sizeof(char)+1);

        strcpy(arrowed,strtok(line,"\t"));
        strcpy(radical,strtok(NULL,"\t"));
        strcpy(forms,strtok(NULL,"\n"));
        //On insère les différents éléments sous forme de noeud de l'arbre
        printf("A: %s R : %s F : %s\n",arrowed,radical,forms);
        p_letter_node tmp = NULL;
        if(strstr(forms,"Ver:")){
            tmp = verbsTree->root;
        }else if(strstr(forms,"Nom:")){
            tmp = nameTree->root;
        }else if(strstr(forms,"Adj:")){
            tmp = adjTree->root;
        }else{
            tmp = advTree->root;
        }

        for(int i = 0; i < (int) strlen(radical); i++){
            // ================== Les problèmes commencent ici

            if(isForbiddenChar(radical[i]) == 0) {
                p_cell ptr_cell = NULL;
                int hasFound = 0;
                ptr_cell = tmp->sons->head;// On se met sur la tête de la liste des fils
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
                    if(tmp->sons->head == NULL){
                        tmp->sons->head = mycell;
                    }else{
                        p_cell tmp_cell = tmp->sons->head;
                        while(tmp_cell->next != NULL){
                            tmp_cell = tmp_cell->next;
                        }
                        tmp_cell->next = mycell;
                    }
                    tmp = mycell->son;
                }
            }

        }
        if(tmp->arrowForms->head == NULL){
            tmp->arrowForms->head = createWordCell();
            strcpy(tmp->arrowForms->head->son->arrowed,arrowed);
            strcpy(tmp->arrowForms->head->son->forms,forms);

        }else{
            p_word_cell tmp_cell = tmp->arrowForms->head;
            while(tmp_cell->next != NULL){
                tmp_cell = tmp_cell->next;
            }
            tmp_cell->next = createWordCell();
            strcpy(tmp_cell->next->son->arrowed,arrowed);
            strcpy(tmp_cell->next->son->forms,forms);
        }


        free(arrowed);
        free(radical);
        free(forms);
    }

    free(line);
    fclose(monFichier);
}
