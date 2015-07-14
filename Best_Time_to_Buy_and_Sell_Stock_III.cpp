//coding:utf-8
/*
Program: Best Time to Buy and Sell Stocks.
Description: 
Author: Flyaway - flyaway1217@gmail.com
Date: 2015-03-23 15:03:25
Last modified: 2015-03-23 15:04:27
GCC version: 4.7.3
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
    int maxProfit(vector<int> &prices) {
        int i,j;
        int max = 0;
        int current = 0;
        int n = prices.size();


        if(n <= 1)
            return 0;

        vector<int> delta(n-1);

        for(i = 1; i < n; ++i)
        {
            delta.push_back(prices[i] - prices[i-1]);
        }

        for(i = 0; i < delta.size(); ++i)
        {
            current += delta[i];

            if(current > max)
                max = current;

            if(current < 0)
                current = 0;
        }
        return max;
    }

};

