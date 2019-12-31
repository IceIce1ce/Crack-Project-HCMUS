#include<iostream>
using namespace std;

int main()
{
    int EBP = 200;
    int EDX = EBP;
    int EAX = EDX;
    EAX = EAX << 2;
    EAX = EAX + EDX;
    EAX = EAX ^ 100;
    EAX = ~EAX;
    int key;
    cout << "Please enter a key: ";
    cin >> key;
    if(key != EAX) cout << "Better luck next time! You are unsuccessful." << endl;
    else if(key == EAX) cout << "Congratulation! You are successful." << endl;
    system("pause");
    return 0;
}