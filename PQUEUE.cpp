#include<bits/stdc++.h>
#define pi pair<int,int>
#include<deque>
using namespace std;

class comp{
public:
		bool operator()(const pi& a,const pi& b){
			if(a.first < b.first){
				return 1;
			}else if(a.first == b.first){
				if(a.second < b.second){
					return 0;
				}else{
					return 1;
				}
			}else{
				return 0;
			}
		}
};
int main(){
	freopen("in.txt","r",stdin);	
//	freopen("out.txt","w",stdout);
	
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		priority_queue< pi, vector<pi> , comp >pq;
		deque< pi >q;
		pi ans;
		for(int i=0;i<n;i++){
			int data;
			cin>>data;
			q.push_back(make_pair(data,i));
			pq.push(make_pair(data,i));
			if(i == m){
				ans = q.back();
			}
		}
		long long int time = 0;
		while(!pq.empty()){
//			cout<<pq.top().first<<" "<<pq.top().second<<"\n";
			while(q.front().first != pq.top().first){
				pi x = q.front();
				q.pop_front();
				q.push_back(x);
			}
			if(q.front().second == m){
				break;
			}else{
				time++;
				pq.pop();
				q.pop_front();
			}
//			cout<<q.front().first<<" "<<q.front().second<<"\n\n";
			
		}
		cout<<time+1<<"\n";
	}




	return 0;
}


