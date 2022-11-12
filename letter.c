//
// Created by Alex on 2022/11/04.
//
#include "letter.h"
#include <stdlib.h>

p_cell createCell(char letter){
    p_letter_node myNode = createLetterNode(letter);
    p_cell myCell = (p_cell) malloc(1*sizeof(p_cell));
    myCell->son = myNode;
    myCell->next = NULL;
}

t_std_list createEmptyList(){
    t_std_list mylist;
    mylist.head = NULL;
    return mylist;
}

p_letter_node createLetterNode(char letter){
    p_letter_node myNode = (p_letter_node) malloc(sizeof(p_letter_node));
    myNode->letter = letter;
    myNode->sons = createEmptyList();
    /*myNode->sons = (struct s_letter_node *) (p_letter_node *) malloc(26 * sizeof(p_letter_node));
    myNode->nbElts = 0;*/
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