#include <stdio.h>

#define MAX 99999

int N;
int M;
int map[20000][20000]; // memory 초과 ==> c언어로 불가?

int A[7]={3,4,3,1,1,2,5};
int B[7]={6,3,2,3,2,4,2};

int main() {
  int k,i,j;

	for(i=1; i<=N;i++){
		for(j=1; j<=N;j++){
			 if(i==j)
				 map[i][j] = 0;
			else
				map[i][j] = MAX;
		}
	}
	
	
	for(i=0;i<M;i++){
		map[A[i]][B[i]] = 1;
		map[B[i]][A[i]] = 1;
	}
	
	
	for(k=1; k<=N;k++){
		for(i=1;i<=N;i++){
			for(j=1; j<=N; j++){
				if(map[i][j]>map[i][k]+map[k][j])
					map[i][j]=map[i][k]+map[k][j];
			}
		}
	}
	
	int max = -1;
	int idx = -1;
	int cnt = 0;
	for(i=2;i<=N;i++){
		if(map[1][i] > max){
			max = map[1][i];
		  idx = i;
		}
	}

	for(i=2;i<=N;i++){
		if(map[1][i] == max){
			cnt++;
		}
	}
	
  printf("%d %d %d ", idx, max, cnt);
	 
	return 0;
}
