#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int value;
    int weight;

    Item(int v, int w) : value(v), weight(w) {}
};

// Comparator function to sort items by value-to-weight ratio in descending order
bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

// Function to calculate the maximum value in the knapsack
double fractionalKnapsack(int capacity, vector<Item>& items) {
    sort(items.begin(), items.end(), compare);

    double maxValue = 0.0;

    for ( auto item : items) {
        if (capacity >= item.weight) {
            // Take the whole item
            capacity -= item.weight;
            maxValue += item.value;
        } else {
            // Take the fraction of the item that fits
            maxValue += item.value * ((double)capacity / item.weight);
            break;
        }
    }

    return maxValue;
}

int main() {
    int capacity = 50; // Capacity of the knapsack
    vector<Item> items = { {30, 30}, {50, 10}, {60, 25} };

    cout << "Maximum value in Knapsack = " << fractionalKnapsack(capacity, items) << endl;
    return 0;
}
