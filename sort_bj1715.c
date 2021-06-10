#include <stdio.h>
#include <stdlib.h>

int card[100010*2];
int N;
int max=1100;

int comp(const void* a,const void* b){
	return *(int*)a > *(int*)b;
}


int main(){
    int i;
	int cnt, idx, len;
    long long sum = 0;
    long long tmp;
    
    scanf("%d", &N);
    
    for(i=0;i<N;i++){
      scanf("%d", &card[i]);
    }
    
    qsort(card, N, sizeof(int),comp);   
	 
    cnt = N;
	  idx = N-1;
    if(N>=2){  
       while(cnt>1){
		cnt--;
			
		sum = sum + card[0]+card[1];
		idx++;
		//printf("%d %d \n", card[0],card[1]);
		card[idx] = card[0]+card[1];;
		card[0] = max;
		card[1] = max;
				
                qsort(card, (idx+1), sizeof(int),comp);   
 
       }
    }
    else
      sum=0;  
        
	
	
    printf("%lld ", sum);
    
    return 0;
}
