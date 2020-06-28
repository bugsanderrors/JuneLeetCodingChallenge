/*
    Reconstruct Itinerary

    Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.

    Note:
        * If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
        * All airports are represented by three capital letters (IATA code).
        * You may assume all tickets form at least one valid itinerary.
        * One must use all the tickets once and only once.

    Example 1:
    Input: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
    Output: ["JFK", "MUC", "LHR", "SFO", "SJC"]

    Example 2:
    Input: [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
    Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
    Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"].
                But it is larger in lexical order.
*/

class Solution {
public:
    vector<string> ans;
    
    map<string, multiset<string>> graph;
public:
    
    void dfs(string source)
    {
        while(graph[source].size())
        {
            string x = *(graph[source].begin());
            graph[source].erase(graph[source].begin());
            dfs(x);
        }
        
        ans.push_back(source);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        for(int i=0; i<tickets.size(); i++)
        {
            string from = tickets[i][0];
            string to = tickets[i][1];
            graph[from].insert(to);
        }
        
        dfs("JFK");
        
        reverse(ans.begin(), ans.end());
        
        return ans; 
    }
};