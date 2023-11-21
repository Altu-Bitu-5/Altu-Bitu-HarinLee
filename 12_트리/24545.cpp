#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> vec(100001, vector<int>());
int twoV[2]={0,0};
int max_len=-1;
vector<int> board(100001, 0);
bool visited[100001];

void dfs(int nowN, int prevN, int len, int i, int &n){
	if(max_len<len){
		max_len=len;
		twoV[i]=nowN;
	}
	for(int j=0;j<vec[nowN].size();j++){
		int nextN=vec[nowN][j];
		if(nextN!=prevN){
		    dfs(nextN, nowN, len+1, i, n);
		}
	}
}

bool route(int nowN, int pointN, int prevN, int len){
	board[len]=nowN;
	if(nowN==pointN){
		return true;
	}
	bool forCheck=false;
	for(int j=0;j<vec[nowN].size();j++){
		int nextN=vec[nowN][j];
		if(nextN==prevN){
		    continue;
		}
		forCheck|=route(nextN, pointN, nowN, len+1);
		if(forCheck==true){
		    break;
		}
	}
	return forCheck;
}

int dfs2(int nowN){
	int maxInt=0;
	for(int j=0;j<vec[nowN].size();j++){
		int nextN=vec[nowN][j];
		if(visited[nextN]){
		    continue;
		}
		visited[nextN]=true;
		maxInt=max(maxInt,dfs2(nextN));
	}
	return maxInt+1;
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
	int n;
	
	cin >> n;
	
	for(int i=1;i<=n-1;i++){
		int temp1, temp2;
		cin >> temp1 >> temp2;
		vec[temp1].push_back(temp2);
		vec[temp2].push_back(temp1);
	}
	for(int i=0;i<100001;i++){
		visited[i]=false;
	}
	dfs(1, 0, 0, 0, n);
	max_len=-1;
	dfs(twoV[0], 0, 0, 1, n);
	route(twoV[0], twoV[1], 0, 0);

	for(int i=0;i<=max_len;i++){
		visited[board[i]]=true;
	}
	int maxInt=1;
	for(int i=1;i<=max_len-1;i++){
		maxInt=max(maxInt,dfs2(board[i]));
	}
	cout << (maxInt==1?0:max_len+maxInt);

	return 0;
}
