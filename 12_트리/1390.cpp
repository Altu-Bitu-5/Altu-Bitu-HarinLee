#include <iostream>
#include <queue>

using namespace std;

int main(){
    
    int n, x_in, y_in , k, l, cnt=0, dir=0, x=0, y=0;
    char d;
    
    int board[101][101];
    bool visited[101][101];
    queue<pair<int, int>> snake;
    int dx[4]={1, 0, -1, 0};
    int dy[4]={0, 1, 0, -1};
    
    snake.push(make_pair(x, y));

    cin >> n;
    cin >> k;
    
    for(int i=0;i<k;i++){
        cin >> x_in >> y_in;
        board[x_in-1][y_in-1]=1;
    }
    
    cin>>l;

    for(int i=0;i<l;i++){
        
        int num;
        
        cin >> num >> d;
        
        while(cnt<num||i==l-1){ 
            int nx=x+dx[dir];
            int ny=y+dy[dir];
            cnt++;
 
            if(nx<0||ny<0||nx>=n||ny>=n||visited[ny][nx]){
                cout << cnt;
                return 0;
            }
            if(board[ny][nx]==1){
                board[ny][nx]=0;
                snake.push(make_pair(nx, ny));
                visited[ny][nx]=true;
                }
            else{
                snake.push(make_pair(nx,ny)); 
                visited[ny][nx]=true; 
                visited[snake.front().second][snake.front().first]=false;
                snake.pop();
                }
       
            x=nx;
            y=ny;
            if(cnt==num){
                if(d=='D'){
                    dir=(dir+1)%4; 
                }
                else if(d=='L'){
                    dir=(dir+3)%4;
                }
            }
        }
    }
    return 0;
}