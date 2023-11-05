#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

vector<int> dir_x={-1, 1, -1, 1, 0, 0, -1, 1};
vector<int> dir_y={-1, 1, 1, -1, 1, -1, 0, 0};
int board[50][50];
bool visited[50][50]={false,};

bool is_ok(int x, int y, int w, int h){
    return (x>=0 && x<h && y>=0 && y<w);
}

void dfs(int x, int y, int w, int h){
    
    for(int i=0; i<8; i++){
        int nx=x+dir_x[i];
        int ny=y+dir_y[i];
        
        if(is_ok(nx, ny, w, h)){
            if(!visited[nx][ny]&&board[nx][ny]){
                visited[nx][ny]=true;
                dfs(nx, ny, w, h);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    int w, h, count=0;
    
    while(1){
        
        cin >> w >> h;
        
        if(w==0 && h==0){
            break;
        }
        for(int i=0; i<h; i++){
            for(int j=0;j<w;j++){
                cin >> board[i][j];
            }
        }
        for(int i=0; i<h;i++){
            for(int j=0;j<w;j++){
                if(!visited[i][j] && board[i][j]){
                    count++;
                    dfs(i, j, w, h);
                }
            }
        }
        cout << count << '\n';
        
        memset(visited,false,sizeof(visited));
        count=0;
    }
}
