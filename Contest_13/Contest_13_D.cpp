#include <iostream>
#include <vector>
#define ll long long
#define i32 int
#define in cin
#define out cout
#define INFINITY 1000000
using namespace std;

template<typename T>
class Hash {
    private:
        vector<T> hash;
        vector<T> count;

    public:
        T N, output = 0, summ = 0;
        Hash(const T &N) : N(N), hash(N), count(INFINITY * 2 + 1, 0) {}

        i32 solve() {
            for (T i = 0; i < N; i++) {
                summ = i - hash[i] + INFINITY;
                output += count[summ];
                count[summ]++;
            }
            return 0;
        }

        i32 vvod() {
            for (T i = 0; i < N; i++) {
                in >> hash[i];
            }
            return 0;
        }
};

i32 main() {
    ll N;
    in >> N;
    Hash<ll> hash(N);
    hash.vvod();
    hash.solve();
    out << hash.output;
    return 0;
}
