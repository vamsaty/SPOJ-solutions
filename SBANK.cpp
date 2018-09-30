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
for((container.begin())it = container.begin();it!=container.end();it++)	// iterator
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

int main(){
	IN;
	
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		map< string ,int > track;
		while(n--){
			string p1,p2,p3,p4,p5,p6,final;
			cin>>p1>>p2>>p3>>p4>>p5>>p6;
			final.append(p1);
			final.push_back('_');
			final.append(p2);
			final.push_back('_');
			final.append(p3);
			final.push_back('_');
			final.append(p4);
			final.push_back('_');
			final.append(p5);
			final.push_back('_');
			final.append(p6);
//			cout<<final<<"\n";
			if(track.find(final) == track.end()){
				track[final] = 1;
			}else{
				track[final]++;
			}
		}
		map<string,int>::iterator it = track.begin();
		while(it != track.end()){
			string data = (*it).first;
			int val = (*it).second;
			for(int i=0;i<31;i++){
				if(data[i]=='_'){
					printf(" ");
				}else{
					cout<<data[i];
				}
			}
			cout<<" "<<val<<"\n";
			it++;
		}
		cout<<"\n";
	}
	
	
	
	
    return 0;
}  
