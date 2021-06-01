#include <stdio.h>
#include <stdlib.h>

int N;
int loc[200010];

void InputData(void){
	int i;
	
	scanf("%d", &N);
	for(i=0; i<N;i++)
			scanf("%d", &loc[i]);
}

int comp(const void* a, const void* b){
	return *((int*)a) > *((int*)b);
}

int ABS(int val){
	if(val<0) 
		return -val;
	else
		return val;
}
	

int main() {
 int i;
 int start, end, mid, idx;
 int sum=0;
 long long min=99999999999;
	
 InputData();
	
 qsort(loc,N,sizeof(loc[0]),comp);

 //	for(i=0; i<N;i++)
 //		printf("%d ",loc[i]);

 start=0;
 end=N-1;
	
 while(start<=end){
	 mid=(start+end)/2;
	 sum=0;
	 for(i=0; i<N; i++){
	 	sum += ABS(loc[mid]-loc[i]);
		 
	 }
	  //printf("sum:%d ", sum);
	 if(sum < min){
		 min = sum;
		 start=mid+1;
		 idx=mid;
	 }
		else{
			end = mid-1;
		} 
	 
 }
	
    printf("%d ", loc[idx]);
	
	
	return 0;
}
