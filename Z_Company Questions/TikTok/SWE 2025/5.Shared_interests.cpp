#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <algorithm>
using namespace std;

int maxShared(int friends_nodes, vector<int> &friends_from, vector<int> &friends_to, vector<int> &friends_weight)
{
    // Step 1: Create a map to store shared interests for each node pair
    map<pair<int, int>, unordered_set<int>> interest_map;

    int friends_edges = friends_from.size();

    // Step 2: Populate the map with interests shared between each node pair
    for (int i = 0; i < friends_edges; i++)
    {
        int from = friends_from[i];
        int to = friends_to[i];
        int interest = friends_weight[i];

        // Ensure the pair is always in sorted order (smaller node first)
        // Not necessary
        // if (from > to) swap(from, to);

        // Add the interest to the set of interests for this pair
        interest_map[{from, to}].insert(interest);
    }

    // Step 3: Find the maximum number of shared interests
    int max_shared_interests = 0;
    for (const auto &pair : interest_map)
    {
        max_shared_interests = max(max_shared_interests, (int)pair.second.size());
    }

    // Step 4: Calculate the maximal product for node pairs with the maximum shared interests
    // You done need DFS to find the path and then calculate the which node is connected to which node inorder to find the (node1*node2)
    int max_product = 0;
    for (const auto &pair : interest_map)
    {
        if (pair.second.size() == max_shared_interests)
        {
            int node1 = pair.first.first;
            int node2 = pair.first.second;
            max_product = max(max_product, node1 * node2);
        }
    }

    return max_product;
}

int main()
{
    int friends_nodes = 4;
    int friends_edges = 5;

    vector<int> friends_from = {1, 1, 2, 2, 2};
    vector<int> friends_to = {2, 2, 3, 3, 4};
    vector<int> friends_weight = {2, 3, 1, 3, 4};

    int result = maxShared(friends_nodes, friends_from, friends_to, friends_weight);

    cout << "Maximal Product: " << result << endl;

    return 0;
}
