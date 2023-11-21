#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

bool visited[100001];
vector<pair<int, int>> board[100001];
int endI;

void dfs(int x, int len, int &answer){
    
    if(visited[x]==true){
        return;
    }
    
	visited[x]=true;

	if(len>answer){
		answer=len;
		endI=x;
	}

	for(int i=0;i<board[x].size();i++){
		dfs(board[x][i].first,len+board[x][i].second,answer);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
	int n, o, p, q, answer=0;

	cin >> n;

	for(int i=1;i<n;i++){
		cin >> o >> p >> q;
		
		board[o].push_back(make_pair(p,q));
		board[p].push_back(make_pair(o,q));
	}

	dfs(1,0,answer);
	
	memset(visited,false,sizeof(visited));
		
	dfs(endI,0,answer);
	
	cout << answer;
	
	return 0;
}