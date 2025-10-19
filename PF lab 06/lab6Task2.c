#include <stdio.h>
int main(){
	int n;
	int rem = 0;
	int sum = 0;
	
	printf("Enter numbers for reversal: ");
	scanf("%d",&n);
	
	printf("The reverse of given input is:");
	while(n){
		rem = n%10;
		printf("%d",rem);
		sum = sum + rem;
		n = n/10;
		}
	

	return 0;
}
