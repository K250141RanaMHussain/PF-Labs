#include <stdio.h>
int main(){
	int n,d;
	int rem = 0;
	int sum = 0;
	int i=0;
	printf("Enter PIN: ");
	scanf("%d",&n);
	d=n;
	while(d){
		d=d/10;
		i++;
	}
	if(i==4 && n<=9999){
	while(n){
		rem = n%10;
		sum = sum + rem;
		n = n/10;
	}
	if(sum>10){
	printf("Its a strong PIN. \n");
	}
	else{
		printf("Its a weak PIN. \n");
	}
	}
	else{
		printf("Invalid PIN. \n");
	}
	

	return 0;
}
