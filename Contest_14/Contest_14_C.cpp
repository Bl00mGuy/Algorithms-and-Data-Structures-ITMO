#include <iostream>
#include <string>
#include <vector>

using ll = long long;

namespace Solution {
    template<typename T>
    class Counter {
        private:
            T count;
        public:
            Counter() : count(0) {}

            void increment() {
                count++;
            }
            T getCount() const {
                return count;
            }
    };

    class WordComparer {
        private:
            std::string str;
        public:
            WordComparer(const std::string &str) : str(str) {}

            bool compareWords(ll a, ll b, ll length) const {
                std::string word1 = str.substr(a - 1, length);
                std::string word2 = str.substr(b - 1, length);
                return (word1 == word2);
            }
    };

    template<typename T>
    void count(ll m, Counter<T> &counter, const std::string &str) {
        WordComparer comparer(str);

        for (ll i = 0; i < m; i++) {
            ll a, b, c;
            std::cin >> a >> b >> c;
            if (comparer.compareWords(a, b, c)) {
                counter.increment();
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    ll N, M;
    std::cin >> N >> M;
    std::string str;
    std::cin >> str;
    Solution::Counter<ll> counter;
    Solution::count(M, counter, str);
    std::cout << counter.getCount() << "\n";
    return 0;
}
