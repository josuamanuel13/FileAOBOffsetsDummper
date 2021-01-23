#include "FILE.h"
#include "AOB.h"
#include "Globals.h"
#include "Structs.h"
#include "Utils.h"
#include "main.h"

void HandleOffsetLogFile(const char* szfile)
{
	int length = lengthChar((char*)szfile);
	char ModuleName[256];
	for (int i = length; i > 0; i--)
	{
		if (szfile[i] == '/')
		{
			i++;
			strcpy(&ModuleName[0], &szfile[i]);
			break;
		}

		if (i == 1)
		{
			strcpy(ModuleName, szfile);
		}
	}
	
	
	if (IMAGE_NT_HEADER_32.times)
	{
		std::cout << "Getting Dll Base Addr\n";
		uintptr_t DllEntryAddr = (uintptr_t)GetModuleHandle(ModuleName);

		if (!DllEntryAddr)
		{
			std::cout << "Couldnt Get Dll Base Addr Closing";
			return;
		}
		
		std::cout << "Getting IMAGE_NT_HEADERS\n";
		ih = (IMAGE_NT_HEADERS32*)(DllEntryAddr + IMAGE_NT_HEADER_32.RawFileOffsets[0]);

		StartLoggingOffsets();
	}

	std::cout << "Done Offset Saved" << std::endl;
}

void StartAOBScan(const char* szfile)
{
	int i = 0;
	int lastBuff = 0;
	std::cout << "Finding IMAGE_NT_HEADER Offset\n";
	std::cout << "Starting AOB Scan\n";


	//std::string parameter = BinaryPos;



	if (!hinst)
	{
		return;
	}

	// open a file
	std::ifstream in = std::ifstream(szfile, std::ios::binary);
	if (!in.is_open()) { std::cout << "Error: File Path is Wrong" << std::endl; }

	// Get file size, file name
	long long Beg = in.tellg();
	in.seekg(0, std::ios::end);
	long long End = in.tellg();
	long long fileSize = End - Beg;



	in.seekg(0, std::ios::beg);
	std::cout << "File Size: " << fileSize / 1024.0 << "KB" << std::endl;

	// Read the file (read 1 byte per cycle)
	int byteBeenRead = 0;
	char hexNumber[9] = "00000000";
	unsigned char temp;
	while (in.read((char*)&temp, 1))
	{
		// Line break every 16 bytes read
		if (byteBeenRead % 16 == 0)
		{
			// Set the row subscript
			//cout << endl;
			//setIndex(byteBeenRead, hexNumber);
			//cout << hexNumber << ":\t";
		}
		// read 1 byte
		int hex = (unsigned)temp;
		char a = HEX[hex / 16];
		char b = HEX[hex % 16];

		cb[i].a = a;
		cb[i].b = b;
		i++;
		byteBeenRead++;

		if (i == 4096)
		{

			lastBuff += 4096;
			i = 0;

			AOBScan();
			chunckTimes++;
		}




	}
	std::cout << "AOB Scan Finished\n";
	in.close();

	HandleOffsetLogFile(szfile);
}


