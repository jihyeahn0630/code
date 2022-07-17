#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue> 
using namespace std;
int dist[1000001];
bool check[1000001];
int f,s,g,u,d;


int main() {

 cin >> f >> s >> g >> u >> d;
 
 queue<int> q;
	
 q.push(s);
 check[s]=true;
 dist[s]=0;
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		
		if(cur + u <= f &&  check[cur+u] == false){
			dist[cur+u] = dist[cur] +1;
			check[cur+u] =true;
			q.push(cur+u);
		}
		
		if(cur - d > 0 &&  check[cur-d] == false){
			dist[cur-d] = dist[cur] +1;
			check[cur-d] =true;
			q.push(cur-d);
		}
		
		
	}
	
	
 if(check[g])
	cout << dist[g] <<endl;
 else
	 cout <<"use the stairs"<<endl;
	
	return 0;
	
}
