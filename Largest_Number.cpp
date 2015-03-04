//coding:utf-8
/*
Program: Largest Number
Description: 
Author: Flyaway - flyaway1217@gmail.com
Date: 2015-01-26 20:02:17
Last modified: 2015-01-26 21:35:26
GCC version: 4.7.3
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
    public:
    string largestNumber(vector<int> &num) 
    {
        vector<string> strnum;
        int i;
        string reval;
        for(i = 0; i < num.size(); ++i)
        {
            strnum.push_back(to_string(num[i]));
        }

        sort(strnum.begin(), strnum.end(), comp);

        if(strnum[strnum.size()-1] == "0")
        {
            return "0";
        }

        for(i = strnum.size() - 1; i >= 0; i--)
        {
            reval += strnum[i];
        }

        return reval;


    }

    static bool comp(string &strA, string &strB)
    {
        if(strA + strB < strB + strA)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};



int main()
{
    #define N 5
    int a[N] = {3, 30, 34, 5, 9};
    vector<int> arg(N);

    for(int i = 0; i < N; ++i)
    {
        arg[i] = a[i];
    }

    Solution s = Solution();
    cout<<s.largestNumber(arg);

}
