class Solution {
public:
    int lowerBound(vector<int>& nums, int key){
        int n=nums.size() ,low=0,high=n-1,pos=0;
        while(low<=high){
            int mid = low + (high-low)/2; 
            if(nums[mid]==key){
                return mid;
            }
            if(nums[mid]<key){
                low=mid+1;
            }
            if(nums[mid]>key){
                pos=mid;
                high=mid-1;
            }
        }
    //cout<<low<<" "<<pos<<"\n";
    if(pos<n && nums[n-1]<key) pos++; //low and pos are equal 
    return pos;
    }
    int lengthOfLIS(vector<int>& nums) {
        // binary search 
        vector<int>lis;
        lis.push_back(nums[0]); 
        for(int i=1;i<nums.size();i++){
            if(lis.back()<nums[i]) lis.push_back(nums[i]); 
            else{
                int pos = lowerBound(lis,nums[i]) ; 
                lis[pos] = nums[i];
            }
        }
    return lis.size();
    }
};
