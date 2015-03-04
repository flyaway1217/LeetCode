//coding:utf-8
/*
Program: Maximum Gap
Description: 
Author: Flyaway - flyaway1217@gmail.com
Date: 2015-01-13 14:12:57
Last modified: 2015-02-02 19:51:50
GCC version: 4.7.3
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
    public:
    int maximumGap(vector<int> &num) 
    {
        if(num.size() < 2)
        {
            return 0;
        }

        int min = getMin(num) ;
        int max = getMax(num);
        int step =  (max - min) / (num.size() - 1 );

        if(step == 0)
        {
            step = 1;
        }

        //cout<<"step="<<step<<endl;

        vector<vector<int> > temp((max - min) / step + 1);
        vector<vector<int> > table;

        int i,j,index;
        int delta = 0;


        //cout<<"temp size="<<temp.size()<<endl;
        for(i = 0; i < num.size(); ++i)
        {
            index = (num[i] - min) / step;
            //cout<<i<<"\t"<<index<<endl;
            temp[index].push_back(num[i]);
        }


        for(i = 0; i < temp.size(); ++i)
        {
            if(temp[i].size() != 0)
            {
                table.push_back(temp[i]);
            }
        }

        //cout<<"table size="<<table.size()<<endl;

        for(i = 1; i < table.size(); ++i)
        {
            max = getMax(table[i-1]);
            min = getMin(table[i]);
            if(delta < (min - max) )
            {
                delta = min - max ;
            }
        }
        return delta;
    }

    int getMin(vector<int> &num)
    {
        int i;
        int min = num[0];
        for(i = 0; i < num.size(); ++i)
        {
            if(num[i] < min)
            {
                min = num[i];
            }
        }
        return min;
    }

    int getMax(vector<int> &num)
    {
        int i;
        int max = num[0];
        for(i = 0; i < num.size(); ++i)
        {
            if(num[i] > max)
            {
                max = num[i];
            }
        }
        return max;
    }

};

int main()
{
    #define N 10
    //int a[N] = {3,6,9,1};
    //int a[N] = {2,4,7,11,12,1002};
    int a[N] = {1,1,1,1,1,5,5,5,5,5};

    //39 int a[N] = {15252,16764,27963,7817,26155,20757,3478,22602,20404,6739,16790,10588,16521,6644,20880,15632,27078,25463,20124,15728,30042,16604,17223,4388,23646,32683,23688,12439,30630,3895,7926,22101,32406,21540,31799,3768,26679,21799,23740};
    vector<int> v(N) ;
    
    for(int i = 0; i < N; ++i)
    {
        v[i] = a[i];
    }
    Solution s = Solution();
    cout<<s.maximumGap(v);
}
