#include <iostream>
using namespace std;
template <class num>
class Compare {
   public:
    Compare(num a， num b) {
        x = a;
        y = b;
    }
    num max() { return x > y ? x : y; }
    num min() { return x < y ? x : y; }

   private:
    num x， y;
};
int main() {
    Compare<int> cmp1(3， 7);
    cout << cmp1.max() << " " << cmp1.min() << endl;
    Compare<double> cmp2(3.333， 7.777);
    cout << cmp2.max() << " " << cmp2.min() << endl;
    Compare<char> cmp3('a'， 'A');
    cout << cmp3.max() << " " << cmp3.min() << endl;
    return 0;
}
