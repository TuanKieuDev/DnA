#include "stack2.h"
#include <stdlib.h>
#include <stdio.h>
Address *push(Address *p,char name[], int tel,char email[]) {
    Address *temp;
    temp=(Address *) malloc(sizeof(Address));
    if(temp==NULL) {
        printf("No Memory available Error\n");
        exit(0);
    }
    temp->name = name;
    temp->tel = tel;
    temp->email = email;
    temp->link = p;
    p = temp;
    return(p);
}
Address *pop(Address *p, char *name, int *tel, char *email) {
    Address *temp;
    if(p==NULL) {
        printf("The stack is empty cannot pop Error\n");
        exit(0);
    }
    *name = p->name;
    *tel = p->tel;
    *email = p->email;
    temp = p;
    p = p->link;
    free(temp);
    return(p);
}
