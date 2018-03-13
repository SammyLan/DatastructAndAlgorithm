
#include <queue>
#include <iostream>
#include <functional>
using namespace std;
void test_priority_queue() {
	std::priority_queue<int, std::vector<int>, std::greater<int>> que;

	que.push(1);
	que.push(0);
	que.push(2);
	que.push(2);
	que.push(3);
	que.push(4);
	que.push(5);
	que.push(6);
	que.push(7);
	
	while (!que.empty()) {
		std::cout << que.top() << endl;
		que.pop();
	}
}
