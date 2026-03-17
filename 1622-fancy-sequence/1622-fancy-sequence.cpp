#include <vector>

class Fancy {
private:
    static const long long MOD = 1e9 + 7;

    std::vector<long long> arr;
    long long a = 1;
    long long b = 0;

    long long modPow(long long x, long long n) {
        long long res = 1;
        while (n) {
            if (n & 1) res = res * x % MOD;
            x = x * x % MOD;
            n >>= 1;
        }
        return res;
    }

public:
    Fancy() {}

    void append(int val) {
        long long v = (val - b) % MOD;
        if (v < 0) v += MOD;

        long long invA = modPow(a, MOD - 2);
        v = v * invA % MOD;

        arr.push_back(v);
    }

    void addAll(int inc) {
        b = (b + inc) % MOD;
    }

    void multAll(int m) {
        a = a * m % MOD;
        b = b * m % MOD;
    }

    int getIndex(int idx) {
        if (idx >= arr.size()) return -1;

        long long val = (a * arr[idx] + b) % MOD;
        return static_cast<int>(val);
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */