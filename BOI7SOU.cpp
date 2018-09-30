#include<bits/stdc++.h>

using namespace std;




int main(){
	freopen("in.txt","r",stdin);
	int n,m,c;
	scanf("%d%d%d",&n,&m,&c);
	int *a = (int*)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	
	multiset<int> x;
	set<int> vals;
	for(int i=0;i<n;i++){
		x.insert(a[i]);
		if(i > m-1){
			x.erase(x.find(a[i-m]));
		}
		if(i >= m-1){
			if(*(--x.end())-(*x.begin()) <= c){
				vals.insert(i-m+1);
			}
		}
	}
	if(!vals.size()){
		cout<<"NONE\n";
	}else{
		for(auto x:vals){
			cout<<x+1<<"\n";
		}
	}
	
	return 0;
}
