#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<vector<string>> orders = {{"David", "3", "Ceviche"},
                                     {"Corina", "10", "Beef Burrito"},
                                     {"David", "3", "Fried Chicken"},
                                     {"Carla", "5", "Water"},
                                     {"Carla", "5", "Ceviche"},
                                     {"Rous", "3", "Ceviche"}};
    set<string> food_items;
    set<string> table_numbers;

    for (int i = 0; i < orders.size(); i++)
    {
        food_items.insert(orders[i][2]);
        table_numbers.insert(orders[i][1]);
    }

    sort(food_items.begin(), food_items.end());
    sort(table_numbers.begin(), table_numbers.end());

    vector<vector<string>> display_table;
}