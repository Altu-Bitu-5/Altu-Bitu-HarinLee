#include <iostream>
#include <string>

using namespace std;

int main()
{
    string king, rock, dir_str;
    int num, kingX, kingY, rockX, rockY, dir;
    
    cin >> king >> rock >> num;
    
    kingX='8'-king[1];
    kingY=king[0]-'A';
    rockX='8'-rock[1];
    rockY=rock[0]-'A';
    
    int chessX[8]={0, 0, 1, -1, -1, -1, 1, 1};
    int chessY[8]={1, -1, 0, 0, 1, -1, 1, -1};
    
    for(int i=0;i<num;i++){
        cin >> dir_str;
        if(dir_str=="R"){
            dir=0;
        }
        else if(dir_str=="L"){
            dir=1;
        }
        else if(dir_str=="B"){
            dir=2;
        }
        else if(dir_str=="T"){
            dir=3;
        }
        else if(dir_str=="RT"){
            dir=4;
        }
        else if(dir_str=="LT"){
            dir=5;
        }
        else if(dir_str=="RB"){
            dir=6;
        }
        else if(dir_str=="LB"){
            dir=7;
        }
        
        int kx=kingX+chessX[dir];
        int ky=kingY+chessY[dir];
        
        if (kx<0 || kx>7 || ky<0 || ky>7){
            continue;
        }
        if(kx==rockX && ky==rockY){
            int rx=rockX+chessX[dir];
            int ry=rockY+chessY[dir];
            if(rx<0 || rx>7 || ry<0 || ry>7){
                continue;
            }
            rockX=rx;
            rockY=ry;
        }
        kingX=kx;
        kingY=ky;
    }
    
    cout << (char)(kingY+'A') << 8-kingX << '\n';
    cout << (char)(rockY+'A') << 8-rockX << '\n';

    return 0;
}