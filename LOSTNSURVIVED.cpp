#include<bits/stdc++.h>

using namespace std;

struct rec{
	int par,size;
};

rec data[100002];
int mi = INT_MAX,maxx = INT_MIN;
multiset<int> group_size;

int parent(int x){
	while(data[x].par != x)
		x = data[x].par;
	
	return x;
}

void unite(int x,int y){
	int px = parent(x);
	int py = parent(y);

	if(px != py){
		group_size.erase(group_size.find(data[px].size));
		group_size.erase(group_size.find(data[py].size));
		group_size.insert(data[px].size+data[py].size);

		if(data[px].size <= data[py].size){
			data[px].par = py;
			data[py].size += data[px].size;
		}else{
			data[py].par = px;
			data[px].size += data[py].size;
		}
		
	}
}

int get_size(int x){
	int px = parent(x);
	return data[px].size;
}

int main(){
	 freopen("in.txt","r",stdin);
	
	int n,q;
	cin>>n>>q;
	group_size.clear();
	for(int i=1;i<=n;i++){
		data[i].size = 1;
		data[i].par = i;
		group_size.insert(1);
	}
	
	while(q--){
		int a,b;
		cin>>a>>b;
		unite(a,b);
		cout<<(*(--group_size.end())) - (*group_size.begin())<<"\n";
	}
	
	
	return 0;
}
