class DLL{
public:
    int key;
    int data;
    DLL* prev;
    DLL* next;
    
    DLL(int key,int data){
        this->key = key;
        this->data = data;
        prev = next = NULL;
    }
};

class LRUCache {
private:
    
    unordered_map<int,DLL*> mappings;
    DLL* d1 = new DLL(-1,-1);
    DLL* d2 = new DLL(-1,-1);
    
    void insert(DLL* newNode){
        DLL* nextNode = d1->next;
        d1->next = newNode;
        newNode->prev = d1;
        newNode->next = nextNode;
        nextNode->prev = newNode;
    }
    
    void deleteNode(DLL* targetNode){
        mappings.erase(targetNode->key);
        DLL* prevNode = targetNode->prev;
        DLL* nextNode = targetNode->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        targetNode->next = targetNode->prev = NULL;
    }
    
public:   
    int capacity;
    LRUCache(int capacity) {
        this->capacity = capacity;
        d1->next = d2;
        d2->prev = d1;
    }
    
    int get(int key) {
        if(mappings.count(key) > 0){
            int result = mappings[key]->data;
            // delete the node from its position
            deleteNode(mappings[key]);
            // insert it in the front
            DLL* newNode = new DLL(key,result);
            mappings[key] = newNode;
            insert(newNode);
            return result;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mappings.count(key)>0){
            deleteNode(mappings[key]);
        }else if(mappings.size() == capacity){
            deleteNode(d2->prev);
        }
        DLL* newNode = new DLL(key,value);
        mappings[key] = newNode;
        insert(newNode);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */