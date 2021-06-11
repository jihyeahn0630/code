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
			
		 dp[i]= getMax(pay[i]+dp[t],max);
		 max = dp[i];

		}
	  }
	  
	printf("%d ",max);
	
	
	
	return 0;
}
