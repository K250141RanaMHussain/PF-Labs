#include <stdio.h>
int main(){
	int n=0;
	int i = 0;
	int sum = 0;
	float average = 0;
	printf("Enter marks of each subject: \n");
	
	do{
		scanf("%d",&n);
		if(n!=-1){
		sum = sum + n;
		i++;
		}
	}while(n!=-1);
	
	average = (float) sum/i;
	printf("The average of marks are: %.2f", average);

	return 0;
}
