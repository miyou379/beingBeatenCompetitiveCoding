#include <iostream>
int p10[][1] = {{1}, {10}, {100}, {1000}};
int y = 7788;
const int p20[] = {1, 20, 400, 8000};

int main() {
    std::cout << p10[0][1] << "\n" << p20[-1];
}
