#include <bits/stdc++.h>
using namespace std;

string parityCalculator(string message, int r);

string reverseString(string data)
{
    string reverse = "";
    for (int i = data.size() - 1; i >= 0; i--)
    {
        reverse.push_back(data[i]);
    }
    return reverse;
}

string createMessage(string data)
{
    int dataSize = data.size();
    int r = 0;
    while (1)
    {
        if (pow(2, r) >= dataSize + r + 1)
            break;
        r++;
    }
    cout << "Value of r : " << r << endl;
    string message = "";
    int i = 0, j = dataSize - 1, k = 0;
    while (k < (dataSize + r))
    {
        if ((pow(2, i) - 1) == k)
        {
            message.push_back('p');
            i++;
        }
        else
        {
            message.push_back(data[j]);
            j--;
        }
        k++;
    }
    cout << "Intermediate message : " << reverseString(message) << endl;
    return reverseString(parityCalculator(message, r));
}

string parityCalculator(string message, int r)
{
    int i = 0;
    while (i < r)
    {
        int j = pow(2, i);
        int stLoc = 0;
        int parity = -1;
        while (stLoc <= message.size())
        {
            int skip = j, accept = j;
            stLoc += skip;
            while (accept && stLoc <= message.size())
            {
                if (message[stLoc - 1] != 'p')
                {
                    if (parity == -1)
                        parity = message[stLoc - 1] - '0';
                    else
                        parity ^= (message[stLoc - 1] - '0');
                }
                stLoc++;
                accept--;
            }
        }
        i++;
        message[j - 1] = '0' + parity;
        // cout << "\n" << parity << endl;
    }
    return message;
}

int main()
{
    string data = "1011";
    string hammingMessage = createMessage(data);
    cout << hammingMessage << endl;
    // parityCalculator("pp1p101", 3);
    return 0;
}