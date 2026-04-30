#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<int> arr, long long l, long long r) {
    const long long len = r - l + 1;
    
    long long S0 = 0;
    int j_lo = 1, j_hi = 1;
    int c_lo = 1, c_hi;
    for (long long acc = 0; j_hi - 1 < arr.size(); j_hi++) {
        long long e = arr[j_hi - 1];
        if (acc + e >= len) {
            c_hi = len - acc + 1;
            S0 += e * (c_hi - 1);
            break;
        }
        acc += e;
        S0 += e * e;
    }
    
    // pair of (d, cnt)
    vector<pair<int, int>> intervals;
    
    while (j_hi - 1 < arr.size()) {
        int x_lo = arr[j_lo - 1] - c_lo + 1;
        int x_hi = arr[j_hi - 1] - c_hi + 1;
        
        int d = arr[j_hi - 1] - arr[j_lo - 1];
        int advance = min(x_lo, x_hi);
        intervals.push_back({d, advance});

        c_hi += advance;
        c_lo += advance;
        if (x_lo <= x_hi) {
            j_lo++;
            c_lo = 1;
        }
        if (x_lo >= x_hi) {
            j_hi++;
            c_hi = 1;
        }
    }
    intervals.push_back({0, 1});
    
    long long K = S0, C = 0;
    for (long long acc = 0; auto [d, cnt] : intervals) {
        if (acc + cnt >= l) {
            K += d * (l - acc - 1);
            break;
        }
        acc += cnt;
        K += static_cast<long long>(d) * cnt;
    }
    for (long long S = S0; auto [d, cnt] : intervals) {
        if (d == 0) {
            if (K == S) {
                C += cnt;
            }
        }
        else {
            if ((K - S) % d == 0 && (K - S) / d >= 0 && (K - S) / d < cnt) {
                C++;
            }
        }
        S += static_cast<long long>(d) * cnt;
    }
    
    return {K, C};
}