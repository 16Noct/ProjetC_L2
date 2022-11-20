#ifndef PROJETCREEL_LETTER_H
#define PROJETCREEL_LETTER_H

#endif //PROJETCREEL_LETTER_H

typedef struct s_letter_node t_letter_node, *p_letter_node ;
// Structure stockant les formes fléchées
typedef struct s_word t_word, *p_word ;

struct s_word
{
    char * arrowed;
    char * forms;
};

typedef struct s_word_cell
{
    p_word son ;
    struct s_word_cell * next ;
} t_word_cell, *p_word_cell ;

typedef struct s_word_list
{
    p_word_cell head ;
} t_word_list ;


typedef struct s_cell
{
    p_letter_node son ;
    struct s_cell * next ;
} t_cell, *p_cell ;

typedef struct s_std_list
{
    p_cell head ;
} t_std_list ;

struct s_letter_node
{
    char letter ;
    t_std_list  * sons ;
    t_word_list  * arrowForms;
    int nbSons;

};

t_std_list * createEmptyList();
p_cell createCell(char letter);
p_letter_node createLetterNode(char letter);
int isForbiddenChar(char letter);
t_word_list * createEmptyWordList();
p_word_cell createWordCell();