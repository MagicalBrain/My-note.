#include <iostream>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	if (a != b)
		cerr << "Data must refer to same value." << endl;
	return 0;
}
