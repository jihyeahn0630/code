#include <stdio.h>
#include <stdbool.h>

int N=5;
int M=4;
int map[501][501];

int parent[501];
int plan[501];

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



int main() {
	int x,i,j;
	int cnt;
	int total = 0;
	
  scanf("%d %d ", &N, &M);
  for(i=0; i<N; i++){
   for(j=0; j<N; j++){
      scanf("%d ", &map[i][j]);
   }
  }
	
  for(i=0; i<M; i++){
    scanf("%d ", &plan[i]);
  }
  
	// 부모 테이블상에서, 부모를 자기 자신으로 초기화
	for(i=1; i<=N; i++){
		parent[i]=i;
	}
	
	 // Union 연산을 각각 수행
  for (i = 0; i < N; i++) {
     for (j = 0; j < N; j++) {
         if (map[i][j] == 1) { // 연결된 경우 합집합(Union) 연산 수행
              unionParent(i + 1, j + 1);
          }
      }
  }

bool result = true;
  // 여행 계획에 속하는 모든 노드의 루트가 동일한지 확인
  for (i = 0; i < M - 1; i++) {
    if (findParent(plan[i]) != findParent(plan[i + 1])) {
        result = false;
      }
  }

	if(result == true)
		printf("Yes");
	else
		printf("No");
	
	return 0;
}
