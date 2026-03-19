#include <string>

using namespace std;

class Solution {
   public:
    char findKthBit(int n, int k) {
        string sequ = "0";
        for (int i = 0; i < n and k > sequ.length(); i++) {
            sequ += '1';
            string temp = sequ;
            for (int j = temp.length() - 2; j >= 0; j--) {
                char invertedBit = (temp[j] == '1') ? '0' : '1';
                sequ += invertedBit;
            }
        }
        return sequ[k - 1];
    }
};
