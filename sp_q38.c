#include <stdio.h>

int N;
int M;
int map[510][510];
static int A[100010];
static int B[100010];


int MAX = 9999999;

int main() {
	int k,i,j;
	int cnt;
	int total = 0;
	
  scanf("%d %d ",&N, &M);
  
  for(i=0; i<M; i++)
    scanf("%d %d ",&A[i], &B[i]);
  
	for(i=1;i<=N;i++){
		for(j=1;j<=N;j++){
			map[i][j]=MAX;
			
			if(i==j)
				map[i][j]=0;
		}
	}
		
	
	for(i=0; i<M; i++){
			map[A[i]][B[i]] = 1;
	}
	
	for(k=1; k<=N; k++){
			for(i=1;i<=N;i++){
		    for(j=1;j<=N;j++){
		        if(map[i][j] > map[i][k] + map[k][j])
							map[i][j] = map[i][k] + map[k][j];
			}
		}
	}
	
	for(i=1;i<=N;i++){
		cnt=0;
		for(j=1;j<=N;j++){
			if((map[i][j] != MAX)||(map[j][i] != MAX)){
				cnt++;
			}
		}
		if(cnt==N)
			total++;
	}
	
		printf("%d ", total);
	
	
	return 0;
}
