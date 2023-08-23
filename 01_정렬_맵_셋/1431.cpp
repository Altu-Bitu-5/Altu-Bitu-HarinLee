#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const string &s1, const string &s2){
    if(s1.size()!=s2.size()){
        return s1.size()<s2.size();
    }
    int s1_sum=0, s2_sum=0;
    for(int i=0;i<s1.size();i++){
        if('0'<=s1[i] && s1[i]<='9'){
            s1_sum+=s1[i]-'0';
        }
        if('0'<=s2[i] && s2[i]<='9'){
            s2_sum+=s2[i]-'0';
        }
    }
    if(s1_sum!=s2_sum){
        return s1_sum<s2_sum;
    }
    return s1<s2;
}

int main(){
    
    int n;
    cin >> n;
    
    vector<string> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    sort(arr.begin(), arr.end(), cmp);
    
    for(int i=0;i<arr.size();i++){
        cout << arr[i] << '\n';
    }
    
    return 0;
}