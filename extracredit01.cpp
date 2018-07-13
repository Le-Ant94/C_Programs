//  Anthony Le
//  extracredit01

#include <iostream>
using namespace std;

int coins[] = {1, 2, 5, 10, 20, 50, 100, 200};

int PrintCombo(int num, int* arr, int index){
    if (num == 0)
        return 1;
    int combinations = 0;
    for (int i = 0; i < 8; i++){ // 8 coin values
        if (coins[i] > num)
            continue;
        if (index != 0 && coins[i] > arr[index - 1])
            continue;
        arr[index] = coins[i];
        combinations += PrintCombo(num - coins[i], arr, index + 1);
    }
    return combinations;
}

int main()

{
    int num = 200;
    int *arr = new int[num];
    cout << PrintCombo(num, arr, 0);
    cout << '\n';
}