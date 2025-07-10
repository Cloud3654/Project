#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;

string generateNumber(int length) {
    vector<int> digits = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    mt19937 rng(static_cast<unsigned int>(time(0)));
    shuffle(digits.begin(), digits.end(), rng);
    string result = "";
    for (int i = 0; i < length; i++) {
        result += to_string(digits[i]);
    }
    return result;
}

int main() {
    int length; cin >> length;
    if (length < 1 || length > 10) {
    	cout << "Invailed Length";
    	exit(0);
    }
    string answer = generateNumber(length);
    string input;
    while (true) {
    	cin >> input;
    	for (int i = 0; i < length; i++) {
    		int pos = answer.find(input[i]);
    		if (pos == string::npos) cout << 'O';
    		else if (pos == i) cout << 'S';
    		else cout << 'B';
    	}
    	if (input == answer) {
    		cout << "\nCorrect!\n";
    		break;
    	}
    	cout << endl;
    }
}
