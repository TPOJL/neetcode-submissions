class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for(int i = 0; i < gas.size(); i++){
            gas[i]-=cost[i];
        }
        int total = 0;
        for(auto && el : gas){
            total += el;
        }
        if(total < 0) return -1;
        total = 0;
        int pos = 0;
        for(int i = 0; i < gas.size(); i++){
            total += gas[i];
            if(total < 0){
                total = 0;
                pos = i+1;
            }
        }
        return pos;

    }
};
/// 1 2 3 4 5 6 7 8 9