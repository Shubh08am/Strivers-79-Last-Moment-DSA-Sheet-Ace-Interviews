class Solution {
public:
    bool isPossible(int banana,vector<int>& piles, int h) {
        long required=0;
        for(auto & val : piles) required+=(val+banana-1)/banana;
        return required<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1 , high = *max_element(piles.begin(),piles.end()) ; 
        while(low<=high){
            int mid = low + (high-low)/2; 
            if(isPossible(mid,piles,h)) high=mid-1;
            else low=mid+1;
        }
    return low;//always return opposite polarities 
    }
};
