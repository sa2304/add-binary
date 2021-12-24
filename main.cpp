#include <cassert>
#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  string addBinary(string a, string b) {
    int l = std::max(a.size(), b.size());
    a.insert(0, l - a.size(), '0');
    b.insert(0, l - b.size(), '0');
    for (int i = l - 1; 0 < i; --i) {
      if (_addWithCarry(a[i], b[i])) {
        _incrementBit(a[i-1]);
      }
    }
    if (_addWithCarry(a.front(), b.front())) {
      a.insert(0, 1, '1');
    }

    return a;
  }

 private:
  int _toInt(char c) {
    return c - 0x30;
  }

  char _fromInt(int val) {
    return val + 0x30;
  }

  void _incrementBit(char& c) {
    c = _fromInt(_toInt(c) + 1);
  }

  bool _addWithCarry(char& a, const char& b) {
    int val = _toInt(a) + _toInt(b);
    bool carry = false;
    if (1 < val) {
      val %= 2;
      carry = true;
    }
    a = _fromInt(val);

    return carry;
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
