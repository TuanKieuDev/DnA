#include <stdio.h>
#include <stdlib.h>
#include "stack2.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Address *top=NULL;
	int n,tel;
	char email[30];
	char name[30];
    do {
        do {
            printf("Enter the name: \n");
            gets(name);
            printf("Enter telephone number: ");
            scanf("%d",&tel);
            printf("Enter email address: ");
            scanf("%s",email);
            top = push(top,name,tel,email);
//            printStack();
            printf("Enter 1 to continue\n");
            scanf("%d",&n);
        } while(n == 1);
        printf("Enter 1 to pop an element\n");
        scanf("%d",&n);
        while( n == 1) {
            top = pop(top,&name,&tel,&email);
            printf("The name poped is %s\n",name);
            printf("The tel poped is %d\n",tel);
            printf("The email poped is %s\n",email);
            printf("Enter 1 to pop an element\n");
            scanf("%d",&n);
        }
        printf("Enter 1 to continue\n");
        scanf("%d",&n);
    } while(n == 1);
	return 0;
}
