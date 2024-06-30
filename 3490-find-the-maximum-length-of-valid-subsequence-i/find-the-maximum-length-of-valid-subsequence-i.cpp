class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int counteven = 0;
        int countodd = 0;
        int both = 0;
        int parity = nums[0]%2;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2) countodd+=1;
            else counteven++;

            if(nums[i]%2==parity){
                both++;
                parity = 1-parity;
            }
        }

        return max(countodd,max(counteven,both));

    }
};