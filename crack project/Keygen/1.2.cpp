#include<iostream>
using namespace std;

int main()
{
    int id;
    cout << "Enter number from 0 to 9999: ";
    cin >> id;
    int serial = 0;
    serial += id + 76 + 1 + 907;
    serial += serial;
    serial *= 3;
    serial -= 1;
    cout << "Serial: "<< serial << endl;
    system("pause");
    return 0;
}