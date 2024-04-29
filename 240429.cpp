#include <iostream>


using namespace std;

int main()
{
	//errno_t

	FILE* pFile = NULL;
	FILE* pFile2 = NULL;
	errno_t errRead = fopen_s(&pFile, "Data/Image.jpg", "rb");
	errno_t errWrite = fopen_s(&pFile2, "Data/Myimage2.jpg", "wb");
	if (0 == errRead && 0 == errWrite)
	{
		while (0 == feof(pFile))
		{
			fputc(fgetc(pFile), pFile2);
			//fread(iTemp, sizeof(iTemp), 1, pFile);
		}
		fclose(pFile);
		fclose(pFile2);
	}
	else
	{
		cout << "error" << endl;
	}
}

#pragma region HW
//binary 입출력을 이용하여 이 texture를 복사해오세요
#pragma endregion