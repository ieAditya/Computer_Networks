#include<bits/stdc++.h>
using namespace std;

int precidence(char c){
    if(c == '^')
        return 3;
    else if(c == '*' || c == '/')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string infixToPostfix(string s){
    string ans;
    stack<char> temp;
    int i = 0, size = s.size();
    while(i<size){
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9')){
            ans += s[i];
        }
        else if(s[i] == '('){
            temp.push('(');
        }
        else if(s[i] == ')'){
            while(temp.top() != '('){
                ans += temp.top();
                temp.pop();
            }
            temp.pop();
        }
        else{
            int precCurr = precidence(s[i]);
            while(!temp.empty() && precCurr <= precidence(temp.top())){
                ans += temp.top();
                temp.pop();
            }
            temp.push(s[i]);
        }
        i++;
    }
    while(!temp.empty()){
        ans += temp.top();
        temp.pop();
    }
    return ans;
}

int main(){
    // string s = "((A+B)-C*(D/E))+F";
    // string s = "A+B*C+D";
    string s = "C+H*B+(F+H)";
    string ans = infixToPostfix(s);
    cout<<ans;
    return 0;
}