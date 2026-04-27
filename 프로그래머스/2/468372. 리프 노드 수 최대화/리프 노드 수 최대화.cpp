#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int max_leaf(int k, int l, int dist_limit) {
    int budget = dist_limit;
    int frontier = 1;
    int leaf_cnt = 1;
    
    for (size_t i = 0; budget > 0 && i < k + l; i++) {
        int splits = min(budget, frontier);
        budget -= splits;
        leaf_cnt += splits * (i < k ? 1 : 2);
        frontier = splits * (i < k ? 2 : 3);
    }
    return leaf_cnt;
}

int solution(int dist_limit, int split_limit) {
    int answer = 0;
    
    for (int k = 0;; k++) {
        long long cmp{split_limit * 1l};
        for (size_t i = 0; i < k; i++) {
            cmp /= 2;
        }
        if (cmp == 0)
            break;

        int l = 0;
        while (true) {
            cmp /= 3;
            if (cmp == 0)
                break;
            l++;
        }
        answer = max(answer, max_leaf(k, l, dist_limit));
    }
    return answer;
}