//16 задач на указатели
//1 task
#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;
int myStrlen(const char* str) {
    int k = 0;
    while (str[k] != '\0') {
        k++;
    }
    return k;
}
int main() {
    const char* k = "hello, world";
    cout << "length: " << myStrlen(k);
    return 0;
}

//2 task
#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;
void myStrCopy(char* dest, const char* src) {
    int k = 0;
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}
int main() {
    char k[] = "hello, world";
    char l[20];
    myStrCopy(l,k);
    cout << "result: "<< l;
    return 0;
}

//3 task
#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;
void myStrCopy(char* dest, const char* src) {
    int k = 0;
    while (*dest != '\0') {
        dest++;
    }
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}
int main() {
    char k[50] = "hello, world";
    char l[]=". Hi!";
    myStrCopy(k, l);
    cout << "result: " << k;
    return 0;
}

//4 task
#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;
int myStrCopy(char* dest, char s) {
   int k = 0;
   while (*dest != '\0') {
       if (*dest == s) {
           k++;
       }
       dest++;
   }
       return k;
   }
int main() {
    char m[50];
    char l;
    cout << "type string: ";
    cin.getline(m, 50);
    cout << "type symbol: ";
    cin >> l;
    cout << "result: " << myStrCopy(m, l);
    return 0;
}

//5 task
#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;
void myStrCopy(char* dest) {
    while (*dest != '\0') {
        if (*dest == ' ') {
            *dest='_';
        }
        dest++;
    }
}
int main() {
    char m[50];
    cout << "type string: ";
    cin.getline(m, 50);
    myStrCopy(m);
    cout << "result: " <<m;
    return 0;
}

//6 task
#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;
void reverse(char* str){
    if (*str == '\0') return;
    char* start = str;
    char* end = str;
    while (*end != '\0') {
        end++;
    }
    end--;
    while (start < end) {
        char t = *start;
        *start = *end;
        *end = t;
        start++;
        end--;
    }
}
int main() {
    char m[50];
    cout << "type string: ";
    cin.getline(m, 50);
    reverse(m);
    cout << "result: " << m;
    return 0;
}

//7 task
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
bool isPalindrome(const char* str) {
    const char* end = str;
    while (*end) end++;
    end--;

    while (str < end) {
        if (*str != *end) return false;
        str++;
        end--;
    }
    return true;
}
int main() {
    cout << isPalindrome("racecar") << endl;
    return 0;
}

//8 task
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const char* findSubstring(const char* text, const char* word) {
    const char* p1 = text;
    while (*p1) {
        const char* p1_temp = p1;
        const char* p2 = word;
        while (*p1_temp && *p2 && *p1_temp == *p2) {
            p1_temp++;
            p2++;
        }
        if (!*p2) return p1;
        p1++;
    }
    return nullptr;
}
int main() {
    const char* found = findSubstring("hello world", "world");
    if (found) cout << found << endl;
    return 0;
}

//9 task
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
void removeSpaces(char* str) {
    char* dst = str;
    while (*str) {
        if (*str != ' ') {
            *dst = *str;
            dst++;
        }
        str++;
    }
    *dst = '\0';
}
int main() {
    char str[] = "a b c d";
    removeSpaces(str);
    cout << str << endl;
    return 0;
}

//10 task
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int myStrCmp(const char* s1, const char* s2) {
    while (*s1 && *s2 && *s1 == *s2) {
        s1++;
        s2++;
    }
    return *s1 - *s2;
}
int main() {
    cout << myStrCmp("abc", "abd") << endl;
    return 0;
}

//11 task
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int vectorSum(const std::vector<int>& vec) {
    int sum = 0;
    const int* p = &vec[0];
    for (size_t i = 0; i < vec.size(); i++) {
        sum += *(p + i);
    }
    return sum;
}
int main() {
    vector<int> vec1 = { 1, 2, 3, 4, 5 };
    cout << vectorSum(vec1) << endl;
    return 0;
}

//12 task
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
void increaseBy10(std::vector<int>& vec) {
    int* p = vec.data();
    for (size_t i = 0; i < vec.size(); i++) {
        *(p + i) += 10;
    }
}
int main() {
    increaseBy10(vec1);
    for (int val : vec1) cout << val << " ";
    cout << endl;
    return 0;
}

//13 task
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
void parseTelemetry(const char* data) {
    const char* p = data;
    while (*p) {
        while (*p == ';') p++;

        const char* name_start = p;
        while (*p && *p != ':') p++;
        if (!*p) break;

        const char* value_start = ++p;
        while (*p && *p != ';') p++;

        cout.write(name_start, value_start - name_start - 1);
        cout << ": ";
        cout.write(value_start, p - value_start);
        cout << std::endl;
    }
}
int main() {
    parseTelemetry("TEMP:24.5;PRESS:101.3;HUM:55.2");
    return 0;
}

//14 task
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
double computeRMS(const std::vector<double>& signal) {
    const double* p = signal.data();
    double sum = 0.0;
    for (size_t i = 0; i < signal.size(); i++) {
        sum += *(p + i) * *(p + i);
    }
    return sqrt(sum / signal.size());
}
int main() {
    vector<double> signal = { 2.0, 3.0, 1.0, 4.0, 3.0 };
    cout << computeRMS(signal) << endl;
    return 0;
}

//15 task
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
struct Command {
    std::string name;
    int value;
};

void parseCommand(const char* input, std::vector<Command>& buffer) {
    const char* p = input;

    const char* name_start = p;
    while (*p && *p != ' ') p++;
    string name(name_start, p - name_start);

    int value = 0;
    if (*p) {
        p++;
        while (*p && *p >= '0' && *p <= '9') {
            value = value * 10 + (*p - '0');
            p++;
        }
    }

    buffer.push_back({ name, value });
}
int main() {
    vector<Command> commands;
    parseCommand("FORWARD 10", commands);
    parseCommand("TURN 90", commands);
    parseCommand("STOP", commands);
    for (const auto& cmd : commands) {
        cout << "Command: " << cmd.name << ", Value: " << cmd.value << std::endl;
    }
    return 0;
}

//16 task
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
void analyzePressure(const std::vector<double>& data, double& minVal, double& maxVal, double& avgVal) {
    const double* p = data.data();
    minVal = maxVal = avgVal = *p;

    for (size_t i = 1; i < data.size(); i++) {
        double current = *(p + i);
        if (current < minVal) minVal = current;
        if (current > maxVal) maxVal = current;
        avgVal += current;
    }
    avgVal /= data.size();
}
int main() {
    vector<double> pressure = { 101.3, 100.8, 101.9, 100.5, 102.0 };
    double minVal, maxVal, avgVal;
    analyzePressure(pressure, minVal, maxVal, avgVal);
    cout << "Min: " << minVal << "\nMax: " << maxVal << "\nAvg: " << avgVal << endl;
    return 0;

}
