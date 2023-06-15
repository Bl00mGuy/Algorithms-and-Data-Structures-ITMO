#include <iostream>
#include <vector>

using ll = long long;
using namespace std;

ll N, M, Q;

namespace Imagine {

    class Image {
    public:
        ll x1, y1, x2, y2;

        Image(ll x1, ll y1, ll x2, ll y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}
    };

    class PictureComparer {
    public:
        vector<vector<ll>> hash;
        vector<ll> arr;

        PictureComparer(vector<vector<ll>> hash, vector<ll> arr) : hash(hash), arr(arr) {}

        bool preCompare(const Image& picture1, const Image& picture2) {
            if (picture1.x2 - picture1.x1 != picture2.x2 - picture2.x1) {
                cout << "NO" << "\n";
                return false;
            }

            if (picture2.y2 - picture2.y1 != picture1.y2 - picture1.y1) {
                cout << "NO" << "\n";
                return false;
            }
            return true;
        }

        bool comparePictures(const Image& picture1, const Image& picture2) {

            if (!preCompare(picture1, picture2)) {
                return false;
            }

            ll tmp = (picture1.x2 - picture1.x1) + 1;
            for (ll i = 0; i < tmp; i++) {
                ll i_first = picture1.x1 + i - 1, left_first = picture1.y1 - 1, right_first = picture1.y2;
                ll i_second = picture2.x1 + i - 1, left_second = picture2.y1 - 1, right_second = picture2.y2;
                ll pic1_hash = (hash[i_first][right_first] - hash[i_first][left_first] * arr[right_first - left_first] % 1000000009 + 1000000009) % 1000000009;
                ll pic2_hash = (hash[i_second][right_second] - hash[i_second][left_second] * arr[right_second - left_second] % 1000000009 + 1000000009) % 1000000009;
                if (pic1_hash != pic2_hash) {
                    cout << "NO" << "\n";
                    return false;
                }
            }
            cout << "YES" << "\n";
            return true;
        }
    };
}

void readInput(vector<vector<ll>>& hash, vector<ll>& arr) {
    cin >> N >> M;

    hash.resize(N + 1, vector<ll>(M + 1));
    arr.resize(M + 1);
    arr[0] = 1;

    for (ll i = 1; i <= M; i++) {
        arr[i] = arr[i - 1] * 41 % 1000000009;
    }

    for (ll i = 0; i < N; i++) {
        for (size_t j = 0; j < M; j++) {
            ll input;
            cin >> input;
            hash[i][j + 1] = (hash[i][j] * 41 % 1000000009 + input) % 1000000009;
        }
    }

    cin >> Q;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    vector<vector<ll>> hash;
    vector<ll> arr;

    readInput(hash, arr);

    Imagine::PictureComparer comparer(hash, arr);

    for (ll i = 0; i < Q; i++) {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        Imagine::Image picture1(x1, y1, x2, y2);
        cin >> x1 >> y1 >> x2 >> y2;
        Imagine::Image picture2(x1, y1, x2, y2);
        comparer.comparePictures(picture1, picture2);
    }

    return 0;
}
