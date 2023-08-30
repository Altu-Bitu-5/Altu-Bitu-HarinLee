/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a, b, ab_total;
    int a_digit, b_digit, a_b, ab_over=0;
    char ab_char;
    
    cin >> a >> b;
    
    int a_size=a.size();
    int b_size=b.size();
    
    while (a_size>0||b_size>0){
        if(a_size>0){
            a_digit=a[--a_size]-'0';
        }
        else{
            a_digit=0;
        }
        if(b_size>0){
            b_digit=b[--b_size]-'0';
        }
        else{
            b_digit=0;
        }
        a_b=a_digit+b_digit+ab_over;
        ab_over=a_b/10;
        a_b%=10;
        ab_char=a_b+'0';
        ab_total+=ab_char;
    }
    if(ab_over!=0){
        ab_char=ab_over+'0';
        ab_total+=ab_char;
    }
    
    for(int i=ab_total.length()-1;i>=0;i--){
        cout << ab_total[i];
    }

    return 0;
}