#include <cassert>
#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  string addBinary(string a, string b) {
    // FIXME
    return {};
  }
};

void TestAddBinary() {
  Solution s;
  {
    string a{"11"s}, b{"1"s};
    assert("100"s == s.addBinary(a, b));
  }
  {
    string a{"1010"s}, b{"1011"s};
    assert("10101"s == s.addBinary(a, b));
  }
//  {
//    string a{""s}, b{""s};
//    assert(""s == s.addBinary(a, b));
//  }
}

int main() {
  TestAddBinary();
  std::cout << "Ok!" << std::endl;
  return 0;
}
