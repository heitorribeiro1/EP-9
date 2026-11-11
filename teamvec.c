#include "teamvec.h"
#include <stdlib.h>

struct teamvec {
    int size;
    int capacity;
    Team **data;
};

TeamVec *tv_create(void) {
    TeamVec *tv = malloc(sizeof(TeamVec));
    tv->size = 0;
    tv->capacity = 4;
    tv->data = malloc(tv->capacity * sizeof(Team *));
    return tv;
}

void tv_insert(TeamVec *tv, Team *t) {
    if (tv->size == tv->capacity) {
        tv->capacity *= 2;
        tv->data = realloc(tv->data, tv->capacity * sizeof(Team *));
    }
    tv->data[tv->size++] = t;
}

int tv_size(TeamVec *tv) {
    return tv->size;
}

Team *tv_get(TeamVec *tv, int i) {
    return tv->data[i];
}

void tv_free(TeamVec *tv) {
    for (int i = 0; i < tv->size; i++)
        team_free(tv->data[i]);
    free(tv->data);
    free(tv);
}
