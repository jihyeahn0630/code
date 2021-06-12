#include <stdio.h>

#define MAX 9999999

typedef struct{
	int y;
	int x;
}XY_T;
XY_T queue[125*125*120];

int N=5;

int map[126][126];
int visit[126][126];


int rp = 0;
int wp = 0;

void BFS(){
	int dy[]={1,-1,0,0};
	int dx[]={0,0,1,-1};
	int i;
	
	visit[0][0]=map[0][0];
  queue[wp].y = 0;
	queue[wp].x = 0;
	wp++;
	
	while(rp < wp){
	 XY_T cur = queue[rp++];
		
  	for(i=0;i<4;i++){
	  	int ny = cur.y + dy[i];
		  int nx = cur.x + dx[i];
		
		  if((ny>=N)||(nx>=N)||(ny<0)||(nx<0))
			  continue;
		
		  if(visit[ny][nx] > visit[cur.y][cur.x]+map[ny][nx]){
		  	visit[ny][nx] = visit[cur.y][cur.x]+map[ny][nx];
			  queue[wp].y=ny;
			  queue[wp].x=nx;
			  wp++;
		  }
		
	  }
	
	}
}


int main() {
	int i,j;
	
  scanf("%d", &N);
  
   for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			scanf("%d", &map[i][j]);
		}
	}
 	
  
  for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			visit[i][j]=MAX;
		}
	}
 	
	
	BFS();
	
	printf("%d ", visit[N-1][N-1]);
	
	return 0;
}
