#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
//this program just work only in visual studio
int main()
{
	unsigned char key[11], convert[4];
	int i;
	unsigned int tempDword;
	unsigned char tempByte, tempByte2;
	srand((unsigned int)time(NULL));
	Start:
	for(i = 0; i < 11; i++) key[i] = (rand() % 0x5d) + 0x21;
	//transform on numbers 2-5
	for(i = 0; i < 4; i++)
	{
		convert[i] = key[i + 2] + (14 - i);
		if(convert[i] > 0x7b) convert[i] = convert[i] >> 1;
	}
	tempDword = *(unsigned int*)(convert);
	__asm
	{
		//convert to 18 digit and add perform math 
		pushad;
		push 0;
		push 0;
		mov eax, [tempDword];
		push eax;
		fild qword ptr[esp];
		fbstp [esp];
		pop ecx;
		pop eax;
		pop eax;
		mov edx, ecx;
		shr ecx, 4;
		and edx, 0x0f0f0f0f;
		and ecx, 0x0f0f0f0f;
		add edx, 0x30303030;
		add ecx, 0x30303030;
		//get low word
		mov [tempByte], cl;
		mov [tempByte2], dl;
		popad;
	}
	key[0] = tempByte;
	key[1] = tempByte2;
	//reverse of math ((ax + bx) ^ 0x1b3f) - 0x123
	*(unsigned short*)key += 0x1a1c;
	//reverse transform
	key[0] -= 16;
	key[1] -= 15;
	if(key[0] < 0x21 || key[1] < 0x21) goto Start;
	cout << "Key: ";
	for(i = 0; i < 11; i++) cout << key[i];
	cout << endl;
	system("pause");
	return 0;
}