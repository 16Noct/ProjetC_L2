#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dictionnary.h"
#include <time.h>

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
        //printf("A: %s R : %s F : %s\n",arrowed,radical,forms);
        p_letter_node tmp = NULL;
        if(strstr(forms,"Ver:")){
            tmp = verbsTree->root;
        }else if(strstr(forms,"Nom:")){
            tmp = nameTree->root;
        }else if(strstr(forms,"Adj:")){
            tmp = adjTree->root;
        }else {
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
                        tmp->nbSons+=1;
                    }else{
                        p_cell tmp_cell = tmp->sons->head;
                        while(tmp_cell->next != NULL){
                            tmp_cell = tmp_cell->next;
                        }
                        tmp_cell->next = mycell;
                        tmp->nbSons+=1;
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

int isWordInTree(char * word,t_tree mytree){
    p_letter_node tmp = mytree.root;
    for(int i = 0; i < (int) strlen(word); i++){

        if(isForbiddenChar(word[i]) == 0) {
            p_cell ptr_cell = NULL;
            int hasFound = 0;
            ptr_cell = tmp->sons->head;// On se met sur la tête de la liste des fils
            while(ptr_cell != NULL && hasFound != 1){
                if(word[i] == ptr_cell->son->letter){
                    tmp = ptr_cell->son;
                    hasFound = 1;
                }else{
                    ptr_cell = ptr_cell->next;
                }
            }

            if(hasFound == 0){
                return 0;
            }
        }

    }
    return 1;
}

char * extractRandomRadicalWord(t_tree mytree){
    char * myFinalWord = calloc(60,sizeof(char));
    p_letter_node tmp = mytree.root;

    while(tmp->sons->head != NULL){
        p_cell ptr_cell = tmp->sons->head;
        int i = 0;
        int max = tmp->nbSons-1;
        int min = 0;
        int num = 0;
        int randNum = rand();
        num = (( randNum % (max + 1 - min)) + min);
        for(i = 0;i < num; i++){
            ptr_cell = ptr_cell->next;
        }

        printf("%c",ptr_cell->son->letter);
        //strcat(myFinalWord,&ptr_cell->son->letter);
        tmp = ptr_cell->son;
    }
    return myFinalWord;
}

char * extractRandomArrowedWord(t_tree mytree){
    char * myFinalWord = calloc(60,sizeof(char));
    p_letter_node tmp = mytree.root;
    p_cell ptr_cell;
    while(tmp->sons->head != NULL){
        ptr_cell = tmp->sons->head;
        int i = 0;
        int max = tmp->nbSons-1;
        int min = 0;
        int num = 0;
        int randNum = rand();
        num = (( randNum % (max + 1 - min)) + min);
        for(i = 0;i < num; i++){
            ptr_cell = ptr_cell->next;
        }

        //strcat(myFinalWord,&ptr_cell->son->letter);
        tmp = ptr_cell->son;
    }
    // On prend le premier qu'on trouve là
    char * arrowed = ptr_cell->son->arrowForms->head->son->arrowed;
    char * forms = ptr_cell->son->arrowForms->head->son->forms;
    if(strstr(forms,"Nom:Mas+SG")){
        printf("le ");
    }else if(strstr(forms,"Nom:Mas+PL")){
        printf("les ");
    }else if(strstr(forms,"Nom:Fem+SG")){
        printf("la ");
    }else if(strstr(forms,"Nom:")){
        printf("les ");
    }
    printf("%s",ptr_cell->son->arrowForms->head->son->arrowed);
    return myFinalWord;
}
