#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>

using namespace std;

bool isPrime(int num) {
    if (num < 2) return false; 
    if (num == 2) return true; 
    if (num % 2 == 0) return false; 
    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

bool isPowerOfTwo(int num) {
    return (num > 0) && !(num & (num - 1)) && (num != 1);
}

int main(int argc, char* argv[]) {
    setlocale(LC_CTYPE, "rus");
    bool isHuman = false;
	if (argc <= 1 || strcmp(argv[1], "false") != 0)
	{
		isHuman = true;
	}
    int N;
    if(isHuman) cout << "Введите число значений: ";
    cin >> N;
    int countMultiplesOfFive = 0;
    int countPowersOfTwo = 0;
    int sum = 0;
    int maxNum = INT_MIN;
    int minNum = INT_MAX;
    int a, prev1 = 0, prev2 = 0;
    int countGreaterThanSumOfTwo = 0;
    string primeNumbers;
    for (int i = 0; i < N; ++i) {
        if(isHuman) cout << "Введите число " << i+1 << ". ";
        cin >> a;
        if (isPrime(a)) {
            primeNumbers += to_string(a) + "\n";
        }
        sum += a;
        if (a > maxNum) maxNum = a;
        if (a < minNum) minNum = a;
        if (a % 5 == 0) {
            countMultiplesOfFive++;
        }
        if (isPowerOfTwo(a)) {
            countPowersOfTwo++;
        }
        if (i >= 2 && a > (prev1 + prev2)) {
            countGreaterThanSumOfTwo++;
        }
        prev2 = prev1;
        prev1 = a;
    }
    double average = static_cast<double>(sum) / N;
    if(isHuman){
        cout << "Bсе числа последовательности, являющиеся простыми числами (в том же порядке): " << endl;
        cout << primeNumbers;
        cout << "Среднее арифметическое значение: " << endl;
        cout << fixed << setprecision(2) << average << endl;
        cout << "Размах ряда: " << endl;
        cout << (maxNum - minNum) << endl;
        cout << "Количество чисел, кратных числу 5: " << endl;
        cout << countMultiplesOfFive << endl;
        cout << "Количество чисел, являющихся степенью двойки:" << endl;
        cout << countPowersOfTwo << endl;
        cout << "Kоличество чисел, превышающих сумму двух предшествующих членов последовательности: " << endl;
        cout << countGreaterThanSumOfTwo << endl;
    }
    else{
        cout << primeNumbers << endl;
        cout << fixed << setprecision(2) << average << endl;
        cout << (maxNum - minNum) << endl;
        cout << countMultiplesOfFive << endl;
        cout << countPowersOfTwo << endl;
        cout << countGreaterThanSumOfTwo << endl;
    }
    return 0;
}
