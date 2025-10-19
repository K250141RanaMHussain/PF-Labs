#include <stdio.h>
int main(){
	int i;
	int n;
	int multiplication = 0;
	
	printf("Enter number for multiplication table: ");
	scanf("%d", &n);

	for(i=1; i<11 ;i++){
		multiplication = n*i; 
		printf("%d x %d = %d \n",n,i,multiplication);
		}
	

	return 0;
}
