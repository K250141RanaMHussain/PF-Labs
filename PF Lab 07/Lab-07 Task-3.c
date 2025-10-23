#include <stdio.h>
int main(){
	
	int num;
	int value;
	int i=0;
	int j=0;
	printf("Enter the number of elements you want in the array:\n");
	scanf("%d",&num);
	
	int array[num];
	
	printf("--------ENTERING YOUR %d ELEMENTS IN THE ARRAY---------- \n");
	for (i=0;i<num;i++){
		printf("Enter element at place %d:",i);
		scanf("%d",&array[i]);
	}
	
	printf("Enter the value you want to check for occurences and remove from the array:\n");
	scanf("%d",&value);
	
	int size=num;
	for (i=0; i<size;i++){
		
		if (array[i] == value) {
        // Shift only elements after current position
        for (j = i; j < size - 1; j++) {
            array[j] = array[j + 1];
        }
        size--;
        i--; // Check current position again since elements shifted left
    }
	}
	
	printf("Edited array is :\n");
	
	for (i=0;i<size;i++){
		
		printf(" %d |",array[i]);
	}
	printf("The size of the edited array is:%d",size);
	return 0;
}
