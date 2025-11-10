#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;
    vector<int> weight(n), value(n);
    cout << "Enter weights of items:\n";
    for (int i = 0; i < n; i++)
        cin >> weight[i];
    cout << "Enter values of items:\n";
    for (int i = 0; i < n; i++)
        cin >> value[i];
    cout << "Enter maximum capacity of knapsack: ";
    cin >> W;
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (weight[i - 1] <= w) {
                dp[i][w] = max(
                    value[i - 1] + dp[i - 1][w - weight[i - 1]],
                    dp[i - 1][w]
                );
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    cout << "\nMaximum profit: " << dp[n][W] << endl;
    cout << "Items included (1-based indices): ";
    int w = W;
    for (int i = n; i > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            cout << i << " ";
            w -= weight[i - 1];
        }
    }
    cout << endl;

    return 0;
}
