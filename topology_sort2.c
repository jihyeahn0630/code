#include <stdio.h>

int N=5;

//A->B
int A[5]={1,1,1,3,3};
int B[5]={2,3,4,4,5};
int indeg[6]; //1~
int map[6][6]; //1~

int queue[64];
int result[6]={0,10,10,4,4,3};
int time[6]={0,10,10,4,4,3};

int rp = 0;
int wp = 0;

int getMax(int a, int b){
	if(a>b)
		return a;
	else
		return b;
}

int main() {
  int i,j;
	
	for(i=0;i<N;i++){
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
		int cur = queue[rp++];
		
		indeg[cur]--;
		
		for(j=1; j<=N;j++){
			if(map[cur][j] != 0){
				result[j]=getMax(result[j], result[cur]+time[j]);
				indeg[j]--;
				
				if(indeg[j]==0){
				 queue[wp]=j;
				 wp++;
			   }
			 }
		}

	}
	
	for(i=1;i<=N;i++){
	   printf("%d ", result[i]);
	}

	
	return 0;
}
