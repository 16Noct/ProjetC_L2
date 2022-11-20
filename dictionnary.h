#include <stdio.h>
#include <stdlib.h>
#include "letter.h"
// importDictionnary : importer un fichier dictionnaire dans le programme
// renvoi FILE* si le fichier est trouvÃ© sinon renvoi 0.

typedef struct s_tree
{
    p_letter_node root;
} t_tree, *p_tree;

t_tree createBaseTree();
FILE* importFile(char* dictionnaryName);
void createListFromFile(p_tree nameTree,p_tree verbsTree,p_tree adjTree,p_tree advTree,FILE * monFichier);
int isWordInTree(char * word,t_tree mytree);
char * extractRandomRadicalWord(t_tree mytree);
char * extractRandomArrowedWord(t_tree mytree);