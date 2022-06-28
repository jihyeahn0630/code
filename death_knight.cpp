#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int map[201][201];

int dr[]={-2,-2,0,0,2,2};
int dc[]={-1,1,-2,2,-1,1};
//(r-2, c-1), (r-2, c+1), (r, c-2), (r, c+2), (r+2, c-1), (r+2, c+1)

int main(){
	int n;
	int r1,c1,r2,c2;
	
	cin >> n;
	cin >> r1 >> c1 >> r2 >> c2;
	
	for(int i=0; i< n; i++){
			for(int j=0; j< n; j++){
				map[i][j]=-1;
		}
	}
	
	queue<pair<int,int>> q;
	map[r1][c1]=0;
	q.push(make_pair(r1,c1));
	
	while(!q.empty()){
		int cur_r = q.front().first;
		int cur_c = q.front().second;
		q.pop();
		
		for(int i=0; i<6; i++){
			int nr=cur_r + dr[i];
			int nc=cur_c + dc[i];
			
			if(nr<0 || nr>=n || nc<0 || nc>=n)
				continue;
			
			
			if(map[nr][nc]==-1){
				map[nr][nc]=map[cur_r][cur_c]+1;
				q.push(make_pair(nr,nc));
				
			}
		}
		
	}


	cout <<map[r2][c2]<< endl;
	
	return 0;
}
