#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int mySqrt(int x) {
    return std::abs(1.0 / Q_rsqrt(x));
  }

 private:
  /** Fast Inverse Square Root as implemented in Quake III Arena
   *
   * https://archive.softwareheritage.org/browse/content/sha1_git:bb0faf6919fc60636b2696f32ec9b3c2adb247fe/?origin_url=https://github.com/id-Software/Quake-III-Arena&path=code/game/q_math.c&revision=dbe4ddb10315479fc00086f08e25d968b4b43c49&snapshot=4ab9bcef131aaf449a7c01370aff8c91dcecbf5f
   * @param number
   * @return
   */
  float Q_rsqrt( float number ) {
    long i;
    float x2, y;
    const float threehalfs = 1.5F;

    x2 = number * 0.5F;
    y  = number;
    i  = * ( long * ) &y;						// evil floating point bit level hacking
    i  = 0x5f3759df - ( i >> 1 );               // what the fuck?
    y  = * ( float * ) &i;
    y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration
//	y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed

    return y;
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
