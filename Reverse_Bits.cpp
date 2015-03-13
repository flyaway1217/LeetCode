//coding:utf-8
/*
Program: Reverse Bits
Description: 
Author: Flyaway - flyaway1217@gmail.com
Date: 2015-03-11 18:47:07
Last modified: 2015-03-11 19:20:35
GCC version: 4.7.3
*/

#include<iostream>
#include<cstdint>
using namespace std;

class Solution {
    public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t x = n;
        uint32_t y = 0;
        uint32_t t;

        int i = 0;
        while(true)
        {
            t = x & 1;
            y = y | t;
            //bitset<32> my(y);
            //cout<<my<<endl;
 
            i += 1;
            if(i >= 32)
            {
                break;
            }
            x = x >> 1;
            y = y << 1;
        }
        //cout<<i<<endl;
        //bitset<32> myset(y);
        //cout<<endl<<myset<<endl;
 
        return y;
    }
};

int main()
{
    uint32_t  x = 43261596;
    //uint32_t  x = 1;
    Solution S = Solution();
    cout << S.reverseBits(x);
}
