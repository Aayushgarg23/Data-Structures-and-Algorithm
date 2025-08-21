/* USing the brute force can be done
time: O(N^2)
space:O(1) [I use a set to identify unique no. but the size of set at max will be 3 so log3~1 
so taking complexity O(1)]
*/


/* Optimised method by using: Sliding Window (Two Pointer) with HashMap
Time Complexity: O(2N)
Space Complexity: O(3) (since max 3 fruit types at once)
*/

/*
 int totalFruits(vector<int>& fruits) {
        int n = fruits.size();
        int l = 0, r = 0;
        int maxLen = 0;
        unordered_map<int,int> temp;

        while (r < n) {
            temp[fruits[r]]++;

            // shrink window if more than 2 fruit types
            while (temp.size() > 2) {
                temp[fruits[l]]--;
                if (temp[fruits[l]] == 0) {
                    temp.erase(fruits[l]);
                }
                l++;
            }

            maxLen = max(maxLen, r - l + 1);
            r++;
        }
        return maxLen;
*/


//most optimised one
// using the sliding window(two pointers) with hashmaps
// time: O(N)
// space: O(3)
 int totalFruits(vector<int>& fruits) {
        int n = fruits.size();
        int l = 0, r = 0;
        int maxLen = 0;
        unordered_map<int,int> temp;

        while (r < n) {
            temp[fruits[r]]++;

            // shrink window if more than 2 fruit types
            if (temp.size() > 2) {
                temp[fruits[l]]--;
                if (temp[fruits[l]] == 0) {
                    temp.erase(fruits[l]);
                }
                l++;
            }

            if(temp.size()<=2)maxLen = max(maxLen, r - l + 1);
            r++;
        }
    }
        return maxLen;