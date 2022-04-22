class Solution {
    unordered_map<string, vector<string>> graph;
    unordered_map<string, bool> visited;
    unordered_map<string, string> emailNameRelation;
    
    void dfs(string email, vector<string>& emailList) {
        
        visited[email] = true;
        emailList.push_back(email);
        
        for(string emails : graph[email]) {
            if(!visited[emails]) 
                dfs(emails, emailList);
        }
        
    }
    
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        // Constructing the graph
        for(vector<string> acc : accounts) {
            
            int n = acc.size();
            string name = acc[0];
            emailNameRelation[acc[1]] = name; // Associating the first email with the name.
            visited[acc[1]] = false;
            
            for(int i=2 ; i<n ; i++) {
                visited[acc[i]] = false;
                emailNameRelation[acc[i]] = name; // Associating all other emails with the name.
                
                // Creating an edge between 1st email and ith email.
                graph[acc[i]].push_back(acc[1]);
                graph[acc[1]].push_back(acc[i]);
            }
            
        }
        
        vector<vector<string>> result;
        
        for(int i=0 ; i<accounts.size() ; i++) {
            for(int j=1 ; j<accounts[i].size() ; j++) {
                
                // Performing the DFS about the email accounts[i][j]
                if(!visited[accounts[i][j]]) {
                    
                    vector<string> emailList;
                    dfs(accounts[i][j], emailList);
                    emailList.push_back(emailNameRelation[accounts[i][j]]);
                    
                    reverse(emailList.begin(), emailList.end());
                    sort(emailList.begin()+1, emailList.end());
                    result.push_back(emailList);
                    
                }
                
            }
        }
        
        return result;
    }
};