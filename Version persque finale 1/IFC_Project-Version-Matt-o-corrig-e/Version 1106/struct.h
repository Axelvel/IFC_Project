#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED

typedef struct S_question S_question;
struct S_question
{
    char solution[50];
    int points;
    char enonce[100];
};

#endif // STRUCT_H_INCLUDED
