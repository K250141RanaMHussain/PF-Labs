#include<stdio.h>
 
 int main(){
 	float BS, HRA, DA, GS;
 	
 	printf("Enter your basic salary: ");
 	scanf("%f",&BS);
 	
 	if( BS > 0){
	 
 	HRA = BS/100 * 10;
 	DA = BS/100 * 5;
 	GS = BS + HRA + DA;
 	
 	 printf("\n--- Salary Breakdown ---\n");
 	 printf("First of all, your Basic Salary is: Rs %.0f \n", BS);
	 printf("Your House rent allowance is: Rs %.2f \n", HRA);
	 printf("Your Dearness allowance is: Rs %.2f \n", DA);
	 printf("So, Your Gross Salary is: Rs %.2f \n", GS);
	 }
	 else {
	 	printf("Your input is invalid.");
	 }
 }
