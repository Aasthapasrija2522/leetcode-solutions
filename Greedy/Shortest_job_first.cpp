class Solution {
public:
    long long solve(vector<int>& bt) {

        sort(bt.begin(), bt.end());

        long long waiting = 0;
        long long totalWaiting = 0;

        for (int i = 0; i < bt.size(); i++) {
            totalWaiting += waiting;
            waiting += bt[i];
        }

        return totalWaiting / bt.size();
    }
};