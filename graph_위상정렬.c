#include <stdio.h>

int N=7;
int M=8;

//A->B
int A[8]={1,1,2,2,3,4,5,6};
int B[8]={2,5,3,6,4,7,6,4};
int indeg[8]; //1~
int map[8][8]; //1~

int queue[64];
int result[7];

static int rp = 0;
static int wp = 0;

int main() {
  int i,j;
	
	for(i=0;i<M;i++){
		map[A[i]][B[i]]=1;
		indeg[B[i]]++;
	}
	
	for(i=1;i<=N;i++){
	   if(indeg[i] == 0){
			 queue[wp]=i;
			 wp++;
		}
	}
  	
	while(rp < wp){
		int cur = queue[rp];
		result[rp]=cur;
		rp++;
		indeg[cur]--;
		
		for(j=1; j<=N;j++){
			if(map[cur][j] != 0){
				indeg[j]--;
				
				if(indeg[j]==0){
				 queue[wp]=j;
				 wp++;
			   }
			 }
		}

	}
	
	for(i=0;i<N;i++){
	   printf("%d ", result[i]);
	}

	
	return 0;
}
