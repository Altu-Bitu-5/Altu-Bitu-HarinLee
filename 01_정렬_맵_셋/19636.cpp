#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int w1, day_eat, diet_eat, diet_ex, n, tr;
    
    cin >> w1 >> day_eat >> tr;
    cin >> n >> diet_eat >> diet_ex;
    
    int day_life=day_eat;
    int diet_life=day_life;
    int w0=w1;
    int tr_w;
    
    for(int i=0;i<n;i++){
        tr_w=diet_eat - diet_life - diet_ex;
        w1+=tr_w;
        if (abs(tr_w)>tr){
            diet_life+=floor(tr_w/2.0);
        }
        w0+=diet_eat - day_life - diet_ex;
    }
    
    if(w0<=0){
        cout<<"Danger Diet" << '\n';
    }
    else{
        cout << w0 << ' ' << day_life << '\n';
    }
    
    if(diet_life<=0 || w1<=0){
        cout << "Danger Diet" << '\n';
    }
    else{
        if(day_life > diet_life){
            cout << w1 << ' ' << diet_life << ' ' << "YOYO" << '\n';
        }
        else{
            cout << w1 << ' ' << diet_life << ' ' << "NO" << '\n';
        }
    }
    
    return 0;
}
