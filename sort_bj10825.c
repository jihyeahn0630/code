#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N;

typedef struct{
	char name[10];
	int korean;
	int eng;
	int math;
}T_GPA;

T_GPA test[100010];


void InputData(void){
	int i;
	
	scanf("%d", &N);
	for(i=0; i<N; i++){
		scanf("%s %d %d %d ",test[i].name, &test[i].korean, &test[i].eng, &test[i].math);
	} 
}

int comp(const void* a, const void* b){
  T_GPA *A = NULL, *B = NULL;
	A = (T_GPA *)a;
	B = (T_GPA *)b;

	 if(A->korean == B->korean){
		  if(A->eng == B->eng){
				 if(A->math == B->math){
                     if(strcmp(A->name, B->name) < 0) return -1;
                     else if(strcmp(A->name, B->name) > 0) return 1;
                     else return 0;
				 }else
				return ((T_GPA*)a)->math < ((T_GPA*)b)->math;
			}
		  else
				return ((T_GPA*)a)->eng > ((T_GPA*)b)->eng;
	 }
	
	return ((T_GPA*)a)->korean < ((T_GPA*)b)->korean;
}

int main() {
 int i;
	
 InputData();
	
 qsort(test,N,sizeof(test[0]),comp);
 	
 for(i=0;i<N;i++){
 		printf("%s ", test[i].name);
 }
	return 0;
}
