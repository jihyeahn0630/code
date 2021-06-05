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
  int x = 0;

  scanf("%d ", &N);
  
  for(i=0;i<N;i++)
    scanf("%d ", &man[i]);
	
   qsort(man, N, sizeof(int),comp);
	
   //for(i=0;i<N;i++)
   //	printf("%d ",man[i]);
	
 for(i=0;i<N;i++){
	x++;
	if(x >= man[i]){
		cnt++;
		x=0;
	}
 }
	
  printf("%d ",cnt);
	
  return 0;
}
