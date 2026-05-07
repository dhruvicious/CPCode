#include <algorithm>
#include <string>

using namespace std;

class Solution {
   public:
    bool canBeEqual(string& s1, string& s2) {
        string t = s1;

        swap(t[1], t[3]);
        if (t == s2) return true;

        t = s1;
        swap(t[0], t[2]);
        if (t == s2) return true;

        t = s1;
        swap(t[0], t[2]);
        swap(t[1], t[3]);
        if (t == s2) return true;

        return s1 == s2;
    }
};
