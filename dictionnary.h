#include <stdio.h>
#include <stdlib.h>
#include "letter.h"
// importDictionnary : importer un fichier dictionnaire dans le programme
// renvoi FILE* si le fichier est trouvé sinon renvoi 0.
/*
struct s_word{
    char * arrowed;
    char * radical;
    char * forms;
} typedef word;
*/

typedef struct s_cell
{
    p_letter_node son ;
    struct s_cell * next ;
} t_cell, *p_cell ;

typedef struct s_std_list
{
    p_cell head;
} t_std_list ;

// Words

typedef struct s_word // Mot d'un maillon d'une liste chainée contenant des mots
{
    char * arrowed;
    char * radical;
    char * forms;

} t_word, * p_word ;

typedef struct s_word_cell // Maillon d'un liste chainée contenant des mots
{
    p_word word ;
    struct s_word_cell * next ;
} t_word_cell, *p_word_cell ;

typedef struct s_word_list // Liste chainée contenant des mots
{
    p_word_cell head;
} t_word_list ;

p_word_cell createWordCell(/*char * arrowed,char * radical,char * forms*/);
p_word_cell createCellFromLine(char * myLine);
FILE* importFile(char* dictionnaryName);
void createListFromFile(t_word_list * myList,FILE * monFichier);
p_word_cell createWordCell2(char * constructionString);
void printList(t_word_list * mylist);

//parseLineFromFile()