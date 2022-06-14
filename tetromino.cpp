#include<set>
#include<map>
#include<cassert>
#include<vector>
#include<cstdio>
#include<cstring>
#include<memory>
#include<algorithm>
#include<string>
#include<queue>
#include<iostream>

using namespace std;

int dy[4]={0,0,1,-1};
int dx[4]={1,-1,0,0};

int n,m;
int maxV = -1;
int arr[500+1][500+1];
int visit[500+1][500+1];

void solve(int y, int x, int cur, int cnt){

  if(cnt ==4){
		if(cur > maxV)
			maxV = cur;
		return;
	}
		
	if((y>=n)||(y<0)||(x>=m)||(x<0))
		return;
	
  if(visit[y][x]==1)
		return;
  
	visit[y][x]=1;
	for(int k=0; k<4; k++){
		 solve(y+dy[k], x+dx[k], cur+arr[y][x],cnt+1);
	}
  visit[y][x]=0;
  
}

int main() {
	   
	
	cin >> n >> m;
			
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++)
      cin >> arr[i][j];	
  }
	
  for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			solve(i,j,0,0);
			
			if(j+2 < m){
				int temp = arr[i][j] + arr[i][j+1] + arr[i][j+2];
				if(i-1>= 0){
					int temp2 = temp+ arr[i-1][j+1];
					if(temp2 >maxV)
						maxV = temp2;
				}
				
				if(i+1< n){
					int temp2 = temp+ arr[i+1][j+1];
					if(temp2 >maxV)
						maxV = temp2;
				}
			}
		
			if(i+2 < n){
				int temp = arr[i][j] + arr[i+1][j] + arr[i+2][j];
				if(j-1>= 0){
					int temp2 = temp+ arr[i+1][j-1];
					if(temp2 >maxV)
						maxV = temp2;
				}
				
				if(j+1< m){
					int temp2 = temp+ arr[i+1][j+1];
					if(temp2 >maxV)
						maxV = temp2;
				}
			}
		
		}      
  }
	
	
	cout << maxV << endl;
	
	
	
	return 0;
}
