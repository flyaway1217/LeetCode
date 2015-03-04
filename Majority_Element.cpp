//coding:utf-8
/*
Program: Majority Element
Description: 
Author: Flyaway - flyaway1217@gmail.com
Date: 2015-01-12 10:40:54
Last modified: 2015-01-12 15:20:50
GCC version: 4.7.3
*/

#include <iostream>
#include <vector>

#define LENGTH 5

using namespace std;

class Solution 
{
    public:
    int majorityElement(vector<int> &num) 
    {
        int temp = num[0];
        int i = 1;
        int count = 1;
        for(i = 1; i < num.size() - 1;++i)
        {
            if(temp != num[i])
            {
                count--;
                if(count <= 0)
                {
                    temp = num[i+1];
                }
            }
            else
            {
                count++;
            }
        }
        return temp;
    }
};

int main()
{
    vector<int> num(LENGTH);
    //int a[LENGTH] = {8,8,7,7,7};
    int a[LENGTH] = {6,6,6,7,7};
    for(int i = 0;i < LENGTH; ++i)
    {
        num[i] = a[i];
    }
    Solution s = Solution();
    cout<<s.majorityElement(num);

}
