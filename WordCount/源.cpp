#include<iostream>
using namespace std;

int main(int argc, char* argv[])
{
	char fileName[80] = { 0 };
	char str[10000];
	FILE* file;
	int count,i;
	memcpy(fileName, argv[2], sizeof(argv[2]));

	if (strcmp(argv[1], "-c")==0) {
		if ((file = fopen(fileName, "r"))==NULL) 
		{
			cout << "Can't open file " << fileName << endl;
			exit(1);
		}
		count = 0;
		while (fgetc(file) != EOF)
		{
			count++;
		}
		fclose(file);
		cout << "该文件共有" << count << "个字符" << endl;
	}
	if (strcmp(argv[1], "-w")==0)
	{
		if ((file = fopen(fileName, "r")) == NULL)
		{
			cout << "Can't open file " << fileName << endl;
			exit(1);
		}
		count = 0;
		fgets(str, 10000, file);
		for (i = 0; str[i] != '\0'; i++)
		{
			if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z')
			{
				str[i] = str[i];
			}
			else
			{
				str[i] = ' ';
			}
		}
		for (i = 0; str[i] != '\0'; i++)
		{
			if (str[i] == ' ' && str[i + 1] != ' ')
			{
				count++;
			}
		}
		if (str[0] != '\0')
		{
			if (str[i - 1] != ' ')
			{
				count++;
			}
		}
		cout << "该文件共有" << count << "个单词" << endl;
	}
}
