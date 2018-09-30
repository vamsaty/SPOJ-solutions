#include<bits/stdc++.h>

using namespace std;

int grid[100][100];
int front[100],side[100];
int w,d;	

int print(int ,int ,int);

int getleft(int i,int j,int lim){
	while(i>=lim && !grid[j][i]){
		i--;
	}
	return max(i,lim);
}

int getright(int i,int j,int lim){
	while(i<lim && !grid[j][i]){
		i++;
	}
	return min(i,lim-1);
}

int getup(int i,int j,int lim){
	while(i>=lim && !grid[i][j]){
		i--;
	}
	return max(i,lim);
}

int getdown(int i,int j,int lim){
	while(i<lim && !grid[i][j]){
		i++;
	}
	return min(i,lim-1);
}

int check(int i,int j,int w,int d,int v1){
	int ma = -10,md = -10;
	bool f1 = 1,f2 = 1;
	for(int x=0;x<w;x++){
		if(grid[i][x] > ma ){
			ma = grid[i][x];
		}
	}	

	for(int x=0;x<d;x++){
		if(grid[x][j] > md){
			md = grid[x][j];
		}
	}
	
	if((ma == side[i]) && (md == front[j])){
		return 1;
	}
	return 0;
}

int print(int d,int w,int flag){
		
		if(!flag){
			for(int i=0;i<d;i++){
				for(int j=0;j<w;j++){
					printf("%2d ",grid[i][j]);
				}
				cout<<"\n";
			}
			cout<<"\n\n";	
			return 0;
		}
		else{
			long long int sum = 0;
			for(int i=0;i<d;i++){
				for(int j=0;j<w;j++){
					sum += grid[i][j];
				}
			}
			return sum;
		}		
}

void manipulate(int i,int j,int up,int left,int u,int l){
	int vu = up;
	int le = left;
	int val = grid[i][j];
	grid[i][l] = grid[u][j] = 0;
	grid[i][j] = up;
	if(check(u,l,w,d,up)){
		val = up;
	}else{
		grid[i][l] = vu;
		grid[u][j] = le;
	}
	grid[i][j] = val;
	
}



int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	
	while(1){
		cin>>w>>d;
		if(!w and !d)
			break;
		
		int mrow = -10,mcol = -10,row = -1,col = -1;
		for(int i=0;i<w;i++){
			cin>>front[i];
			if(mcol < front[i]){
				mcol = front[i];
				col = i;
			}
		}
		for(int i=0;i<d;i++){
			cin>>side[i];
			if(mrow < side[i]){
				mrow = side[i];
				row = i;
			}
		}
		for(int i = 0;i<d;i++){
			for(int j=0;j<w;j++){
				grid[i][j] = 0;
			}
		}
		
		for(int i=0;i<d;i++){
			grid[i][col] = side[i];
		}
		for(int i=0;i<w;i++){
			grid[row][i] = front[i];
		}
		
		for(int i=0;i<d;i++){
			for(int j=0;j<w;j++){
				if(!grid[i][j]){
					int l = getleft(j,i,0),r = getright(j,i,w),di = getdown(i,j,d),u = getup(i,j,0);
					int left = grid[i][l];
					int right = grid[i][r];
					int down = grid[di][j];
					int up = grid[u][j];
					
					
					if(up == left && up){
						manipulate(i,j,up,left,u,l);
					}else if(up == right && up){
						manipulate(i,j,up,right,u,r);
					}else if(down == left && down){
						manipulate(i,j,down,left,di,l);						
					}else if(down == right && down){
						manipulate(i,j,down,right,di,r);
					}
					
				}
				
			}
		}
		cout<<print(d,w,1)<<"\n";
		
	}
	
	return 0;
}
