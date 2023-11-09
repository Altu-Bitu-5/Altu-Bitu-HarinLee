#include <iostream>
#include <vector>

using namespace std;

int board[500][500];
int visited[500][500];

void dfs(int y, int x, int cnt, int num, int &answer, int n, int m, vector<int> dx, vector<int> dy){
    visited[y][x]=true;
    num+=board[y][x];
    if(cnt==4){
        answer=answer<num ? num:answer;
        visited[y][x]=0;
    }
    else{
        for(int i=0;i<4;i++){
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(ny<0 || ny>=n || nx<0 || nx>=m){
                continue;
            }
            if(visited[ny][nx]){
                continue;
            }
            dfs(ny, nx, cnt + 1, num, answer, n, m, dx, dy);
        }
        visited[y][x]=false;
    }
}

void shape(int y, int x, int &answer, int n, int m, vector<int> dx, vector<int> dy){
    
    int sum, ny, nx;
	for(int i=0;i<4;i++){
		sum=board[y][x];
		for(int j=0;j<4;j++){
			if(i==j){
				continue;
			}
			ny=y+dy[j];
			nx=x+dx[j];
			if(ny>=0 && ny<n && nx>=0 && nx<m){
				sum+=board[ny][nx];
			}
		}
		answer=answer<sum ? sum:answer;
	}
}

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
	int n, m, answer;
    vector<int> dx={0,1,0,-1};
    vector<int> dy={1,0,-1,0};
    
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> board[i][j];
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            dfs(i, j, 1, 0, answer, n, m, dx, dy);
            shape(i, j, answer, n, m, dx, dy);
        }
    }
    
    cout << answer;
    

    return 0;
}
