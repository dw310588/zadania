#include <iostream>

int main() {
    const int KOD_SIZE = 12; 
    int kod[KOD_SIZE] = {11,10,96,43,15,17,55,17,55,19,13,17};
    int arr[4];
    int counter = 0;
    for(int i = 0; i < KOD_SIZE; i++) {
        if(counter > 1) {
            break;
        }
        if(kod[i] % 2 == 1) {
            arr[counter] = kod[i];
            counter++;
        }
    }
    for(int i = KOD_SIZE-1; i >= 0; i--) {
        if(counter > 3) {
            break;
        }
        if(kod[i] % 2 == 1) {
            arr[counter] = kod[i];
            counter++;
        }
    }
    std::cout << "{ ";
    for(int i = 0; i < 4; i++) {
        arr[i] = arr[i] / 10;
        std::cout << arr[i] << " ";
    }
    std::cout << "}" << std::endl;
    return 0;
}
