class Solution {
public:
    int solve(vector<vector<int>>& triangle, int idx, int idx2,
              vector<vector<int>>& dp) {
        if(idx == triangle.size() - 1)
            return triangle[idx][idx2];
        if(dp[idx][idx2] != 1e9)
            return dp[idx][idx2];

        int take = triangle[idx][idx2]
                 + solve(triangle, idx + 1, idx2, dp);

        int takeahead = triangle[idx][idx2]
                      + solve(triangle, idx + 1, idx2 + 1, dp);

        return dp[idx][idx2] = min(take, takeahead);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<vector<int>> dp(n, vector<int>(n, 1e9));

        return solve(triangle, 0, 0, dp);
    }
};