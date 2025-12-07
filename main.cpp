#include <vector>
#include <queue>
#include <functional>
#include <iostream>

std::vector<int> heapSort(const std::vector<int>& nums) {

    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

    for (int x : nums) {
        pq.push(x);
    }

    std::vector<int> result;
    result.reserve(nums.size());

    while (!pq.empty()) {
        result.push_back(pq.top());
        pq.pop();
    }

    return result;
}

int kthSmallest(const std::vector<int>& nums, int k) {
    std::priority_queue<int> pq;

    for (int x : nums) {
        pq.push(x);
        if ((int)pq.size() > k)
            pq.pop();
    }
    return pq.top();
}

int kthSmallest_minHeap(const std::vector<int>& nums, int k) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq(nums.begin(), nums.end());

    while (--k) pq.pop();
    return pq.top();
}


struct Node {
    int value;
    int listIndex;
    int elementIndex;

    bool operator>(const Node& other) const {
        return value > other.value;
    }
};

std::vector<int> mergeKSortedLists(const std::vector<std::vector<int>>& lists) {
    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> pq;
    std::vector<int> result;

    for (int i = 0; i < (int)lists.size(); i++) {
        if (!lists[i].empty()) {
            pq.push(Node{lists[i][0], i, 0});
        }
    }

    while (!pq.empty()) {
        Node top = pq.top();
        pq.pop();

        result.push_back(top.value);

        int nextIndex = top.elementIndex + 1;
        if (nextIndex < (int)lists[top.listIndex].size()) {
            pq.push(Node{
                lists[top.listIndex][nextIndex],
                top.listIndex,
                nextIndex
            });
        }
    }

    return result;
}


class MedianFinder {
private:
    std::priority_queue<int> left;
    std::priority_queue<int, std::vector<int>, std::greater<int>> right;

public:
    void addNum(int num) {
        if (left.empty() || num <= left.top()) {
            left.push(num);
        } else {
            right.push(num);
        }

        if (left.size() > right.size() + 1) {
            right.push(left.top());
            left.pop();
        }
        else if (right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        }
    }

    double findMedian() {
        if (left.size() > right.size()) {
            return left.top();
        }
        return (left.top() + right.top()) / 2.0;
    }
};
struct Point {
    int x, y;
};

int dist(const Point& p) {
    return p.x * p.x + p.y * p.y;
}


std::vector<Point> kClosest(std::vector<Point>& pts, int k) {
    std::priority_queue<std::pair<int,int>> pq;
    for (int i = 0; i < (int)pts.size(); ++i) {
        pq.push({dist(pts[i]), i});
        if ((int)pq.size() > k) pq.pop();
    }
    std::vector<Point> result;
    while (!pq.empty()) {
        result.push_back(pts[pq.top().second]);
        pq.pop();
    }
    return result;
}







int main() {

    // 1
    // std::vector<int> nums = {4, 2, 8, 1, 9, 3};
    // auto result = heapSort(nums);
    //
    // for (int x : result){
    //     std::cout << x << " ";
    // }


    //2
    std::vector<int> nums = {7, 10, 4, 3, 20, 15, -1, 8};
    int k = 3;
    std::cout <<kthSmallest(nums, k) << std::endl;


    //3
    //
    // std::vector<std::vector<int>> lists = {
    //     {1, 4, 5},
    //     {1, 3, 4},
    //     {2, 6}
    // };
    // auto result = mergeKSortedLists(lists);
    // // result: {1, 1, 2, 3, 4, 4, 5, 6}

    //4


    // MedianFinder mf;
    // mf.addNum(1);
    // mf.addNum(2);
    // std::cout << mf.findMedian() << '\n';  // 1.5
    // mf.addNum(3);
    // std::cout << mf.findMedian() << '\n';  // 2.0


    // 5

    std::vector<Point> pts = {{1, 3}, {-2, 2}, {5, 8}};
    auto result = kClosest(pts, 2);
    // result: {{-2, 2}, {1, 3}}
    // Расстояния: (-2)²+(2)² = 8, (1)²+(3)² = 10, (5)²+(8)² = 89

}
