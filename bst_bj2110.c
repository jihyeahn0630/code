#include <stdio.h>
#include <stdlib.h>

int wifi[200010];
int N;
int C;

int comp(const void* a,const void* b){
	return *(int*)a > *(int*)b;
}


int main(){
    int i;
	int start, end, result;
    
     scanf("%d %d ", &N, &C);
    
    for(i=0;i<N;i++){
      scanf("%d", &wifi[i]);
    }
    
  qsort(wifi, N, sizeof(int),comp);   
	
	start = 1;
	end = wifi[N-1]-wifi[0];
	
  while (start <= end) {
            // mid는 가장 인접한 두 공유기 사이의 거리(gap)을 의미
            int mid = (start + end) / 2;
		    
            // 첫째 집에는 무조건 공유기를 설치한다고 가정
            int value = wifi[0];
            int cnt = 1;
            // 현재의 mid 값을 이용해 공유기를 설치하기
            for (int i = 1; i < N; i++) { // 앞에서부터 차근차근 설치
                if (wifi[i] >= value + mid) {
                    value = wifi[i];
                    cnt += 1;
                }
            }
            // C개 이상의 공유기를 설치할 수 있는 경우, 거리를 증가시키기
            if (cnt >= C) {
                start = mid + 1;
                result = mid; // 최적의 결과를 저장
						  
            }
            // C개 이상의 공유기를 설치할 수 없는 경우, 거리를 감소시키기
            else {
                end = mid - 1;
            }
        }
	
   
    printf("%d ", result);
    
    return 0;
}
