#include <stdlib.h>
#include <stdio.h>
#include "dictionnary.h"
#include <errno.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[]){
    //FILE * monDico = importDictionnary("/dicos/dico_10_lignes.txt");
    FILE * monDico = importFile("C:\\Users\\Alexandre\\CLionProjects\\projetarbre\\ProjetC_L2\\dico.txt");
    if(monDico == NULL){
        printf("Erreur lors du lancement du programme. ");
        printf("%s",strerror(errno));
    }else{
        srand(time(NULL));
        printf("Programme lance.\n");
        //t_tree mytree = createBaseTree();
        t_tree nameTree = createBaseTree();
        t_tree verbsTree = createBaseTree();
        t_tree adjTree = createBaseTree();
        t_tree advTree = createBaseTree();

        //createListFromFile(&mytree,monDico);
        createListFromFile(&nameTree,&verbsTree,&adjTree,&advTree,monDico);
        //printf("le mot stabilimetre est dans l'arbre ? : %d\n",isWordInTree("stabilimetre",nameTree));

        printf("Modèle 1 : \n");
        printf("%s ",extractRandomRadicalWord(nameTree));
        printf("%s ",extractRandomRadicalWord(adjTree));
        printf("%s ",extractRandomRadicalWord(verbsTree));
        printf("%s ",extractRandomRadicalWord(nameTree));

        printf("\n\nModèle 2 : \n");
        printf("%s ",extractRandomRadicalWord(nameTree));
        printf("qui ");
        printf("%s ",extractRandomRadicalWord(verbsTree));
        printf("%s ",extractRandomRadicalWord(verbsTree));
        printf("%s ",extractRandomRadicalWord(nameTree));
        printf("%s ",extractRandomRadicalWord(adjTree));

        printf("\n\nModèle 2 (flechies) : \n");
        printf("%s ",extractRandomArrowedWord(nameTree));
        printf("qui ");
        printf("%s ",extractRandomArrowedWord(verbsTree));
        printf("%s ",extractRandomArrowedWord(verbsTree));
        printf("%s ",extractRandomArrowedWord(nameTree));
        printf("%s ",extractRandomArrowedWord(adjTree));
    }
    return 0;


}
