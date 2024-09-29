#include <unordered_map>
#include <unordered_set>
#include <list>
#include <string>
using namespace std;

class AllOne {
private:
    // List node to hold the count and the set of keys with that count
    struct Bucket {
        int count;
        unordered_set<string> keys;
        Bucket(int c) : count(c) {}
    };

    // Doubly linked list of buckets (each node has a unique count)
    list<Bucket> countList;
    
    // Maps a key to its position in the list (an iterator pointing to its Bucket)
    unordered_map<string, list<Bucket>::iterator> keyBucket;
    
public:
    // Constructor
    AllOne() {
    }

    // Increment the count of the key
    void inc(string key) {
        if (keyBucket.find(key) != keyBucket.end()) {
            // If key exists, move it to the next bucket
            auto currBucket = keyBucket[key];
            auto nextBucket = next(currBucket);
            
            // If the next bucket doesn't exist or its count is not currentCount + 1, create a new one
            if (nextBucket == countList.end() || nextBucket->count != currBucket->count + 1) {
                nextBucket = countList.insert(nextBucket, Bucket(currBucket->count + 1));
            }
            
            // Move key to the next bucket
            nextBucket->keys.insert(key);
            keyBucket[key] = nextBucket;
            
            // Remove the key from the current bucket
            currBucket->keys.erase(key);
            if (currBucket->keys.empty()) {
                countList.erase(currBucket); // Remove the bucket if it's empty
            }
        } else {
            // If key doesn't exist, add it to the first bucket with count 1
            if (countList.empty() || countList.front().count != 1) {
                countList.push_front(Bucket(1));
            }
            countList.front().keys.insert(key);
            keyBucket[key] = countList.begin();
        }
    }

    // Decrement the count of the key
    void dec(string key) {
        if (keyBucket.find(key) == keyBucket.end()) return; // Key does not exist
        
        auto currBucket = keyBucket[key];
        if (currBucket->count == 1) {
            // If count is 1, remove the key completely
            currBucket->keys.erase(key);
            if (currBucket->keys.empty()) {
                countList.erase(currBucket); // Remove the bucket if it's empty
            }
            keyBucket.erase(key); // Remove key from the map
        } else {
            // Otherwise, move the key to the previous bucket
            auto prevBucket = prev(currBucket);
            
            // If the previous bucket doesn't exist or its count is not currentCount - 1, create a new one
            if (currBucket == countList.begin() || prevBucket->count != currBucket->count - 1) {
                prevBucket = countList.insert(currBucket, Bucket(currBucket->count - 1));
            }
            
            // Move key to the previous bucket
            prevBucket->keys.insert(key);
            keyBucket[key] = prevBucket;
            
            // Remove the key from the current bucket
            currBucket->keys.erase(key);
            if (currBucket->keys.empty()) {
                countList.erase(currBucket); // Remove the bucket if it's empty
            }
        }
    }

    // Returns one of the keys with the maximum count
    string getMaxKey() {
        if (countList.empty()) return ""; // No keys
        return *(countList.back().keys.begin()); // Return any key from the last bucket
    }

    // Returns one of the keys with the minimum count
    string getMinKey() {
        if (countList.empty()) return ""; // No keys
        return *(countList.front().keys.begin()); // Return any key from the first bucket
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */






