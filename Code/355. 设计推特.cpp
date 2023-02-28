class Twitter {// https://leetcode.cn/problems/design-twitter/description/
private:
    inline static int timestamp = 0;
    struct Tweet {
        // 需要传入推文内容（id）和发文时间
        Tweet(int id, int time) {
            this->id = id;
            this->time = time;
            this->next = NULL;
        }
        int id;
        int time;
        Tweet* next;
    };
public:
    Twitter() {

    }
    
    void postTweet(int userId, int tweetId) {
        if (!userMap.count(userId)) {
            // 不存在，新建
            User* u = new User(userId);
            userMap[userId] = u;
        }
        userMap[userId]->post(tweetId);
    }
    
    class MyComp {
    public:
        bool operator()(Tweet const& A, Tweet const& B) {
            return A.time < B.time;
        }
    };

    vector<int> getNewsFeed(int userId) {
        if (!userMap.count(userId)) return {};
        vector<int> res;
        unordered_set<int>& users = userMap[userId]->followed;
        // 优先队列按照推文时间排序
        priority_queue<Tweet, vector<Tweet>, MyComp> pq;
        for (int id : users) {
            Tweet* usrTwt = userMap[id]->tweetHead;
            if (usrTwt == NULL) continue;
            pq.push(*usrTwt);
        }

        while (!pq.empty()) {
            if (res.size() == 10) break;
            Tweet twt = pq.top();
            pq.pop();
            res.push_back(twt.id);
            if (twt.next) {
                // 把该用户下一条推文插入并排序。反正pq的top一定是排好的、时间最近的那个。
                pq.push(*(twt.next));
            }
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        // 若 follower 不存在，则新建
		if(!userMap.count(followerId)){
			User* u = new User(followerId);
			userMap[followerId] = u;
		}
        // 若 followee 不存在，则新建
		if(!userMap.count(followeeId)){
			User* u = new User(followeeId);
			userMap[followeeId] = u;
		}
		userMap[followerId]->follow(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (userMap.count(followerId)) {
            userMap[followerId]->unfollow(followeeId);
        }
    }
private:
    class User {
    private:
        int id;
    public:
        unordered_set<int> followed;
        // 用户发表的推文链表头结点
        Tweet* tweetHead;

        User(int userId) {
            this->id = userId;
            this->tweetHead = NULL;
            // 关注一下自己
            follow(id);
        }

        void follow(int userId) {
            followed.insert(userId);
        }

        void unfollow(int userId) {
            // 不可以取关自己
            if (userId != this->id)
                followed.erase(userId);
        }

        void post(int tweetId) {
            Tweet* twt = new Tweet(tweetId, timestamp);
            timestamp++;
            // 将新建的推文插入链表头
            // 越靠前的推文 time 值越大
            twt->next = tweetHead;
            tweetHead = twt;
        }
    };
    unordered_map<int, User*> userMap; // userId->User
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */