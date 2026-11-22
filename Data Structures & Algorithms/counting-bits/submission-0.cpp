class Solution {
public:
    vector<int> countBits(int n) {
        if(n == 0) return {0};
        vector<int> answer;
        answer.push_back(0);
        int number = 0;
        int counter = 0;
        for(int i = 1; i <= n; i++){
            number = i;
            counter = 0;
            while(number > 0){
                if(number % 2 == 1) counter++;
                number /= 2;
            }
            answer.push_back(counter);
        }
        return answer;
    }
};
