#include <bits/stdc++.h>
using namespace std;

int maximumProfit(vector<vector<int>> &cost, vector<vector<int>> &dp, int n, int m){
    if (m == 0 or n == 0){
        dp[n][m] = 0;
        return 0;
    }
    if (dp[n][m] != -1){
        return dp[n][m];
    }
    int maxProfit = 0;
    for (int i = 1; i <= n / 2; i++){
        int m1 = maximumProfit(cost,dp,i,m);
        int m2 = maximumProfit(cost,dp,n - i,m);
        maxProfit = max(maxProfit, m1 + m2);
    }
    for (int i = 1; i <= m / 2; i++){
        int m1 = maximumProfit(cost,dp,n,i);
        int m2 = maximumProfit(cost,dp,n,m - i);
        maxProfit = max(maxProfit, m1 + m2);
    }
    maxProfit = max(maxProfit, cost[n][m]);
    dp[n][m] = maxProfit;
    return dp[n][m];
}

int calculateProfit(int n, int m, vector<vector<int>> &cost){
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    int max_prof = maximumProfit(cost,dp,n,m);
    return max_prof;
}

int main() {
    int m, n;
    cin >> n >> m;
    vector<vector<int>> cost(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> cost[i][j];
        }
    }
    int profit = calculateProfit(n, m, cost);
    cout << profit << endl;
    return 0;
}