#include <iostream>
using namespace std;

class Solution {

    public:

    int trailingZeroes(int n) 
    {
        int result = 0;
        long  i = 5;
        for(i = 5; n / i > 0; i *= 5)
        {
            result += (n/i);
        }
        return result;
    }
};


int main()
{
    Solution S = Solution();
    cout << S.trailingZeroes(15) << "\n";
    cout << S.trailingZeroes(25) << "\n";
    cout << S.trailingZeroes(30) << "\n";
    cout << S.trailingZeroes(125) << "\n";
    cout << S.trailingZeroes(126) << "\n";
//    cout << S.trailingZeroes(2147483647)<< "\n";
}
