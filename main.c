#include <stdlib.h>
#include <stdio.h>
#include "dictionnary.h"
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[]){
    //FILE * monDico = importDictionnary("/dicos/dico_10_lignes.txt");
    FILE * monDico = importFile("C:\\Users\\Alex\\Documents\\Alex\\ECOLE\\PROJETS\\L2\\ProjetCREEL\\ProjetC_L2\\dico.txt");
    if(monDico == NULL){
        printf("Erreur lors du lancement du programme. ");
        printf("%s",strerror(errno));
    }else{
        printf("Programme lance.");
        t_word_list dictionnaryStdList;
        dictionnaryStdList.head = NULL;
        createListFromFile(&dictionnaryStdList,monDico);
        //printf("\n A : %s\tR : %s\t F : %s\n",dictionnaryStdList.head->next->word->arrowed,dictionnaryStdList.head->next->word->radical,dictionnaryStdList.head->next->word->forms);
        printList(&dictionnaryStdList);
    }
    return 0;
}