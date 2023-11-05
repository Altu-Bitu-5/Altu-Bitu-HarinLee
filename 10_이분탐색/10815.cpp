#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m, num, temp;
    vector<int> nums;
    
    cin >> n;
    
    while (n--){
        cin >> temp;
        nums.push_back(temp);
    }
    
    sort(nums.begin(), nums.end());
    
    cin >> m;
    while (m--){
        cin >> num;
        if(binary_search(nums.begin(), nums.end(), num)){
            cout << '1' << ' ';
        }
        else{
            cout << '0' << ' ';
        }
    }

    return 0;
}