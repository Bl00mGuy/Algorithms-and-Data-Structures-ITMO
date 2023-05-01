#include <iostream>
#include <string>
#include <vector>
using namespace std;

void parseString(const string &str, vector<char> &chars, vector<int> &numbers) {
    int i = 0;
    while (i < str.size()) {
        if (isdigit(str[i])) {
            int num = 0;
            while (i < str.size() && isdigit(str[i])) {
                num = num * 10 + (str[i] - '0');
                ++i;
            }
            numbers.push_back(num);
        } else {
            chars.push_back(str[i]);
            ++i;
        }
    }
}

int counter(int k, vector<char> &chars1, vector<int> &numbers1, vector<char> &chars2, vector<int> &numbers2) {
    int i = 0, j = 0;
    while (i < chars1.size() and j < chars2.size()) {
        if (chars1[i] == chars2[j]) {
            if (numbers1[i] == numbers2[j]) {
                i += 1;
                j += 1;
            }
            else if (numbers1[i] < numbers2[j]) {
                numbers2[j] = numbers2[j] - numbers1[i];
                i += 1;
            } else {
                numbers1[i] = numbers1[i] - numbers2[j];
                j += 1;
            }
        } else {
            if (numbers1[i] == numbers2[j]) {
                k = k - numbers2[j];
                j += 1;
            } else if (numbers1[i] < numbers2[j]) {
                numbers2[j] = numbers2[j] - numbers1[i];
                k = k - numbers1[i];
                i += 1;
            } else {
                numbers1[i] = numbers1[i] - numbers2[j];
                k = k - numbers2[j];
                j += 1;
            }
        }
    }
    return k;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 0, m = 0, k = 0;
    string message1 = "", message2 = "";

    cin >> n >> m >> k;
    cin >> message1;
    cin >> message2;

    // 2 vectors for message1
    vector<char> chars1;
    vector<int> numbers1;

    // 2 vectors for message2
    vector<char> chars2;
    vector<int> numbers2;

    parseString(message1, chars1, numbers1);
    parseString(message2, chars2, numbers2);

    k = counter(k, chars1, numbers1, chars2, numbers2);

    cout << ((k < 0)? "No" : "Yes");
    return 0;
}
