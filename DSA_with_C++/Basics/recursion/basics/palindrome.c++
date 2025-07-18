class Solution {
public:
    bool isPalindrome(string s) {
        // Step 1: Clean the string
        string cleaned = "";
        for (char c : s) {
            if (isalnum(c)) {
                cleaned += tolower(c);
            }
        }

        // Step 2: Check palindrome recursively
        return isPalindromeRecursive(cleaned, 0, cleaned.length() - 1);
    }

private:
    bool isPalindromeRecursive(const string& str, int left, int right) {
        if (left >= right) return true;  // Base case
        if (str[left] != str[right]) return false;
        return isPalindromeRecursive(str, left + 1, right - 1);  // Recursive step
    }
};
