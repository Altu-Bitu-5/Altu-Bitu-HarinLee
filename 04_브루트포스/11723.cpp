#include <iostream>

using namespace std;

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, S=0, cmd_num;
    string cmd="";
    
    cin >> n;
    
    for(int i=0;i<n;i++){
        cin >> cmd;
        if(cmd=="add"){
            cin>>cmd_num;
            S|=(1<<cmd_num);
        }
        else if(cmd=="remove"){
            cin >> cmd_num;
            S&= ~(1<<cmd_num);
        }
        else if(cmd=="check"){
            cin>>cmd_num;
            if(S&(1<<cmd_num)){
                cout<<1<<'\n';
            }
            else{
                cout<<0<<'\n';
            }
        }
        else if(cmd=="toggle"){
            cin>>cmd_num;
            S^=(1<<cmd_num);
        }
        else if(cmd=="all"){
            S=(1<<21)-1;
        }
        else if(cmd=="empty"){
            S=0;
        }
    }
    
    return 0;
}