class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum = 0;
        int maxi = 0;

        for (int a : nums) {
            maxi = max(maxi, a);
            sum = sum + a;
        }

        return maxi * (int)nums.size() - sum;
    }
};
