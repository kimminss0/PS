#include <string>
#include <vector>
#include <tuple>

using namespace std;

vector<long long> solution(vector<int> arr, long long l, long long r) {
    long long len = r - l + 1;
    
    long long S = 0;
    long long i_lo = 1, i_hi = len + 1;
    int j_lo = 1, j_hi = 1;
    int c_lo = 1, c_hi;
    for (long long acc = 0; j_hi - 1 < arr.size(); j_hi++) {
        long long e = arr[j_hi - 1];
        if (acc + e > i_hi - 1) {
            c_hi = i_hi - acc;
            S += e * (c_hi - 1);
            break;
        }
        acc += e;
        S += e * e;
    }
    
    // tuple of (S, d, cnt)
    vector<tuple<long long, int, int>> intervals;
    
    while (j_hi - 1 < arr.size()) {
        int x_lo = arr[j_lo - 1] - c_lo + 1;
        int x_hi = arr[j_hi - 1] - c_hi + 1;
        
        int d = arr[j_hi - 1] - arr[j_lo - 1];
        int advance;
        if (x_lo < x_hi) {
            // touch left
            advance = x_lo;
            j_lo++;
            c_lo = 1;
            c_hi += x_lo;
        } else if (x_lo > x_hi) {
            // touch right
            advance = x_hi;
            j_hi++;
            c_lo += x_hi;
            c_hi = 1;
        } else {
            // touch both
            advance = x_hi;
            j_lo++;
            j_hi++;
            c_lo = 1;
            c_hi = 1;
        }

        intervals.push_back({S, d, advance});
        S += static_cast<long long>(d) * advance;
        i_lo += advance;
        i_hi += advance;
    }
    intervals.push_back({S, 0, 1});
    
    long long K, C = 0;
    for (long long acc = 0; auto [S, d, cnt] : intervals) {
        if (acc + cnt >= l) {
            K = S + d * (l - acc - 1);
            break;
        }
        acc += cnt;
    }
    for (auto [S, d, cnt] : intervals) {
        if (d == 0) {
            if (K == S) {
                C += cnt;
            }
            continue;
        }
        if ((K - S) % d == 0 && (K - S) / d >= 0 && (K - S) / d < cnt) {
            C++;
        }
    }
    
    return {K, C};
}