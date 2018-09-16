/// Source : https://leetcode.com/problems/sum-of-subarray-minimums/description/
/// Author : liuyubobobo
/// Time   : 2018-09-16

#include <iostream>
#include <vector>

using namespace std;


/// Two Stacks
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {

private:
    long long mod = 1e9 + 7;

public:
    int sumSubarrayMins(vector<int>& A) {

        int n = A.size();

        vector<int> s;
        long long repeat = 0;

        vector<int> rSmaller(n, n);
        for(int i = 0; i < n ; i ++){
            if(s.empty() || A[i] > A[s.back()])
                s.push_back(i);
            else{
                while(!s.empty() && A[s.back()] >= A[i]){
                    rSmaller[s.back()] = i;
                    s.pop_back();
                }
                s.push_back(i);
            }
        }
//        Solution::print_vec(rSmaller);

        s.clear();
        vector<int> lSmaller(n, -1);
        int r = n - 1;
        for(int i = n - 1; i >= 0; i --){
            if(s.empty() || A[i] > A[s.back()])
                s.push_back(i);
            else{
                while(!s.empty() && A[s.back()] > A[i]){
                    lSmaller[s.back()] = i;
                    s.pop_back();
                }
                s.push_back(i);
            }
        }
//        Solution::print_vec(lSmaller);

        long long res = 0;
        for(int i = 0; i < n; i ++){
            res = res + (long long)(rSmaller[i] - i) * (long long)(i - lSmaller[i]) % mod * (long long)A[i] % mod;
            res %= mod;
        }

        return res % mod;
    }

    static void print_vec(const vector<int>& vec){
        for(int e: vec)
            cout << e << " ";
        cout << endl;
    }
};


int main() {

    vector<int> nums1 = {3,1,2,4};
    cout << Solution().sumSubarrayMins(nums1) << endl;
    // 17

    vector<int> nums2 = {48, 87, 27};
    cout << Solution().sumSubarrayMins(nums2) << endl;
    // 264

    vector<int> nums3 = {71, 55, 82, 55};
    cout << Solution().sumSubarrayMins(nums3) << endl;
    // 593

    vector<int> nums4 = {19, 19, 62, 66};
    cout << Solution().sumSubarrayMins(nums4) << endl;
    // 323

    return 0;
}