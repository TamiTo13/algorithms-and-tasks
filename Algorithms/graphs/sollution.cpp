#include <iostream>

int f(const int& n, int it) {
    if(it > n) return 0;
    if(it == n) return 1;

    return f(n, it+1) + f(n, it+2);
}

int main() {
    std::cout<<f(10, 0);

}