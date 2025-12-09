//12 задач на файлы
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <numeric>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <cctype>

using namespace std;

//1 task
int main1() {
    ifstream file("book.txt");
    if (!file) {
        cout << "File book.txt not found!" << endl;
        return 0;
    }
    string target = "hero";
    string line;
    int line_num = 0;
    vector<pair<int, int>> positions;
    
    while (getline(file, line)) {
        line_num++;
        size_t pos = 0;
        while ((pos = line.find(target, pos)) != string::npos) {
            positions.push_back({line_num, static_cast<int>(pos + 1)});
            pos += target.length();
        }
    }
    file.close();

    ofstream out("word_positions.txt");
    for (const auto& p : positions) {
        out << "Line: " << p.first << ", Position: " << p.second << ", Word: " << target << endl;
    }
    out.close();

    cout << "Found " << positions.size() << " occurrences of the word \"" << target << "\"" << endl;
    cout << "Results saved in word_positions.txt" << endl;
    return 0;
}

//2 task
int main2() {
    fstream file("config.txt", ios::in | ios::out);
    if (!file) {
        cout << "File config.txt not found!" << endl;
        return 0;
    }

    string content((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();

    size_t pos = content.find("timeout=30");
    if (pos != string::npos) {
        content.replace(pos, strlen("timeout=30"), "timeout=60");
        ofstream out("config.txt");
        out << content;
        out.close();
        cout << "Timeout value changed to 60." << endl;
    } else {
        cout << "Parameter timeout=30 not found." << endl;
    }
    return 0;
}

//3 task
int main3() {
    ifstream in("application.log");
    if (!in) {
        cout << "File application.log not found!" << endl;
        return 0;
    }

    const size_t MAX_PART_SIZE = 1024;
    vector<string> part_files;
    string line;
    size_t current_size = 0;
    int part_num = 1;
    ofstream out;

    while (getline(in, line)) {
        if (current_size == 0) {
            string part_name = "log_part" + to_string(part_num) + ".txt";
            part_files.push_back(part_name);
            out.open(part_name);
            if (!out) {
                cerr << "Failed to create " << part_name << endl;
                return 0;
            }
        }
        size_t line_size = line.size() + 1;
        if (current_size + line_size > MAX_PART_SIZE && current_size > 0) {
            out.close();
            current_size = 0;
            part_num++;
            continue; 
        }
        out << line << '\n';
        current_size += line_size;
    }
    if (out.is_open()) out.close();
    in.close();

    ofstream idx("log_index.txt");
    idx << "Total parts: " << part_num << endl;
    for (const string& name : part_files) {
        idx << name << endl;
    }
    idx.close();

    cout << "Log split into " << part_num << " parts. Index: log_index.txt" << endl;
    return 0;
}

//4 task
int main4() {
    int numbers[] = {15, 23, 7, 42, 18, 91, 3, 56, 77, 10};
    const size_t N = sizeof(numbers) / sizeof(numbers[0]);

    ofstream out_bin("numbers.bin", ios::binary);
    out_bin.write(reinterpret_cast<char*>(numbers), sizeof(numbers));
    out_bin.close();

    ifstream in_bin("numbers.bin", ios::binary);
    in_bin.seekg(0, ios::end);
    size_t file_size = in_bin.tellg();
    in_bin.seekg(0, ios::beg);

    vector<int> buffer(N);
    in_bin.read(reinterpret_cast<char*>(buffer.data()), sizeof(int) * N);
    in_bin.close();

    cout << "Numbers from file: ";
    long long sum = 0;
    for (int x : buffer) {
        cout << x << " ";
        sum += x;
    }
    cout << "\nFile size: " << file_size << " bytes\n";
    cout << "Sum: " << sum << endl;
    return 0;
}

//5 task
struct Student {
    int id;
    char name[50];
    int age;
    double average_grade;
};

int main5() {
    Student students[] = {
        {1, "Ivan Petrov", 20, 4.5},
        {2, "Maria Sidorova", 19, 4.8},
        {3, "Alexey Ivanov", 21, 4.2}
    };
    const size_t N = 3;

    ofstream out_st("students.dat", ios::binary);
    for (size_t i = 0; i < N; ++i) {
        out_st.write(reinterpret_cast<char*>(&students[i]), sizeof(Student));
    }
    out_st.close();

    vector<Student> all;
    ifstream in_st("students.dat", ios::binary);
    Student s;
    while (in_st.read(reinterpret_cast<char*>(&s), sizeof(Student))) {
        all.push_back(s);
    }
    in_st.close();

    cout << "Students:\n";
    for (const auto& st : all) {
        cout << "ID: " << st.id << ", Name: " << st.name
             << ", Age: " << st.age << ", Average grade: " << st.average_grade << endl;
    }

    auto best = max_element(all.begin(), all.end(),
        [](const Student& a, const Student& b) { return a.average_grade < b.average_grade; });
    cout << "Best student: " << best->name << " (" << best->average_grade << ")\n";
    cout << "Total students: " << all.size() << endl;
    return 0;
}

//6 task
int main6() {
    srand(static_cast<unsigned>(time(0)));
    ofstream out("products.csv");
    out << "id,name,category,price,quantity\n";

    vector<string> categories = {"Electronics", "Accessories", "Clothing", "Books", "Household"};
    vector<string> names = {"Laptop", "Mouse", "T-shirt", "Novel", "Kettle", "Headphones", "Clock", "Sneakers", "Notebook", "Lamp"};

    for (int i = 1; i <= 20; ++i) {
        string name = names[rand() % names.size()] + " " + to_string(i);
        string cat = categories[rand() % categories.size()];
        int price = 100 + rand() % 9901; // 100–10000
        int qty = 1 + rand() % 100;      // 1–100
        out << i << "," << name << "," << cat << "," << price << "," << qty << "\n";
    }
    out.close();

    ifstream check("products.csv");
    int lines = 0;
    string line;
    while (getline(check, line)) lines++;
    check.close();

    cout << "File products.csv created. Records: " << (lines - 1) << " (header + " << lines - 1 << " products)" << endl;
    return 0;
}

//7 task
struct Product {
    int id;
    string name;
    string category;
    double price;
    int quantity;
};

int main7() {
    ifstream in("products.csv");
    if (!in) {
        cout << "File products.csv not found! Please complete task 6 first." << endl;
        return 0;
    }

    string line;
    getline(in, line);
    vector<Product> products;
    while (getline(in, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string field;
        vector<string> fields;
        while (getline(ss, field, ',')) {
            fields.push_back(field);
        }
        if (fields.size() != 5) continue;
        Product p;
        p.id = stoi(fields[0]);
        p.name = fields[1];
        p.category = fields[2];
        p.price = stod(fields[3]);
        p.quantity = stoi(fields[4]);
        products.push_back(p);
    }
    in.close();

    cout << "Products:\n";
    double total_value = 0;
    int total_qty = 0;
    for (const auto& p : products) {
        cout << p.id << ": " << p.name << " (" << p.category << ") — "
             << p.price << " rub., " << p.quantity << " pcs.\n";
        total_value += p.price * p.quantity;
        total_qty += p.quantity;
    }

    auto cheapest = min_element(products.begin(), products.end(),
        [](const Product& a, const Product& b) { return a.price < b.price; });
    auto expensive = max_element(products.begin(), products.end(),
        [](const Product& a, const Product& b) { return a.price < b.price; });

    cout << "\nTotal products in stock: " << total_qty << endl;
    cout << "Total value: " << fixed << setprecision(2) << total_value << " rub." << endl;
    cout << "Cheapest: " << cheapest->name << " (" << cheapest->price << " rub.)" << endl;
    cout << "Most expensive: " << expensive->name << " (" << expensive->price << " rub.)" << endl;
    return 0;
}

//8 task
int main8() {
    ifstream in("products.csv");
    if (!in) {
        cout << "File products.csv not found! Please complete task 6 first." << endl;
        return 0;
    }

    string line;
    getline(in, line);
    vector<Product> products;
    while (getline(in, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string field;
        vector<string> fields;
        while (getline(ss, field, ',')) fields.push_back(field);
        if (fields.size() != 5) continue;
        Product p;
        p.id = stoi(fields[0]);
        p.name = fields[1];
        p.category = fields[2];
        p.price = stod(fields[3]);
        p.quantity = stoi(fields[4]);
        products.push_back(p);
    }
    in.close();
    vector<Product> filtered;

    auto expensive_filter = [](const Product& p) { return p.price > 5000; };
    auto category_filter = [](const Product& p) { return p.category == "Electronics"; };
    auto stock_filter = [](const Product& p) { return p.quantity > 10; };

    copy_if(products.begin(), products.end(), back_inserter(filtered), expensive_filter);

    ofstream out("filtered_products.csv");
    out << "id,name,category,price,quantity\n";
    for (const auto& p : filtered) {
        out << p.id << "," << p.name << "," << p.category << "," << p.price << "," << p.quantity << "\n";
    }
    out.close();

    cout << "Filtered products (more expensive than 5000): " << filtered.size() << endl;
    cout << "Result saved in filtered_products.csv" << endl;
    return 0;
}

//9 task
int main9() {
    ifstream in("products.csv");
    if (!in) {
        cout << "File products.csv not found!" << endl;
        return 0;
    }

    string line;
    getline(in, line);
    vector<Product> products;
    while (getline(in, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string field;
        vector<string> fields;
        while (getline(ss, field, ',')) fields.push_back(field);
        if (fields.size() != 5) continue;
        Product p;
        p.id = stoi(fields[0]);
        p.name = fields[1];
        p.category = fields[2];
        p.price = stod(fields[3]);
        p.quantity = stoi(fields[4]);
        products.push_back(p);
    }
    in.close();

    int choice = 1;
    auto comp = [](const Product& a, const Product& b) { return a.price < b.price; };
    string desc = "by price (ascending)";

    sort(products.begin(), products.end(), comp);

    ofstream out("sorted_products.csv");
    out << "id,name,category,price,quantity\n";
    for (const auto& p : products) {
        out << p.id << "," << p.name << "," << p.category << "," << p.price << "," << p.quantity << "\n";
    }
    out.close();

    cout << "Products sorted " << desc << " and saved in sorted_products.csv" << endl;
    return 0;
}

//10 task
int main10() {
    ofstream cfg("config.json");
    cfg << "{\n";
    cfg << "  \"app_name\": \"My Application\",\n";
    cfg << "  \"version\": \"1.0.0\",\n";
    cfg << "  \"settings\": {\n";
    cfg << "    \"max_connections\": 100,\n";
    cfg << "    \"timeout\": 30,\n";
    cfg << "    \"debug_mode\": true\n";
    cfg << "  },\n";
    cfg << "  \"database\": {\n";
    cfg << "    \"host\": \"localhost\",\n";
    cfg << "    \"port\": 5432,\n";
    cfg << "    \"username\": \"admin\"\n";
    cfg << "  }\n";
    cfg << "}";
    cfg.close();
    cout << "config.json created.\n";

    ifstream in("config.json");
    string line;
    cout << "Contents of config.json:\n";
    while (getline(in, line)) {
        cout << line << endl;
    }
    in.close();

    ifstream in2("config.json");
    string content((istreambuf_iterator<char>(in2)), istreambuf_iterator<char>());
    in2.close();

    size_t pos = content.find("\"timeout\": 30");
    if (pos != string::npos) {
        content.replace(pos, strlen("\"timeout\": 30"), "\"timeout\": 60");
        ofstream out("config.json");
        out << content;
        out.close();
        cout << "Timeout changed to 60.\n";
    }

    return 0;
}

//11 task
int main11() {
    ifstream in("sensor_data.txt");
    if (!in) {
        cout << "File sensor_data.txt not found!" << endl;
        return 0;
    }

    vector<double> temps;
    string line;
    while (getline(in, line)) {
        stringstream ss(line);
        double val;
        while (ss >> val) {
            temps.push_back(val);
        }
    }
    in.close();

    vector<double> valid;
    copy_if(temps.begin(), temps.end(), back_inserter(valid),
        [](double t) { return t >= -50.0 && t <= 50.0; });

    if (valid.empty()) {
        cout << "No valid data." << endl;
        return 0;
    }

    double avg = accumulate(valid.begin(), valid.end(), 0.0) / valid.size();

    ofstream out("filtered_sensor_data.txt");
    for (double t : valid) {
        out << t << "\n";
    }
    out.close();

    cout << "Filtering complete. Valid values: " << valid.size() << endl;
    cout << "Average temperature: " << fixed << setprecision(2) << avg << "°C" << endl;
    cout << "Filtered data saved in filtered_sensor_data.txt" << endl;
    return 0;
}

//12 task
int main12() {
    const int N = 100000;
    vector<int> data(N);
    for (int i = 0; i < N; ++i) data[i] = rand();

    auto time_write = [](const vector<int>& d, const string& fname, bool batch) -> double {
        auto start = chrono::steady_clock::now();
        ofstream f(fname, ios::binary);
        if (batch) {
            f.write(reinterpret_cast<const char*>(d.data()), d.size() * sizeof(int));
        } else {
            for (int x : d) f.write(reinterpret_cast<const char*>(&x), sizeof(int));
        }
        f.close();
        auto end = chrono::steady_clock::now();
        return chrono::duration<double, milli>(end - start).count();
    };

    double time_batch = time_write(data, "batch.bin", true);
    double time_individual = time_write(data, "individual.bin", false);

    cout << "Write speed comparison (100,000 numbers):\n";
    cout << "Batch write: " << fixed << setprecision(2) << time_batch << " ms\n";
    cout << "Individual write: " << time_individual << " ms\n";
    cout << "Difference: " << (time_individual - time_batch) << " ms\n";
    return 0;
}

// Main function
int main() {
    cout << "Choose task (1-12): ";
    int choice;
    cin >> choice;
    switch (choice) {
        case 1: main1(); break;
        case 2: main2(); break;
        case 3: main3(); break;
        case 4: main4(); break;
        case 5: main5(); break;
        case 6: main6(); break;
        case 7: main7(); break;
        case 8: main8(); break;
        case 9: main9(); break;
        case 10: main10(); break;
        case 11: main11(); break;
        case 12: main12(); break;
        default: cout << "Invalid choice!" << endl;
    }
    return 0;
}

