#include <iostream>
#include <vector>
#include <string>
using namespace std;

void sift_down(vector<int>&arr, int i) {
    int left, right, j;
    while (2 * i + 1 < arr.size()) {
        left = 2 * i + 1;
        right = 2 * i + 2;
        j = left;
        if (right < arr.size() && arr[right] < arr[left]) {
            j = right;
        }
        if (arr[i] <= arr[j]) {
            break;
        }
        swap(arr[i], arr[j]);
        i = j;
    }
}

void sift_up(vector<int>&arr ,int i){
    while (arr[i] < arr[(i - 1) / 2]){
        swap(arr[i], arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void decrease_key(vector<int>&arr, int key, int numb) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == key){
            arr[i] = numb;
            sift_up(arr, i);
            break;
        }
    }
}

void extreact_min(vector<int>&arr){
    if (arr.size() == 0){
        cout << '*' << "\n";
    }
    else {
        cout << arr[0] << "\n";
        swap(arr[0], arr[arr.size() - 1]);
        arr.pop_back();
        sift_down(arr, 0);
    }
}

int main(){
    int x, y;
    int number;
    vector<int>arr, arr_key;
    string cmd;
    while(cin >> cmd){
        if (cmd == "extract-min"){
            extreact_min(arr);
            arr_key.push_back(1000001);
        }
        if (cmd == "push"){
            cin >> number;
            arr.push_back(number);
            arr_key.push_back(number);
            sift_up(arr, arr.size()-1);
        }
        if (cmd == "decrease-key"){
            cin >> x >> y;
            decrease_key(arr, arr_key[x-1], y);
            arr_key[x-1] = y;
            arr_key.push_back(1000001);
        }
    }
    return 0;
}
