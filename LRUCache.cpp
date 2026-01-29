#include <iostream>
#include <unordered_map>
#include <list>
/**
 * LRU Cache implementation using a Hash Map and a Doubly Linked List.
 * This ensures O(1) time complexity for both 'get' and 'put' operations.
 */
class LRUCache {
private:
    int capacity;
    //std::list stores the keys in the order of their usage (Most Recent at front)
    std::list<int> recent_list;
    //std::unordered_map stores the key-value pair and an iterator to its position in the list
    std::unordered_map<int, std::pair<int, std::list<int>::iterator>> cache_map;
public:
    LRUCache(int cap) : capacity(cap) {}
    //Function to retrieve a value from the cache
    int get(int key) {
        if (cache_map.find(key) == cache_map.end()) {
            return -1; // Key not found
        }
        // Move the accessed key to the front of the list (mark as most recently used)
        recent_list.erase(cache_map[key].second);
        recent_list.push_front(key);
        cache_map[key].second = recent_list.begin();
        return cache_map[key].first;
    }
    // Function to put/update a value in the cache
    void put(int key, int value) {
        if (cache_map.find(key) != cache_map.end()) {
            // If key exists, remove old entry from list
            recent_list.erase(cache_map[key].second);
        } else if (cache_map.size() >= capacity) {
            // If cache is full, remove the Least Recently Used (LRU) element
            int last_key = recent_list.back();
            recent_list.pop_back();
            cache_map.erase(last_key);
        }
        // Add new key to the front of the list and update the map
        recent_list.push_front(key);
        cache_map[key] = {value, recent_list.begin()};
    }
    void display() {
        std::cout << "Current Cache (Most Recent -> Oldest): ";
        for (int key : recent_list) {
            std::cout << "[" << key << ":" << cache_map[key].first << "] ";
        }
        std::cout << std::endl;
    }
};

int main() {
    LRUCache cache(3); // Cache capacity of 3 items
    std::cout << "Putting (1,10), (2,20), (3,30)..." << std::endl;
    cache.put(1, 10);
    cache.put(2, 20);
    cache.put(3, 30);
    cache.display();
    std::cout << "Getting key 1: " << cache.get(1) << std::endl;
    std::cout << "Adding key 4 (will evict key 2, as 1 was just used)..." << std::endl;
    cache.put(4, 40);
    cache.display();
    return 0;
}
