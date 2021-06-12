#include <stdio.h>

int N;

int time[16];
int pay[16];
int dp[16];

void input(){
    int i;
    
    scanf("%d ", &N);
    for(i=0; i<N ;i++){
       scanf("%d %d ", &time[i], &pay[i]);
    }
}


int getMax(int a, int b){
	if(a>b)
		return a;
	else
		return b;
}

int main() {
  int i,k,p;
	
	int max =0;
	int t;
    
	input();
        
	
	  for(i=N-1; i>=0; i--){
		t = i + time[i];
	   if(t > N){
		dp[i] = max;
		}
		else{	
	         //직전까지의 최대값(max)과 현재의 pay를 택했을 경우 현재의 상담이 종료됐을 시점의 최대값과의 합을 비교
		 dp[i]= getMax(pay[i]+dp[t],max);
		 max = dp[i];

		}
	  }
	  
	printf("%d ",max);
	
	
	
	return 0;
}
