//coding:utf-8
/*
Program: Numer of 1 bits
Description: 
Author: Flyaway - flyaway1217@gmail.com
Date: 2015-03-11 13:33:54
Last modified: 2015-03-11 19:04:42
GCC version: 4.7.3
*/

#include<iostream>
#include<cstdint>
#include<bitset>
using namespace std;

class Solution 
{
    public:
    int hammingWeight(uint32_t n) 
    {
        uint32_t m = n;
        int count = 0;
        while(m > 0)
        {
            count += (m & 1);
            m = m >> 1;
        }
        return count;
            
    }
};

int main()
{
    Solution S = Solution();
    uint32_t n = 11;
    cout << S.hammingWeight(n);
}
