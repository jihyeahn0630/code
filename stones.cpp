#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

bool check[1501][1501];
int sum;

void DFS(int x, int y){
	
	int a[3]={x, y, sum-x-y};
	
	if(check[x][y])
		return;
	
	check[x][y]=true;
	
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			int b[3]={x, y, sum-x-y};
			
			if(a[i]<a[j]){
				b[i] += a[i];
				b[j] -= a[i];
				DFS(b[0], b[1]);
			}
			
		}
	}
	
	
	
}



int main() {

	int x,y,z;
	
	cin >> x >> y >> z;
	
	sum=x+y+z;
	
	if(sum%3 !=0){
		cout << "0" << endl;
		return 0;
	}
	 
	DFS(x,y);
	
  if(check[sum/3][sum/3])
		cout << "1" << endl;
	else
		cout << "0" << endl;
	
	return 0;
	
}
