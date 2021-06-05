#include <stdio.h>

int N;
int M;
int map[110][110];
int A[100010];
int B[100010];
int D[100010];

int MAX = 99999999;

int main() {
	int k,i,j;
	
    scanf("%d",&N);
    scanf("%d",&M);
    
    for(i=0 ;i<M ;i++){
     scanf("%d %d %d ",&A[i], &B[i], &D[i]);
    }
        
    
	for(i=1;i<=N;i++){
		for(j=1;j<=N;j++){
			map[i][j]=MAX;
			
			if(i==j)
				map[i][j]=0;
		}
	}
	
	for(i=0; i<M; i++){
		if(map[A[i]][B[i]] > D[i])
			map[A[i]][B[i]] = D[i];

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
		for(j=1;j<=N;j++){
            if(map[i][j]==MAX)
                map[i][j]=0;
            
			printf("%d ",map[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
