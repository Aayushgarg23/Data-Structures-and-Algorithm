class Solution {
public:
    vector<int> getFloorAndCeil(vector<int> nums, int x) {
  int s = 0;
        int e = nums.size() - 1;
        int floor = -1;
        int ceil = -1;

        while (s <= e) {
            int mid = (s + e) / 2;

            if (nums[mid] == x) {
                floor = ceil = nums[mid];
                break;
            }
            else if (nums[mid] < x) {
                floor = nums[mid];  // potential floor
                s = mid + 1;
            }
            else {
                ceil = nums[mid];   // potential ceil
                e = mid - 1;
            }
        }

        return {floor, ceil};
    }
};