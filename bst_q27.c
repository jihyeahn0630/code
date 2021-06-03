#include <stdio.h>


int N,X;
int loc[1000010];

void InputData(void){
	int i;
	
	scanf("%d %d ", &N, &X);
	for(i=0; i<N;i++)
			scanf("%d", &loc[i]);
}

int cound_by_range(){
	 int start, end, mid;
	 int upper;
   int lower;
	
	 start=0;
   end=N-1;

	//upper bound	
 while(start<end){
	 mid=(start+end)/2;
	 
	
	 if(loc[mid] > X){
		 end=mid;
	 }
	 else {
		 start = mid+1;
		} 

 }
 upper = end;
	
 start=0;
 end=N-1;
	
//lower bound	
 while(start<end){
	 mid=(start+end)/2;
	 
	 if(loc[mid] >= X){
		 end=mid;
	 }
	 else {
		 start = mid+1;
		} 

 }
   lower = end;
	
	return (upper-lower);
	
}
int main() {

 int cnt=0;

 InputData();


 cnt = cound_by_range();
	
	if(cnt==0)
	  printf("%d", -1);
	else
	  printf("%d", cnt);
	
 
	return 0;
}
