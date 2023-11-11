#include <iostream>
#include <algorithm>

using namespace std;
 
int main(){
    
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
	int n, k, start=0, end=0, answer=0;
	int num[200001];
    int cnt[100001];
	
	cin >> n >> k;
	
	for(int i=0;i<n;i++){
        cin >> num[i];
	}

	while(start<n){
		if(cnt[num[start]]==k){
			cnt[num[end]]--;
			end++;
		}
		else{
			cnt[num[start]]++;
			start++;
		}
		
		answer=answer>start-end?answer:start-end;
	}
	
	cout << answer;
	
	return 0;
}