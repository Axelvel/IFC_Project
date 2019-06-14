#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

void viderBuffer();
int cherche_exercice(char[][25]);
void Creation_exercice(void);
void execution(S_question[],int,int);
void inscription(char[]);
void lectureFichier(FILE * fichier, S_question[], int);
int menu();
int nombreQuestions(FILE * fichier);

typedef struct S_question S_question;
struct S_question
{
    char solution[50];
    int points;
    char enonce[100];
};

#ifdef _WIN32
#define NETTOYER() system("cls");
#elif __linux__
#define NETTOYER() system("clear");
#endif

#endif // FONCTIONS_H_INCLUDED
