#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct {
	char name[30];
	char phone[15];
	char email[30];
}Address;

void swap(Address *a, Address *b)
{
	Address temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

//void SWAP(Address* a, Address* b, Address* c)
//{
//    // Before overwriting b, store its 
//    // value in temp.
//    Address temp = *b;
//  
//    // Now do required swapping starting
//    // with b.
//    *b = *a;
//    *a = *c;
//    *c = temp;
//}
  

void adjust(Address list[], int root, int n){
	int child; 
	Address temp;
	temp=list[root]; 
	child=2*root;
	while (child <= n) {
		if ((child < n) &&
		(strcmp(list[child].name,list[child+1].name)<0))
		child++;
		if (strcmp(list[root].name,list[child].name)>0) break;
		else {
			swap(&list[child/2], &list[child]);
			child *= 2;
		}
	} 
}

// main function to do heap sort
void heapSort(Address arr[], int n)
{
    // Build heap (rearrange array)
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
        adjust(arr, n, i);
 
    // One by one extract an element from heap
    for (i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(&arr[0], &arr[i]);
 
        // call max heapify on the reduced heap
        adjust(arr, i, 0);
    }
}

//void heapsort(Address list[], int n){
//	int i, j;
//	Address temp;
//	for (i=n/2; i>0; i--) 
//	adjust(list, i, n);
//	for (i=n-1; i>0; i--) {
//	SWAP(&list[1], &list[i+1], &temp);
//	adjust(list, 1, i);
//	}
//}


void insertionSort(Address a[], int n)
{
    int i, j;
    int k=0;
    Address key;
    for (i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;
        while (j >= 0 && strcmp(a[j].name,key.name)>0) {
            a[j + 1] = a[j];
            j = j - 1;
            k++;
        }
        a[j + 1] = key;
    }
    printf("\n\n\n\nThe number of comparisons is %d",k);
}

void selection(Address a[], int n){ 
	int k=0;
	int i, j, min;
	Address tmp;
	for (i= 0; i< n-1; i++){
		min = i;
		for (j = i+1; j <=n-1 ; j++) 
			if ( strcmp(a[j].name,a[min].name)<0){
				min = j;
				k++;
			}
			tmp= a[i];
			a[i]= a[min];
			a[min] = tmp;
	}
	printf("\n\n\n\nThe number of comparisons is %d",k); 
}

void printList(Address list[],int n){
	int i=0;
	for(i=0;i<n;i++){
		printf("\n\nNumber %d: ",i+1);
		printf("\nName: %s",list[i].name);
		printf("\nPhone: %s",list[i].phone);
		printf("\nEmail: %s",list[i].email);
	}
}

int main(int argc, char *argv[]) {
	Address data[100];
	Address b;
	int i;
	//read from file
	char *filepath_in = "data.txt";
	char *filepath_out = "data_out.txt";
	FILE *fin=fopen(filepath_in,"r+");
    if (fin == NULL) {
        printf("Cannot open file %s for reading.\n", filepath_in);
        return -1;
    }
	for(i=0;i<10;i++){
		fscanf(fin,"%s%s%s",data[i].name,data[i].phone,data[i].email);
		
	}
	fclose(fin);
	
	printList(data,3);
	//selection(data,3);
	//insertionSort(data,3);
	heapSort(data,3);
	printf("\n\nAfter use heap sort: \n");
	printList(data,3);
	
	//write to another file
    FILE *fout = fopen(filepath_out, "wt");
    if (fout == NULL) {
        printf("Cannot open file %s for writting.\n", filepath_out);
        return -1;
    }
    for(i=0;i<3;i++){
    	fprintf(fout, "%s\t%s\t%s\n", data[i].name, data[i].phone, data[i].email);
    }
    fclose(fout);
	
	return 0;
}
