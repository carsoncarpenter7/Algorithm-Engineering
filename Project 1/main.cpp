#include <iostream>
#include <chrono>
#include <vector>
#include <time.h>

using namespace std;

float mean(vector<int> array) {
    auto total = 0;
    for (auto x : array) total += x;
    return (float) total / array.size();
}

vector<vector<float>> construct_square_matrix(int size, float value) {
    vector<vector<float>> matrix(size, vector<float>(size));
    for (auto& row : matrix) for (auto& element : row) element = value;
    return matrix;
}

void test_mean(int size) {
    vector<int> array(size);
    for (auto& x : array) x = rand() % 100;

    auto start = chrono::system_clock::now();

    auto average = mean(array);

    auto duration = std::chrono::duration<float>(chrono::system_clock::now() - start).count();

    cout << "Mean of array (size " << array.size() << ") calculated in " << duration << " seconds.\n";
}

void test_square_matrix(int size) {
    auto value = float(rand()) / float(RAND_MAX); // [0.0f, 1.0f]

    auto start = chrono::system_clock::now();

    auto matrix = construct_square_matrix(size, value);

    auto duration = std::chrono::duration<float>(chrono::system_clock::now() - start).count();

    cout << size << "x" << size << " matrix created in " << duration << " seconds.\n";
}

int main() {
    srand(time(nullptr));

    test_mean(10000000);
    test_mean(15000000);
    test_mean(20000000);
    test_mean(25000000);
    test_mean(30000000);
    test_mean(35000000);
    test_mean(40000000);
    test_mean(45000000);
    test_mean(50000000);

    test_square_matrix(5000);
    test_square_matrix(10000);
    test_square_matrix(15000);
    test_square_matrix(20000);
    test_square_matrix(25000);
    test_square_matrix(30000);
    test_square_matrix(35000);
    test_square_matrix(40000);
    test_square_matrix(45000);

}
