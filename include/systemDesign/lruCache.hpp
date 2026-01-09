#ifndef LRU_CACHE_HPP
#define LRU_CACHE_HPP

#include <list>
#include <unordered_map>
#include <stdexcept>
#include <iostream>

// LRU Cache (Least Recently Used)
// Goal: A fixed-size cache that evicts the least recently accessed item when full.
// Mechanics:
// 1. Doubly Linked List (std::list): Stores the actual Key-Value pairs. 
//    - Why? O(1) insertion at head and O(1) deletion from tail.
//    - Head = Most Recently Used.
//    - Tail = Least Recently Used.
// 2. Hash Map (std::unordered_map): Maps Keys to Iterators (pointers) in the list.
//    - Why? O(1) lookup. Without this, finding an item in the list would be O(N).

template <typename K, typename V>
class LRUCache {
private:
    size_t capacity;
    std::list<std::pair<K, V>> items; // Doubly Linked List of {Key, Value}
    std::unordered_map<K, typename std::list<std::pair<K, V>>::iterator> lookup; // Key -> Iterator

public:
    LRUCache(size_t cap) : capacity(cap) {}

    // Get value by key
    // Complexity: O(1)
    V get(const K& key) {
        auto it = lookup.find(key);
        if (it == lookup.end()) {
            throw std::runtime_error("Key not found");
        }
        
        // 1. Move accessed item to the front of list (Mark as Recently Used)
        // splice() moves an element from one list position to another in O(1) without copying.
        items.splice(items.begin(), items, it->second);
        
        // 2. Return value
        return it->second->second;
    }

    // Insert or Update value
    // Complexity: O(1)
    void put(const K& key, const V& value) {
        auto it = lookup.find(key);
        
        // Case 1: Update existing key
        if (it != lookup.end()) {
            // Move key to front
            items.splice(items.begin(), items, it->second);
            // Update value
            it->second->second = value;
            return;
        }

        // Case 2: Insert new key
        // If cache is full, evict LRU (Back of list)
        if (items.size() == capacity) {
            auto lru = items.back(); // Last item
            lookup.erase(lru.first); // Remove from map
            items.pop_back();        // Remove from list
        }

        // Add new item to front of list
        items.push_front({key, value});
        // Update map
        lookup[key] = items.begin();
    }
    
    // Helper for debugging/testing
    size_t size() const {
        return items.size();
    }
};

#endif // LRU_CACHE_HPP
