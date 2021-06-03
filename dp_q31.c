#include <stdio.h>


int T,N,M;
int map[22][22];

void InputData(void){
	int i,j;
	
	scanf("%d", &T);
  scanf("%d %d ", &N, &M);
	
  for(i=0; i<N; i++){
 	 	for(j=0; j<M; j++){
			 scanf("%d", &map[i][j]);
		}
   }
	
}


int main() {

 int cnt=0;
 int max = -1;
 int i,j,idx;
 int start=0;
 int end=0;
 int sum=0;
	
 InputData();

	 
 for(i=0;i<N;i++){
	 if(map[i][0] > max){
		 max = map[i][0];
		 idx=i;
	 }
 }
 
 sum = max;
	
 for(j=1; j<M; j++){
	  start = idx-1;
	  end = idx+1;
	 
	  if(start<0)
			start =0;
	 
	  if(end>N)
			end=N;
	 
	  max = -1;
	  for(i=start;i<=end;i++){
	 		if(map[i][j] > max){
				 max = map[i][j];
				 idx=i;
	    }
		}
	
	  sum = sum + max;
 }
	 

  printf("%d", sum);
	
 
	return 0;
}
