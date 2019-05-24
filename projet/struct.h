#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED

typedef struct S_question S_question;
struct S_question
{
    int solution;
    int points;
    char enonce[100];
};

#endif // STRUCT_H_INCLUDED
