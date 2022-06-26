#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int dist[101];
int func[101];


int main(){
	int n, m ,x,y;
	
	for(int i=1; i<=100; i++){
		func[i]=i;
		dist[i]=-1;
	}
	
	cin >> n >> m;
	
	for(int i=0; i< n+m; i++){
		cin >> x >> y;
		func[x]=y;
	}
	
	queue<int> q;
	dist[1]=0;
	q.push(1);
	
	while(!q.empty()){
		int cur=q.front();
		q.pop();
		
		for(int i=1; i<=6; i++){
			int next=cur+i;
			
			if(next > 100)
				continue;
			
			next = func[next];
			
			if(dist[next]==-1){
				dist[next]=dist[cur]+1;
				q.push(next);
			}
		}
		
	}


	cout << dist[100] << endl;
	
	return 0;
}
