#include <iostream>
#include <vector>

using namespace std;

bool is_valid(int x, int y){
    return (x>=0 && x<19 && y>=0 && y<19);
}

bool check(int num, int x, int y, vector<vector<int>>& dir, vector<vector<int>>& board, int& dir_5){
    for(int d=0; d<4; d++){
        int count=1;
        int dx=dir[d][0];
        int dy=dir[d][1];

        for(int i=1; i<=4; i++){
            int nx=x+i*dx;
            int ny=y+i*dy;

            if(is_valid(nx, ny) && board[nx][ny]==num){
                count++;
            }
            else{
                break;
            }
        }
        
        if(count==5){
            int dx_6=dir[dir_5][0], dy_6=dir[dir_5][1];
            if(is_valid(x-dx_6, y-dy_6) && board[x-dx_6][y-dy_6]==num){
                return false;
            }
            return true;
        }
    }
    return false;
}

bool six_check(int num, int x, int y, vector<vector<int>>& dir, vector<vector<int>>& board, int& dir_5){
    for(int d=0; d<4; d++){
        int count=1;
        int dx=dir[d][0];
        int dy=dir[d][1];

        for(int i=1; i<=5; i++){
            int nx=x+i*dx;
            int ny=y+i*dy;

            if(is_valid(nx, ny) && board[nx][ny]==num){
                count++;
            }
            else{
                break;
            }
        }
        
        if(count>5){
            dir_5=d;
            return true;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int winner, x_result, y_result, dir_5=2;
    vector<vector<int>> board(19,vector <int>(19));
    vector<vector<int>> dir={{1, 0}, {0, 1}, {1, 1}, {1, -1}};
    
    for(int i=0; i<19; i++){
        for(int j=0; j<19; j++){
            cin >> board[i][j];
        }
    }

    for(int i=0; i<19; i++){
        for(int j=0; j<19; j++){
            if(board[i][j]!=0){
                if(!six_check(board[i][j], i, j, dir, board, dir_5)){
                    if(check(board[i][j], i, j, dir, board, dir_5)){
                        winner=board[i][j];
                        x_result=i+1;
                        y_result=j+1;
                        break;
                    }
                }
            }
        }
        if(winner!=0){
            break;
        }
    }

    cout << winner << '\n';
    if(winner!=0){
        cout << x_result << " " << y_result;
    }

    return 0;
}
