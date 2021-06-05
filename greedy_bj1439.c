#include <stdio.h>


char input[1000010];


int main() {
  int i;
  int val[2]={0,};

	
	scanf("%s", input);
  
  val[input[0]-'0']=1;
	
	for(i=1; input[i]; i++){
			
		if(input[i] != input[i-1]){
		  val[input[i]-'0']++;
		}
	}

	
	printf("%d ",(val[0]>val[1])? val[1]:val[0]);
	
	return 0;
}
