#include <stdio.h>

int main() {
    int num;
    int rem=0;
    int evenCount = 0;
	int oddCount = 0;
	int digit=0;

    printf("Enter a number: ");
    scanf("%d", &num);
    if(num==0){
    	evenCount++;
    }else{
    while (num) {
    digit= num%10;
	rem = digit%2;
	if(rem == 0){
		evenCount++;
	}else{
		oddCount++;
	}
	num = num/10;
}
}


    printf("Even digits: %d\n", evenCount);
    printf("Odd digits: %d\n", oddCount);

    return 0;
}

