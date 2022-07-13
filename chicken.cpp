#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

/*1500 2000  1600
3         2      0
2         1      2
1         0      4*/


int main() {

  int a,b,c,x,y;
	int sum;
	cin >> a >> b >> c >> x >> y;
	
  int minV = a*x + b*y;
  for(int i=1; i<=100000; i++){	
			sum = a*max(x-i,0) + b*max(y-i,0) + c*i*2;
			if(sum < minV)
				minV = sum;
	}
  
	cout << minV << endl;
	
	return 0;
	
}
