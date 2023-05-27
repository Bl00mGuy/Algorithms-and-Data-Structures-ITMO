#include <iostream>
#include <vector>
using namespace std;
using ui = unsigned int;

size_t N = 0;
string song = "";

class SongAnalyzer {
public:
    static vector<ui> Prefix(string &str) {
        size_t size = str.length();
        vector<ui> pi(size, 0);
        for (ui i = 1; i < size; i++) {
            ui j = pi[i - 1];
            while (j > 0 and str[i] != str[j])
                j = pi[j - 1];
            if (str[i] == str[j])
                j++;
            pi[i] = j;
        }
        return pi;
    }
    static bool Primitive(string &str) {
        size_t size = str.length();
        vector<ui> prefix = Prefix(str);
        ui last = prefix[size - 1];
        return (size % (size - last) == 0 and last > 0);
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    cin >> N;
    cin >> song;
    cout << (SongAnalyzer::Primitive(song) ? "YES" : "NO");
    return 0;
}
