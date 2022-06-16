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
int minV = 401;
char arr[20+1][20+1];
int v1[20+1][20+1];
int v2[20+1][20+1];

int solve(int y1, int x1, int y2, int x2, int cnt){
	bool fall1 = false;
	bool fall2 = false;
	
	if(cnt > 10){
		return -1;
	}
	
	if((y1>=n)||(y1<0)||(x1>=m)||(x1<0)) 
		fall1=true;
	
	if((y2>=n)||(y2<0)||(x2>=m)||(x2<0)) 
		fall2=true;
	
	if((fall1 == true)&&(fall2 == true))
  	return -1;
 
	if((fall1 == true)||(fall2 == true)){
		return cnt;
	}
  	
	int ans = -1;
	for(int k=0; k<4; k++){
		int temp;
		
		int ny1 = y1+dy[k];
		int nx1 = x1+dx[k];
		int ny2 = y2+dy[k];
		int nx2 = x2+dx[k];
	
	
		if((ny1<n)&&(ny1>=0)&&(nx1<m)&&(nx1>=0) && arr[ny1][nx1]=='#'){
			ny1=y1;
		  nx1=x1;
		}
		
		if((ny2<n)&&(ny2>=0)&&(nx2<m)&&(nx2>=0) && arr[ny2][nx2]=='#'){
			ny2=y2;
		  nx2=x2;
		}
		
		temp = solve(ny1, nx1, ny2, nx2, cnt+1);
		
		if(temp == -1)
			continue;
		
		if((ans == -1)||(ans > temp))
			ans = temp;
	  
	}
	
	return ans;
}

int main() {
	int sol;   
	bool found = false;
	int x1,y1;
	int x2,y2;
	
	cin >> n >> m;
			
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++)
      cin >> arr[i][j];	
  }
	
  for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if((arr[i][j]=='o') && (found == false)){
				y1=i;
				x1=j;
				found = true;
				continue;
			}
			if((arr[i][j]=='o') && (found == true)){
				y2=i;
				x2=j;
				break;
			}
				
		}      
  }
	
	sol = solve(y1, x1, y2, x2, 0);
	
	cout << sol << endl;
	
	
	return 0;
}
