#include <bits/stdc++.h>
using namespace std;

typedef unsigned int uint32;

enum PaddingType { LEFT, RIGHT };

string padString(const string& toPad, size_t paddingCountToAdd, char paddingChar, PaddingType paddingType = RIGHT) {
    string s(paddingCountToAdd, paddingChar);
    return paddingType == LEFT ? s + toPad : toPad + s;
}

bool isZero(const string& oper) {
    for (size_t i = 0, l = oper.size(); i < l; i++)
        if (oper[i] != '0') return false;
    return true;
}

string sumIntStrings(const string& op1, const string& op2) {
    if (op2 == "") return op1;
    if (op1 == "") return op2;
    string total = "";
    size_t op1Size = op1.size();
    size_t op2Size = op2.size();
    size_t m = max(op1Size, op2Size);

    uint32 carry = 0;
    for (int i = 0; i < static_cast<int>(m); i++) {
        uint32 c0 = i < op1Size ? op1[op1Size - 1 - i] - '0' : 0;
        uint32 c1 = i < op2Size ? op2[op2Size - 1 - i] - '0' : 0;
        uint32 c = c0 + c1 + carry;
        carry = c / 10;
        total += (c % 10) + '0';
    }
    if (carry) total += carry + '0';
    reverse(total.begin(), total.end());
    return total;
}

string removeLeftZeros(const string& value) {
    // Delete '0's from the left
    if (value.size() > 1 && value[0] == '0') {
        for (size_t i = 0, l = value.size(); i < l; i++) {
            if (value[i] == '0')
                continue;
            return value.substr(i, l - i);
        }
    }
    return value;
}

string subIntStrings(const string& op1, const string& op2) {
    if (op2 == "") return op1;

    string total = "";
    size_t op1Size = op1.size();
    size_t op2Size = op2.size();

    uint32 carry = 0;
    for (int i = 0; i < op1Size; i++) {
        int c0 = op1[op1Size - 1 - i] - '0' - carry;
        int c1 = i < op2Size ? op2[op2Size - 1 - i] - '0' : 0;
        carry = 0;
        if (c0 < c1) {
            carry = 1;
            c0 += 10;
        }
        total += (c0 - c1) + '0';
    }
    reverse(total.begin(), total.end());
    return isZero(total) ? "0" : removeLeftZeros(total);
}

string mulIntStringByChar(const string& op1, const char op2) {
    if (op2 == '0') return "0";
    if (op2 == '1') return op1;

    int carry = 0;
    int d0 = op2 - '0';
    string r = "";
    for (int j = op1.size() - 1; j >= 0; j--) {
        int d1 = op1[j] - '0';
        int d = (d0 * d1) + carry;
        carry = d / 10;
        d %= 10;
        r += d + '0';
    }
    if (carry) r += carry + '0';
    reverse(r.begin(), r.end());
    return r;
}

string multKaratsuba(const string& oper1, const string& oper2) {
    // 2 * O(n)
    if (isZero(oper1) || isZero(oper2)) {
        return "0";
    }

    // 2 * O(n)
    string op1 = removeLeftZeros(oper1);
    string op2 = removeLeftZeros(oper2);

    // O(1) (theoritically)
    size_t l1 = op1.size();
    size_t l2 = op2.size();

    if (l1 == 1 || l2 == 1)
        // O(1)
        return mulIntStringByChar(l1 == 1 ? op2 : op1, l1 == 1 ? op1[0] : op2[0]);

    // Divide
    size_t n = max(l1, l2);
    n += (n & 1);

    // 2 * O(n)
    op1 = padString(op1, n - l1, '0', LEFT);
    op2 = padString(op2, n - l2, '0', LEFT);

    size_t n2 = n / 2;

    // 4 * O(n)
    string a = op1.substr(0, n2);
    string b = op1.substr(n2, n2);
    string c = op2.substr(0, n2);
    string d = op2.substr(n2, n2);

    // 2 recursive calls
    string ac = multKaratsuba(a, c);
    string bd = multKaratsuba(b, d);

    // 2 * O(n)
    string _ab = sumIntStrings(a, b);
    string _cd = sumIntStrings(c, d);

    // another call
    string abcd = multKaratsuba(_ab, _cd);

    // 2 * O(n)
    abcd = subIntStrings(abcd, ac);
    abcd = subIntStrings(abcd, bd);

    // 5 * O(n)
    ac = padString(ac, n, '0', RIGHT);
    abcd = padString(abcd, n2, '0', RIGHT);
    string res = sumIntStrings(ac, abcd);
    res = sumIntStrings(res, bd);
    return removeLeftZeros(res);
}

int main(int argc, char** argv) {
    string a, b;
    cin >> a >> b;
    cout << multKaratsuba(a, b) << endl;
    return 0;
}
