class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = 0;
        for(auto && el : piles) {
            if(right < el) right = el;
        }
        int ans = right;
        
        while (left <= right) {
            int k = left + (right - left) / 2;
            int total_h = 0; 
            

            for (int el : piles) {
                total_h += ceil((double)el / k); 
            }
            
            if (total_h <= h) {
                ans = k;
                right = k - 1;
            } else {
                left = k + 1;     
            }
        }
        
        return ans;
    }
};
