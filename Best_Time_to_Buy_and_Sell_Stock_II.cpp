//coding:utf-8
/*
Program: Best Time to Buy and Sell Stock
Description: 
Author: Flyaway - flyaway1217@gmail.com
Date: 2015-03-23 14:48:18
Last modified: 2015-03-23 14:54:03
GCC version: 4.7.3
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
    int maxProfit(vector<int> &prices) {
        int i;
        int sum = 0;
        int delta = 0;
        int n = prices.size();

        if(n <= 1)
            return 0;

        for(i = 1; i < n; ++i)
        {
            delta = prices[i] - prices[i-1];
            if(delta > 0)
                sum += delta;
        }

       return sum;
    }
};


