class Solution {
public:
    vector<int>PreviousSmaller(vector<int>& heights) {
        int n = heights.size();
        stack<int>s;
        vector<int>prev(n);
        for(int i=0;i<n;i++){
            while(!s.empty() && heights[s.top()]>=heights[i]) s.pop();
            if(s.empty()) prev[i]=0;
            else prev[i]=s.top()+1;
            s.push(i);
        }
    return prev;
    }
    vector<int>NextSmaller(vector<int>& heights) {
        int n = heights.size();
        stack<int>s;
        vector<int>next(n);
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && heights[s.top()]>=heights[i]) s.pop();
            if(s.empty()) next[i]=n-1;
            else next[i]=s.top()-1;
            s.push(i);
        }
    return next;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size() , maxArea = 0;
        vector<int>prev=PreviousSmaller(heights) ; 
        vector<int>next=NextSmaller(heights) ; 
        
       /* for(auto i : prev) cout<<i<<" ";
        cout<<"\n";
        for(auto i : next) cout<<i<<" ";
        cout<<"\n";
      */
        for(int i=0;i<n;i++){
            int breadth = next[i]-prev[i]+1;
            int length = heights[i] ; 
            int area = length*breadth; 
            maxArea=max(maxArea,area);
        }
    return maxArea;
    }
};
