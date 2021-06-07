#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char new[10010];
char input[10010];
int cnt;

int comp(const void* a, const void* b){
  char *A = NULL, *B = NULL;
	A = (char *)a;
	B = (char *)b;


  if(strcmp(A, B) < 0)
		return -1;
  else if(strcmp(A, B) > 0) 
		return 1;
  else 
		return 0;

}

int find_the_number(){
  int i;
	int sum = 0;
	cnt = 0;
	
	for(i=0; input[i];i++){
	
		switch(input[i]){
			case '0':
				break;
			case '1':
				sum+=1;
				break;
			case '2':
				sum+=2;
				break;	
			case '3':
				sum+=3;
				break;
			case '4':
				sum+=4;
				break;
			case '5':
				sum+=5;
				break;
			case '6':
				sum+=6;
				break;	
			case '7':
				sum+=7;
				break;
			case '8':
				sum+=8;
				break;	
			case '9':
				sum+=9;
				break;
			default:
				strncat(new,&input[i],1);
				cnt++;
			  break;
		}
		
		
	}
	
	
	return sum;
}

int main() {

	int sum;
	
	scanf("%s",input);

	sum = find_the_number();
	
	qsort(new, cnt, sizeof(char), comp);	
	
	printf("%s%d",new,sum);
	
	
	return 0;
}
