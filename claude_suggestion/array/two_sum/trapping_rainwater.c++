


//brute force approach
// Time Complexity: O(n^2)
// Space Complexity: O(1)

class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();
        int water = 0;

        for(int i=0;i<n;i++)
        {
            int leftMax = 0;
            int rightMax = 0;

            // Find tallest on left
            for(int j=0;j<=i;j++)
                leftMax = max(leftMax,height[j]);

            // Find tallest on right
            for(int j=i;j<n;j++)
                rightMax = max(rightMax,height[j]);

            water += min(leftMax,rightMax)-height[i];
        }

        return water;
    }
};



//better approach using prefix and suffix arrays
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();

        vector<int> prefix(n);
        vector<int> suffix(n);

        prefix[0]=height[0];

        for(int i=1;i<n;i++)
            prefix[i]=max(prefix[i-1],height[i]);

        suffix[n-1]=height[n-1];

        for(int i=n-2;i>=0;i--)
            suffix[i]=max(suffix[i+1],height[i]);

        int water=0;

        for(int i=0;i<n;i++)
        {
            water+=min(prefix[i],suffix[i])-height[i];
        }

        return water;
    }
};



// optimal:  but instead of using the prefix and suffix arrays we can use two pointers to reduce the space complexity to O(1)
// Time Complexity: O(n)
// Space Complexity: O(1)


class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n-1;
        int leftMax = 0;
        int rightMax = 0;
        int water = 0;

        while(left<=right)
        {
            if(height[left]<=height[right])
            {
                if(height[left]>=leftMax)
                    leftMax = height[left];
                else
                    water += leftMax-height[left];
                left++;
            }
            else
            {
                if(height[right]>=rightMax)
                    rightMax = height[right];
                else
                    water += rightMax-height[right];
                right--;
            }
        }

        return water;
    }
};

