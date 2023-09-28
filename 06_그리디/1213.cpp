#include <iostream>

using namespace std;

int alphabet[26];

bool isPossible(string &mid){
    int count=0;
    
    for(int i=0;i<26;i++){
        if(alphabet[i]!=0){
            if(alphabet[i]%2==1){
                count++;
                if(count>1){
                    return false;
                }
                mid=i+'A';
            }
        }
    }
    return true;
}

string makePd(string mid){
    string ans;
    for(int i=0;i<26;i++){
        for(int j=0;j<alphabet[i]/2;j++){
            ans+=i+'A';
        }
    }
    ans+=mid;
    for(int i=25;i>=0;i--){
        for(int j=0;j<alphabet[i]/2;j++){
            ans+=i+'A';
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    
    string s, answer="", mid="";
    
    cin >> s;
    
    for(int i=0;i<s.size();i++){
        alphabet[s[i]-'A']++;
    }
    
    if(!isPossible(mid)){
        cout << "I'm Sorry Hansoo";
        return 0;
    }
    else{
        answer=makePd(mid);
    }
    
    cout << answer;

    return 0;
}