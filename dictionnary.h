#include <stdio.h>
#include <stdlib.h>
#include "letter.h"
// importDictionnary : importer un fichier dictionnaire dans le programme
// renvoi FILE* si le fichier est trouvé sinon renvoi 0.

typedef struct s_tree
{
    p_letter_node root;
} t_tree, *p_tree;

t_tree createBaseTree();
FILE* importFile(char* dictionnaryName);
void createListFromFile(p_tree mytree,FILE * monFichier);
