#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* createLinkedList(const int arr[], int size) {
    if (size == 0) return nullptr;
    
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    
    for (int i = 1; i < size; ++i) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    
    return head;
}

class Solution{
    public:
        // bool WaterMelon(int w){
        //     int remainder= w & 1;
        //     return (remainder==0);
        // };

        // void HalloumiBoxes(){
        //     //if k is greater than or equal to 2 print yes else no
        //     int t;
        //     cin>>t;
        //     while(t--){
        //         long long n,k;
        //         cin >> n >> k;
        //         vector<long long> arr(n) 
        //         for (int i = 0; i < n; i++)
        //         {
        //             /* code */
        //             cin >> arr[i];
        //         }
        //         vector<long long> copy_arr=arr;
        //         sort(copy_arr.begin(), copy_arr.end());
        //         if(copy_arr == arr || k>=2){
        //             cout << "Yes"<< endl;
        //         }
        //         else{
        //             cout<< "No" << endl;
        //         }
        //     }
        // }

        // void HalloumiBoxes(){
        //     int t;
        //     cin >> t;
        //     while(t--){
        //         //inputs
        //         long long n,k;
        //         cin >> n >> k;
        //         vector<long long> arr(n);
        //         for(int i=0; i < n; i++){
        //             cin >> arr[i];
        //         }
        //         vector<long long> copy_arr=arr;
        //         sort(copy_arr.begin(), copy_arr.end());
        //         if(copy_arr==arr||k>=2){
        //             cout<< "Yes"<<endl;
        //         }else{
        //             cout<< "No"<<endl;
        //         }
        //     }
        // }

        // void lineTrip(){
        //     int maxDiff;
        //     int t;
        //     cin >> t;
        //     while(t--){
        //         //inputs
        //         int x, n;
        //         cin>>n>>x;
        //         vector<int> arr(n);
        //         for(int i =0; i < n; i++){
        //             cin>>arr[i];
        //         }
        //         maxDiff=arr[0]-0;
        //         for(int i = 0; i < n-1; i++){
        //             int diff=arr[i+1]-arr[i];
        //             if(diff>maxDiff){
        //                 maxDiff=diff;
        //             }
        //         }
        //         if((x-arr[n-1])*2>maxDiff){
        //             maxDiff=(x-arr[n-1])*2;
        //         }
        //         cout << maxDiff<<endl;
        //     }
        // }

        // bool isPrime(int x){
        //     if(x<2) return false;
        //     for(int i = 2; i *i<= x; i++){
        //         if(x%i==0){
        //             return false;
        //         }
        //     }
        //     return true;
        // }
        // vector<int> closestPrimes(int left, int right) {
        //     std::vector<int> primeArray;
        //     // find primes between left and right that have minimum difference between them
        //     for(int i = left; i <= right; i++){
        //         if(isPrime(i)){
        //             //add it to the prime array
        //             primeArray.push_back(i);
        //         }
        //     }
        //     if(primeArray.size()<2) return {-1,-1};
        //     int minDiff= INT_MAX;
        //     vector<int> result(2);
        //     for(int i =1;i<primeArray.size();i++){
        //         int diff= primeArray[i]-primeArray[i-1];
        //         if(diff<minDiff){
        //             minDiff=diff;
        //             result= {primeArray[i-1], primeArray[i]};
        //         }
        //     }
        //     return result;
        // }

    // void CoverInWater(){
    //     int t;
    //     cin >> t;
    //     while(t--){
    //         //inputs
    //         int n;
    //         string waterRow;
    //         cin >> n;
    //         cin >> waterRow;
    //         //calculations
    //         // if(waterRow.find('.')==string::npos){
    //         //     cout<<0<<endl;
    //         //     continue;
    //         // }
    //         size_t pos=waterRow.find("...");
    //         if(pos==string::npos){
    //             int emptyCellCount=0;
    //             for(int i =0; i<waterRow.size(); i++){
    //                 if(waterRow[i]=='.'){
    //                     emptyCellCount++;
    //                 }
    //             }
    //             cout<<emptyCellCount<<endl;
    //         }else{
    //             cout<<2<<endl;
    //         }
    //     }
    // }

    // void coverInWater(){
    //     int t;
    //     cin >> t;
    //     while(t--){
    //         string waterRow;
    //         int n;
    //         cin >> n;
    //         cin >> waterRow;
    //         int emptyCellCount=0;
    //         for(int i =0; i < waterRow.size(); i++){
    //             if(waterRow[i]=='.'){
    //                 emptyCellCount++;
    //             }
    //         }
    //         //calculations;
    //         if(waterRow.find('...')==string::npos){
    //             cout << emptyCellCount << endl;
    //         }else{
    //             cout << 2 << endl;
    //         }
    //     } 
    // }

    // void gameWithIntegers(){
    //     int testCase;
    //     cin >> testCase;
    //     while(testCase--){
    //         int x;
    //         cin >> x;
    //         if(x%3==0){
    //             cout<< "Second"<<endl;
    //         }else cout << "First"<<endl;
    //     }
    // }

    // int numberOfAlternatingTiles(vector<int>& colors, int k){
    //     //find the number of alternating subsets of size k
    //     int n = colors.size();
    //     vector<int> circClr= colors;
    //     circClr.insert(circClr.end(), colors.begin(), colors.end());
    //     int count=0;
    //     int valid=0;
    //     for(int i =0;i< k-1;i++){
    //         if(circClr[i] != circClr[i+1]){
    //             valid++;
    //         }
    //     }
    //     for(int i = 0; i < n; i++){
    //         if(valid==k-1){
    //             count++;
    //         }
    //         if(circClr[i]!=circClr[i+1]){
    //             valid--;
    //         }
    //         if(circClr[i+k-1]!=circClr[i+k]){
    //             valid++;
    //         }
    //     }
    //     return count;
    // }

    // string mergeAlternately(string word1,string word2){
    //     string ans="";
    //     if(word1.size()>word2.size()){
    //         for(int i =0;i<word2.size(); i++){
    //             ans.push_back(word1[i]);
    //             ans.push_back(word2[i]);
    //         }
    //         ans.append(word1, word2.size(),word1.size());
    //         return ans;
    //     }else{
    //         for(int i =0;i<word1.size(); i++){
    //             ans.push_back(word1[i]);
    //             ans.push_back(word2[i]);
    //         }
    //         ans.append(word2, word1.size(),word2.size());
    //         return ans;
    //     }
    // }

    // long long countOfSubstrings(string word, int k){
    //     unordered_set<char> vowels={'a','e','i','o','u'};
    //     int left=0;
    //     unordered_set<int> vowel_set;
    //     int consonant_count=0;
    //     long long result=0;
    //     for(int right=0; right<word.length(); right++){
    //         if(vowels.count(word[right])){
    //             vowel_set.insert(word[right]);
    //         }else{
    //             consonant_count++;
    //         }
    //         while(consonant_count>k){
    //             if(vowels.count(word[left])){
    //                 vowel_set.erase(word[left]);
    //             }else{
    //                 consonant_count--;
    //             }left++;
    //         }
    //         if(vowel_set.size()==5 && consonant_count==k){
    //             result+=(left+right-1);
    //         }
    //     }
    //     return result;
    // }
    
    // int maximumCount(vector<int>& nums){
    //     int neg=0;
    //     int pos=0;
    //     for(int i=0; i < nums.size(); i++){
    //         if(nums[i]<0){
    //             neg++;
    //         }else if(nums[i]>0){
    //             pos++;
    //         }
    //     }
    //     return max(pos,neg);
    // }

    // string gcdOfStrings(string str1, string str2){
    //     if(!(str1+str2==str2+str1)){
    //         return "";
    //     }
    //     int GCDLength=gcd(str1.length(), str2.length());
    //     return str1.substr(0, GCDLength);
    // }
    // int gcd(int a, int b){
    //     if(b==0){
    //         return a;
    //     }
    //     return gcd(b,a%b);
    // }

    // vector<bool> kidsWithCandies(vector<int>& candies, int extracandies){
    //     vector<bool> result;
    //     int maxCandies=0;
    //     for(int i=0;i<candies.size();i++){
    //         maxCandies=max(maxCandies, candies[i]);
    //     }
    //     for(int i=0; i < candies.size(); i++){
    //         result.push_back(candies[i]+extracandies>maxCandies);
    //     }
    //     return result;
    // }

    //  void jaggedSwaps(){
    //     int t;
    //     cin>>t;
    //     while(t--){
    //         //input
    //         int n;
    //         cin>>n;
    //         vector<int> nums(n);
    //         for(int i = 0; i < n; i++){
    //             cin >> nums[i];
    //         }
    //         //solution
    //         if(nums[0]==1){
    //             cout<<"YES"<<endl;
    //         }else{
    //             cout<<"NO"<<endl;
    //         }
    //     }
    //  }

    // bool canPlaceFlowers(vector<int>& flowerbed, int n){
    //     for(int i = 0; i < flowerbed.size();i++){
    //         if(flowerbed[i]==0){
    //             bool isLeftEmpty= (i==0)|| flowerbed[i-1]==0;
    //             bool isRightEmpty= (i==flowerbed.size()-1) || flowerbed[i+1]==0;
    //             if(isRightEmpty&&isLeftEmpty)
    //             {
    //                 flowerbed[i]=1;
    //                 n--;
    //                 i++;
    //             }
    //         }
    //     }
    //     if(n<=0) return true;
    //     return n==0;
    // }
    
    // void doremyPaint(){
    //     int t;
    //     cin>>t;
    //     while(t--){
    //         //input
    //         int n;
    //         cin>>n;
    //         vector<int> a(n);
    //         for(int i=0;i<n;i++){
    //             cin>>a[i];
    //         }
    //         //logic
    //         map<int, int> freqMap;
    //         for(int i =0; i< n;i++){
    //             freqMap[a[i]]++;
    //         }
    //         if(freqMap.size()>3){
    //             cout<<"NO"<<"\n";
    //         }else{
    //             int freq1= freqMap.begin()->second;
    //             int freq2= freqMap.rbegin()->second;
                
    //             if(freq1==freq2){
    //                 cout<<"YES"<<"\n";
    //             }else if(n%2==1 && abs(freq2-freq1)==1){
    //                 cout<<"YES"<<"\n";
    //             }else{
    //                 cout<<"NO"<<"\n";
    //             }
    //         }

    //     }
    // }

    // bool isZeroArray(vector<int> nums){
    //     for(int i = 0; i < nums.size(); i++){
    //         if(nums[i]!=0){
    //             return false;
    //         }
    //     }
    //     return true;
    // }
    // int minZeroArray(vector<int>& nums, vector<vector<int>>& queries){
    //     if(isZeroArray(nums)){
    //         return 0;
    //     }
    //     int n=queries.size();
    //     vector<int> diff(n+1,0);
    //     for(int i =0; i< queries.size();i++){
    //         int l=queries[i][0];
    //         int r=queries[i][1];
    //         int val=queries[i][2];
    //         diff[l]-=val;
    //         if(r+1<n){
    //             diff[r+1]+=val;
    //         }
    //         int curr=0;
    //         for(int j=0;j<n;j++){
    //             curr+=diff[j];
    //             nums[j]=max(0,nums[j]+curr);
    //         }
    //         if(isZeroArray(nums)){
    //             return i+1;
    //         }
    //     }
    //     return -1;
    // }

    // string reverseVowels(string s){
    //     unordered_set<char> vowels={'a','e','i','o','u','A','E','I','O','U'};
    //     vector<int> VowelsIndex;
    //     for(int i =0;i< s.length();i++){
    //         if(vowels.count(s[i])){
    //             VowelsIndex.push_back(i);
    //         }
    //     }
    //     int left=0, right=VowelsIndex.size()-1;
    //     while(left<right){
    //         swap(s[VowelsIndex[left]],s[VowelsIndex[right]]);
    //         left++;
    //         right--;
    //     }
    //     return s;
    // }

    // string reverseWords(string s){
    //     vector<string> words;
    //     stringstream ss(s);
    //     string word,returnStr;
    //     while (getline(ss, word, ' ')) {
    //         if(!word.empty()) words.push_back(word);
    //     }

    //     for(int i =words.size()-1; i>=0; i--){
    //         returnStr+=words[i];
    //         if(i>0) returnStr+=" ";
    //     }
    //     return returnStr;
    // }

    // void extractInt(double x){
    //     double fracPart;
    //     int intPart;

    //     intPart= static_cast<int>(x);
    //     fracPart= x-intPart;

    //     cout<<"fractional part is "<<fracPart<<"\n";
    //     cout<<"integral part is "<<intPart<<"\n";
        
    // }

    // vector<int> productExceptSelf(vector<int>& nums){
    //     int n=nums.size();
    //     vector<int> result(n,1);
    //     for(int i = 0, prefix=1, sufix=1; i < n; i++){
    //         int j= n-1-i;
    //         if(i>0) prefix*=nums[i-1];
    //         if(j<n-1) sufix*=nums[j+1];
    //         result[i]*=prefix;
    //         result[j]*=sufix;
    //     }
    //     return result;
    // }

    // int compress(vector<char>& chars){
    //     int write =0,count=1;
    //     for(int i = 1; i <= chars.size(); i++){
    //         if(i<chars.size() && chars[i]==chars[i-1]){
    //             count++;
    //         }else{
    //             chars[write++]=chars[i-1];
    //             if(count>1){
    //                 for(char c: to_string(count)){
    //                     chars[write++]=c;
    //                 }
    //             }
    //             count=1;
    //         }
    //     }
    //     return write;
    // }

    // bool increasingTriplet(vector<int>& nums){
    //     int first=INT_MAX;
    //     int second=INT_MAX;
        
    //     for(int i=0;i<nums.size();i++){
    //         if(nums[i]<=first) first=nums[i];
    //         else if(nums[i]<=second) second=nums[i];
    //         else return true;
    //     }
    //     return false;
    // }

    // void moveZeroes(vector<int>& nums){
    //     int write=0;
    //     for(int num: nums){
    //         if(num!=0){
    //             nums[write++]=num;
    //         }
    //     }
    //     while(write<nums.size()){
    //         nums[write++]=0;
    //     }
    // }

//    bool isSubsequences(string s, string t){
//         int i =0,j=0;
//         while(j<t.size()){
//             if(s[i]==t[j]){
//                 i++;
//             }
//             j++;
//         }
//         if(i==s.size()) return true;
//         else return false;
//     }
    
    // int maxArea(vector<int>& height){
    //     int left=0, right= height.size()-1;
    //     int max_area=0,area;
    //     while(left<right){
    //         if(height[left]<height[right]){
    //             area=height[left]*(right-left);
    //             if(max_area<area) max_area=area;
    //             left++;
    //         }else{
    //             area=height[right]*(right-left);
    //             if(max_area<area) max_area=area;
    //             right--;
    //         }
    //     }
    //     return max_area;
    // }

    // int maxOperations(vector<int> nums, int k){
    //     std:sort(nums.begin(), nums.end());
    //     int lft=0;
    //     int ryt=nums.size()-1;
    //     int count;
    //     while(lft<ryt){
    //         if(nums[lft]+nums[ryt]==k){
    //             count++;
    //             lft++;
    //             ryt--;
    //         }else if(nums[lft]+nums[ryt]<k) lft++;
    //         else if(nums[lft]+nums[ryt]>k) ryt--;
    //     }
    //     return count;
    // }

    // double findMaxAverage(vector<int>& nums, int k){
    //     int left=0, right=0;
    //     int sum=nums[0];
    //     while(right<k){
    //         sum+=nums[right++];
    //     }
    //     int maxsum=sum;
    //     while(right<nums.size()){
    //         sum+=nums[++right];
    //         sum-=nums[left++];
    //         maxsum=max(maxsum, sum);
    //     }
    //     return maxsum;
    // }

    // int maxVowels(string s, int k){
    //     unordered_set<char> vowels ={'a','e','i','o','u'};
    //     int left=0, right=0;
    //     int vowelCount=0;
    //     while(right<k){
    //         if(vowels.count(s[right++])){
    //             vowelCount++;
    //         }
    //     }
    //     int maxVowelCount= vowelCount;
    //     while(right<s.size()){
    //         if(vowels.count(s[right])){
    //             vowelCount++;
    //         }
    //         if(vowels.count(s[left])){
    //             vowelCount--;
    //         }
    //         right++;
    //         left++;
    //         maxVowelCount=max(maxVowelCount, vowelCount);
    //     }
    //     return maxVowelCount;
    // }

    // int longestOnesBrute(vector<int>& nums, int k){
    //     int n= nums.size();
    //     int maxLength=0;
    //     for(int i =0; i< n;i++){
    //         int zero_count=0;
    //         for(int j=i;j<n;j++){
    //             if(nums[j]==0){
    //                 zero_count++;
    //             }
    //             if(zero_count<=k){
    //                 maxLength=max(maxLength, j-i+1);
    //             }else{
    //                 break;
    //             }
    //         }
    //     }
    //     return maxLength;
    // }

    // bool divideArray(vector<int>& nums){
    //     unordered_map<int, int> umap;

    //     for(int i:nums){
    //         umap[i]++;
    //     }
    //     for(const auto&p:umap){
    //         if(p.second%2!=0){
    //             return false;
    //         }
    //     }
    //     return true;
    // }

    // bool divideArray(vector<int>& nums){
    //     std::sort(nums.begin(), nums.end());
    //     for(int i =0;i<nums.size();i+=2){
    //         if(nums[i]!=nums[i+1]){
    //             return false;
    //         }
    //     }
    //     return true;
    // }

    // int longestOnes(vector<int>& nums, int k){
    //     int zero_count=0,
    //         max_length=0,
    //         left=0;
    //     for(int right=0;right<nums.size();right++){
    //         if(nums[right]==0){
    //             zero_count++;
    //         }
    //         while(zero_count>k){
    //             if(nums[left]==0){
    //                 zero_count--;
    //             }
    //             left++;
    //         }
    //         max_length=max(max_length, (right-left+1));
    //     }
    //     return max_length;
    // }

    // int longestNiceSubarray(vector<int>& nums){
    //     int left=0;
    //     long long currentAND=0;
    //     int max_length=0;
    //     for(int right =0;right<nums.size();right++){
    //         while(currentAND&nums[right]!=0){
    //             currentAND&= ~nums[left];
    //             left++;
    //         }
    //         currentAND |=nums[right];
    //         max_length=max(max_length, (right-left+1));
    //     }
    //     return max_length;
    // }

    // int longestSubarray(vector<int>& nums){
    //     int left = 0;
    //     int zeroCount = 0;
    //     int maxCount = 0;

    //     for(int right=0; right<nums.size();i++){
    //         if(nums[right]==0){
    //             zeroCount++;
    //         }
    //         while(zeroCount>1){
    //             if(nums[left]==0){
    //                 zeroCount--;
    //             }
    //             left++;
    //         }
    //         maxCount=max(maxCount, right-left+1);
    //     }
    //     return maxCount;
    // }

    // int largestAltitude(vector<int>& gains){
    //     for(int i =1 ;i<gains.size()-1;i++){
    //         gains[i]+=gains[i-1];
    //     }
    //     int maxAlt=INT_MIN;
    //     for(int i=0;i<gains.size();i++){
    //         maxAlt=max(gains[i], maxAlt);
    //     }
    //     return maxAlt;
    // }

    // int pivotIndex(vector<int>& nums){
    //     int totalSum=0;
    //     int leftSum=0;

    //     for(int n:nums){
    //         totalSum+=n;
    //     }
    //     for(int i =0;i<nums.size();i++){
    //         int rightSum= totalSum-leftSum-nums[i];
    //         if(leftSum==rightSum){
    //             return i;
    //         }
    //         leftSum+=nums[i];
    //     }
    //     return -1;
    // }
    
    // vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2){
    //     sort(nums1.begin(), nums1.end());
    //     sort(nums2.begin(), nums2.end());

    //     vector<int> diff1, diff2;
    //     int i =0,j=0;

    //     while(i<nums1.size()&&j<nums2.size()){
    //         while(i>0 &&i<nums1.size() && nums1[i]==nums1[i-1]) i++;
    //         while(j>0 &&j<nums2.size() && nums2[j]==nums2[j-1]) j++;

    //         if(i<nums1.size() && (j==nums2.size() || nums1[i]<nums2[j])){
    //             diff1.push_back(nums1[i]);
    //             i++;
    //         }
    //         else if(j<nums2.size() && (i==nums1.size() || nums1[i]>nums2[j])){
    //             diff2.push_back(nums2[i]);
    //             j++;
    //         }else{
    //             i++;
    //             j++;
    //         }
    //     }
    //     while(i<nums1.size()){
    //         if (i == 0 || nums1[i] != nums1[i - 1]) diff1.push_back(nums1[i]);
    //         i++;
    //     }
    //     while(j<nums2.size()){
    //         if (j == 0 || nums1[j] != nums1[j - 1]) diff2.push_back(nums2[j]);
    //         j++;
    //     }
    //     return {diff1,diff2};        
    // }

    // vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2){
    //     unordered_set<int> set1(nums1.begin(), nums1.end());
    //     unordered_set<int> set2(nums2.begin(), nums2.end());

    //     vector<int> diff1, diff2;

    //     for(int num: set1){
    //         if(set2.find(num)==set2.end()){
    //             diff1.push_back(num);
    //         }
    //     }
    //     for(int num: set2){
    //         if(set1.find(num)==set1.end()){
    //             diff2.push_back(num);
    //         }
    //     }
    //     return {diff1,diff2};
    // }

    // bool uniqueOccuracne(vector<int>& arr){
    //     unordered_map<int, int> map;
    //     for(int num:arr){
    //         map[num]++;
    //     }
    //     unordered_set<int> seen;

    //     for(auto& [num, count]: map){
    //         if(seen.find(count)!=seen.end()){
    //             return false;
    //         }
    //         seen.insert(count);
    //     }
    //     return true;
    // }

    // bool closeString(string word1, string word2){
    //     if(word1.length()!= word2.length()){
    //         return false;
    //     }
    //     map<char, int> charMap1, charMap2;
    //     for(char c: word1){
    //         charMap1[c]++;
    //     }
    //     for(char c: word2){
    //         charMap2[c]++;
    //     }
    //     if(charMap1!=charMap2){
    //         return false;
    //     }
    //     vector<int> freq1, freq2;
    //     for(auto it: charMap1){
    //         freq1.push_back(it.second);
    //     }
    //     for(auto it: charMap2){
    //         freq2.push_back(it.second);
    //     }
    //     sort(freq1.begin(), freq1.end());
    //     sort(freq2.begin(), freq2.end());
        
    //     if(freq1!= freq2){
    //         return false;
    //     }

    //     return true;
    // }

    // int equalPairs(vector<vector<int>>& grid){
    //     int n = grid.size();
    //     map<vector<int>, int> rowMap;
    //     int count=0;

    //     for(int i = 0; i<n;i++){
    //         rowMap[grid[i]]++;
    //     }

    //     for(int j=0;j<n;j++){
    //         vector<int> col;
    //         for(int i=0;i<n;i++){
    //             col.push_back(grid[i][i]);
    //         }
    //         if(rowMap.find(col)!= rowMap.end()){
    //             count+=rowMap[col];
    //         }
    //     }
    //     return count;
    // }

    // int sumOfGoodNumbers(vector<int>& nums, int k){
    //     int totalsum=0;
        
    //     for(int i =0;i<nums.size();i++){
    //         int right, left;
    //         if(i-k<0){
    //             right = nums[i-k];
    //         }else right=INT_MIN;
    //         if(i+k>nums.size()){
    //             left=nums[i+k];
    //         }else left= INT_MIN;

    //         if(nums[i]>right&& nums[i]>left){
    //             totalsum+=nums[i];
    //         }
    //     }
    // }

    // int guessNumber(int n){
    //     int low=0, high=n;
    //     while(low<=high){
    //         int middle=low+(high-low)/2;
    //         int res=guess(middle);
    //         if(res==0){
    //             return middle;
    //         }else if(res==-1){
    //             high = middle-1;
    //         }else{
    //             low = middle+1;;
    //         }
    //     }
    //     return -1;
    // }

    // string removeStars(string s){
    //     stack<char> charStack;
    //     string result;
    //     for(char c: s){
    //         if(c!='*'){
    //             charStack.push(c);
    //         }else if(c=='*'){
    //             charStack.pop();
    //         }
    //     }
    //     while(!charStack.empty()){
    //         result+=charStack.top();
    //         charStack.pop();
    //     }
    //     reverse(result.begin(), result.end());
    //     return result;
    // }

    // vector<int> astriodCollision(vector<int>& astroids){
    //     stack<int> st;
    //     for(int astroid: astroids){
    //         bool destroyed = false;
    //         while(!st.empty() && astroid<0 && st.top()>0){
    //             if(abs(astroid)>st.top()){
    //                 st.pop();
    //                 continue;
    //             }else if(abs(astroid)==st.top()){
    //                 st.pop();
    //             }
    //             destroyed=true;
    //             break;
    //         }
    //         if(!destroyed){
    //             st.push(astroid);
    //         }
    //     }
    //     vector<int> result(st.size());
    //     for(int i =st.size()-1;i>0;i++){
    //         result[i]=st.top();
    //         st.pop();
    //     }
    //     return result;
    // }

    // string decodeString(string s){
    //     stack<int> numStack;
    //     stack<string> strStack;
    //     string currString = "";
    //     int num = 0;
    //     for(char c : s){
    //         if(isdigit(c)){
    //             //Build the repeat number
    //             num = num * 10 + (c - '0');
    //         }else if(c=='['){
    //             //Push the  current state onto stacks
    //             numStack.push(num);
    //             strStack.push(currString);
    //             //Reset the stack
    //             num = 0;
    //             currString = "";
    //         }else if(c==']'){
    //             //code to execute if character is ']'
    //             int repeatCount = numStack.top(); numStack.pop();
    //             string lastString = strStack.top(); strStack.pop();
    //             for(int i =0; i<repeatCount;i++){
    //                 lastString+=currString;
    //             }
    //             currString=lastString;
    //         }else{
    //             //code to execute if anything else is encountered like normal characters
    //             currString+=c;
    //         }
    //     }
    //     return currString;
    // }
    // string decodeString(string s){
    //     stack<int> numsStack;
    //     stack<string> strStack;
    //     int num = 0;
    //     string currString = "";
    //     for(char c : s){
    //         if(isdigit(c)){
    //             num= num*10+(c-'0');
    //         }else if(c=='['){
    //             numsStack.push(num);
    //             strStack.push(currString);
    //             num=0;
    //             currString="";
    //         }else if(c==']'){
    //             int repeatCount= numsStack.top(); numsStack.pop();
    //             string repeatString= strStack.top(); strStack.pop();
    //             for(int i=0;i<repeatCount;i++){
    //                 repeatString+=currString;
    //             }
    //             currString=repeatString;
    //         }
    //     }
    //     return currString;
    // }

    // ListNode* deleteMiddle(ListNode* head){
    //     if(head == nullptr || head->next == nullptr) return nullptr;

    //     ListNode* fast=head;
    //     ListNode* slow=head;

    //     while(fast->next!=nullptr && fast->next->next != nullptr){
    //         slow=slow->next;
    //         fast=fast->next->next;
    //     }
    //     if(slow->next!=nullptr){
    //         ListNode* temp =slow->next;
    //         slow->next=temp->next;
    //         delete temp;
    //     }
    //     return head;
    // }

    // ListNode* oddEvenList(ListNode* head){
    //     if(head==nullptr || head->next==nullptr) return nullptr;
    //     ListNode* odd=head;
    //     ListNode* even =head->next;
    //     ListNode* evenHead= even;

    //     while(even && even->next){
    //         odd->next=even->next;
    //         odd=odd->next;

    //         even->next=odd->next;
    //         even=even->next;
    //     }
    //     odd->next=evenHead;
    //     return head;
    // }

    // 

    // int reverseDegree(string s){
    //     int sum=0;
    //     for(int i =0;i<s.size();i++){
    //         //position in the stri
    //         int posStr=i+1;
    //         int posAlph= 26-(s[i]-'a');
    //         int prod=posStr*posAlph;
    //         sum+=prod;
    //     }
    //     return sum;
    // }
    // void printLinkedList(ListNode* head) {
    //     ListNode* current = head;
    //     while (current) {
    //         std::cout << current->val << " -> ";
    //         current = current->next;
    //     }
    //     std::cout << "nullptr" << std::endl;
    // }

    // int pairSum(ListNode* head){
    //     ListNode* fast=head;
    //     ListNode* slow=head;
    //     while(fast!=nullptr && fast->next!=nullptr){
    //         fast=fast->next->next;
    //         slow=slow->next;
    //     }
    //     ListNode* reverseMidHead=reverseList(slow);
        
    //     int maxPairSum=INT_MIN;

    //     while(reverseMidHead != nullptr){
    //         int currSum=head->val+reverseMidHead->val;
    //         head=head->next;
    //         reverseMidHead=reverseMidHead->next;
    //         maxPairSum=currSum>maxPairSum? currSum:maxPairSum;
    //     }
    //     return maxPairSum;
    // }

    // vector<int> countBits(int n){
        
    // }

    // vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,int success){
    //     vector<int> result(spells.size());
    //     sort(potions.begin(), potions.end());
    //     for(int i=0;i<spells.size();i++){
    //         int target=(success + spells[i] - 1) / spells[i];
    //         int left =0;
    //         int right =potions.size()-1;
    //         while(left<=right){
    //             int mid=left+ (right-left)/2;
    //             if(potions[mid]>=target){
    //                 right = mid - 1;
    //             }else left = mid + 1;
    //         }
    //         result[i] = potions.size()- left;
    //     }
    //     return result;
    // }

    // int findPeakElement(vector<int>& nums){
    //     int left=0, right=nums.size()-1;
    //     while(left<right){
    //         int mid=left+ (right-left)/2;
    //         if(nums[mid]>nums[mid+1]){
    //             right=mid;
    //         }else{
    //             left=mid+1;
    //         }
    //     }
    //     return left;
    // }

    // int minEatingSpeed(vector<int>& piles, int h){
    //     int left=1;
    //     int right= *max_element(piles.begin(), piles.end());
    //     int minSpeed= *max_element(piles.begin(), piles.end());
    //     while(left<right){
    //         int mid= left+ (right-left)/2;
    //         int hours_needed=0;
    //         for(int i =0;i<piles.size();i++){
    //             hours_needed+= ceil(double(piles[i])/mid);
    //         }
    //         if(hours_needed<=h){
    //             right=mid;
    //         }else{
    //             left=mid+1;
    //         }
    //     }
    //     return left;
    // }

    // long long maximumTripletValue(vector<int> nums){
    //     int n= nums.size();
    //     if(n<3) return 0;
    //     vector<int> prefixMax(n);
    //     vector<int> SuffixMax(n);
    //     prefixMax[0]=nums[0];
    //     for(int i =1; i<n;i++){
    //         prefixMax[i]=max(prefixMax[i-1],nums[i]);
    //     }
    //     SuffixMax[n-1]=nums[n-1];
    //     for(int i = n-2;i>=0;i--){
    //         SuffixMax[i]=max(SuffixMax[i+1], nums[i]);
    //     }
    //     int maxVal=0;
    //     for(int i=1; i<nums.size()-1;i++){
    //         int maxBefore=prefixMax[i-1];
    //         int maxAfter=SuffixMax[i+1];
    //         int tripletValue= 1LL * (maxBefore-nums[i])*maxAfter;
    //         maxVal=max(maxVal, tripletValue);
    //     }
    //     return maxVal;
    // }

    // double findMedianOfSortedArrays(vector<int> nums1, vector<int> nums2){
    //     int i =0,j=0;
    //     vector<int> merged;
    //     while(i<nums1.size() && j<nums2.size()){
    //         if(nums1[i]<nums2[j]){
    //             merged.push_back(nums1[i++]);
    //         }else{
    //             merged.push_back(nums2[j++]);
    //         }
    //     }
    //     while(i<nums1.size()) merged.push_back(nums1[i++]);
    //     while(j<nums2.size()) merged.push_back(nums2[j++]);
    //     if(merged.size()%2!=0){
    //         return merged[(int)merged.size()/2];
    //     }else{
    //         int median= (merged[floor(merged.size()/2)]+merged[(int)merged.size()/2])/2;
    //         return median;
    //     }
    // }

    // int reverse(int x){
    //     long long rev;
    //     while(x!=0){
    //         rev= rev*10+x%10;
    //         x/=10;
    //     }
    //     if(rev>INT_MAX|| rev<INT_MIN) return 0;
    //     else return rev;
    // }

    // void setZeroes(vector<vector<int>>& matrix){
    //     unordered_set<int> rows;
    //     unordered_set<int> cols;
    //     for(int i=0;i<matrix.size();i++){
    //         for(int j=0;j<matrix[0].size();j++){
    //             if(matrix[i][j]==0){
    //                 rows.insert(i);
    //                 cols.insert(j);
    //             }
    //         }
    //     }
    // }

    // bool isValid(string s){
    //     stack<char> st;
    //     for(char c:s){
    //         if(c=='(' ||c=='{' ||c=='['){
    //             st.push(c);
    //         }else{
    //             if(st.empty()) return false;
    //             if(c==')' && st.top()=='('){
    //                 st.pop();
    //             }else if(c=='}' && st.top()=='{'){
    //                 st.pop();
    //             } else if(c==']' && st.top()=='['){
    //                 st.pop();
    //             }
    //             else{
    //                 return false;
    //             }
    //         }
    //     }
    //     if(st.empty()) return true;
    //     else return false;
    // }

    // vector<int> largestDivisibleSubset(vector<int>& nums){
        
    // }

    
};

int main(){
    Solution solution;
    // int weight;
    // cin >> weight;
    // if(weight>2 && solution.WaterMelon(weight)){
    //     cout<<"Yes";
    // }else{
    //     cout<<"No";
    // }
    // solution.HalloumiBoxes();
    // solution.lineTrip();
    // solution.CoverInWater();
    // solution.gameWithIntegers();
    // solution.jaggedSwaps();
    // solution.doremyPaint();
    // solution.extractInt(5.6);
    // cout<<solution.maxVowels("abciiidef", 3)<<endl;
    // solution.doremyPaint();
    // int arr[] = {7,57,13,31,17,65,32,3,97,22,7,20,69,35,69,75,13,33,50,80,64,71,15,28,2,27,39,48,13,22,84,5,51,46,26,78,56,63};
    // int size = sizeof(arr) / sizeof(arr[0]);
    // ListNode* head = createLinkedList(arr, size);
    // cout<<solution.pairSum(head);

    return 0;
    
};


