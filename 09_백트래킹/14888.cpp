#include <iostream>

using namespace std;

void calculate(int n, int &maxnum, int &minnum, int result, int cnt, int nums[11], int ops[4])
{
    if(cnt==n)
    {
        if(result>maxnum){
            maxnum=result;
        }
        if(result<minnum){
            minnum=result;
        }
    }
    else{
        for(int i=0; i<4; i++)
        {
            if(ops[i]!=0)
            {
                ops[i]--;
                switch(i){
                    case 0:
                        calculate(n, maxnum, minnum, result+nums[cnt], cnt+1, nums, ops);
                        break;
                    case 1:
                        calculate(n, maxnum, minnum, result-nums[cnt], cnt+1, nums, ops);
                        break;
                    case 2:
                        calculate(n, maxnum, minnum, result*nums[cnt], cnt+1, nums, ops);
                        break;
                    case 3:
                        calculate(n, maxnum, minnum, result/nums[cnt], cnt+1, nums, ops);
                        break;
                }
                ops[i]++;
            }
        }
    }
    return;
}
int main() {
    int n;
    int maxnum=-1000000000, minnum=1000000000;
    int ops[4];
    int nums[11];
    
    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }
    for(int i=0; i<4; i++){
        cin >> ops[i];
    }
    
    calculate(n, maxnum, minnum, nums[0],1,nums,ops);
    cout << maxnum << '\n' << minnum;
}