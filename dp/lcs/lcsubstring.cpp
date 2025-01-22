#include<iostream>
#include<string.h>

using namespace std;

int dp[40][40];

int lcSubstring(string x, int xIndex, string y, int yIndex, int &maxLength)
{
    if(xIndex < 0 || yIndex < 0)
        return 0;

    if(dp[xIndex][yIndex] != -1)
        return dp[xIndex][yIndex];
    
    if(x[xIndex] == y[yIndex])
    {
        dp[xIndex][yIndex] = 1 + lcSubstring(x, xIndex-1, y, yIndex-1, maxLength);
        maxLength = max(maxLength, dp[xIndex][yIndex]);
        return dp[xIndex][yIndex];
    }
    
    return dp[xIndex][yIndex] = 0;
}

int main()
{
    string x = "abcdgh";
    string y = "abedohr";
    memset(dp, -1, sizeof(dp));
    int maxLength = 0;

    for(int i = 0; i < x.size(); i++)
    {
        for(int j = 0; j < y.size(); j++)
        {
            lcSubstring(x, i, y, j, maxLength);
        }
    }
    
    cout << "Length of Longest Common Substring: " << maxLength << endl;
    return 0;
}
