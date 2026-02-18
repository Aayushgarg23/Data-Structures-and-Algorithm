#include<bits/stdc++.h>
using namespace std;


// time complexity: O(N*M*26) -> N is the number of words in the word list, M is the length of each word, and 26 represents the number of possible character substitutions for each position in the word.
// space complexity: O(N) -> The queue can hold at most N words in the worst
// case, and the unordered_set also takes O(N) space to store the words from the word list.
// approach: We can use a breadth-first search (BFS) approach to solve this problem


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());

        if(st.find(endWord)==st.end())return 0;

        queue<string>q;

        q.push(beginWord);
        int ans =1;

        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                string front = q.front();
                if(front==endWord)return ans;
                q.pop();

                for(int i=0;i<front.length();i++)
                {
                    char real = front[i];

                    for(char j='a';j<='z';j++)
                    {
                        front[i] = j;
                        
                        if(st.find(front)!=st.end())
                        {
                            q.push(front);
                            st.erase(front);
                        }
                    }
                    front[i] = real;

                }
                
            }
            ans++;
        }
        return 0;
    }
};