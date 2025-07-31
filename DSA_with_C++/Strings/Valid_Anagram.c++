//Time: O(n log n)
//Space: O(1)


/*
bool isAnagram(string s, string t) {
    if (s.length() != t.length()) return false;

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    return s == t;
}
*/


// Method-1

// Time: O(n)
//Space: O(1) (only 26 letters)

/* if the char are out of the range a-z then use the unordered map and then map the char according to thier frequency and
then chechk but in that space complexity will be O(K) where k is no. of unique char stroed in map */

bool isAnagram(string s, string t) {
    if (s.length() != t.length()) return false;

    int count[26] = {0};

    for (char c : s) count[c - 'a']++;
    for (char c : t) count[c - 'a']--;

    for (int i = 0; i < 26; i++)
        if (count[i] != 0) return false;

    return true;
}
