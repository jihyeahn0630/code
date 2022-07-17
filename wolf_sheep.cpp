#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int dy[]={1,-1,0,0};
int dx[]={0,0,1,-1};
char map[501][501];
int r, c;


int main() {
	
	cin >> r >> c;
	
  for(int i=0; i<r; i++){
		  for(int j=0; j<c; j++){
				cin >> map[i][j];
		}
	}

	bool ok = true;
  for(int i=0; i<r; i++){
		  for(int j=0; j<c; j++){
				if(map[i][j] == 'S'){
						for(int k=0; k<4;k++){
							int ny=i+dy[k];
							int nx=j+dx[k];
							if(ny<0 || nx<0 || ny>=r || nx>=c)
								continue;
							if(map[ny][nx]=='W')
								ok=false;
						}
				}
		}
	}
	
	if(!ok)
		cout << "0" <<endl;
	else{	
		cout << "1" <<endl;
		for(int i=0; i<r; i++){
			  for(int j=0; j<c; j++){
					if(map[i][j]=='.')
						cout <<"D";
					else
						cout <<map[i][j];
			}
			cout << endl;
		}
	}
	
	
	return 0;
	
}
