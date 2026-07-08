//https://leetcode.com/problems/container-with-most-water/

#include<bits/stdc++.h>
using namespace std;

// bruteforce solution
// time complexity = O(n^2)
// space complexity = O(1)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans =0;
        int n= height.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int width = j-i;

                ans = max(ans,width*(min(height[i],height[j])));
            }
        }
        return ans;
    }
};

//optimal solution
// time complexity = O(n)
// space complexity = O(1)

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0;
        int r= height.size()-1;
        int ans =0;

        while(l<r)
        {
            int width =r-l;

            ans = max(ans,width*(min(height[l],height[r])));

            if(height[l]<height[r])l++;
            else r--;
        }
        return ans;
    }
};



