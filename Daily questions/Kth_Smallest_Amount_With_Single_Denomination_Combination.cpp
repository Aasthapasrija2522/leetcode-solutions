class Solution {
public:
    using int64 = long long;
    using i128 = __int128_t;

    long long gcdll(long long a, long long b) {
        while (b) {
            long long t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    long long lcmLimit(long long a, long long b, long long limit) {
        long long g = gcdll(a, b);
        i128 t = (i128)(a / g) * b;
        if (t > limit) return limit + 1;
        return (long long)t;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        sort(coins.begin(), coins.end());

        // Remove redundant coins.
        vector<long long> c;
        for (int x : coins) {
            bool ok = true;
            for (long long y : c) {
                if (x % y == 0) {
                    ok = false;
                    break;
                }
            }
            if (ok) c.push_back(x);
        }

        int m = c.size();

        auto count = [&](long long x) {
            long long ans = 0;
            int total = 1 << m;

            for (int mask = 1; mask < total; mask++) {
                long long L = 1;
                bool bad = false;

                for (int i = 0; i < m; i++) {
                    if (mask & (1 << i)) {
                        L = lcmLimit(L, c[i], x);
                        if (L > x) {
                            bad = true;
                            break;
                        }
                    }
                }

                if (bad) continue;

                if (__builtin_popcount(mask) & 1)
                    ans += x / L;
                else
                    ans -= x / L;
            }

            return ans;
        };

        long long lo = 1, hi = 1e18;

        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (count(mid) >= k)
                hi = mid;
            else
                lo = mid + 1;
        }

        return lo;
    }
};