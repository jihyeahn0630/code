#include <stdio.h>
#include <stdlib.h>

int card[100010];
int N;

int comp(const void* a,const void* b){
	return *(int*)a > *(int*)b;
}


int main(){
    int i;
	int cnt;
    long long sum = 0;
   
    
    scanf("%d", &N);
    
    for(i=0;i<N;i++){
      scanf("%d", &card[i]);
    }
    
    qsort(card, N, sizeof(int),comp);   
	 
    cnt = N;
	 
    if(N>=2){  
      while(cnt>1){
		cnt--;
			
		sum = sum + card[0]+card[1];
				
				//printf("%d %d \n", card[0],card[1]);
		card[1] = card[0]+card[1];;

		memcpy(&card[0], &card[1], sizeof(int)*cnt);
				
		//printf("%d  \n", cnt);
                qsort(card, cnt, sizeof(int),comp);   
     
       }
    }
    else
      sum=0;  
        
	
	
    printf("%lld ", sum);
    
    return 0;
}
