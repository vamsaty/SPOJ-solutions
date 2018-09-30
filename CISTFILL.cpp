#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <deque>
#include <list>
#include <math.h>
#include <sstream>
#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()	// all the elements of the container
#define tr(container,it)\
for(typeof(container.begin()) it=container.begin();it!=container.end();it++)	// iterator
#define msearch(cont,ele) (cont.find(ele)!=cont.end())	//search for map
#define vsearch(cont,ele) (cont.find(all(x),ele)!=cont.end())	//search for vector
#define ll long long int
#define FOR(i,z,n) for(int i=z;i<n;i++)
#define fora(i,z,n,a) for(int i=z;i<n;i++) cin>>a[i]
#define MALL(t,n) (t*)malloc(sizeof(t)*n)
#define IN freopen("in.txt","r",stdin)
#define OUT freopen("out.txt","w",stdout)
#define ld double

using namespace std;

struct record{
	ld b,h,w,d;
	ld vol(int x){
		if(x < b)
			return 0;
		else
			return (x-b)*d*w;
	}
};


ld bin_search(record *data,ld v,int n,ld limit){
	ld l = 0,h = limit;
	
	ld m = (l+h)/2;
	
	while( h-l > 1e-8 ){
		m = (l+h)/2;
		ld val = 0;
		
		for(int i=0;i<n;i++){
			if(m > data[i].b){
				if(m > data[i].b + data[i].h){
					val += data[i].h*data[i].w*data[i].d;
				}else{
					val += (m-data[i].b)*data[i].d*data[i].w;
				}
			}
		}
		
		if(val < v){
			l = m;
		}else{
			h = m;
		}
	}
	
	return m;
}



int main(){
//	IN;
	int t;
	cin>>t;
	
	while(t--){
		int n;
		cin>>n;
		ld limit = -100;
		ld total_capacity = 0;
		record *data = (record*)malloc(n*sizeof(record));
		for(int i=0;i<n;i++){
			cin>>data[i].b>>data[i].h>>data[i].w>>data[i].d;
			total_capacity += data[i].h*data[i].w*data[i].d;			
			limit = (limit > data[i].b+data[i].h)?limit:data[i].b+data[i].h;
		}
		
		ld v;
		cin>>v;

		if(total_capacity < v){
			cout<<"OVERFLOW\n";
		}else{
			ld k = bin_search(data,v,n,limit);
			printf("%0.2lf\n",k);
		}
		
	}
	
	
	return 0;
}
