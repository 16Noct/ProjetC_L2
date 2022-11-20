#include "letter.h"
#include <stdlib.h>

p_cell createCell(char letter){
    p_letter_node myNode = createLetterNode(letter);
    p_cell myCell = (p_cell) malloc(sizeof(t_cell));
    myCell->son = myNode;
    myCell->next = NULL;
    return myCell;
}

p_word_cell createWordCell(){
    p_word_cell myCell = (p_word_cell) malloc(sizeof(t_word_cell));
    p_word myWord = (p_word) malloc(sizeof(t_word));
    myWord->arrowed = calloc(40,sizeof(char));
    myWord->forms = calloc(40,sizeof(char));
    myCell->son = myWord;
    myCell->next = NULL;
    return myCell;
}

t_std_list * createEmptyList(){
    t_std_list * mylist = (t_std_list *) (malloc(sizeof(t_std_list)));
    mylist->head = NULL;
    return mylist;
}

t_word_list * createEmptyWordList(){
    t_word_list * mylist = (t_word_list *) (malloc(sizeof(t_word_list)));
    mylist->head = NULL;
    return mylist;
}


p_letter_node createLetterNode(char letter){
    p_letter_node myNode = (p_letter_node) malloc(sizeof(t_letter_node));
    myNode->letter = letter;
    myNode->sons = createEmptyList();
    myNode->arrowForms = createEmptyWordList();
    myNode->nbSons = 0;
    return myNode;
}

int isForbiddenChar(char letter){
    char forbiddenChars[2] = {'\r','\t'};
    for(int i = 0; i < 2; i++){
        if(letter == forbiddenChars[i]){
            return 1;
        }
    }
    return 0;
}