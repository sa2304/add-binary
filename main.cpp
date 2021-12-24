#include <cassert>
#include <iostream>
#include <string>
#include <string_view>

using namespace std;

struct Proxy {
  string_view s;
  size_t offset;

  char operator[](size_t pos) {
    int i = pos - offset;
    return (0 <= i) ? s[i] : '0';
  }
};

class Solution {
 public:
  string addBinary(string a, string b) {
    if (a.size() <= b.size()) {
      return _add(b, a);
    } else {
      return _add(a, b);
    }
  }

 private:
  string &_add(string &result, const string &arg) {
    Proxy parg{arg, result.size() - arg.size()};
    for (int i = result.size() - 1; 0 < i; --i) {
      if (_addWithCarry(result[i], parg[i])) {
        _incrementBit(result[i - 1]);
      }
    }
    if (_addWithCarry(result[0], parg[0])) {
      result.insert(0, 1, '1');
    }

    return result;
  }

  int _toInt(char c) {
    return c - 0x30;
  }

  char _fromInt(int val) {
    return val + 0x30;
  }

  void _incrementBit(char &c) {
    c = _fromInt(_toInt(c) + 1);
  }

  bool _addWithCarry(char &a, const char &b) {
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
