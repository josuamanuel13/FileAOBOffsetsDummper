#include "AOB.h"
#include "Utils.h"
#include "main.h"
#include <Windows.h>

void StartLoggingOffsets()
{
	std::cout << "Logging Offsets\n";
	std::ofstream offsets("../debug/Offsets.h");
	
	
	offsets << "#pragma once\n\n";
	offsets << "namespace dump {\n";
	
	if (GetTruePosition.contains == true)
	{
		for (int i = 0; i < GetTruePosition.times; i++)
		{
			GetTruePosition.RVAOffsets[i] = FileOffsetToRVA(ih, GetTruePosition.RawFileOffsets[i]);
			if (GetTruePosition.times - 2 == i)
			{
				offsets << "\tinline uintptr_t " << GetTruePosition.Name << "_Recomended" << " = " << "0x" << std::hex << GetTruePosition.RVAOffsets[i] << ";\n";
			}
			else
			{
				offsets << "\tinline uintptr_t " << GetTruePosition.Name << "_" << i << " = " << "0x" << std::hex << GetTruePosition.RVAOffsets[i] << ";\n";
			}


		}
	}

	if (FindPlayerByID.contains == true)
	{
		for (int i = 0; i < FindPlayerByID.times; i++)
		{
			FindPlayerByID.RVAOffsets[i] = FileOffsetToRVA(ih, FindPlayerByID.RawFileOffsets[i]);
			offsets << "\tinline uintptr_t " << FindPlayerByID.Name << "_" << i << " = " << "0x" << std::hex << FindPlayerByID.RVAOffsets[i] << ";\n";
		}
	}

	if (getPlayerCount.contains == true)
	{
		for (int i = 0; i < getPlayerCount.times; i++)
		{
			getPlayerCount.RVAOffsets[i] = FileOffsetToRVA(ih, getPlayerCount.RawFileOffsets[i]);
			if (getPlayerCount.times - 1 == i)
			{
				offsets << "\tinline uintptr_t " << getPlayerCount.Name << "_Recomended" << " = " << "0x" << std::hex << getPlayerCount.RVAOffsets[i] << ";\n";
			}
			else
			{
				offsets << "\tinline uintptr_t " << getPlayerCount.Name << "_" << i << " = " << "0x" << std::hex << getPlayerCount.RVAOffsets[i] << ";\n";
			}
			

		}
	}

	if (InnerNetUpdate.contains == true)
	{
		for (int i = 0; i < InnerNetUpdate.times; i++)
		{
			InnerNetUpdate.RVAOffsets[i] = FileOffsetToRVA(ih, InnerNetUpdate.RawFileOffsets[i]);
			offsets << "\tinline uintptr_t " << InnerNetUpdate.Name << "_" << i << " = " << "0x" << std::hex << InnerNetUpdate.RVAOffsets[i] << ";\n";
		}
	}

	if (IsGameOver.contains == true)
	{
		for (int i = 0; i < IsGameOver.times; i++)
		{
			IsGameOver.RVAOffsets[i] = FileOffsetToRVA(ih, IsGameOver.RawFileOffsets[i]);
			offsets << "\tinline uintptr_t " << IsGameOver.Name << "_" << i << " = " << "0x" << std::hex << IsGameOver.RVAOffsets[i] << ";\n";
		}
	}

	if (getMainCamera.contains == true)
	{
		for (int i = 0; i < getMainCamera.times; i++)
		{
			getMainCamera.RVAOffsets[i] = FileOffsetToRVA(ih, getMainCamera.RawFileOffsets[i]);
			offsets << "\tinline uintptr_t " << getMainCamera.Name << "_" << i << " = " << "0x" << std::hex << getMainCamera.RVAOffsets[i] << ";\n";
		}
	}

	if (w2s.contains == true)
	{
		for (int i = 0; i < w2s.times; i++)
		{
			w2s.RVAOffsets[i] = FileOffsetToRVA(ih, w2s.RawFileOffsets[i]);
			offsets << "\tinline uintptr_t " << w2s.Name << "_" << i << " = " << "0x" << std::hex << w2s.RVAOffsets[i] << ";\n";
		}
	}

	if (GetTranform.contains == true)
	{
		for (int i = 0; i < GetTranform.times; i++)
		{
			GetTranform.RVAOffsets[i] = FileOffsetToRVA(ih, GetTranform.RawFileOffsets[i]);
			offsets << "\tinline uintptr_t " << GetTranform.Name << "_" << i << " = " << "0x" << std::hex << GetTranform.RVAOffsets[i] << ";\n";
		}
	}

	if (TransformGetPos.contains == true)
	{
		for (int i = 0; i < TransformGetPos.times; i++)
		{
			TransformGetPos.RVAOffsets[i] = FileOffsetToRVA(ih, TransformGetPos.RawFileOffsets[i]);
			offsets << "\tinline uintptr_t " << TransformGetPos.Name << "_" << i << " = " << "0x" << std::hex << TransformGetPos.RVAOffsets[i] << ";\n";
		}
	}

	if (TranformSetPos.contains == true)
	{
		for (int i = 0; i < TranformSetPos.times; i++)
		{
			TranformSetPos.RVAOffsets[i] = FileOffsetToRVA(ih, TranformSetPos.RawFileOffsets[i]);
			offsets << "\tinline uintptr_t " << TranformSetPos.Name << "_" << i << " = " << "0x" << std::hex << TranformSetPos.RVAOffsets[i] << ";\n";
		}
	}

	offsets << "} //Offset ByPattern";
	offsets.close();

	
}

void AOBScan()
{
	Contains(&IMAGE_NT_HEADER_32, IMAGE_NT_HEADER_32Arr);
	Contains(&GetTruePosition, GetTruePositionArr);
	Contains(&FindPlayerByID, FindPlayerByIDArr);
	Contains(&getPlayerCount, getPlayerCountArr);
	Contains(&InnerNetUpdate, InnerNetUpdateArr);
	Contains(&IsGameOver, IsGameOverArr);
	Contains(&getMainCamera, getMainCameraArr);
	Contains(&w2s, w2sArr);
	Contains(&GetTranform, GetTranformArr);
	Contains(&TransformGetPos, TransformGetPosArr);
	Contains(&TranformSetPos, TranformSetPosArr);
}

