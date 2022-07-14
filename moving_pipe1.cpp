#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int map[17][17];
int n;

bool check(int r, int c){
	if(map[r][c+1] ==0 && map[r+1][c]==0 && map[r+1][c+1]==0)
		return true;
	else
		return false;
}

int go(int r1, int c1, int r2, int c2){
	
	if(map[r1][c1] == 1 || map[r2][c2] == 1)
		return 0;
	
	if(r2==n && c2==n){
		return 1;
	} 
	
	if(r2>n || c2>n){
		return 0;
	} 
	
	int ans=0;
	if(r1==r2 && c1!=c2){
		if(check(r2, c2))
			ans += go(r2, c2, r2+1, c2+1);
		ans += go(r2, c2, r2, c2+1);
	}
	else if(r1!=r2 && c1==c2){
		if(check(r2, c2))
			ans += go(r2, c2, r2+1, c2+1);
		ans += go(r2, c2, r2+1, c2);
	}
	else if(r1!=r2 && c1!=c2){
		if(check(r2, c2))
			ans += go(r2, c2, r2+1, c2+1);
		ans += go(r2, c2, r2+1, c2);
		ans += go(r2, c2, r2, c2+1);
	}
	else {
		return ans;
	}
	
	return ans;
}


int main() {
	
	cin >> n;
	
  for(int i=1; i<=n; i++){
		  for(int j=1; j<=n; j++){
				cin >> map[i][j];
		}
	}
  
	
	cout << go(1,1,1,2) << endl;
	
	return 0;
	
}
