class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> answer;
        int counter = 0;
        int len = 0;
        int number = 0;
        for(int i = 0; i <= n; i++){
            number = i;
            len = 0;
            counter = 0;

            while(number > 0){number /= 2; len++;}
            number = i;
            
            for(int j = 0; j < len; j++){
                if(number & (1 << j)) counter++;
            }
            answer.push_back(counter);
        }
        return answer;
    }
};
