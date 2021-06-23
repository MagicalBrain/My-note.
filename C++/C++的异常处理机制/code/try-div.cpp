#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    //if (m == 0)
    //    throw runtime_error("除数不能为0.");
    //cout << n / m << endl;
    while (cin >> n >> m) {
        try
        {
            if (m == 0)
                throw runtime_error("除数不能为0.");
            cout << n / m << endl;
        }
        catch(runtime_error e)
        {
            std::cerr << e.what() << '\n';
            cout << "Try Again? Enter y or n" << endl;
            char c;
            cin >> c;
            if (!cin || c == 'n')
                break;
        }
    }
    return 0;
}