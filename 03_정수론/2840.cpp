#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k, pt;
    
    cin >> n >> k;
    
    vector<char> arr(n,'?');
    
    for(int i=0;i<k;i++){
        int turns;
        char c;
        
        cin >> turns >> c;
        
        if(i==0){
            pt=i;
            arr[i]=c;
            continue;
        }
        
        pt=(pt+turns)%n;
        if(arr[pt]!='?' && arr[pt]!=c){
            cout << "!";
            return 0;
        }
        else{
            arr[pt]=c;
        }

    }
    
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]!='?' && arr[i]==arr[j]){
                cout << "!";
                return 0;
            }
        }
    }
    
    for(int i=0;i<arr.size();i++){
        cout << arr[pt];
        pt--;
        if(pt<0){
            pt=n-1;
        }
    }
    
    return 0;
}