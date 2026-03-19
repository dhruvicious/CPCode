#include <algorithm>
#include <functional>
#include <memory>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

class Solution {
   public:
    // Question 1; Get Concat
    //  You are given an integer array nums of length n.
    //  Create an array ans of length 2n where ans[i] == nums[i]
    //  and ans[i + n] == nums[i] for 0 <= i < n (0-indexed).
    // Specifically, ans is the concatenation of two nums arrays.
    // Return the array ans.
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            nums.push_back(nums[i]);
        }
        return nums;
    }

    // Question 2; Has Duplicates
    //  Given an integer array nums, return true if any
    //  value appears more than once in the array, otherwise return false.
    bool hasDuplicate(vector<int>& nums) {
        auto seen = make_unique<unordered_set<int>>();
        for (int i : nums) {
            if (seen->contains(i)) {
                return true;
            }
            seen->insert(i);
        }
        return false;
    }

    // Question 3; Is Anagram
    //  Given two strings s and t, return true if the two strings are anagrams
    //  of each other,otherwise return false.
    //  An anagram is a string that contains the exact same characters as
    //  another string, but the order of the characters can be different.
    bool isAnagram(string s, string t) {
        unordered_map<char, int> freqMap;
        for (char& c : s) freqMap[c]++;
        for (char& c : t) freqMap[c]--;
        for (auto [c, f] : freqMap) {
            if (f != 0) return false;
        }
        return true;
    }

    // Question 4; Two Sum
    //  Given an array of integers nums and an integer target, return the
    //  indices i and j such that nums[i] + nums[j] == target and i != j.
    //  You may assume that every input has exactly one pair of indices i
    //  and j that satisfy the condition.
    //  Return the answer with the smaller index first.
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> indexMap;
        for (int i = 0; i < n; i++) {
            int comp = target - nums[i];
            if (indexMap.find(comp) != indexMap.end()) {
                return {i, indexMap[comp]};
            }
            indexMap[nums[i]] = i;
        }
        return {};
    }

    // Question 5; Longest Common Prefix
    //  Write a function to find the longest common prefix string amongst an array
    //  of strings. If there is no common prefix, return an empty string "".
    //
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if (strs.empty()) return "";
        string prefix = strs[0];
        for (int i = 0; i < n; i++) {
            while (strs[i].find(prefix) != 0) {
                prefix.pop_back();
                if (prefix.empty()) return "";
            }
        }
        return prefix;
    }

    // Question 6; Group Anagrams
    //  Given an array of strings strs, group all anagrams together into sublists.
    //  You may return the output in any order.
    //  An anagram is a string that contains the exact same characters as another string,
    //   but the order of the characters can be different.
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for (const string s : strs) {
            vector<int> freq(26);
            for (char c : s) freq[c - 'a']++;
            string keyHash;
            for (int count : freq) {
                keyHash += '#';
                keyHash += to_string(count);
            }
            map[keyHash].push_back(s);
        }
        vector<vector<string>> res;
        for (auto [hash, strs] : map) {
            res.push_back(strs);
        }
        return res;
    }

    // Question 7; Remove Elements
    //  You are given an integer array nums and an integer val. Your task is to remove
    //  all occurrences of val from nums in-place.
    //  After removing all occurrences of val, return the number of remaining elements, say k,
    //   such that the first k elements of nums do not contain val.
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int k = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == val) {
                nums[k++] = nums[i];
            }
        }
        return k;
    }

    // Question 8; Majority Elements
    //  Given an array nums of size n, return the majority element.
    //  The majority element is the element that appears more than ⌊n / 2⌋ times in the array.
    //  You may assume that the majority element always exists in the array.
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ms = 0;
        int mel = nums[0];

        int left = 0;
        for (int right = 1; right <= n; right++) {
            if (right == n || nums[right] != nums[left]) {
                if (right - left > ms) {
                    ms = right - left;
                    mel = nums[left];
                }
                left = right;
            }
        }
        return mel;
    }

    // Question 9; Design Hashset
    //  Design a HashSet without using any built-in hash table libraries.
    //  Implement MyHashSet class:
    //  void add(key) Inserts the value key into the HashSet.
    //  bool contains(key) Returns whether the value key exists in the HashSet or not.
    //  void remove(key) Removes the value key in the HashSet. If key does not exist
    //  in the HashSet, do nothing.
    class MyHashSet {
       private:
        vector<bool> table;

       public:
        MyHashSet() { table.resize(1000001, false); }

        void add(int key) { table[key] = true; }

        void remove(int key) { table[key] = false; }

        bool contains(int key) { return table[key]; }
    };

    // Question 10; Design HashMap
    // Design a HashMap without using any built-in hash table libraries.
    // Implement the MyHashMap class:
    // MyHashMap() initializes the object with an empty map.
    // void put(int key, int value) inserts a (key, value) pair into the HashMap.
    // If the key already exists in the map, update the corresponding value.
    // int get(int key) returns the value to which the specified key is mapped,
    // or -1 if this map contains no mapping for the key.
    // void remove(key) removes the key and its corresponding value if the map
    // contains the mapping for the key.
    class MyHashMap {
       private:
        vector<int> table;
        vector<bool> present;

       public:
        MyHashMap() {
            table.resize(1000001);
            present.resize(1000001, false);
        }

        void put(int key, int value) {
            table[key] = value;
            present[key] = true;
        }

        int get(int key) {
            if (!present[key]) return -1;
            return table[key];
        }

        void remove(int key) { present[key] = false; }
    };

    // Question 11; Sort Array
    // You are given an array of integers nums, sort the array in ascending order and return it.
    // You must solve the problem without using any built-in functions in O(nlog(n)) time complexity
    // and with the smallest space complexity possible.
    void merge(vector<int>& nums, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        vector<int> L(n1);
        vector<int> R(n2);

        for (int i = 0; i < n1; i++) L[i] = nums[left + i];
        for (int j = 0; j < n2; j++) R[j] = nums[mid + 1 + j];

        int i = 0, j = 0;
        int k = left;

        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                nums[k] = L[i];
                i++;
            } else {
                nums[k] = R[j];
                j++;
            }
            k++;
        }
        while (i < n1) {
            nums[k] = L[i];
            i++;
            k++;
        }
        while (j < n2) {
            nums[k] = R[j];
            j++;
            k++;
        }
    }
    void mysort(vector<int>& nums, int start, int end) {
        if (start >= end) return;
        int mid = start + ((end - start) / 2);
        mysort(nums, start, mid);
        mysort(nums, mid + 1, end);
        merge(nums, start, mid, end);
    }
    vector<int> sortArray(vector<int>& nums) {
        mysort(nums, 0, nums.size() - 1);
        return nums;
    }

    // Question 12; Sort Colors
    //  You are given an array nums consisting of n elements where each element is an integer
    //  representing a color:
    //  0 represents red
    //  1 represents white
    //  2 represents blue
    //  Your task is to sort the array in-place such that elements of the same color are grouped
    //  together and arranged in the order: red (0), white (1), and then blue (2).
    //  You must not use any built-in sorting functions to solve this problem.
    void sortColors(vector<int>& nums) {
        int count0 = 0, count1 = 0, count2 = 0;
        for (int i : nums) {
            if (i == 0)
                count0++;
            else if (i == 1)
                count1++;
            else if (i == 2)
                count2++;
        }
        int index = 0;
        while (count0-- > 0) nums[index++] = 0;
        while (count1-- > 0) nums[index++] = 1;
        while (count2-- > 0) nums[index++] = 2;
    }

    // Question 13; Top K Frequent Elements
    //  Given an integer array nums and an integer k, return the k most frequent elements within the array.
    //  The test cases are generated such that the answer is always unique.
    //  You may return the output in any order.
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        for (int i : nums) freq[i]++;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (auto& p : freq) {
            pq.push({p.second, p.first});
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }

    // Question 14; Encode and Decode Strings
    //  Design an algorithm to encode a list of strings to a string.
    //  The encoded string is then sent over the network and is decoded back to
    //  the original list of strings.
    string encode(vector<string>& strs) {
        string encoded;
        for (string s : strs) {
            encoded.append(to_string(s.size()));
            encoded.push_back('#');
            encoded.append(s);
        }
        return encoded;
    }
    
    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;
        int n = s.size();

        while (i < n) {
            int len = 0;

            while (s[i] != '#') {
                len = len * 10 + (s[i] - '0');
                i++;
            }

            i++;
            result.push_back(s.substr(i, len));
            i += len;
        }

        return result;
    }
    
    
};

int main() {
    return 0;
}
