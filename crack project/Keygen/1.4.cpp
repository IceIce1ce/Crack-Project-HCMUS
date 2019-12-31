#include<iostream>
#include<string.h>
using namespace std;

int main()
{
    char name[100], serial[100];
    int temp = 0;
    cout << "Name: ";
    cin.getline(name, 100);
    _strrev(name); //reverse name
    for(int i = 0; i < strlen(name); i++) temp -= (name[i] - 0x20);
    sprintf(serial,"%08X", temp); //convert temp to base hexa, then convert to string for storing to serial
    _strrev(serial); //reverse serial
    system("cls");
    cout << "Name           : " << name << endl;
    cout << "Your serial    : " << serial << endl;
    system("pause");
    return 0; 
}