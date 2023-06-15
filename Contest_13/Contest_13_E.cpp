#include <iostream>
#include <vector>
#include <string.h>
#define ll long long
#define vvs std::vector<std::vector<std::string>>

ll N;
bool check_access = true;
std::vector<bool> check_collision(1e4, false);

namespace HashTables {
    ll HASH_1(std::string &str, ll crusher) {
        ll hashValue = 0;
        ll prime = 521;
        for (char ch: str) {
            hashValue = (hashValue * prime + ch) % crusher;
        }
        return hashValue;
    }

    ll HASH_2(std::string &str, ll crusher) {
        ll hashValue = 0;
        ll prime = 523;
        for (char ch: str) {
            hashValue = (hashValue * prime + ch) % crusher;
        }
        return hashValue;
    }

    bool areSolutionsEqual(std::string &solution1, std::string &solution2) {
        return solution1 == solution2;
    }

    class HashTable {
    private:
        ll counter;
        std::vector<std::pair<ll, std::string>> table;
        ll limit;

    public:
        HashTable(ll size, ll limit) : table(size), counter(0), limit(limit) {}

        void swap_s(std::string &s1, std::string &s2) {
            std::string tmp = s1;
            s1 = s2;
            s2 = tmp;
        }

        void swap_i(ll &s1, ll &s2) {
            ll tmp = s1;
            s1 = s2;
            s2 = tmp;
        }

        void push(std::string key, ll crusher) {
            counter += 1;
            bool check = true;
            for (ll i = 0; i < limit; i++) {
                ll h1 = HASH_1(key, crusher), h2 = HASH_2(key, crusher);
                if (table[h1].first == 0 and table[h1].second.empty()) {
                    table[h1].first = h1;
                    table[h1].second = key;
                    break;
                }
                if (table[h2].first == 0 and table[h2].second.empty()) {
                    table[h2].first = h2;
                    table[h2].second = key;
                    break;
                }
                ll h;
                if (check == true) {
                    h = h1;
                } else if (check == false) {
                    h = h2;
                }
                swap_i(h1, table[h].first);
                swap_s(key, table[h].second);
                check_collision.push_back(false);
                check = false;
            }
        }

        void del_case_1(std::vector<std::pair<ll, std::string>>& table, ll &h1) {
            table[h1].first = 0;
            table[h1].second = "";
            counter--;
        }

        void del_case_2(std::vector<std::pair<ll, std::string>>& table, ll &h2) {
            table[h2].first = 0;
            table[h2].second = "";
            counter--;
        }

        void del(std::string key) {
            ll h1 = HASH_1(key, table.size()), h2 = HASH_2(key, table.size());
            if (table[h1].second == key) {
                del_case_1(table, h1);
            } else if (table[h2].second == key) {
                del_case_2(table, h2);
            }
        }

        ll search(std::string key) {
            ll h1 = HASH_1(key, table.size()), h2 = HASH_2(key, table.size());
            if (table[h1].first == h1 and table[h1].second == key) {
                return true;
            }
            if (table[h2].first == h2 and table[h2].second == key) {
                return true;
            }
            return false;
        }
    };
}

vvs getInputData() {
    std::cin >> N;
    vvs mass(3, std::vector<std::string>(N));
    std::string str;
    for (ll i = 0; i < 3; i++) {
        for (ll j = 0; j < N; j++) {
            std::cin >> str;
            mass[i][j] = str;
        }
    }
    return mass;
}

std::vector<ll> count_balls(vvs &mass) {
    HashTables::HashTable first_table(N * 15, 2);
    HashTables::HashTable second_table(N * 15, 2);
    std::vector<ll> balls(3);
    ll crusher = N * 15;

    for (ll i = 0; i < N; i++) {
        first_table.push(mass[0][i], crusher);
        second_table.push(mass[1][i], crusher);
    }
    for (ll i = 0; i < N; i++) {
        if (!second_table.search(mass[2][i]) and !first_table.search(mass[2][i])) {
            balls[2] += 3;
        } else if (!second_table.search(mass[2][i]) || !first_table.search(mass[2][i])) {
            if ((!second_table.search(mass[2][i]) and first_table.search(mass[2][i])) || (second_table.search(mass[2][i]) and !first_table.search(mass[2][i]))) {
                balls[2] += 1;
            }
        }
    }
    for (ll i = 0; i < N; i++) {
        second_table.del(mass[1][i]);
    }
    for (ll i = 0; i < N; i++) {
        second_table.push(mass[2][i], crusher);
    }
    for (ll i = 0; i < N; i++) {
        if (!second_table.search(mass[1][i]) and !first_table.search(mass[1][i])) {
            balls[1] += 3;
        } else if (!second_table.search(mass[1][i]) || !first_table.search(mass[1][i])) {
            if ((!second_table.search(mass[1][i]) and first_table.search(mass[1][i])) || (second_table.search(mass[1][i]) and !first_table.search(mass[1][i]))) {
                balls[1] += 1;
            }
        }
    }
    for (ll i = 0; i < N; i++) {
        second_table.del(mass[2][i]);
        first_table.del(mass[0][i]);
    }
    for (ll i = 0; i < N; i++) {
        first_table.push(mass[1][i], crusher);
        second_table.push(mass[2][i], crusher);
    }
    for (ll i = 0; i < N; i++) {
        if (!second_table.search(mass[0][i]) and !first_table.search(mass[0][i])) {
            balls[0] += 3;
        } else if (!second_table.search(mass[0][i]) || !first_table.search(mass[0][i])) {
            if ((!second_table.search(mass[0][i]) and first_table.search(mass[0][i])) || (second_table.search(mass[0][i]) and !first_table.search(mass[0][i]))) {
                balls[0] += 1;
            }
        }
    }
    return balls;
}

void result(std::vector<ll> &balls) {
    std::cout << balls[0] << " " << balls[1] << " " << balls[2];
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    vvs mass = getInputData();
    std::vector<ll> balls = count_balls(mass);
    result(balls);
    return 0;
}
