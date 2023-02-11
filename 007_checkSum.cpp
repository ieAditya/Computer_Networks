#include <bits/stdc++.h>
using namespace std;

void checkForAcceptance(string &message)
{
    int size = message.size();
    int initIndex = (2 * size) / 3;
    int lenOfSubstr = size - initIndex;
    // cout << initIndex << " " << lenOfSubstr;
    string block1 = message.substr(0, size / 3);
    string block2 = message.substr(size / 3, size / 3);
    string checkSum = message.substr(initIndex, lenOfSubstr);
    // cout << block1 << endl;
    // cout << block2 << endl;
    // cout << checkSum << endl;
    string sum = "";
    int carry = 0;
    for (int i = block1.size() - 1; i >= 0; i--)
    {
        int tempSum = (block1[i] - '0') + (block2[i] - '0') + carry;
        carry = 0;
        if (tempSum == 2)
        {
            sum = '1' + sum; // storing compliment
            carry = 1;
        }
        else if (tempSum == 3)
        {
            sum = '0' + sum; // storing compliment
            carry = 1;
        }
        else
        {
            if (tempSum == 0)
                sum = '1' + sum; // storing compliment
            else
                sum = '0' + sum; // storing compliment
        }
    }
    // cout << sum << endl;
    if (sum == checkSum)
        cout << "Accepted";
    else
        cout << "Rejected";
}

int main()
{
    // string data = "101010010011100100011101"; // Right data
    // string data = "101011010011100100011101"; // Wrong data
    string data = "001010011011100100011101"; // Wrong data still accepts
    checkForAcceptance(data);
    return 0;
}