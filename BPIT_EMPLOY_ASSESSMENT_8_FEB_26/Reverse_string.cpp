/*
Given a string s, reverse it in place.

Example:
str = "railway"
ans = "yawliar"

Example:
str = "dad"
ans = "dad"
*/

#include <iostream>
#include<string>
#include<algorithm>
using namespace std;

void reverseStr(string& str) {
    int i = 0, j = str.length()-1;

    while(i < j) swap(str[i++], str[j--]);
}
int main() {
    string str = "rail";
    reverseStr(str);
    cout<<str<<endl;
    return 0;
}