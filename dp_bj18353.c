#include <stdio.h>


int N;
int b[2010];
int dp[2010];

int getMax(int a, int b){
	if(a>b)
		return a;
	else
		return b;
}


int main() {
	int i,j;
	int max=0;
	
    scanf("%d ", &N);
  
     // 순서를 뒤집어 '최장 증가 부분 수열' 문제로 변환
    for(i=N-1;i>=0;i--)
        scanf("%d ", &b[i]);
    
	for(i=0;i<N;i++)
        dp[i]=1;
    
    // 가장 긴 증가하는 부분 수열(LIS) 알고리즘 수행
	for(i=1;i<N;i++){
        for(j=0; j<i;j++){
         if(b[j]<b[i]){
            dp[i] = getMax(dp[i], dp[j]+1); 
         }   
       }
    }
    
    for(i=0;i<N;i++){
     if(dp[i] > max)   
         max = dp[i];
    }
	
	printf("%d ",N-max);
    
    
	return 0;
}
