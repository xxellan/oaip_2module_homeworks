#include <iostream>
#include<locale>
#include<fstream>
#include<map>
#include<vector>
#include<numeric>
#include<string>
#include<sstream>
using namespace std;

int main()
{
    
    //1 task
    ifstream inFile("input.txt");
    if (inFile.fail()) {
        cout << "Не удалось открыть файл!" << endl;
    }
    else {
        string line;
        while (getline(inFile, line)) {
            cout << line << endl;
        }
    }

    //2 task
    int k = 0;
    ifstream inFile("data.txt");
    if (inFile.fail()) {
        cout << "Не удалось открыть файл!" << endl;
    }
    else {
        string line;
        while (getline(inFile, line)) {
            k++;
        }
        cout << "Количество строк в файле: " << k;
    }

    //3 task
    int k = 0;
    ifstream inFile("text.txt");
    if (inFile.fail()) {
        cout << "Не удалось открыть файл!" << endl;
    }
    else {
        string word;
        while (inFile>>word) {
            k++;
        }
        cout << "Количество слов в файле: " << k<<endl;
    }

    //4 task
    int k = 0;
    ifstream inFile("source.txt");
    ofstream outFile("copy.txt");
    if (inFile.fail()) {
        cout << "Не удалось открыть файл source.txt!" << endl;
    }
    else {
        if (outFile.fail()) {
            cout << "Не удалось открыть файл copy.txt!" << endl;
        }
        else {
            string line;
            while (getline(inFile, line)) {
                outFile << line << endl;
                k++;
            }
            cout << "Файл успешно скопирован " << endl;
            cout << "Количество скопированных строк: " << k;
        }

    }

    //5 task
    int k = 0;
    ifstream inFile("text.txt");
    if (inFile.fail()) {
        cout << "Не удалось открыть файл!" << endl;
    }
    else {
        char c;
        while (inFile.get(c)) {
            k++;
        }
        cout << "Количество символов в файле: " << k<<endl;
    }

    //6 task
    ofstream outFile("output.txt");
    if (outFile.fail()) {
        cout << "Не удалось открыть файл output.txt!" << endl;
    }
    else {
        string line;
        getline(cin, line);
        while (!line.empty()) {
            outFile << line << endl;
            getline(cin, line);
       }
        cout << "Данные записаны в файл" << endl;
    }

    //7 task
    int k = 0;
    int sums = 0;
    ifstream inFile("numbers.txt");
    if (inFile.fail()) {
        cout << "Не удалось открыть файл!" << endl;
    }
    else {
        string word;
        while (inFile>>word) {
            k++;
            sums += stoi(word);
        }
        cout << "Количество чисел в файле: " << k<<endl;
        cout << "Сумма чисел в файле: " <<sums << endl;
        cout << "Среднее значение чисел в файле: " << sums/k << endl;
    }

    //8 task
    ifstream inFile1("file1.txt");
    ifstream inFile2("file2.txt");
    if (inFile.fail()) {
        cout << "Не удалось открыть файл file1.txt !" << endl;
    }
    else {
        if (inFile.fail()) {
            cout << "Не удалось открыть файл file2.txt !" << endl;
        }
        else {
            string line1;
            string line2;
            bool l = true;
            while (getline(inFile1, line1) && getline(inFile2, line2)) {
                if (line1 != line2) {
                    l = false;
                }
            }
            if (l) {
                cout << "Файлы идентичны. " << endl;
            }
            else {
                cout << "Файлы различаются. " << endl;
            }
        }
    }

    //9 task
    ifstream inFile("temperature_data.txt");
    ofstream outFile("report.txt");
    if (inFile.fail()) {
        cout << "Не удалось открыть файл temperature_data.txt!" << endl;
    }
    else {
        map<string, vector<double>> v;
        string line;
        while (getline(inFile, line)) {
            stringstream ss(line);
            string name;
            double temp;
            ss >> name >> temp;
            v[name].push_back(temp);
        }
        if (outFile.fail()) {
            cout << "Не удалось открыть файл report.txt!" << endl;
        }
        else {
            for (auto& d : v) {
                const string& names = d.first;
                const vector<double>& temps = d.second;
                if (temps.empty()) continue;
                double mint = *min_element(temps.begin(), temps.end());
                double maxt = *max_element(temps.begin(), temps.end());
                double srt = 0.0;
                if (temps.size() != 0) {
                    srt = accumulate(temps.begin(), temps.end(), 0.0) / temps.size();
                }

                outFile <<names << ": min=" << mint << ", max=" << maxt << ", avg=" << srt << endl;
            }
            cout << "Все данные записаны в файл" << endl;
        }
    }
    inFile.close();
    outFile.close();

    //10 task
    ifstream inFile("power_log.txt");
    ofstream outFile("energy_report.txt");
    if (inFile.fail()) {
        cout << "Не удалось открыть файл temperature_data.txt!" << endl;
    }
    else {
        map<string, vector<double>> v;
        string line;
        while (getline(inFile, line)) {
            stringstream ss(line);
            string name;
            string name2;
            double temp;
            ss >>name2>> name >> temp;
            v[name].push_back(temp);
        }
        if (outFile.fail()) {
            cout << "Не удалось открыть файл report.txt!" << endl;
        }
        else {
            for (auto& d : v) {
                const string& names = d.first;
                const vector<double>& temps = d.second;
                if (temps.empty()) continue;
                double sums = accumulate(temps.begin(), temps.end(), 0.0);
                double srt = 0.0;
                if (temps.size() != 0) {
                    srt = sums / temps.size();
                }

                outFile <<names << ": measurements=" << temps.size() << ", total=" << sums << " kWh, average=" << srt <<" kW"<< endl;
            }
            cout << "Все данные записаны в файл" << endl;
        }
    }
    inFile.close();
    
    //11 task
    ifstream inFile("vibration_log.txt");
    ofstream outFile("vibration_report.txt");

    if (inFile.fail()) {
        cout << "Не удалось открыть файл vibration_log.txt!" << endl;
        return 1;
    }

    vector<double> v;
    double value;
        while (inFile >> value) {
            v.push_back(value);
        }

    if (outFile.fail()) {
        cout << "Не удалось открыть файл vibration_report.txt!" << endl;
        return 1;
    }

    auto filtr = [](double l) { return l > 0.05; };
    auto sr = [](vector<double>& temps) {
        if (temps.empty()) return 0.0;
        else return accumulate(temps.begin(), temps.end(), 0.0) / temps.size();
        };
    auto mins = [](vector<double>& temps) {
        if (temps.empty()) return 0.0;
        else return *min_element(temps.begin(), temps.end());
        };
    auto maxs = [](vector<double>& temps) {
        if (temps.empty()) return 0.0;
        else return *max_element(temps.begin(), temps.end());
        };

    outFile << "Количество измерений: " << v.size() << endl;

    outFile << "Фильтрованные значения (>0.05): ";
    for (auto k : v) {
        if (filtr(k)) {  // Проверяем условие фильтрации
            outFile << k << " ";  // Выводим значение
        }
    }
    outFile << endl;

    outFile << "Среднее значение: " << sr(v) << endl;
    outFile << "Минимум: " << mins(v) << endl;
    outFile << "Максимум: " << maxs(v) << endl;

    cout << "Все данные записаны в файл" << endl;

    inFile.close();
    outFile.close();

    return 0;