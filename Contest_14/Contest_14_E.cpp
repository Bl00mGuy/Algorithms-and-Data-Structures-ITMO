#include <iostream>
#include <regex>
#include <vector>

#define check_name "[A-Z][a-z]*"
#define check_city "g\\.[A-Z]{3},"
#define check_address "ul\\.[A-Z][a-z]*,"
#define check_department "d\\.[0-9]+"

#define check_phone1 "^\\+7\\(([0-9]{3})\\)-([0-9]{3})-([0-9]{2})-([0-9]{2})$"
#define check_phone2 "^\\+7([0-9]{10})$"
#define check_phone3 "^\\+7\\(([0-9]{3})\\)([0-9]{3})-([0-9]{4})$"

using namespace std;
using ll = long long;
std::vector<std::string> checker_phones(11*5, "+");

bool checkName(const string &s) {
    regex regular(check_name);
    return regex_match(s, regular);
}

bool checkNumber(const string &s) {
    if (s.length() == 2) {
        if (isdigit(s[0]) and isdigit(s[1])) {
            return true;
        }
    }
    return false;
}

bool checkPhoneNumber(const string &s) {
    regex first_regular(check_phone1);
    regex second_regular(check_phone2);
    regex third_regular(check_phone3);
    return regex_match(s, first_regular) or regex_match(s, second_regular) or regex_match(s, third_regular);
}

bool checkCity(const string &s) {
    regex regular(check_city);
    return regex_match(s, regular);
}

bool checkAddress(const string &s) {
    regex regular(check_address);
    return regex_match(s, regular);
}

bool checkDepartment(const string &s) {
    regex regular(check_department);
    return regex_match(s, regular);
}

void checks(const string &s, ll choice, bool &flag) {
    switch (choice) {
        case 0:
        case 1:
        case 2:
            flag = checkName(s);
            break;
        case 3:
            flag = checkNumber(s);
            break;
        case 4:
            if (s[0] == '+' and s[1] != '7') {
                flag = false;
            } else if (s[0] == '+') {
                string number = s;
                number.erase(remove(number.begin(), number.end(), '('), number.end());
                number.erase(remove(number.begin(), number.end(), ')'), number.end());
                number.erase(remove(number.begin(), number.end(), '-'), number.end());
                flag = checkPhoneNumber(number);
            }
            break;
        case 5:
            flag = checkCity(s);
            break;
        case 6:
            flag = checkAddress(s);
            break;
        case 7:
            flag = checkDepartment(s);
            break;
        default:
            flag = false;
            break;
    }
}

int main() {
    ll N;
    cin >> N;
    for (ll k = 0; k < N; k++) {
        char symbol;
        cin >> symbol;
        string input;
        getline(cin, input);
        input = symbol + input;
        vector<string> checker(8, "FAIL");
        string tmp;
        ll t = 0;
        for (char L: input) {
            if (!isspace(L)) {
                tmp += L;
            }
            if (isspace(L)) {
                checker[t] = tmp;
                t++;
                tmp.clear();
            }
        }
        checker[t] = tmp;
        bool check = true;
        for (const string &S: checker) {
            if (S == "FAIL") {
                check = false;
                break;
            }
        }
        if (!check) {
            cout << "NO" << '\n';
            continue;
        }
        for (ll i = 0; i < 8; i++) {
            string s = checker[i];
            bool flag = true;
            checks(s, i, flag);
            if (!flag) {
                check = false;
                break;
            }
        }
        if (check) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}
