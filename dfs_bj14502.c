#include <stdio.h>

int map[9][9];
int temp[9][9];
int N,M;
int dy[]={1,-1,0,0};
int dx[]={0,0,1,-1};
int max = -1;
void virus(int y, int x){
    int i;
    
    for(i=0;i<4;i++){
        int ny= y+dy[i];
        int nx= x+dx[i];
        
        if((ny<0)||(nx<0)||(ny>=N)||(nx>=M))
            continue;
        
        if(temp[ny][nx]==0){
            temp[ny][nx]=2;
            virus(ny,nx);
        }
    }
}

int getScore(){
    int i,j;
    int cnt=0;
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            if(temp[i][j]==0)
                cnt++;
        }
    }
    return cnt;
}

void DFS(int count){
    int i,j;
    
    if(count == 3){
     for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            temp[i][j]=map[i][j];
        }
      }
    
      for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            if(temp[i][j]==2)
                virus(i,j);
        }
      }
    
      if(getScore() > max)
          max = getScore();
      
        return;
    }
    
    
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            if(map[i][j]==0){
                map[i][j]=1;
                count++;
                DFS(count);
                count--;
                map[i][j]=0;
            }
        }
    }
}

int main(){
    int i,j;
    
    scanf("%d %d ", &N, &M);
    
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
             scanf("%d ", &map[i][j]);
        }
    }
    
    DFS(0);
    
    printf("%d ", max);
    
    return 0;
}
