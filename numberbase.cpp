#include <iostream>
using namespace std;
struct NUM {
    vector<int> nums(10);
};
vector<NUM> digits(5);
void init() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j <= 9; j++) {
            digits[i].nums[j] = j;
        }
    }
}
bool compare1(pair<int, int> a, pair<int, int> b) { return a.first > b.first; }
int choose() {
    vector<pair<int, int>> length_pos;
    for (int i = 0; i < 5; i++) length_pos = { digits[i].nums.size(), i };
}
void del() {
    
}
int main() {
    cout << "Initializing..." << endl;
    init();
    string cor;
    while (cor != "sssss") {
        
    }
}
