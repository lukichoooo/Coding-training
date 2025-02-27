#include <iostream>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    int arr[20];
    for (int i = 0; i < 20; ++i) {
        arr[i] = rand() % 201 - 100;
    }

    int minP = 0x7FFFFFFF;
    int maxN = 0x80000000;
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i) {
        if(arr[i] > 0){

        if(arr[i] < minP){
            minP = arr[i];
        }
    } else {
        if(arr[i] > maxN){
            maxN = arr[i];
        }
    }
}
    cout << "Min Positive: " << minP << ", Max Negative: " << maxN << endl;

    return 0;
}