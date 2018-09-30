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
#define pb push_back
#define mp make_pair
#define pi pair< int,int >
#define FOR(i,z,n) for(int i=z;i<n;i++)
#define fora(i,z,n,a) for(int i=z;i<n;i++) cin>>a[i]
#define MALL(t,n) (t*)malloc(sizeof(t)*n)
#define IN freopen("in.txt","r",stdin)
#define OUT freopen("out.txt","w",stdout)

using namespace std;

struct rec{
	int val,rank,freq;
};

int comp(rec a,rec b){
	if(a.freq > b.freq){
		return 1;
	}else if(a.freq == b.freq){
		if(a.rank < b.rank){
			return 1;
		}
	}
	return 0;
}

int main(){
	IN;
	int n;
	long long int c;
	cin>>n>>c;
	
	map<ll,int> rank;
	map<ll,int> freq;
	int data;
	for(int i=0;i<n;i++){
		cin>>data;
		if(freq.find(data) == freq.end()){
			freq[data] = 1;
			rank[data] = i;
		}else{
			freq[data]++;
		}
	}
	
	
	rec reco[freq.size()];
	int pos = 0;
	for(auto i:freq){
		reco[pos++] = {i.first,rank[i.first],i.second};
	}
	
	sort(reco,reco+pos,comp);
	
	for(int i=0;i<pos;i++){
		while(reco[i].freq--)
		cout<<reco[i].val<<" ";
	}
	cout<<"\n";
	
    return 0;
}  
