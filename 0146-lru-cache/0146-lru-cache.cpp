class DLL {
    public:
    int key, value;
    DLL *prev, *next; 
    DLL(int key, int value) {
        this->key = key;
        this->value = value;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

class LRUCache {
public:
    map<int, DLL*> hashMap;
    int capacity;
    DLL* start;
    DLL* end;
    LRUCache(int capacity) {
        this->capacity = capacity;
        start = new DLL(-1, -1);
        end = new DLL(-1, -1);
        start->next = end;
        end->prev = start;
    }

    void moveToFront(DLL* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->next = start->next;
        node->prev = start;
        start->next->prev = node;
        start->next = node;
    }
    
    int get(int key) {
        if(hashMap.find(key) == hashMap.end()) {
            return -1;
        }
        DLL* node = hashMap[key];
        moveToFront(node);
        return node->value;   
    }
    
    void put(int key, int value) {
        if (hashMap.find(key) != hashMap.end()) {
            DLL* node = hashMap[key];
            node->value = value;
            moveToFront(node);
        } else {
            if (hashMap.size() == capacity) {
                DLL* lru = end->prev;
                hashMap.erase(lru->key);
                lru->prev->next = end;
                end->prev = lru->prev;
                delete lru;
            }

            DLL* newNode = new DLL(key, value);
            hashMap[key] = newNode;
            newNode->next = start->next;
            newNode->prev = start;
            start->next->prev = newNode;
            start->next = newNode;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */