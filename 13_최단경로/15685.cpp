#include <iostream>
#include <vector>

using namespace std;

vector<int> dir;
int board[101][101];

void dragon_curve(int &x, int &y, vector<int> dx, vector<int> dy){
    for(int i=dir.size()-1;i>=0;i--){
        int temp=(dir[i]+1)%4;
        x+=dx[temp];
        y+=dy[temp];
        dir.push_back(temp);
        board[x][y] = 1;
    }
}

int main()
{
    int n, x, y, d, g, cnt=0;
    vector<int> dx={1,0,-1,0};
    vector<int> dy={0,-1,0,1};
    
    cin >> n;

    while(n--){
        dir.clear();
        
        cin >> x >> y >> d >> g;

        board[x][y]=1;
        x+=dx[d];
        y+=dy[d];
        board[x][y]=1;
        dir.push_back(d);

        while (g--){
            dragon_curve(x,y, dx, dy);
        }
    }

    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            if(board[i][j]==1&&board[i][j+1]==1&&board[i+1][j+1]==1&&board[i+1][j]==1)
                cnt++;
        }
    }

    cout << cnt;

    return 0;
}