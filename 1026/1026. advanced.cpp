//https://blog.csdn.net/qq_45228537/article/details/107911527
/*
据说现在PAT已经不考这种大模拟了，准备PAT的同学可以酌情跳过节省时间~
我的想法是用优先队列保存即将要发生的事件（一共三种事件），先发生的排在前面。用户排队的情况我是使用两个队列分别存储vip和普通用户的。接下来我们一个一个处理这些事件即可：
（1）有vip过来打球。若有空桌，则先选择vip桌中序号最小桌，若无空vip桌则选普通桌中序号最小桌；若无空桌，该vip进入vip等待队列。
（2）有非vip过来打球。若有空桌，选择编号最下桌，若无空桌则进入非vip等待队列。
（3）有球桌空闲。（当同一时间有多个桌子空闲时我们优先处理编号更小的桌子）若当前空桌为vip桌，则优先查询vip队列，vip队列无人再查询普通用户队列；若为普通桌，则查找两个队列首部的两个人，选择到达时间更早的那一个。
坑点：
1.题意不清。题目明明说的是“be assigned to the available table with the smallest number”，我也不清楚为什么如果普通桌和vip桌都空着，vip要先选vip桌，不是应该一视同仁选择编号最小桌吗？
2.超过两小时应该改为两小时；
3.等待时间四舍五入，我之前用的ceil函数，以为round up to是向上取整QAQ；
*/

#include <bits/stdc++.h>

using namespace std;

const int EndTime = 21 * 3600;
int n, k, m, cnt[105];
bool vip[105], vct[105];

struct Evt {
	int t, ifo, tag;   // time  no/last-time  tag
	bool operator > (const Evt & e) const {
		return t > e.t;
	}
};

struct Ans { int at, st, wt;  }; //arrive  serve  wait	

inline int cal(int & h, int & m, int & s) {
	return h * 3600 + m * 60 + s;	
}

priority_queue<Evt, vector<Evt>, greater<Evt> > que;  //queue of events
queue<Evt> py, vpy; //players

inline void print(int & t) {
	printf("%02d:%02d:%02d", t / 3600, t % 3600 / 60, t % 60); 	
}

inline int find(int & tag) {
	if(tag) for(int i = 1; i <= k; ++i) {
		if(vct[i] && vip[i]) return i;	
	}
	for(int i = 1; i <= k; ++i) {
		if(vct[i]) return i;
	}
	return -1;
}

int main() {
#ifdef MyTest
	freopen("Sakura.txt", "r", stdin);
#endif
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		int h, m, s, p, tag;
		scanf("%d:%d:%d %d %d", &h, &m, &s, &p, &tag);
		if(p > 120) p = 120;
		que.push(Evt{cal(h, m, s), p * 60, tag});
	}
	scanf("%d %d", &k, &m);
	for(int i = 1; i <= k; i++) vct[i] = true;
	for(int i = 0; i < m; i++) {
		int id;
		scanf("%d", &id);
		vip[id] = true;	
	}
	vector<Ans> v;
	while(!que.empty()) {
		Evt e = que.top();
		if(e.t >= EndTime) break;
		que.pop();
		if(e.tag != 2) {
			int pos = find(e.tag);
			if(~pos) {
				vct[pos] = false;
				que.push(Evt{e.t + e.ifo, pos, 2});
				cnt[pos]++;
				v.push_back(Ans{e.t, e.t, 0});
			} else {
				if(e.tag == 0) py.push(e);
				else vpy.push(e);
			}
		} else {
			Evt x, y;
			if(vip[e.ifo]) {
				if(!vpy.empty()) {
					x = vpy.front();
					vpy.pop();	
				} else if(!py.empty()) {
					x = py.front();
					py.pop();
				} else {
					vct[e.ifo] = true;
					continue;
				}
			} else {			
				if(vpy.empty() && py.empty()) {
					vct[e.ifo] = true;
					continue;
				}
				if(!vpy.empty() && !py.empty()) {
					x = vpy.front(), y = py.front();
					if(y.t < x.t) x = y, py.pop();
					else vpy.pop();
				} else if(!vpy.empty()) {
					x = vpy.front();
					vpy.pop();	
				} else if(!py.empty()) {
					x = py.front();
					py.pop();
				}
			}
			cnt[e.ifo]++;
			que.push(Evt{e.t + x.ifo, e.ifo, 2});
			v.push_back(Ans{x.t, e.t, int((e.t - x.t) / 60.0 + 0.5)});
		}
	}
	for(Ans & a : v) {
		print(a.at);
		putchar(' ');
		print(a.st);
		printf(" %d\n", a.wt);	
	}
	for(int i = 1; i <= k; ++i) {
		if(i != 1) putchar(' ');
		printf("%d", cnt[i]);	
	}
	return 0;	
}
