#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
    int n, m, num;
    string stm;
    
    cin >> n >> m;
    
    vector<string> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    
    for(int i=0;i<m;i++){
        cin >> stm;
        if(binary_search(arr.begin(), arr.end(), stm)){
            num++;
        }
    }
    
    cout << num;
    
    return 0;
}