//1 task
#include <iostream>
#include <memory>

using namespace std;

int main() {
    unique_ptr<int> ptr = make_unique<int>(10);
    cout << *ptr << endl;
    *ptr = 25;
    cout << *ptr << endl;

    return 0;
}

//2 task
#include <iostream>
#include <memory>

using namespace std;

int main() {
    int n;
    cout << "ââåäèòå ðàçìåð ìàññèâà: ";
    cin >> n;
    auto arr = make_unique<int[]>(n);
    for (int i = 0; i < n; ++i) {
        arr[i] = i + 1;
    }
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

//3 task
#include <iostream>
#include <memory>

using namespace std;

void fillArray(unique_ptr<int[]>& arr, int n) {
    for (int i = 0; i < n; ++i) {
        arr[i] = i * i;
    }
}

int main() {
    int n;
    cout << "ââåäèòå ðàçìåð ìàññèâà: ";
    cin >> n;

    auto arr = make_unique<int[]>(n);
    fillArray(arr, n);

    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

//4 task
#include <iostream>
#include <memory>

using namespace std;

int main() {
    auto ptr1 = make_unique<int>(42);
    cout << "ptr1 äî ïåðåìåùåíèÿ: " << *ptr1 << endl;
    auto ptr2 = move(ptr1);
    if (ptr1 == nullptr) {
        cout << "ptr1 òåïåðü nullptr" << endl;
    }
    cout << "ptr2 ïîñëå ïåðåìåùåíèÿ: " << *ptr2 << endl;

    return 0;
}

//5 task
#include <iostream>
#include <memory>
#include <iomanip>

using namespace std;

int main() {
    int n, m;
    cout << "ââåäèòå n è m: ";
    cin >> n >> m;
    auto arr = make_unique<int[]>(n * m);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            arr[i * m + j] = i * j;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << setw(3) << arr[i * m + j] << " ";
        }
        cout << endl;
    }

    return 0;
}

//6 task
#include <iostream>
#include <memory>

using namespace std;

int main() {
    auto ptr1 = make_shared<int>(100);
    cout << "use_count ïîñëå ñîçäàíèÿ ptr1: " << ptr1.use_count() << endl;

    auto ptr2 = ptr1;
    auto ptr3 = ptr1;
    cout << "use_count ïîñëå ñîçäàíèÿ êîïèé: " << ptr1.use_count() << endl;

    ptr2.reset();
    cout << "use_count ïîñëå óäàëåíèÿ ptr2: " << ptr1.use_count() << endl;

    return 0;
}

//7 task
#include <iostream>
#include <memory>
#include <cstring>
#include <vector>

using namespace std;

bool isVowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
    const char* str = "Hello, World!";
    size_t len = strlen(str);

    auto arr = make_unique<char[]>(len + 1);
    strcpy(arr.get(), str);

    int vowels = 0, consonants = 0;
    for (size_t i = 0; i < len; ++i) {
        if (isalpha(arr[i])) {
            if (isVowel(arr[i])) vowels++;
            else consonants++;
        }
    }

    auto vowelsArr = make_unique<char[]>(vowels + 1);
    for (size_t i = 0, j = 0; i < len; ++i) {
        if (isVowel(arr[i])) {
            vowelsArr[j++] = arr[i];
        }
    }
    vowelsArr[vowels] = '\0';

    cout << "èñõîäíàÿ ñòðîêà: " << arr.get() << endl;
    cout << "ãëàñíûå: " << vowels << ", cîãëàñíûå: " << consonants << endl;
    cout << "ìàññèâ ãëàñíûõ : " << vowelsArr.get() << endl;

    return 0;
}

//8 task
#include <iostream>
#include <memory>
#include <iomanip>

using namespace std;

double calculateAverage(const unique_ptr<double[]>& arr, int size) {
    double sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum / size;
}

int main() {
    const int size = 5;

    auto temperatures = make_unique<double[]>(size);
    auto pressures = make_unique<double[]>(size);
    auto humidities = make_unique<double[]>(size);

    double tempVals[] = { 25.5, 22.3, 19.8, 21.6, 23.1 };
    double pressVals[] = { 1513.2, 1012.8, 1013.5, 1012.3, 1014.1 };
    double humidVals[] = { 45.5, 51.5, 48.3, 52.0, 47.8 };

    for (int i = 0; i < size; ++i) {
        temperatures[i] = tempVals[i];
        pressures[i] = pressVals[i];
        humidities[i] = humidVals[i];
    }

    double avgTemp = calculateAverage(temperatures, size);
    double avgPress = calculateAverage(pressures, size);
    double avgHumid = calculateAverage(humidities, size);

    cout << fixed << setprecision(2);
    cout << "ïàðàìåòð\tñðåäíåå çíà÷åíèå" << endl;
    cout << "òåìïåðàòóðà\t" << avgTemp << endl;
    cout << "äàâëåíèå\t" << avgPress << endl;
    cout << "âëàæíîñòü\t" << avgHumid << endl;

    return 0;
}

//9 task
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

void processA(shared_ptr<vector<int>> buf) {
    for (auto& val : *buf) {
        val += 1;
    }
}

void processB(shared_ptr<vector<int>> buf) {
    for (auto& val : *buf) {
        val *= 2;
    }
}

int main() {
    auto buffer = make_shared<vector<int>>();

    for (int i = 1; i <= 10; ++i) {
        buffer->push_back(i);
    }

    processA(buffer);
    processB(buffer);

    for (const auto& val : *buffer) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

//10 task
#include <iostream>
#include <memory>

using namespace std;

unique_ptr<int[]> createArray(int n) {
    auto arr = make_unique<int[]>(n);
    for (int i = 0; i < n; ++i) {
        arr[i] = i + 1;
    }
    return arr;
}

int main() {
    int n;
    cout << "ââåäèòå ðàçìåð ìàññèâà: ";
    cin >> n;

    auto arr = createArray(n);

    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

//11 task
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    vector<double> signals = { 25.4, 27.1, 30.0, 29.5, 28.3 };
    int n = signals.size();

    auto uniqueSignals = make_unique<double[]>(n);
    for (int i = 0; i < n; ++i) {
        uniqueSignals[i] = signals[i];
    }

    auto mean = [](const unique_ptr<double[]>& arr, int size) {
        return accumulate(arr.get(), arr.get() + size, 0.0) / size;
        };

    auto normalize = [](unique_ptr<double[]>& arr, int size, double maxVal) {
        for (int i = 0; i < size; ++i) {
            arr[i] /= maxVal;
        }
        };

    auto copyBack = [&](const unique_ptr<double[]>& arr) {
        for (int i = 0; i < n; ++i) {
            signals[i] = arr[i];
        }
        };

    double avg = mean(uniqueSignals, n);
    double maxVal = *max_element(uniqueSignals.get(), uniqueSignals.get() + n);

    normalize(uniqueSignals, n, maxVal);
    copyBack(uniqueSignals);

    cout << "èñõîäíûå äàííûå: ";
    for (double val : {25.4, 27.1, 30.0, 29.5, 28.3}) {
        cout << val << " ";
    }
    cout << "\nñðåäíåå çíà÷åíèå: " << avg;
    cout << "\níîðìàëèçîâàííûå ñèãíàëû: ";
    for (const auto& val : signals) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

//12 task
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<string> logs = {
        "INFO: Start",
        "ERROR: Disk failure",
        "WARNING: Low memory",
        "ERROR: Disk failure",
        "INFO: Stop"
    };

    auto pLogs = make_shared<vector<string>>(logs);
    vector<string> errors;

    copy_if(pLogs->begin(), pLogs->end(), back_inserter(errors),
        [](const string& log) {
            return log.find("ERROR") != string::npos;
        });

    sort(errors.begin(), errors.end());
    errors.erase(unique(errors.begin(), errors.end()), errors.end());

    cout << "èñõîäíûé æóðíàë:\n";
    for (const auto& log : *pLogs) {
        cout << log << endl;
    }

    cout << "\nîøèáêè:\n";
    for (const auto& err : errors) {
        cout << err << endl;
    }

    return 0;
}

//13 task
#include <iostream>
#include <memory>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    auto part1 = make_unique<string>("Sensor data:");
    auto part2 = make_unique<string>("Voltage stable.");
    auto part3 = make_unique<string>("System nominal.");

    vector<unique_ptr<string>> reportParts;
    reportParts.push_back(move(part1));
    reportParts.push_back(move(part2));
    reportParts.push_back(move(part3));

    auto concatParts = [](const vector<unique_ptr<string>>& parts) {
        stringstream ss;
        for (const auto& part : parts) {
            ss << *part << "\n";
        }
        return ss.str();
        };

 
    auto countWord = [](const string& text, const string& word) {
        size_t count = 0;
        size_t pos = text.find(word);
        while (pos != string::npos) {
            count++;
            pos = text.find(word, pos + 1);
        }
        return count;
        };

    string report = concatParts(reportParts);
    int dataCount = countWord(report, "data");

    cout << "îò÷¸ò:\n" << report;
    cout << "ñëîâî \"data\" âñòðå÷àåòñÿ " << dataCount << " ðàç" << endl;

    return 0;
}

//14 task
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cout << "ââåäèòå n è m : ";
    cin >> n >> m;

    auto matrix = make_unique<double[]>(n * m);

    cout << "ââåäèòå ýëåìåíòû ìàòðèöû:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i * m + j];
        }
    }

    auto sumColumns = [&]() {
        vector<double> sums(m, 0.0);
        for (int j = 0; j < m; ++j) {
            for (int i = 0; i < n; ++i) {
                sums[j] += matrix[i * m + j];
            }
        }
        return sums;
        };

    auto maxIndex = [](const vector<double>& vec) {
        return max_element(vec.begin(), vec.end()) - vec.begin();
        };

    auto sums = sumColumns();
    int maxIdx = maxIndex(sums);

    cout << "ñóììû ñòîëáöîâ: [";
    for (size_t i = 0; i < sums.size(); ++i) {
        cout << sums[i];
        if (i != sums.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    cout << "ñòîëáåö ñ ìàêñèìàëüíîé ñóììîé: " << maxIdx + 1
        << " (" << sums[maxIdx] << ")" << endl;

    return 0;
}

//15 task
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<string> routes = {
        "Moscow-Berlin",
        "Berlin-Paris",
        "Paris-Rome",
        "Rome-Moscow"
    };

    auto ptrRoutes = make_shared<vector<string>>(routes);

    auto countCity = [](const shared_ptr<vector<string>>& routes,
        const string& city) {
            return count_if(routes->begin(), routes->end(),
                [&city](const string& route) {
                    return route.find(city) != string::npos;
                });
        };

    auto sortByLength = [](shared_ptr<vector<string>> routes) {
        sort(routes->begin(), routes->end(),
            [](const string& a, const string& b) {
                return a.length() > b.length();
            });
        };

    auto concat = [](const shared_ptr<vector<string>>& routes) {
        string result;
        for (size_t i = 0; i < routes->size(); ++i) {
            result += (*routes)[i];
            if (i != routes->size() - 1) result += " -> ";
        }
        return result;
        };

    int parisCount = countCity(ptrRoutes, "Paris");
    sortByLength(ptrRoutes);
    string connectedRoute = concat(ptrRoutes);

    cout << "êîëè÷åñòâî ìàðøðóòîâ ñ \"Paris\": " << parisCount << endl;
    cout << "îòñîðòèðîâàííûå ìàðøðóòû:" << endl;
    for (const auto& route : *ptrRoutes) {
        cout << route << endl;
    }
    cout << "îáùèé ìàðøðóò:\n" << connectedRoute << endl;

    return 0;
}
