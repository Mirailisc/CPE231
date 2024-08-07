#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cout << "Hello, World!" << endl;

    vector<int> myVector;

    myVector.push_back(10);
    myVector.push_back(20);
    myVector.push_back(30);

    cout << "Before Pop: ";
    for (int i = 0; i < myVector.size(); i++)
    {
        cout << myVector[i] << " ";
    }
    cout << endl;

    cout << myVector.size() << endl;

    myVector.pop_back();

    cout << "After Pop: ";
    for (int i = 0; i < myVector.size(); i++)
    {
        cout << myVector[i] << " ";
    }
    cout << endl;

    auto a = 10;
    cout << "auto: " << a << endl;

    vector<int> vectorTwo;

    for(int i = 0; i < 10; i++) {
        vectorTwo.push_back(i + 1);
    }

    cout << "Vector Two: " << endl;
    for (auto el : vectorTwo) {
        cout << "Nigga #" << el << endl;
    }

    return 0;
}
