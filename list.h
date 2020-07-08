#include"cell.c"

typedef struct List{
    Cell *first, *last;
    int n;
}List;

List* createList();
Cell* removeList(List *l, int op);
Task* removeFront(List *l, int op);
Task* removeEnd(List *l, int op);
Cell* searchForCell(List *l, char *name);
Task* searchForTask(List *l, char *name);
int insert(List *l, Task *ta, int op);
Task* remove(List *l, char *name, int op);
void printList(List *l);