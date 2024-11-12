#include <iostream>
#include <vector>
using namespace std;

pair<int, vector<int>> knapsack_01(int n, vector<int>& values, vector<int>& weights, int W) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    
    vector<int> selected_items;
    int i = n, w = W;

    while (i > 0 && w > 0) {
        if (dp[i][w] != dp[i - 1][w]) {
            selected_items.push_back(i - 1);
            w -= weights[i - 1];
        }
        i--;
    }

    return {dp[n][W], selected_items};
}

int main() {
    int n, W;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<int> values(n), weights(n);
    cout << "Enter the maximum weight of the knapsack: ";
    cin >> W;

    cout << "Enter the values and weights for each item (value weight):\n";
    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << ": ";
        cin >> values[i] >> weights[i];
    }

    auto result = knapsack_01(n, values, weights, W);
    int max_value = result.first;
    vector<int> selected_items = result.second;

    cout << "Maximum value: " << max_value << endl;
    cout << "Selected items: ";
    for (int item : selected_items) {
        cout << item << " "; // Displaying the index of selected items
    }
    cout << endl;

    return 0;
}
