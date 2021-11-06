/*
Problem Link: https://leetcode.com/problems/lru-cache/

LRU Cache

Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:
LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. 
If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.

Example 1:
Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4
 

Constraints:
1 <= capacity <= 3000
0 <= key <= 10^4
0 <= value <= 10^5
At most 2 * 105 calls will be made to get and put.
*/


class LRUCache {
public:
    // About : cache is memory near CPU which is smaller than RAM. It uses the concept LRU. It put LRU item at        
   // the front in case of hit(already present) or new item. if capacity is full then it removes the last item.
    
    // Hit = O(1)
    // Miss = O(1)
    
    //Look for the x in hash table
    // if found (=hit), find the refrence of the node in DLL. Move the node to the front to the DLL
    // if notfound (=miss)          ->insert a new node at the front of DLL
    //                              ->insert an entry into the hash table
    
    int len;
    list<int> dll;                                                         // doubly LL
    unordered_map<int,   pair<int, list<int>::iterator>   >mp;            // pair is storing <element, address of node in list>
    
    LRUCache(int capacity) {
        len = capacity;
    }
    
    int get(int key) {
        if(mp.count(key)){
            dll.erase(mp[key].second);
            dll.push_front(key);
            mp[key].second = dll.begin();
            return mp[key].first;
        } 
        return -1;
    }
    
    void put(int key, int value) {
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




