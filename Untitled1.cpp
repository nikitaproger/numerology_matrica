#include <iostream>
#include <clocale>
#include <string>
#include <algorithm> // дл€ std::reverse
using namespace std;
struct data {
    string a;
    string b;
    string c;
};
struct otvet {
    int ych1 = 0;
    int ych2 = 0;
    int ych3 = 0;
    int ych4 = 0;
    int ych5 = 0;
    int ych6 = 0;
    int ych7 = 0;
    int ych8 = 0;
    int ych9 = 0;
};
std::string to_string(int number) {
    if (number == 0) {
        return "0"; // —пециальный случай дл€ нул€
    }
    std::string result;
    int temp = std::abs(number);
    while (temp > 0) {
        result += static_cast<char>('0' + temp % 10); // ƒобавл€ем цифру
        temp /= 10;
    }
    std::reverse(result.begin(), result.end());
    if (number < 0) {
        result = "-" + result;
    }
    return result;
}
data par_dat(string s) {
    data result;
    result.a = s.substr(0, 2);
    result.b = s.substr(3, 2);
    result.c = s.substr(6, 4);
    return result;
}
otvet podchet(string a, string b, string c) {
    otvet ota;
    int p1 = 0, p2 = 0, p3 = 0, num1, num2, num3, pr, num4;
    string nummatr = "";
    for (int i = 0; i < a.length(); i++) {
        p1 += a[i] - '0';
    }
    for (int i = 0; i < b.length(); i++) {
        p2 += b[i] - '0';
    }
    for (int i = 0; i < c.length(); i++) {
        p3 += c[i] - '0';
    }
    num1 = p1 + p2 + p3;
    num2 = (num1 / 10) + (num1 % 10);
    if (a[0] != '0') {
        pr = a[0] - '0';
    } else {
        pr = a[1] - '0';
    }
    num3 = num1 - 2 * pr;
    num4 = (num3 / 10) + (num3 % 10);
    nummatr = a + b + c + to_string(num1) + to_string(num2) + to_string(num3) + to_string(num4);
    for (int i = 0; i < nummatr.length(); i++) {
        char digit = nummatr[i];
        if (digit == '1') ota.ych1++;
        if (digit == '2') ota.ych2++;
        if (digit == '3') ota.ych3++;
        if (digit == '4') ota.ych4++;
        if (digit == '5') ota.ych5++;
        if (digit == '6') ota.ych6++;
        if (digit == '7') ota.ych7++;
        if (digit == '8') ota.ych8++;
        if (digit == '9') ota.ych9++;
    }
    return ota;
}
int main() {
    setlocale(LC_ALL, "Russian");
    string s;
    data c;
    otvet it;
    cout << "¬ведите полную дату рождени€, вводить числа через точку вот так (XX.XX.XXXX): ";
    cin >> s;
    c = par_dat(s);
    cout << "¬аша дата рождени€: " << c.a << "." << c.b << "." << c.c << endl;
    it = podchet(c.a, c.b, c.c);
    cout << "–езультаты нумерологической матрицы:" << endl;
    cout << "1 (характер) Ч волевые качества, целеустремлЄнность, внутренний стержень: " << it.ych1 << endl;
    cout << "2 (энерги€) Ч энергетический запас, выносливость, способность к общению: " << it.ych2 << endl;
    cout << "3 (интерес) Ч любознательность, практичность, житейска€ смекалка: " << it.ych3 << endl;
    cout << "4 (здоровье) Ч физическа€ выносливость, организованность, устойчивость психики: " << it.ych4 << endl;
    cout << "5 (логика) Ч логика, интуици€, умение планировать и доносить мысли: " << it.ych5 << endl;
    cout << "6 (труд) Ч трудоспособность, мастерство, способность реализовывать идеи: " << it.ych6 << endl;
    cout << "7 (талант) Ч творческие способности, удача, везение: " << it.ych7 << endl;
    cout << "8 (ответственность) Ч чувство долга, способность преодолевать трудности: " << it.ych8 << endl;
    cout << "9 (ум) Ч интеллект, пам€ть, аналитические способности: " << it.ych9 << endl;
    cout << "количество цифр в €чейце опказывает выраженость качества:";
    cout << "0 - отсутствует или нестабильно ";
    cout << "1 - слабое про€вление";
    cout << "2 - норма ";
    cout << "3 - нестабильность ( может резко мен€тьс€)";
    cout << "4+ - сильное про€вление";
    return 0;
}
