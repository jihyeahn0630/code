#include <stdio.h>


int N;
int digit[9];

void find_digit(int n){
	int val = n;
	
	while(val>0){
	if(val/10000000 != 0){
		digit[8]=val/10000000;
		val = val%10000000;
	}
	else if(val/1000000 != 0){
		digit[7]=val/1000000;
		val = val%1000000;
	}
	else if(val/100000 != 0){
		digit[6]=val/100000;
		val = val%100000;
	}
	else if(val/10000 != 0){
		digit[5]=val/10000;
		val = val%10000;
	}
	else if(val/1000 != 0){
		digit[4]=val/1000;
		val = val%1000;
	}
	else if(val/100 != 0){
		digit[3]=val/100;
		val = val%100;
	}
	else if(val/10 != 0){
		digit[2]=val/10;
		val = val%10;
	}
	 else{
		 digit[1]=val;
		 val=0;
	 }
	}
}


int main() {
	int i;
	int cnt;
	int left=0, right=0;
	
	scanf("%d ",&N);

	find_digit(N);
	
	for(i=8 ; i>0; i--){
		if(digit[i] != 0){
	       cnt = i;		
			break;
		}
			
	}
	
	
	for(i=1; i<=cnt/2;i++){
		left += digit[i];
	}
	
	for(i=cnt/2+1; i<=cnt;i++){
		right += digit[i];
	}
	
	if(left == right)
		printf("LUCKY");
	else
		printf("READY");
	
	return 0;
}
