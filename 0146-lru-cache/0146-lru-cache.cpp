class ListtNode {
public:
    ListtNode* pre;
    int key;
    int value;
    ListtNode* next;

    ListtNode(int key,int value){
        this->key=key;
        this->value=value;
    }
};
class LRUCache {
public:
    int capacity;
    int current=0;

    ListtNode* head;
    ListtNode* tail;

    unordered_map<int,ListtNode*> map;

    LRUCache(int capacity) {
        this->capacity=capacity;

        head = new ListtNode(-1,-1);
        tail = new ListtNode(-1,-1);
        head->pre=NULL; head->next=tail;
        tail->pre=head; tail->next=NULL;

    }

    // void display(){
    //     ListtNode* trry=head;
    //     while(trry!=NULL){
    //         cout<<"<--("<<trry->key<<")-->";
    //         trry=trry->next;
    //     }
    //     cout<<endl;
    // }/

    void update(ListtNode* rem){
        current--;
        
        ListtNode* p=rem->pre;
        ListtNode* n=rem->next;

        p->next=rem->next;
        n->pre=rem->pre;

        rem->pre=NULL;
        rem->next=NULL;
        
        int key=rem->key;
        int value=rem->value;

        map.erase(key);

        //enter that in the front

        put(key,value);

    }
    
    int get(int key) {
        if(map.count(key)){
            
            ListtNode* rem=map[key];
            int ans=rem->value;

            //update
            update(rem); 
            
            //display();
            return ans;
        }
        else{
            //display();
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(map.count(key)){
            map[key]->value=value;
            update(map[key]);
        }
        else if(!map.count(key) && current<capacity){
            current++;
            ListtNode* tem = new ListtNode(key,value);
            tem->pre=head;
            tem->next=head->next;
            head->next->pre=tem;
            head->next=tem;

            map[key]=tem;
        }
        else if(current==capacity){
            //remove
            current--;
            ListtNode* rem=tail->pre;
            tail->pre=rem->pre;
            rem->pre->next=tail;
            rem->pre=NULL;
            rem->next=NULL;
            map.erase(rem->key);
            //enter the from the front
            put(key,value);
        }
        //display();
    }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */