#include <cstdio>
#include <stack>
using namespace std;
long long a[100000];

int main() {
  int n;
	
 	scanf("%d",&n);
	for(int i=0;i<n;i++)
 		scanf("%lld",&a[i]);	

	
	stack<long long> s;
	long long ans = 0;
	
	for(int i=0; i<n; i++){
		while(!s.empty() && a[s.top()]>a[i]){
			long long height = a[s.top()];
			s.pop();
			long long width = i;
			if(!s.empty()){
				width = (i-s.top()-1);
			}
			if(ans < height*width)
				ans = height*width;
			
		}
		
		s.push(i);

	}
	
	while(!s.empty()){
			long long height = a[s.top()];
			s.pop();
			long long width = n;
			if(!s.empty()){
				width = (n-s.top()-1);
			}
			if(ans < height*width)
				ans = height*width;
			
	}
	
	
	printf("%lld", ans);
	
	return 0;
	
}
