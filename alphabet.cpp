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
vector<string> v(30);
vector<char> abc;
bool visit[30];
int dy[]={0,0,-1,1};
int dx[]={-1,1,0,0};
int r,c;
int maxS=-1;

bool check(vector<char>& a, char val){ 
	int nsize = a.size();
	
	if(nsize > maxS)
		maxS = nsize;
	
	for(int i=0;i<nsize;i++){
		if(a[i]==val)
			return false;
	}
	return true;
}


void solve(int y, int x){
		
	
	for(int i=0 ; i < 4; i++){
		int ny = y+dy[i];
		int nx = x+dx[i];
		
		if(ny<0 || ny>=r || nx<0 || ny>=c)
			continue;
		
		if(check(abc, v[ny][nx])){
			abc.push_back(v[ny][nx]);
			solve(ny, nx);
			abc.pop_back();
		}	
	}
	
}



int main() {
 
	cin >> r >> c ;
	
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			cin >> v[i][j];
		}
  }

	abc.push_back(v[0][0]);
	solve(0,0);
	cout << maxS <<endl;
	
	
	return 0;
}
