#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void numorder(int n, int m, int num, vector<int> nums, int (&answer)[8]){
    if(num==m){
        
        for(int i=0; i<m; i++){
            cout << answer[i] << '\n';
        }
    }
    
    else{
        int temp=0;
        for(int i=0; i<n; i++){
            if(temp!=nums[i]){
                answer[num]=nums[i];
                temp=nums[i];
                numorder(n, m, num+1, nums, answer);
            }
        }
    }
}

int main()
{
    int n, m;
    vector<int> nums;
    int answer[8];
    
    cin >> n >> m;
    
    for (int i=0; i<n; i++){
        
        int num;
        cin >> num;
        nums.push_back(num);
    }
    
    sort(nums.begin(), nums.end());

    numorder(n, m, 0, nums, answer);
    
    return 0;
}