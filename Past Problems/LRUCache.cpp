#include <bits/stdc++.h>

using namespace std;

class LRUCache
{
private:
    struct Data
    {
        int value;
        int age;
    };
    unordered_map<int, Data> cache;
    int max_size;
    int count = 0;

    // int minAge(unordered_map<int, Data> map)
    // {
    //     pair<int, Data> entry_with_min_age = make_pair(INT_MAX, Data{INT_MAX, INT_MAX});

    //     unordered_map<int, Data>::iterator current_entry;

    //     for (current_entry = map.begin(); current_entry != map.end(); ++current_entry)
    //     {
    //         if (current_entry->second.age < entry_with_min_age.second.age)
    //         {
    //             entry_with_min_age = make_pair(current_entry->first, current_entry->second);
    //         }
    //     }

    //     return entry_with_min_age.first;
    // }

public:
    LRUCache(int capacity)
    {
        cache.reserve(capacity);
        max_size = capacity;
    }

    int get(int key)
    {
        if (cache.find(key) == cache.end())
            return -1;
        count++;
        cache[key].age = count;
        return cache[key].value;
    }

    void put(int key, int value)
    {
        if (cache.count(key) != 0)
        {
            auto it = cache.find(key);
            count++;
            it->second.value = value;
            it->second.age = count;
            return;
        }
        if (cache.size() == max_size)
        {
            // int lru_key = minAge(cache);
            auto lru_key = min_element(cache.begin(), cache.end(),
                                       [](const auto &l, const auto &r) { return l.second.age < r.second.age; });
            cache.erase(lru_key);
            count++;
            Data data;
            data.value = value;
            data.age = count;
            cache.insert(make_pair(key, data));
            return;
        }
        count++;
        Data data;
        data.value = value;
        data.age = count;
        cache.insert(make_pair(key, data));
    }
};

int main()
{
    LRUCache *cache = new LRUCache(2);

    cache->put(1, 1);
    cache->put(2, 2);
    cout << cache->get(1) << endl; // returns 1
    cache->put(3, 3);              // evicts key 2
    cout << cache->get(2) << endl; // returns -1 (not found)
    cache->put(4, 4);              // evicts key 1
    cout << cache->get(1) << endl; // returns -1 (not found)
    cout << cache->get(3) << endl; // returns 3
    cout << cache->get(4) << endl; // returns 4
}


