#include<bits/stdc++.h>

using namespace std;

struct rec{
	int par,size;
};

rec data[100002];

int parent(int x){
	while(data[x].par != x)
		x = data[x].par;
	
	return x;
}

void unite(int x,int y,int m){
	int px = parent(x);
	int py = parent(y);
	if(px != py && data[px].size + data[py].size <= m){
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
//	cout<<"parent = "<<px<<"\t"<<data[px].size<<"\n";
	return data[px].size;
}

int main(){
	freopen("in.txt","r",stdin);
	
	int n,m,q;
	cin>>n>>m>>q;
	
	for(int i=1;i<=n;i++){
		data[i].size = 1;
		data[i].par = i;
	}
	while(q--){
		char a;
		int x,y;
		cin>>a;
		if(a == 'A'){
			cin>>x>>y;
			unite(x,y,m);
		}else if(a == 'E'){
			cin>>x>>y;
			if(parent(x) == parent(y)){
				cout<<"Yes\n";
			}else{
				cout<<"No\n";
			}
		}else if(a == 'S'){
			cin>>x;
			cout<<get_size(x)<<"\n";
		}
		
	}
	
	
	return 0;
}
