#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int mySqrt(int x) {
    int res = 1;
    int base = 1;
    while (res < x) {
      ++base;
      res = base * base;
    }
    return (x == res) ? base : base - 1;
  }
};

void TestMySqrt() {
  Solution s;
  assert(2 == s.mySqrt(4));
  assert(2 == s.mySqrt(8));
//  assert( == s.mySqrt());
//  assert( == s.mySqrt());
//  assert( == s.mySqrt());
}

int main() {
  TestMySqrt();
  std::cout << "Ok!" << std::endl;
  return 0;
}
