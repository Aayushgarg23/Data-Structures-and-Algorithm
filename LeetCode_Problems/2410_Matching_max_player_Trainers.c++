#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int i = 0; // pointer for players
        int j = 0; // pointer for trainers
        int count = 0;

        while (i < players.size() && j < trainers.size()) {
            if (players[i] <= trainers[j]) {
                count++;  // match found
                i++;
                j++;
          } else {
                j++;  // try next trainer
         }
    }

    return count;
    }
};


int main()
{
vector<int> player = {2,1};
vector<int> trainer = {5,4};
Solution sol;
cout << sol.matchPlayersAndTrainers(player, trainer);
}