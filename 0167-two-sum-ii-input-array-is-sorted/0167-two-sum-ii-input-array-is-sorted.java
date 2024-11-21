class Solution {
    public int[] twoSum(int[] numbers, int target) {
     int left_pointer=0;
     int right_pointer=numbers.length-1;
     while(left_pointer<right_pointer)
     {
        if(target==numbers[left_pointer]+numbers[right_pointer])
        {
            return new int[]{left_pointer+1,right_pointer+1};
        }
        else if(target>numbers[left_pointer]+numbers[right_pointer])
        {
           left_pointer++;
        }
        else
        {
            right_pointer--;
        }}
   return new int[0]; }
}