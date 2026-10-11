class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int pos = 0;
        vector<vector<int>> answer;

        // 1. Твой поиск позиции вставки (защищенный от выхода за границы)
        while(pos < intervals.size() && newInterval[0] > intervals[pos][0]) pos++;

        // 2. Твой перенос всех элементов ДО pos в ответ
        int i = 0;
        while(i < pos) { 
            answer.push_back(intervals[i]); 
            i++; 
        }

        // 3. Вставляем newInterval. 
        // Сливаем его с последним добавленным (pos-1), если есть пересечение
        if (pos > 0 && answer.back()[1] >= newInterval[0]) {
            answer.back()[1] = max(answer.back()[1], newInterval[1]);
        } else {
            answer.push_back(newInterval); // Иначе просто добавляем
        }

        // 4. Твой перенос оставшихся элементов ПОСЛЕ pos
        for(; i < intervals.size(); i++){
            // Если текущий интервал пересекается с хвостом ответа - сливаем
            if (answer.back()[1] >= intervals[i][0]) {
                answer.back()[1] = max(answer.back()[1], intervals[i][1]);
            } else {
                answer.push_back(intervals[i]);
            }
        }
        
        return answer;
    }
};