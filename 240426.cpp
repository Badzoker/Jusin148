#include <iostream>

using namespace std;

int main()
{
	char szName[8] = {};
	gets_s(szName, sizeof(szName));
	
	puts(szName);

	//fgets(szName, sizeof(szName),stdin);
	//
	//fputs(szName, stdout);
	return 0;
}