#include <iostream>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	if (a != b)
		throw runtime_error("Data must refer to same value");
	cout << a + b << endl;
	return 0;
}
