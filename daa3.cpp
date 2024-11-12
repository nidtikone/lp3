#include <iostream>
#include <algorithm> // Include this for 'sort'
#include <chrono>
#include <iomanip>
#include <vector>    // Include for std::vector

using namespace std;

struct Item {
    int value;
    int weight;
};

class Solution {
public:
    static bool comp(Item a, Item b) {
        double r1 = static_cast<double>(a.value) / static_cast<double>(a.weight);
        double r2 = static_cast<double>(b.value) / static_cast<double>(b.weight);
        return r1 > r2; // Sort in descending order
    }

    double fractionalKnapsack(int W, vector<Item>& arr) {
        sort(arr.begin(), arr.end(), comp); // Sort items by value-to-weight ratio
        int curWeight = 0;
        double finalValue = 0.0;

        for (int i = 0; i < arr.size(); i++) {
            if (curWeight + arr[i].weight <= W) {
                curWeight += arr[i].weight;
                finalValue += arr[i].value;
            } else {
                int remain = W - curWeight; // Remaining weight capacity
                finalValue += (arr[i].value / static_cast<double>(arr[i].weight)) * static_cast<double>(remain);
                break; // Knapsack is full
            }
        }
        return finalValue;
    }
};

int main() {
    int n, weight; // Number of items and maximum weight of knapsack
    cout << "Enter the number of items: ";
    cin >> n;

    cout << "Enter the maximum weight of the knapsack: ";
    cin >> weight;

    vector<Item> arr(n); // Dynamic array of items
    for (int i = 0; i < n; i++) {
        cout << "Enter value and weight for item " << i + 1 << ": ";
        cin >> arr[i].value >> arr[i].weight;
    }

    Solution obj;

    auto start_time = chrono::high_resolution_clock::now(); // Start time
    double ans = obj.fractionalKnapsack(weight, arr); // Calculate maximum value
    auto end_time = chrono::high_resolution_clock::now(); // End time
    auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time); // Calculate duration

    cout << "The maximum value is " << fixed << setprecision(2) << ans << endl; // Display result
    cout << "Elapsed Time: " << duration.count() << " microseconds" << endl; // Display elapsed time

    return 0;
}
