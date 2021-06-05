#include <stdio.h>
#include <stdlib.h>

int N;
int man[100010];

int comp(const void* a, const void* b){
	return *((int*)a) > *((int*)b);
}

int main() {
  int i;
	int cnt = 0;
	int x;

  scanf("%d ", &N);
  
	for(i=0;i<N;i++)
			scanf("%d ", &man[i]);
	
	qsort(man, N, sizeof(int),comp);
	
	//for(i=0;i<N;i++)
	//	printf("%d ",man[i]);
	
	x=N;
  while(x > 0){
		
		x = x - man[x-1];
		
		if(x<0)
			break;
		
		cnt++;
	}
	
	printf("%d ",cnt);
	return 0;
}
