#include <stdio.h>


int N;
int loc[1000010];

void InputData(void){
	int i;
	
	scanf("%d %d ", &N);
	for(i=0; i<N;i++)
			scanf("%d", &loc[i]);
}


int main() {
 int i;
 int start, end, mid, idx=-1;
 int sum=0;
 int val;
 int cnt=0;
	
 InputData();

 start=0;
 end=N-1;
	
 while(start<=end){
	 mid=(start+end)/2;
	
	
	 if(mid-loc[mid] > 0){
		 start=mid+1;
	 }
	 else if(mid-loc[mid]< 0){
			end = mid-1;
		} 
	  else{
			idx=mid;
			break;
		}
 }

   printf("%d ", idx);
 
	return 0;
}
