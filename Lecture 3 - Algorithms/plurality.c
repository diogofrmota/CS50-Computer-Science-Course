#include <cs50.h>
#include <stdio.h>
#include <string.h>

#define MAX 9 // Número máximo de candidatos

typedef struct
{
    string name;
    int votes;
}
candidates;

candidate candidates[MAX];
int candidate_count;


