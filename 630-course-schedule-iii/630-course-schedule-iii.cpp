class Solution {
public:
    struct task
    {
        int days, limit;
    };
    
    static bool myComp(task x, task y)
    {
        if(x.limit == y.limit)
            return x.days < y.days;
        
        return x.limit < y.limit;
    }
    
    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size();
        vector<task> tasks(n, {0, 0});
        
        for(int i=0;i<n;i++)
        {
            tasks[i].days = courses[i][0];
            tasks[i].limit = courses[i][1];
        }
        
        sort(tasks.begin(), tasks.end(), myComp);
        
        priority_queue<int> pq;
        
        int totalDays = 0;
        
        for(int i=0;i<n;i++)
        {
            int day = tasks[i].days;
            int dead = tasks[i].limit;
            
            if(day + totalDays <= dead)
            {
                totalDays += day;
                pq.push(day);
            }
            
            else if(!pq.empty() && pq.top() > day)
            {
                totalDays -= pq.top();
                pq.pop();
                totalDays += day;
                pq.push(day);
            }
        }
        return pq.size();
    }
};