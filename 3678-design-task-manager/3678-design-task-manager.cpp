class TaskManager {
public:
map<int,map<int,int>>map1;
    TaskManager(vector<vector<int>>& tasks) {
        for(int i=0;i<tasks.size();i++)
        {
              vector<int>a=tasks[i];
              int priority=a[2];
              int taskID=a[1];
              int userid=a[0];
              map1[priority][taskID]=userid;
        }
      
    }
    
    void add(int userId, int taskId, int priority) {
         map1[priority][taskId]=userId;
    }
    
    void edit(int taskId, int newPriority) {
         for (auto it = map1.begin(); it != map1.end(); ++it)
        {
            auto &l=it->second;
            if(l.count(taskId))
            {
                int userid=l[taskId];
                l.erase(taskId);
                if(l.empty())
                map1.erase(it);
                map1[newPriority][taskId]=userid;
                return;
            }
        }
    }
    
    void rmv(int taskId) {
       for (auto it = map1.begin(); it != map1.end(); ++it)
        {
            auto &l=it->second;
            if(l.count(taskId))
            {
                l.erase(taskId);
                if(l.empty())
                map1.erase(it);
                return;
            }
        }
    }
    
    int execTop() {
         if (map1.empty()) {
            return -1; // No tasks available
        }
        auto it=prev(map1.end());
        auto &map2=it->second;
        auto w=prev(map2.end());
        int val=w->second;
        map2.erase(w);
        if(map2.empty())
        {
            map1.erase(it);
        }
        return val;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */