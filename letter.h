//
// Created by Alex on 2022/11/02.
//

#ifndef PROJETCREEL_LETTER_H
#define PROJETCREEL_LETTER_H

#endif //PROJETCREEL_LETTER_H

typedef struct s_letter_node t_letter_node, *p_letter_node ;

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
    t_std_list sons ;
};

t_std_list createEmptyList();
p_cell createCell(char letter);
p_letter_node createLetterNode(char letter);
int isForbiddenChar(char letter);