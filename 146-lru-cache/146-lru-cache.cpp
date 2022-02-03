class LRUCache {
public:
    
    class DllNode{
        public:
        int key;
        int value;
        DllNode* prev;
        DllNode* next;
        DllNode(int key,int value){
            this->key = key;
            this->value = value;
        }
    };
    
    unordered_map<int,DllNode*> mp;
    int cap;
    
    DllNode* head= new DllNode(-1,-1);
    DllNode* tail = new DllNode(-1,-1);
    
    
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.count(key)>0){
            int ans = mp[key]->value;
            deleteNode(mp[key]);
            DllNode* recent = new DllNode(key,ans);
            addNode(recent);
            mp[key] = recent;
            return ans;
        }
        return -1;
    }
    
    void addNode(DllNode* x){
        DllNode* temp = head->next;
        head->next = x;
        x->prev = head;
        temp->prev = x;
        x->next = temp;
        return;
    }
    
    void deleteNode(DllNode* x){
        DllNode* prevx = x->prev;
        DllNode* postx = x->next;
        prevx->next = postx;
        postx->prev = prevx;
        x->prev = x->next = NULL;
        return;
    }
    
    void put(int key, int value) {
        if(mp.count(key)>0){
            DllNode* existingNode = mp[key];
            deleteNode(mp[key]);
        }else if(mp.size()==cap){
            DllNode* notFreq = tail->prev;
            mp.erase(tail->prev->key);
            deleteNode(notFreq);
        }
        DllNode* recent = new DllNode(key,value);
        addNode(recent);
        mp[key] = recent;
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */