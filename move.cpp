#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int map[1001][1001];
int d[1001][1001];


int go(int i, int j) {
    if (i > n || j > m) {
        return 0;
    }
    if (d[i][j] >= 0) {
        return d[i][j];
    }
    d[i][j] = max(go(i+1,j), go(i,j+1)) + map[i][j];
    return d[i][j];
}

int main() {
	
 	cin >> n >> m;
  
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> map[i][j];
			d[i][j]=-1;
		}
	}
	
	
	cout << go(0,0) <<endl;
	
	return 0;
	
}
