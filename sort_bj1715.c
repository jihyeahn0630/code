#include <stdio.h>
#include <stdlib.h>

int card[100010];
int N;

int comp(const void* a,const void* b){
	return *(int*)a > *(int*)b;
}


int main(){
    int i;
    long long sum = 0;
    long long tmp;
    
    scanf("%d", &N);
    
    for(i=0;i<N;i++){
      scanf("%d", &card[i]);
    }
    
    qsort(card, N, sizeof(int),comp);   
    
    if(N>=2){  
     sum = tmp = card[0]+card[1];
    
     for(i=2;i<N;i++){
      sum = sum + tmp + card[i];
      tmp = tmp + card[i];
     }
    }
    else
      sum=0;  
        
    printf("%lld ", sum);
    
    return 0;
}
