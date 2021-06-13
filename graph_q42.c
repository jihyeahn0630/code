#include <stdio.h>

int N=4;
int P=6;
int nP[6]={2,2,3,3,4,4};
int parent[1000001];

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
  int i;
	int cnt = 0;
	
  for (i = 1; i <= N; i++) {
      parent[i] = i;
  }
	
	
  for (i = 0; i < P; i++) {
		int x = nP[i];
    int root = findParent(x); // 현재 비행기의 탑승구의 루트 확인
    if (root == 0) 
			break; // 현재 루트가 0이라면, 종료
    
		unionParent(root, root - 1); // 그렇지 않다면 바로 왼쪽의 집합과 합치기
    
		cnt += 1;
  }	
	
	printf("%d ", cnt);
	
	return 0;
}
