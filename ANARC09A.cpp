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

int main(){
	IN;
	
	int k = 1;
	while(1){
		string data;
		cin>>data;
		if(data[0] == '-')
			break;
		
		int n = data.length();
		stack< char >val;
		long long cnt = 0;
		
		for(int i=0;i<n;i++){
			if(data[i] == '}'){
				if(val.empty()){
					cnt++;
					data[i] = '{';
					val.push(data[i]);
				}else if(val.top() == '{'){
					val.pop();	
				}
				
			}else if(data[i] == '{'){
			
				val.push(data[i]);
				
			}
		}
		
		int c = 0;
		while(!val.empty()){
			val.pop();
			c++;
		}
		cnt += (c/2);
		cout<<k<<". "<<cnt<<"\n";
		k++;
	}
	
    
    return 0;
    
}



