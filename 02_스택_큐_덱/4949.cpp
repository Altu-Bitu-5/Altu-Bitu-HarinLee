#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
    while(true){
        
        string str;
        stack<char> s;
        bool result=true;
        
        getline(cin, str);
        
        if(str[0]=='.'){
            break;
        }
        
        for(int i=0;i<str.length();i++){
            if(str[i]=='('||str[i]=='['){
                s.push(str[i]);
            }
            else if(str[i]==')'){
                if(s.empty()||s.top()=='['){
                    result=false;
                    break;
                }
                else{
                    s.pop();
                }
            }
            else if(str[i]==']'){
                if(s.empty()||s.top()=='('){
                    result=false;
                    break;
                }
                else{
                    s.pop();
                }
            }
        }
        
        if(!s.empty()||result==false){
            cout << "no" << '\n';
        }
        else{
            cout << "yes" << '\n';
        }
    }
    
    return 0;
}