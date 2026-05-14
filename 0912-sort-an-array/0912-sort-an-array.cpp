class Solution {
public:
    
    void divide_conquer(int left,int right,vector<int>& nums){
        //cout<<"left "<<left<<" right "<<right<<endl;
        if(left>=right){ return; }

        int mid=(left+right)/2;
       

        divide_conquer(left,mid,nums);

        divide_conquer(mid+1,right,nums);
        //cout<<"------------------merge--------------------------"<<endl;
        merge(left,mid,right,nums);
    }

    void merge(int left,int mid,int right,vector<int>& nums){
        //cout<<"merge call made "<<" left "<<left<<" mid "<<mid<<" right "<<right<<endl;
        vector<int> temp((right-left)+1);
        int count=0;
        
        int ptr_left=left;
        int ptr_right=mid+1;

        while(ptr_left<=mid && ptr_right<=right){
            //cout<<"checking "<<nums[ptr_left]<<" against "<<nums[ptr_right]<<endl;
            if(nums[ptr_left]>nums[ptr_right]){
                temp[count]=nums[ptr_right];
                ptr_right++;
            }
            else{
                temp[count]=nums[ptr_left];
                ptr_left++;
            }
            count++;
        }

        if(ptr_left<=mid){
                while(ptr_left<=mid){
                temp[count]=nums[ptr_left];
                ptr_left++;
                count++;
                }
        }

        if(ptr_right<=right){
            while(ptr_right!=right+1){
                temp[count]=nums[ptr_right];
                ptr_right++;
                count++;
            }
        }

        //cout<<"------"<<endl;
        for(int i=0;i<temp.size();i++){
            nums[left+i]=temp[i];
            //cout<<temp[i]<<"---";
        }
        //cout<<endl<<"----"<<endl;

        
    }

    vector<int> sortArray(vector<int>& nums) {
        divide_conquer(0,nums.size()-1,nums);
        return nums;
    }
};