#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

//void printStack(){
// if(!isEmpty()){
//     int temp = pop();
//     printStack();
//     printf(" %d ", temp);
//     push( temp);
//    }
//}

void insertAtBottom(struct node** top_ref, 
                                 int item) 
{ 
    if (isEmpty(*top_ref)) 
        push(top_ref, item); 
    else
    { 
  
        // Hold all items in Function Call 
        // Stack until we reach end of the 
        // stack. When the stack becomes 
        // empty, the isEmpty(*top_ref)becomes 
        // true, the above if part is executed 
        // and the item is inserted at the bottom  
        int temp = pop(top_ref,item); 
        insertAtBottom(top_ref, item); 
  
        // Once the item is inserted  
        // at the bottom, push all 
        // the items held in Function  
        // Call Stack  
        push(top_ref, temp); 
    } 
} 


void reverse(struct node** top_ref,int value) 
{ 
    if (!isEmpty(*top_ref)) 
    { 
        int temp = pop(top_ref,value); 
        reverse(top_ref); 
        insertAtBottom(top_ref, temp); 
    } 
} 

void main() {
    struct node *top = NULL;
    int n,value;
    do {
        do {
            printf("Enter the element to be pushed\n");
            scanf("%d",&value);
            top = push(top,value);
//            printStack();
            printf("Enter 1 to continue\n");
            scanf("%d",&n);
        } while(n == 1);
        
         	printf("\n Original Stack "); 
    		print(top); 
    		reverse(&top); 
    		printf("\n Reversed Stack "); 
    		print(top); 
    
    
        printf("\nEnter 1 to pop an element\n");
        scanf("%d",&n);
        while( n == 1) {
            top = pop(top,&value);
            printf("The value poped is %d\n",value);
            printf("Enter 1 to pop an element\n");
            scanf("%d",&n);
        }
        printf("Enter 1 to continue\n");
        scanf("%d",&n);
    } while(n == 1);
}
