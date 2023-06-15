#include <iostream>
#include <vector>
#include <stack>
using namespace std;
using ll = long long;

class CardMirrorChecker {
    private:
        vector<ll> card;
        stack<ll> possible;
        ll check = 1;

    public:
        explicit CardMirrorChecker(vector<ll> &cards) : card(cards) {}

        ll isMirror(ll k) {
            for (ll i = 0; i < k; i++) {
                if (card[(k - 1) - i] != card[k + i]) {
                    check = 0;
                    return 0;
                }
            }
            return 1;
        }

        ll push(ll &i) {
            ll val = card.size() - i;
            possible.push(val);
            return 0;
        }

        ll find() {
            for (ll i = 0; i < card.size(); i++) {
                if (isMirror(i)) {
                    push(i);
                }
            }
            return 0;
        }

        ll print() {
            while (!possible.empty()) {
                cout << possible.top() << " ";
                possible.pop();
            }
            return 0;
        }
};

int main() {
    ll N, M;
    cin >> N >> M;
    vector<ll> card(N);
    for (ll i = 0; i < N; i++) {
        cin >> card[i];
    }
    CardMirrorChecker mirror(card);
    mirror.find();
    mirror.print();
}
