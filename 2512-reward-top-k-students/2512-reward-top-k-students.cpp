class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        
        int n = report.size();
        unordered_set<string> positive(positive_feedback.begin(), positive_feedback.end());
        unordered_set<string> negative(negative_feedback.begin(), negative_feedback.end());
        
        vector<pair<int, int>> scoreCard;
        
        for(int i=0 ; i<n ; i++) {
            
            int score = 0;
            string s = "";
            int m = report[i].length();
            
            for(int j=0 ; j<m ; j++) {
                if(report[i][j] == ' ' || j == m-1) {
                    if(j == m-1) s += report[i][m-1];
                    
                    if(positive.find(s) != positive.end()) score += 3;
                    else if(negative.find(s) != negative.end()) score--;
                    
                    s = "";
                }
                else s += report[i][j];
            }
            
            scoreCard.push_back({ score, student_id[i] });
        }
        
        sort(scoreCard.begin(), scoreCard.end(), [](pair<int, int>& a, pair<int, int>& b) {
            if(a.first == b.first) return a.second < b.second;
            return a.first > b.first;
        });
        
        vector<int> result;
        int i = 0;
        
        while(i<n && k>0) {
            result.push_back(scoreCard[i].second);
            i++;
            k--;
        }
        
        return result;
    }
};