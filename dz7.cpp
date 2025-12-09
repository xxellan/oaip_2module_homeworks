//10 задач указатели на указатели
//1 task
#include <iostream>
#include <locale>
using namespace std;
void swapPointers(int** a, int** b) {
    int* c = *a;
    *a = *b;
    *b = c;
}
void Print(int* a, int* b) {
    cout << "Address p1: " << a << endl;
    cout << "Value p1: " << *a << endl;
    cout << "Address p2: " << b << endl;
    cout << "Value p2: " << *b << endl;
}
int main() {
    setlocale(LC_ALL, "Russian");
    int x = 2;
    int y = 5;
    int* p1 = &x;
    int* p2 = &y;
    cout << "Before swapping pointers" << endl;
    Print(p1, p2);
    swapPointers(&p1, &p2);
    cout << "After swapping pointers" << endl;
    Print(p1, p2);
    return 0;
}

//2-4 tasks
#include <iostream>
#include <locale>
using namespace std;
void free2D(int** arr, int n) {
    for (int i = 0; i < n; ++i) {
        delete[] arr[i];
    }
    delete[] arr;
}
int** transpose(int** matrix, int n, int m) {
    int** array = new int* [m];
    for (int i = 0; i < m; ++i) {
        array[i] = new int[n];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            array[j][i] = matrix[i][j];
        }
    }
    return array;
}
void Show(int** array, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}
int main() {
    int rows, cols;
    cout << "Enter number of rows ";
    cin >> rows;
    cout << "Enter number of columns ";
    cin >> cols;
    int** array = new int* [rows]; 
    for (int i = 0; i < rows; ++i) {
        array[i] = new int[cols]; 
    int value = 1;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            array[i][j] = value++;
        }
    }
    cout << "Old array" << endl;
    Show(array, rows, cols);
    cout << "New array" << endl;
    int** array2 = transpose(array, rows, cols);
    Show(array2, cols, rows);
    free2D(array, rows);
    free2D(array2, cols);
    return 0;
}
}

//5-6 tasks
#include <iostream>
#include <locale>
using namespace std;

void Show(int** array, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}
void free2D(int** arr, int n) {
    for (int i = 0; i < n; ++i) {
        delete[] arr[i]; 
    }
    delete[] arr;
}
int rowSum(int* row, int cols) {
    int sum = 0;
    for (int j = 0; j < cols; ++j) {
        sum += row[j];
    }
    return sum;
}

void sortRowsBySum(int** arr, int rows, int cols) {
    for (int i = 0; i < rows - 1; ++i) {
        for (int j = 0; j < rows - i - 1; ++j) {
            if (rowSum(arr[j], cols) > rowSum(arr[j + 1], cols)) {
                int* temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int sumElements(int** arr, int n, int m) {
    int k = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            k += *(*(arr + i) + j);
        }
    }
    return k;
}
int main() {
    int rows, cols;
    cout << "Enter number of rows ";
    cin >> rows;
    cout << "Enter number of columns ";
    cin >> cols;
    int** array = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        array[i] = new int[cols];
    }
    int k = 1;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Enter element " << k++ << " of array: ";
            cin >> array[i][j];
        }
    }
    int count = sumElements(array, rows, cols);
    cout << "Sum of array elements: " << count << endl;
    sortRowsBySum(array, rows, cols);
    cout << "Sorted array (by row sums): " << endl;
    Show(array, rows, cols);
    free2D(array, rows);
}

//7 tasks
#include <iostream>
#include <locale>
using namespace std;
void Sort(char** words, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            if (strcmp(words[j], words[j + 1]) > 0) {
                char* temp = words[j];
                words[j] = words[j + 1];
                words[j + 1] = temp;
            }
        }
    }
}
int main() {
    char** words= new char* [7];
    words[0] = const_cast<char*>("banana");
    words[1] = const_cast<char*>("apple");
    words[2] = const_cast<char*>("cherry");
    words[3] = const_cast<char*>("date");
    words[4] = const_cast<char*>("grape");
    words[5] = const_cast<char*>("fig");
    words[6] = const_cast<char*>("elderberry");
    int n = 7;
    Sort(words, n);
    for (int i = 0; i < 7; ++i) {
        cout << i + 1 << " word: " << words[i] << endl;
    }
}

//8 task
#include <iostream>
#include <locale>
using namespace std;
double** allocatePlate(double **arr2,int n, int m) {
    double** arr = new double* [n];
    for (int i = 0; i < n; ++i) {
        arr[i] = new double[m];
    }
    arr[0][0] = *(*(arr2 + 1) + 0) + *(*(arr2)+1);
    arr[0][m-1] = *(*(arr2 + 1) + m-1) + *(*(arr2)+m-2);
    arr[n-1][0] = *(*(arr2 + n-2) + 0) + *(*(arr2+n-1)+1);
    arr[n-1][m-1] = *(*(arr2 + n-2) + m-1) + *(*(arr2+n-1)+m-2);
    for (int i = 1; i < n-1; ++i) {
        arr[i][0] = *(*(arr2 + i) + 1) + *(*(arr2 + i + 1)) + *(*(arr2 + i - 1));
        arr[i][m-1] = *(*(arr2 + i)+m - 2) + *(*(arr2 + i + 1)+m-1) + *(*(arr2 + i - 1)+m-1);
    }
    for (int i = 1; i <  m- 1; ++i) {
        arr[0][i] = *(*(arr2 ) +i+ 1) + *(*(arr2  )+i-1) + *(*(arr2+1)+i);
        arr[n-1][i] = *(*(arr2 + n-2) +i) + *(*(arr2 + n-1)+i+1) + *(*(arr2 + n-1)+i - 1);
    }
    for (int i = 1; i < n-1; ++i) {
        for (int j = 1; j < m-1; ++j) {
            arr[i][j]= *(*(arr2 + i+1) + j)+ *(*(arr2 + i-1) + j)+ *(*(arr2 + i) + j-1)+ *(*(arr2 + i) + j+1);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m ; ++j) {
            arr2[i][j] = arr[i][j];
        }
    }
    return arr2;
}
void freePlate(double** plate, int n) {
    for (int i = 0; i < n; i++) {
        delete[] plate[i];
    }
    delete[]plate;
}
void updateTemperature(double** plate, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << plate[i][j] << " ";
        }
        cout << endl;
    }
}
int main() {
    int n, m, k;
    cout << "Enter number of iterations: "; cin >> k;
    cout << "Enter array length:  "; cin >> n;
    cout << "Enter array width: "; cin >> m;
    double** arr = new double* [n];
    for (int i = 0; i < n; ++i) {
        arr[i] = new double[m]; 
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            arr[i][j] = 20.0;
        }
    }
    for (int i = 0; i < k; ++i) {
        arr = allocatePlate(arr, n, m);
    }
    cout << "Final temperature distribution " << endl;
    updateTemperature(arr, n, m);
    freePlate(arr, n);
}

//9 task
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <locale>

using namespace std;

double** create_weights(int n, int m) {
    double** weights = new double* [n];
    for (int i = 0; i < n; i++) {
        weights[i] = new double[m];
        for (int j = 0; j < m; j++) {
            weights[i][j] = (rand() / (double)RAND_MAX) * 2.0 - 1.0;
        }
    }
    return weights;
}

double* create_inputs(int m) {
    double* inputs = new double[m];
    cout << "Enter " << m << " input values: ";
    for (int i = 0; i < m; i++) {
        cin >> inputs[i];
    }
    return inputs;
}

double* forward(double** weights, double* inputs, int n, int m) {
    double* outputs = new double[n];

    for (int i = 0; i < n; i++) {
        outputs[i] = 0.0;
        for (int j = 0; j < m; j++) {
            outputs[i] += weights[i][j] * inputs[j];
        }
    }

    return outputs;
}

void normalize_weights(double** weights, int n, int m) {
    for (int i = 0; i < n; i++) {
        double sum = 0.0;
        for (int j = 0; j < m; j++) {
            sum += abs(weights[i][j]);
        }
        if (sum > 1.0) {
            for (int j = 0; j < m; j++) {
                weights[i][j] /= sum;
            }
            cout << "Neuron " << i << " normalized (sum was: " << sum << ")" << endl;
        }
    }
}

void print_weights(double** weights, int n, int m) {
    cout << "\nWeight matrix " << n << "x" << m << ":" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Neuron " << i << ": ";
        for (int j = 0; j < m; j++) {
            cout << weights[i][j] << " ";
        }
        cout << endl;
    }
}

void print_outputs(double* outputs, int n) {
    cout << "\nCalculation results: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "Neuron output " << i << ": " << outputs[i] << endl;
    }
}

void free_memory(double** weights, double* inputs, double* outputs, int n) {
    
    if (weights != nullptr) {
        for (int i = 0; i < n; i++) {
            delete[] weights[i];
        }
        delete[] weights;
    }

    if (inputs != nullptr) {
        delete[] inputs;
    }
    if (outputs != nullptr) {
        delete[] outputs;
    }
}

int main() {
    srand(time(0));
    int n, m;

    cout << "Enter the number of neurons (N): ";
    cin >> n;
    cout << "Enter the number of inputs for each neuron (M): ";
    cin >> m;

    double** weights = create_weights(n, m);

    cout << "\nInitial weight matrix:" << endl;
    print_weights(weights, n, m);

    normalize_weights(weights, n, m);

    cout << "\nWeight matrix after normalization:" << endl;
    print_weights(weights, n, m);

    double* inputs = create_inputs(m);

    double* outputs = forward(weights, inputs, n, m);

    print_outputs(outputs, n);
    cout << "\nChecking the sum of weights after normalization:" << endl;
    for (int i = 0; i < n; i++) {
        double sum = 0.0;
        for (int j = 0; j < m; j++) {
            sum += abs(weights[i][j]);
        }
        cout << "Sum of the absolute values of a neuron's weights " << i << ": " << sum << endl;
    }
    free_memory(weights, inputs, outputs, n);

    cout << "\nMemory successfully freed!" << endl;

    return 0;
}

//10 task
#include <iostream>
#include <locale>
using namespace std;
double* averageLoadPerNode(int** load, int n, int t) {
    double* arr = new double[n];
    for (int i = 0; i < n; ++i) {
        double k = 0;
        for (int j = 0; j < t; ++j) {
            k += load[i][j];
        }
        arr[i] = k / t;
    }
    return arr;
}
int findCriticalInterval(int** load, int n, int t) {
    int maxSum = 0;
    int criticalInterval = 0;

    for (int j = 0; j < t; j++) {
        int currentSum = 0;
        for (int i = 0; i < n; i++) {
            currentSum += *(*(load + i) + j); 
        }

        if (currentSum > maxSum) {
            maxSum = currentSum;
            criticalInterval = j;
        }
    }

    return criticalInterval;
}
void freeMemory(int** load, int n) {
    if (load != nullptr) {
        for (int i = 0; i < n; i++) {
            delete[] load[i];
        }
        delete[] load;
    }

}
void inputLoadMatrix(int** load, int n, int t) {
    cout << "Enter load for each node by intervals: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "Node " << i << ": ";
        for (int j = 0; j < t; j++) {
            cin >> load[i][j];
            if (load[i][j] < 0 || load[i][j] > 100) {
                cout << "Error: load must be between 0-100%" << endl;
                j--; 
            }
        }
    }
}
void Show(int** arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        cout << "Node " << i << ": ";
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
void normalizeLoad(int** load, int n, int t) {
    int** tempLoad = new int* [n];
    for (int i = 0; i < n; ++i) {
        tempLoad[i] = new int[t];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < t; j++) {
            tempLoad[i][j] = load[i][j];
        }
    }

    for (int j = 0; j < t; j++) {
        for (int i = 0; i < n; i++) {
            if (tempLoad[i][j] > 80) {
                int overload = tempLoad[i][j] - 80;
                int amountToRedistribute = overload * 0.1;
                int nodesToReceive = 0;
                for (int k = 0; k < n; k++) {
                    if (k != i && tempLoad[k][j] < 100) {
                        nodesToReceive++;
                    }
                }

                if (nodesToReceive > 0) {
                    int perNode = amountToRedistribute / nodesToReceive;

                    load[i][j] -= amountToRedistribute;
                    for (int k = 0; k < n; k++) {
                        if (k != i && tempLoad[k][j] < 100) {
                            load[k][j] += perNode;
                            if (load[k][j] > 100) {
                                load[k][j] = 100;
                            }
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        delete[] tempLoad[i];
    }
    delete[] tempLoad;
}
int main() {
    setlocale(LC_ALL, "Russian");
    int n, m;
    cout << "Enter the number of nodes: "; cin >> n;
    cout << "Enter the number of intervals: "; cin >> m;
    int** arr = new int* [n];
    for (int i = 0; i < n; ++i) {
        arr[i] = new int[m];
    }
    inputLoadMatrix(arr, n, m);
    cout << "Initial values" <<  endl;
    Show(arr, n, m);
    double* sr = new double [n];
    sr = averageLoadPerNode(arr, n, m);
    cout << "\nAverage load on each node: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "Node " << i << ": " <<sr[i] << "%" << endl;
    }
    normalizeLoad(arr, n, m);
    cout << "After normalization" << endl;
    Show(arr, n, m);
    int criticalInterval = findCriticalInterval(arr, n, m);
    int totalLoad = 0;
    for (int i = 0; i < n; i++) {
        totalLoad += arr[i][criticalInterval];
    }

    cout << "\nCritical interval: " << criticalInterval
        << " (total load = " << totalLoad << "%)" << endl;
    freeMemory(arr, n);

}
