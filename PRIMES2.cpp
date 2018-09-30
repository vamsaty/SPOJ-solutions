#include<bits/stdc++.h>

using namespace std;

int main(){
	const int n = 1e6;
	bitset<n>p(0);
	int sq = sqrt(n);
	
	
	
	p[1] = 1;
	int prev = 1,next = 501;
	printf("2\n");
	
	for(int i = 3;i<=sq;i+=2){
		if(!p[i]){
			for(int j = i*i;j<n;j+=i){
				p[j] = 1;
			}
			prev++;
			if(prev == next){
				next += 500;
				printf("%d\n",i);
			}
	
		}
	}
	
	
	return 0;
}
