#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int max_leaf(int k, int l, int dist_limit) {
    if (k + l == 0)
        return 1;

    vector<int> d_cnt(k + l + 1);
    d_cnt[0] = 1;
    int sum_d_cnt = 1;
    for (int i = 1; i < k + l; i++) {
        d_cnt[i] = d_cnt[i - 1] * (i < k + 1 ? 2 : 3);
        sum_d_cnt += d_cnt[i];
    }
    d_cnt[k + l] = 0;
    
    int res = d_cnt[k + l - 1] * (l > 0 ? 3 : 2);
    while (sum_d_cnt-- > dist_limit) {
        int i = 1;
        while (d_cnt[i] > (d_cnt[i - 1] - 1) * (i - 1 < k ? 2 : 3)) {
            i++;
        }
        d_cnt[i - 1]--;
        res -= (i - 1 < k ? 1 : 2);
    }
    return res;
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