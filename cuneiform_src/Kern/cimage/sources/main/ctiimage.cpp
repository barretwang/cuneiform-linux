/*
Copyright (c) 1993-2008, Cognitive Technologies
All rights reserved.

����������� ��������� ��������������� � ������������� ��� � ���� ��������� ����,
��� � � �������� �����, � ����������� ��� ���, ��� ���������� ��������� �������:

      * ��� ��������� ��������������� ��������� ���� ������ ���������� ���������
        ���� ����������� �� ��������� �����, ���� ������ ������� � ����������� 
        ����� �� ��������. 
      * ��� ��������� ��������������� ��������� ���� � ������������ �/��� � 
        ������ ����������, ������������ ��� ���������������, ������ �����������
        ��������� ���� ���������� �� ��������� �����, ���� ������ ������� �
        ����������� ����� �� ��������.  
      * �� �������� Cognitive Technologies, �� ����� �� ����������� �� ����� 
        ���� ������������ � �������� �������� ��������� �/��� ����������� 
        ���������, ���������� �� ���� ��, ��� ���������������� �����������
        ����������. 

��� ��������� ������������� ����������� ��������� ���� �/��� ������� ������ "���
��� ����" ��� ������-���� ���� ��������, ���������� ���� ��� ���������������, 
������� �������� ������������ �������� � ����������� ��� ���������� ����, �� ��
������������� ���. �� �������� ��������� ���� � �� ���� ������ ����, ������� 
����� �������� �/��� �������� �������������� ���������, �� � ���� ������ �� 
��Ѩ� ���������������, ������� ����� �����, ���������, ����������� ��� 
������������� ������, ��������� � �������������� ��� ���������� ���������� 
������������� ������������� ��������� (������� ������ ������, ��� ������, 
������� ���������, ��� ������ �/��� ������ �������, ���������� ��-�� �������� 
������� ��� �/��� ������ ��������� �������� ��������� � ������� �����������, 
�� �� ������������� ����� ��������), �� �� ������������� ���, ���� ���� ����� 
�������� ��� ������ ���� ���� �������� � ����������� ����� ������� � ������.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright notice,
      this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright notice,
      this list of conditions and the following disclaimer in the documentation
      and/or other materials provided with the distribution.
    * Neither the name of the Cognitive Technologies nor the names of its
      contributors may be used to endorse or promote products derived from this
      software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE 
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL 
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR 
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, 
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#define __CIMAGE__

#include "resource.h"
#include "ctidefines.h"
#include "ctiimage.h"
#include "ctimemory.h"

#include "cticontrol.h"

// exteren globals
extern CTIControl * Control;
// extern functions
void SetReturnCode(Word16 rc);
Word16 GetReturnCode();

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
CIMAGE_FUNC(Bool32) CIMAGE_WriteCallbackImage(PWord8                 lpName, 
											  CIMAGEIMAGECALLBACK  Cbk)
{
	SetReturnCode(IDS_CIMAGE_ERR_NO);

	if ( Control )
		return Control->WriteCBImage( (PChar8)lpName, Cbk );

	SetReturnCode(IDS_CIMAGE_DLL_NOT_INITIALISING);
	return FALSE;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
CIMAGE_FUNC(Bool32) CIMAGE_GetCallbackImage(PWord8                  lpName, 
											PCIMAGEIMAGECALLBACK  pCbk)
{
	Bool32 A = FALSE;
	SetReturnCode(IDS_CIMAGE_ERR_NO);

	if ( Control )
		A = Control->GetCBImage( (PChar8)lpName, pCbk );
	else
		SetReturnCode(IDS_CIMAGE_DLL_NOT_INITIALISING);

	return A;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
CIMAGE_FUNC(Bool32) CIMAGE_WriteDIB(PWord8    lpName,
									Handle  lpDIB,
									Word32  wFlag)
{
	Bool32 A = FALSE;
	SetReturnCode(IDS_CIMAGE_ERR_NO);

	if ( Control )
		A = Control->SetDIB( (PChar8)lpName, lpDIB, wFlag );
	else
		SetReturnCode(IDS_CIMAGE_DLL_NOT_INITIALISING);
	
	return A;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
CIMAGE_FUNC(Bool32) CIMAGE_ReadDIB(PWord8     lpName,
								   PHandle  lplpDIB,
								   Word32   wFlag)
{
	Bool32 A = FALSE;
	SetReturnCode(IDS_CIMAGE_ERR_NO);

	if ( Control )
		A = Control->GetDIB( (PChar8)lpName, lplpDIB, wFlag );
	else
		SetReturnCode(IDS_CIMAGE_DLL_NOT_INITIALISING);

	return A;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
CIMAGE_FUNC(Bool32) CIMAGE_GetData(PWord8                     lpName, 
								   PCIMAGE_InfoDataInGet       lpIn,
								   PCIMAGE_InfoDataOutGet      lpOut)
{
	Bool32 A = FALSE;
	SetReturnCode(IDS_CIMAGE_ERR_NO);

	if ( Control )
		A = Control->GetImage( (PChar8)lpName, lpIn, lpOut );
	else
		SetReturnCode(IDS_CIMAGE_DLL_NOT_INITIALISING);

	return A;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
CIMAGE_FUNC(Bool32) CIMAGE_GetDIBData(PWord8                      lpName, 
								      PCIMAGE_InfoDataInGet       lpIn,
								      PInt8                       *lpDIB)
{
	Bool32 A = FALSE;
	SetReturnCode(IDS_CIMAGE_ERR_NO);

	if ( Control )
		A = Control->GetDIBFromImage( (PChar8)lpName, lpIn, lpDIB );
	else
		SetReturnCode(IDS_CIMAGE_DLL_NOT_INITIALISING);

	return A;
}/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
CIMAGE_FUNC(Bool32) CIMAGE_ReplaceData(PWord8                        lpName, 
									   PCIMAGE_InfoDataInReplace   lpIn )
{
	Bool32 A = FALSE;
	SetReturnCode(IDS_CIMAGE_ERR_NO);

	if ( Control )
		A = Control->ReplaceImage( (PChar8)lpName, lpIn );
	else
		SetReturnCode(IDS_CIMAGE_DLL_NOT_INITIALISING);

	return A;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
CIMAGE_FUNC(Bool32) CIMAGE_GetImageInfo(PWord8                     lpName, 
										PCIMAGEBITMAPINFOHEADER  lpBIH)
{
	Bool32 A = FALSE;
	SetReturnCode(IDS_CIMAGE_ERR_NO);

	if ( Control )
		A = Control->GetImageInfo( (PChar8)lpName, lpBIH );
	else
		SetReturnCode(IDS_CIMAGE_DLL_NOT_INITIALISING);

	return A;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
CIMAGE_FUNC(Bool32) CIMAGE_DeleteImage( PWord8  lpName)
{
	SetReturnCode(IDS_CIMAGE_ERR_NO);

	if ( Control )
		return Control->RemoveImage( (PChar8)lpName );

	SetReturnCode(IDS_CIMAGE_DLL_NOT_INITIALISING);
	return FALSE;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
CIMAGE_FUNC(Bool32) CIMAGE_FreeCopedDIB(Handle hDIB)
{
	SetReturnCode(IDS_CIMAGE_ERR_NO);
	
	if ( Control )
		return Control->FreeAlloced( hDIB );

	SetReturnCode(IDS_CIMAGE_DLL_NOT_INITIALISING);
	return FALSE;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
CIMAGE_FUNC(Bool32) CIMAGE_FreeBuffers()
{
	SetReturnCode(IDS_CIMAGE_ERR_NO);
	
	if ( Control )
		return Control->FreeBuffers();

	SetReturnCode(IDS_CIMAGE_DLL_NOT_INITIALISING);
	return FALSE;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
CIMAGE_FUNC(Bool32) CIMAGE_Reset(void)
{
	SetReturnCode(IDS_CIMAGE_ERR_NO);
	
	if ( Control )
	{
		delete Control;

		Control = new CTIControl;

		if ( Control )
			return TRUE;
		return FALSE;
	}

	SetReturnCode(IDS_CIMAGE_DLL_NOT_INITIALISING);
	return FALSE;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
CIMAGE_FUNC(Bool32) CIMAGE_AddReadCloseRects(PWord8 lpName, Word32 wCount, PCIMAGE_Rect pFirst)
{
	SetReturnCode(IDS_CIMAGE_ERR_NO);

	if ( Control )
		return Control->AddReadRectangles( (PChar8)lpName, wCount, pFirst );

	SetReturnCode(IDS_CIMAGE_DLL_NOT_INITIALISING);
	return FALSE;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
CIMAGE_FUNC(Bool32) CIMAGE_RemoveReadCloseRects(PWord8 lpName, Word32 wCount, PCIMAGE_Rect pFirst)
{
	SetReturnCode(IDS_CIMAGE_ERR_NO);

	if ( Control )
		return Control->RemoveReadRectangles( (PChar8)lpName, wCount, pFirst );

	SetReturnCode(IDS_CIMAGE_DLL_NOT_INITIALISING);
	return FALSE;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
CIMAGE_FUNC(Bool32) CIMAGE_AddWriteCloseRects(PWord8 lpName, Word32 wCount, PCIMAGE_Rect pFirst)
{
	SetReturnCode(IDS_CIMAGE_ERR_NO);

	if ( Control )
		return Control->AddWriteRectangles( (PChar8)lpName, wCount, pFirst );

	SetReturnCode(IDS_CIMAGE_DLL_NOT_INITIALISING);
	return FALSE;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
CIMAGE_FUNC(Bool32) CIMAGE_RemoveWriteCloseRects(PWord8 lpName, Word32 wCount, PCIMAGE_Rect pFirst)
{
	SetReturnCode(IDS_CIMAGE_ERR_NO);

	if ( Control )
		return Control->RemoveWriteRectangles( (PChar8)lpName, wCount, pFirst );

	SetReturnCode(IDS_CIMAGE_DLL_NOT_INITIALISING);
	return FALSE;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
CIMAGE_FUNC(Bool32) CIMAGE_EnableMask(PWord8 lpName, PWord8 lpType, Bool32 bEnabler)
{
	SetReturnCode(IDS_CIMAGE_ERR_NO);

	if ( Control )
		return Control->EnableMask((PChar8)lpName, (PChar8)lpType, bEnabler);

	SetReturnCode(IDS_CIMAGE_DLL_NOT_INITIALISING);
	return FALSE;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
// For GetCBImage
CIMAGE_CALLBACK_FUNC(CIMAGEBOOL16) CIMAGE_Callback_ImageOpen(PCIMAGE_ImageInfo lpImageInfo)
{
	Bool16 A = FALSE;

	if ( !Control )
	{
		SetReturnCode(IDS_CIMAGE_DLL_NOT_INITIALISING);
		return FALSE;
	}

	A = (CIMAGEBOOL16)(Control->CBImageOpen(lpImageInfo));

	return A;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
CIMAGE_CALLBACK_FUNC(CIMAGEWORD)   CIMAGE_Callback_ImageRead(PInt8  lpImage, Word16 wMaxSize)
{
	if ( !Control )
	{
		SetReturnCode(IDS_CIMAGE_DLL_NOT_INITIALISING);
		return 0;
	}

	return (CIMAGEWORD)(Control->CBImageRead((PChar8)lpImage, wMaxSize));
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
CIMAGE_CALLBACK_FUNC(CIMAGEBOOL16) CIMAGE_Callback_ImageClose(void)
{
	if ( !Control )
	{
		SetReturnCode(IDS_CIMAGE_DLL_NOT_INITIALISING);
		return FALSE;
	}

	return (CIMAGEBOOL16)(Control->CBImageClose());
}
////////////////////////////////////////////////////////////////////////////////////////////////////
// end of file