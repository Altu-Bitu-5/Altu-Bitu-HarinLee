#include <iostream>

using namespace std;

int arr[300000];

int main()
{
    int n, speed;
    
    cin >> n;
    
    for(int i=0;i<n;i++){
        cin >> speed;
        arr[i]=speed;
    }
    
    long long answer=arr[n-1];
    
    for(int i=n-2;i>=0;i--){
        if(answer%arr[i]==0){
            continue;
        }
        else{
            answer = (answer / arr[i] + 1) * arr[i];
        }
    }
    
    cout << answer;

    return 0;
}