include <stdio.h>
#include <stdlib.h>

int N;
int M;

int parent[1000001];

typedef struct{
	int a;
	int b;
	int c;
}XY_T;
XY_T temp[1000001];

   // 특정 원소가 속한 집합을 찾기
int findParent(int x) {
    // 루트 노드가 아니라면, 루트 노드를 찾을 때까지 재귀적으로 호출
    if (x == parent[x]) 
			return x;
	
    return parent[x] = findParent(parent[x]);
}

    // 두 원소가 속한 집합을 합치기
void unionParent(int a, int b) {
    a = findParent(a);
    b = findParent(b);
	
    if (a < b) 
			parent[b] = a;
    else 
			parent[a] = b;
}

int comp(const void* a, const void* b){
	return ((XY_T*)a)->c > ((XY_T*)b)->c;
}

void input(){
    int i;
    scanf("%d %d ", &N, &M);
    
    for(i=0;i<M;i++){
        scanf("%d %d %d ", &temp[i].a, &temp[i].b, &temp[i].c);
    }
}

int main() {
  int i;
	int sum = 0;
	int max = -1;
	
    input();
	
	qsort(temp, M, sizeof(temp[0]),comp);
	
  for (i = 1; i <= N; i++) {
      parent[i] = i;
  }
	
	
  for (i = 0; i < M; i++) {
			
			if(findParent(temp[i].a) != findParent(temp[i].b)){
			 sum = sum + temp[i].c;
			 unionParent(temp[i].a, temp[i].b); //
				
				if(temp[i].c > max)
					max = temp[i].c;
			}
		
		
  }	
	
	printf("%d ", sum-max);
	
	return 0;
}
