class Node{
public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

class MyHashSet {
public:
    vector<Node> arr;

    MyHashSet():arr(1000000,Node(-1)) {
        
    }
    
    void add(int key) {
        //cout<<"adding "<<key<<endl;
        int key_index=key%1000000;

        Node* tem=&arr[key_index];
        Node* to_add=new Node(key);

        while(tem!=NULL){ 
            if(tem->data==key){ return; }
            tem=tem->next;
        }
          
        tem=&arr[key_index];
        to_add->next=tem->next;  
        tem->next=to_add;
    }
    
    void remove(int key) {
        //cout<<"removing "<<key<<endl;

        int key_index=key%1000000;

        Node* tem=&arr[key_index];
        Node* pre=NULL;

        while(tem!=NULL && tem->data!=key){ pre=tem; tem=tem->next;}

        if(tem!=NULL){ pre->next=tem->next; tem->next=NULL; delete tem; }
    }
    
    bool contains(int key) {
        //cout<<"finding "<<key<<endl;

        int key_index=key%1000000;

        Node* tem=&arr[key_index];
        
        while(tem!=NULL){ 
            //cout<<tem->data<<"=="<<endl;
            if(tem->data==key){ return true; }
            tem=tem->next;
            }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */