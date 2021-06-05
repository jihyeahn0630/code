#include <stdio.h>


char input[22];

int main() {
  int i;
	int val;
  int total = 0;
	
	scanf("%s", input);
  
	for(i=0; input[i]; i++){
		
		val = input[i]-'0';
		
		if(val == 0){
			total = total + val;
		}else{
			if(total==0)
				total = total + val;
			else
				total = total * val;
		}
			
	}
		
	
	printf("%d ",total);
  
	return 0;
}
