#include<iostream>

using namespace std;

int a[20][20];
int diag1[40]; // '/' direction
int diag2[40]; // '\'' direction
int col[20];

int n;

bool check(int r, int c){
	
	if(a[r][c])
		return false;
	
	if(col[c])
		return false;
	
	if(diag1[r+c])
		return false;
	
	if(diag2[n-1+r-c])
		return false;
	
	return true;
}


int solve(int r){
	if(r == n)
		return 1; //한바퀴 다 돔
	
  int cnt = 0;
	for(int i=0; i<n;i++){
		if(check(r, i)){
			col[i]=true;
			diag1[r+i]=true;
			diag2[n-1+r-i]=true;
			a[r][i]=true;
		
			cnt += solve(r+1);
			
			a[r][i]=false;
			col[i]=false;
			diag1[r+i]=false;
			diag2[n-1+r-i]=false;
		}
	}
	
	return cnt;
}



int main() {
  
	cin >> n ;

	cout << solve(0) << endl;
	
	return 0;
}
