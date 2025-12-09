//1 task
#include <iostream>
#include <chrono>
using namespace std;

long long calculate_sum(int n) {
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    return sum;
}

int main() {
    setlocale(LC_ALL, "en_US.UTF-8");

    cout << "=== measuring function execution time ===\n";

    int n;
    cout << "enter number n: ";
    cin >> n;

    auto start_time = chrono::high_resolution_clock::now();
    long long result = calculate_sum(n);
    auto end_time = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end_time - start_time);

    cout << "\ncalculation result: sum of numbers from 1 to " << n << " = " << result << endl;
    cout << "execution time: " << duration.count() << " milliseconds\n";

    return 0;
}


//2 task
#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

int main() {
    setlocale(LC_ALL, "en_US.UTF-8");

    cout << "=== countdown timer ===\n";

    int seconds;
    cout << "enter number of seconds: ";
    cin >> seconds;

    cout << "\ntimer started!\n";

    for (int i = seconds; i > 0; i--) {
        cout << "remaining: " << i << " seconds";
        cout << endl;
        this_thread::sleep_for(chrono::seconds(1));
    }

    cout << "time is up!\n";
    return 0;
}


//3 task
#include <iostream>
#include <chrono>
using namespace std;

int main() {
    setlocale(LC_ALL, "en_US.UTF-8");

    cout << "=== time converter ===\n";

    long long total_seconds;
    cout << "enter number of seconds: ";
    cin >> total_seconds;

    auto hours_duration = chrono::seconds(total_seconds);
    auto hours = chrono::duration_cast<chrono::hours>(hours_duration);

    long long remaining_seconds = total_seconds - hours.count() * 3600;

    auto minutes_duration = chrono::seconds(remaining_seconds);
    auto minutes = chrono::duration_cast<chrono::minutes>(minut_
 long long final_seconds = remaining_seconds - minutes.count() * 60;

    cout << "\nconversion result:\n";

    cout << hours.count() << " hours "
         << minutes.count() << " minutes "
         << final_seconds << " seconds" << endl;

    return 0;
}


//4(1) task
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
using namespace std;

int main() {
    setlocale(LC_ALL, "en_US.UTF-8");

    cout << "=== sorting time comparison ===\n";

    const int SIZE = 10000;
    vector<int> original(SIZE);

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 10000);

    cout << "creating array of " << SIZE << " numbers...\n";
    for (int i = 0; i < SIZE; i++) {
        original[i] = dist(gen);
    }
    cout << "array ready!\n\n";

    vector<int> arr1 = original;
    cout << "bubble sort... ";
    auto start = chrono::high_resolution_clock::now();

    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - i - 1; j++) {
            if (arr1[j] > arr1[j + 1]) {
                int temp = arr1[j];
                arr1[j] = arr1[j + 1];
                arr1[j + 1] = temp;
            }
        }
    }

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << duration.count() << " ms\n";

    vector<int> arr2 = original;
    cout << "insertion sort... ";

    start = chrono::high_resolution_clock::now();
    for (int i = 1; i < SIZE; i++) {
        int key = arr2[i];
        int j = i - 1;

        while (j >= 0 && arr2[j] > key) {
            arr2[j + 1] = arr2[j];
            j--;
        }
        arr2[j + 1] = key;
    }
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << duration.count() << " ms\n";

    vector<int> arr3 = original;
    cout << "quick sort... ";
    start = chrono::high_resolution_clock::now();
    sort(arr3.begin(), arr3.end());
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << duration.count() << " ms\n";

    cout << "\n=== results ===\n";
    cout << "for array of " << SIZE << " elements:\n";
    cout << "1. bubble — slowest (O(n²))\n";
    cout << "2. insertion — faster (O(n²))\n";
    cout << "3. quick — fastest (O(n log n))\n";

    bool sorted1 = true, sorted2 = true, sorted3 = true;
    for (int i = 1; i < SIZE; i++) {
        if (arr1[i] < arr1[i - 1]) sorted1 = false;
        if (arr2[i] < arr2[i - 1]) sorted2 = false;
        if (arr3[i] < arr3[i - 1]) sorted3 = false;
    }

    cout << "\nsort checking:\n";
    cout << "bubble: " << (sorted1 ? "✓ correct" : "✗ error") << "\n";
    cout << "insertion: " << (sorted2 ? "✓ correct" : "✗ error") << "\n";
    cout << "quick: " << (sorted3 ? "✓ correct" : "✗ error") << "\n";

    return 0;
}


//5(2) task
#include <iostream>
#include <chrono>
using namespace std;

int main() {
    setlocale(LC_ALL, "en_US.UTF-8");

    cout << "=== seconds to hours/minutes/seconds converter ===\n";

    long long total_seconds;
    cout << "enter number of seconds: ";
    cin >> total_seconds;

    auto seconds_duration = chrono::seconds(total_seconds);
    auto hours = chrono::duration_cast<chrono::hours>(seconds_duration);
    auto remaining_after_hours = seconds_duration - hours;
    auto minutes = chrono::duration_cast<chrono::minutes>(remaining_after_hours);
    auto seconds = remaining_after_hours - minutes;

    long long h = hours.count();
    long long m = minutes.count();
    long long s = seconds.count();

    cout << "\nresult: ";
    cout << h << " hours " << m << " minutes " << s << " seconds\n\n";

    cout << "=== simple method (without chrono) ===\n";

    long long simple_hours = total_seconds / 3600;
    long long simple_minutes = (total_seconds % 3600) / 60;
    long long simple_seconds = total_seconds % 60;

    cout << "hours: " << simple_hours << "\n";
    cout << "minutes: " << simple_minutes << "\n";
    cout << "seconds: " << simple_seconds << "\n";

    return 0;
}