#include <stdio.h>

int N;
int dp[1010];


int check(int num){
		
	
	 while(1){
		
	  	if(num%5 == 0){
		  	num = num/5;	
			}		
	  	else if(num%3 == 0){
				num = num/3;		
			}		
			else if(num%2==0){
		  	num = num/2;	
			}
	  	else{
				if(num==1)
					return 1;
				else
					return 0;
			}
		 
	 }
}



int main() {
	int i;
	int cnt=1;
	int num=1;
	
  scanf("%d", &N);
	
	dp[0]=num;
	while(cnt<=N){
	  num++;
    if(check(num) == 1){
			dp[cnt++]= num;
		}  
		
	}
		
//	for(i=0;i<N;i++)
//		printf("%d ",dp[i]);	
		
	printf("%d ",dp[N-1]);	

	return 0;
}
