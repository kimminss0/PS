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
        long long cmp_lk{min(split_limit * 1l, dist_limit * 18l - 1)};
        long long cmp_k{min(split_limit * 1l, dist_limit * 4l - 1)};
        for (size_t i = 0; i < k; i++) {
            cmp_lk /= 2;
            cmp_k /= 2;
        }
        if (cmp_k == 0)
            break;

        int l = 0;
        while (true) {
        	cmp_lk /= 3;
            if (cmp_lk == 0)
                break;
            l++;
        }
        answer = max(answer, max_leaf(k, l, dist_limit));
    }
    return answer;
}