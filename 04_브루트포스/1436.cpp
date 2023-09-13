#include <iostream>

using namespace std;

int main(){
    
    int n, n_temp, count=1, num=666;
    
    cin >> n;
    
    while(count!=n){
        if(n==1){
            break;
        }
        
        num++;
        n_temp=num;
        
        while(n_temp!=0){
            if(n_temp%1000==666){
                count++;
                break;
            }
            else{
                n_temp/=10;
            }
        }
    }
    
    cout << num;
    return 0;
}