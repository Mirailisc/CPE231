#include <iostream>
#include <vector>

using namespace std;
void loopRecursive(int n) {

    if (n == 10) {
        return;    
    }

    cout << "Nigga#" <<  n << endl;

    return loopRecursive(n + 1);
}

int main()
{
    loopRecursive(1);

    return 0;
}
