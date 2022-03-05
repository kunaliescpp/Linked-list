/*
Problem Link: https://leetcode.com/problems/lru-cache/

Design LRU Cache
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Example 1:
Input: ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
        [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output: [null,  null,   null,   1,   null,  -1,   null,  -1,   3,  4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {2=2, 1=1}
lRUCache.get(1);    // return (val of key 1), cache is{1=1, 2=2}
lRUCache.put(3, 3); // cache is {3=3, 1=1}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return (val of key 3)
lRUCache.get(4);    // return (val of key 4)
 */

class LRUCache {
public:   
    int len;
    list<int> dll;                                                         // doubly LL
    unordered_map<int,   pair<int, list<int>::iterator>   >mp;            // pair is storing <node, address of node in list>
    
    LRUCache(int capacity) {
        len = capacity;
    }
    
    int search(int key) {
        if(mp.count(key)){
            dll.erase(mp[key].second);
            dll.push_front(key);
            mp[key].second = dll.begin();
            return mp[key].first;
        } 
        return -1;
    }
    
    void insert(int key, int value) {
        if(mp.count(key)){
            dll.erase(mp[key].second);
            dll.push_front(key);
            mp[key] = {value, dll.begin()};
        } else {
            if(dll.size() == len){
              mp.erase(dll.back());
              dll.pop_back();
            } 
              dll.push_front(key);
              mp[key] = {value, dll.begin()};   
        }
    }
};

/* About: cache is memory near CPU which is smaller than RAM. It uses the concept LRU. It put LRU item at the front in case of 
          hit(already present) or new item. if capacity is full then it removes the last item.
          Hit in O(1)
          Miss in O(1) 
*/


