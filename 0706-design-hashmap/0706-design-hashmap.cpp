class Node{
public:
    int key;
    int value;
    Node* next;

    Node(int key, int value){
        this->key=key;
        this->value=value;
        next=NULL;
    }
};

class MyHashMap {
public:
    vector<Node> arr;

    MyHashMap():arr(10000,Node(-1,-1)) {
        
    }
    
    void put(int key, int value) {
        //cout<<"putting "<<key<<" "<<value<<endl;
        int key_index=key%10000;

        Node* to_add = new Node(key,value);
        Node* find = &arr[key_index];

        while(find!=NULL){ 
            if(find->key==key){
                find->value=value;
                return;
            }
            find=find->next;
        }

        find = &arr[key_index];
        to_add->next=find->next;
        find->next=to_add; 
    }
    
    int get(int key) {
        //cout<<"getting "<<key<<" "<<endl;
        int key_index=key%10000;

        Node* find = &arr[key_index];

        while(find!=NULL){ 
           // cout<<find->key<<" ";
            if(find->key==key){
                //cout<<"found "<<key<<" "<<find->value<<endl;
                return find->value;
            }
            find=find->next;
        }


        return -1;
    }
    
    void remove(int key) {
        //cout<<"getting "<<key<<endl;
        int key_index=key%10000;

        Node* before = &arr[key_index];
        Node* find = before->next;

        while(find!=NULL){ 
            if(find->key==key){
                before->next=find->next;
                find->next=NULL;
                delete find;
                return;
            }
            before=find;
            find=find->next;
        }

    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */