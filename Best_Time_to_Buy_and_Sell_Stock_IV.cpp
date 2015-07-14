//coding:utf-8
/*
Program: Best time to buy and sell stock.
Description: 
Author: Flyaway - flyaway1217@gmail.com
Date: 2015-03-18 17:04:34
Last modified: 2015-03-18 21:34:55
GCC version: 4.7.3
*/

#include<iostream>
#include<vector>
#include<algorithm>

#define M 8

using namespace std;


class Solution 
{
    public:
    int maxProfit(int k, vector<int> &prices) 
    {

        if(prices.size() <= 0)
            return 0;
        vector<int> delta_prices(prices.size()-1);
        vector<int> table;
        int i;
        int s = 0;

        //init delta prices
        for(i = 0; i < prices.size()-1; ++i)
        {
            delta_prices[i] = prices[i+1] - prices[i];
        }

        s = 0;
        for(i = 0 ; i < delta_prices.size() ; ++i)
        {
            if(delta_prices[i] >= 0)
                s += delta_prices[i];
            else
            {
                if(s != 0)
                    table.push_back(s);
                s = 0;
                table.push_back(delta_prices[i]);
            }
        }
        if(s != 0)
            table.push_back(s);


        sort( table.begin(), table.end(), greater<int>() );

        s = 0;
        for(i = 0; i < k && table[i] >= 0 ; ++i)
        {
            s += table[i];
        }

        return s;
   }

    void print(vector<int> v)
    {
        int i = 0;
        cout<<v.size()<<endl;
        for(i = 0; i < v.size(); ++i)
        {
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }


};

int main()
{
    Solution s = Solution();
    int a[M] = {0,1,3,1,3,1,3,4};

    vector<int> b(M);

    for(int i = 0; i < M; ++i)
    {
        b[i] = a[i];
    }

    cout<<s.maxProfit(2, b);
}
