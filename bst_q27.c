#include <stdio.h>


int N,X;
int loc[1000010];

void InputData(void){
	int i;
	
	scanf("%d %d ", &N, &X);
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
	 
	
	 if(loc[mid] < X){
		 start=mid+1;
	 }
	 else if(loc[mid] > X){
			end = mid-1;
		} 
	  else{
			idx=mid;
			break;
		}
 }

 if(idx==-1)
		 printf("%d ", idx);
 else{	
   val=loc[idx];
   
	 for(i=idx; i<N;i++){
		if(loc[i]==val)
			cnt++;
		 else
			 break;
	}
	
	 for(i=idx-1; i>0;i--){
		if(loc[i]==val)
			cnt++;
		 else
			 break;
	}
	
	printf("%d ", cnt);
	
 }	
	return 0;
}
