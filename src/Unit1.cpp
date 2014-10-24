?/*
** ReleaseMaker
** Copyright (C) 2014 Krinkels Inc
** Contact: site: http://krinkels.org/

** Этот файл — часть ReleaseMaker.
**
** ReleaseMaker - свободная программа: вы можете перераспространять ее и/или
** изменять ее на условиях Стандартной общественной лицензии GNU в том виде,
** в каком она была опубликована Фондом свободного программного обеспечения;
** либо версии 3 лицензии, либо (по вашему выбору) любой более поздней
** версии.
**
** ReleaseMaker распространяется в надежде, что она будет полезной,
** но БЕЗО ВСЯКИХ ГАРАНТИЙ; даже без неявной гарантии ТОВАРНОГО ВИДА
** или ПРИГОДНОСТИ ДЛЯ ОПРЕДЕЛЕННЫХ ЦЕЛЕЙ. Подробнее см. в Стандартной
** общественной лицензии GNU.
**
** Вы должны были получить копию Стандартной общественной лицензии GNU
** вместе с этой программой. Если это не так, см.
** <http://www.gnu.org/licenses/>.)
**
*/
//---------------------------------------------------------------------------

#include <vcl.h>
#include <StrUtils.hpp>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"

#include <wchar.h>
#include <io.h>
#include <stdio.h>
#include <stdlib.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

String MyBuf;
wchar_t g_tszRoot[ MAX_PATH ] = {0};

typedef struct
{
	wchar_t Screen[ 10 ];
	wchar_t Description[ 10 ];

	wchar_t DopContent[ 10 ];
	wchar_t OsobIgri[ 10 ];
	wchar_t OsobRep[ 10 ];
	wchar_t MyList[ 256 ];
	wchar_t Path[ MAX_PATH ];
}MySetting;

MySetting Setting;

#define SIZEOF(X) (sizeof(X)/sizeof(X[0]))

int PathIsAbsolute( const String path )
{
	if( path.c_str() && path.Length() > 2 )
		if( ( path[ 2 ] == ':' && path[ 3 ] == '\\' ) || ( path[ 1 ] == '\\' && path[ 2 ] == '\\' ) )
			return 1;
	return 0;
}

int PathToAbsolute( const wchar_t *pSrc, wchar_t *pOut )
{
	if (!pSrc || !pSrc[ 0 ] || wcslen( pSrc ) > MAX_PATH)
	 {
		pOut = 0;
		return 0;
	}

	wchar_t buf[ MAX_PATH ];
	if( pSrc[ 0 ] < ' ' )
		return snwprintf( pOut, MAX_PATH, L"%s", pSrc );

	if( PathIsAbsolute( pSrc ) )
		return GetFullPathName( pSrc, MAX_PATH, pOut, NULL );

	if( pSrc[ 0 ] == '\\' )
		pSrc++;

	snwprintf( buf, MAX_PATH, L"%s", pSrc );
	return GetFullPathName( buf, MAX_PATH, pOut, NULL );
}

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	ValueListEditor->ItemProps[ 6 ]->EditStyle = esPickList;
	ValueListEditor->ItemProps[ 6 ]->PickList->Add( "Repack" );
	ValueListEditor->ItemProps[ 6 ]->PickList->Add( "Steam Rip" );
	ValueListEditor->ItemProps[ 6 ]->PickList->Add( "Лицензия" );

	PathToAbsolute( L"\\setting.ini", g_tszRoot );
	if( _waccess( g_tszRoot, 0 ) != 0 )
	{
		MessageBox( 0, L"Не найдей файл настроек, значения по умолчанию", L"Внимание!", MB_ICONERROR );
		wcscpy( Setting.Screen, L"1" );
		wcscpy( Setting.Description, L"1" );
		wcscpy( Setting.DopContent, L"1" );
		wcscpy( Setting.OsobIgri, L"1" );
		wcscpy( Setting.OsobRep, L"1" );
		wcscpy( Setting.MyList, L"[*][b][i][color=\"#333333\"]%Listing%[/color][/i][/b]" );

	}
	else
	{
		GetPrivateProfileString( L"Настройки", L"Скрины", L"", Setting.Screen, SIZEOF( Setting.Screen ), g_tszRoot );
		GetPrivateProfileString( L"Настройки", L"Описание", L"", Setting.Description, SIZEOF( Setting.Description ), g_tszRoot );


		GetPrivateProfileString( L"Настройки", L"Дополнительный контент", L"", Setting.DopContent, SIZEOF( Setting.DopContent ), g_tszRoot );
		GetPrivateProfileString( L"Настройки", L"Особенности игры", L"", Setting.OsobIgri, SIZEOF( Setting.OsobIgri ), g_tszRoot );
		GetPrivateProfileString( L"Настройки", L"Особенности репака", L"", Setting.OsobRep, SIZEOF( Setting.OsobRep ), g_tszRoot );
		GetPrivateProfileString( L"Настройки", L"Описание", L"", Setting.Description, SIZEOF( Setting.Description ), g_tszRoot );
		GetPrivateProfileString( L"Настройки", L"Листинг", L"", Setting.MyList, SIZEOF( Setting.MyList ), g_tszRoot );

		GetPrivateProfileString( L"Настройки", L"Шаблон", L"", Setting.Path, SIZEOF( Setting.Path ), g_tszRoot );
		ShabloniEdit->Text = Setting.Path;
	};
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
	WritePrivateProfileString( L"Настройки", L"Шаблон", ShabloniEdit->Text.c_str(), g_tszRoot );
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DopContentClick(TObject *Sender)
{
	if( DopContent->Checked == TRUE )
	{
		Description->Caption = "Дополнительный контент";
		DescriptionMemo->Visible = FALSE;
		DopContentMemo->Visible = TRUE;
		OsobeGame->Enabled = FALSE;
	}
	else
	{
		Description->Caption = "Описание";
		DescriptionMemo->Visible = TRUE;
		DopContentMemo->Visible = FALSE;
		OsobeGame->Enabled = TRUE;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::OsobeGameClick(TObject *Sender)
{
	if( OsobeGame->Checked == TRUE )
	{
		Description->Caption = "Особенности игры";
		DescriptionMemo->Visible = FALSE;
		OsobeGameMemo->Visible = TRUE;
		DopContent->Enabled = FALSE;
	}
	else
	{
		Description->Caption = "Описание";
		DescriptionMemo->Visible = TRUE;
		OsobeGameMemo->Visible = FALSE;
		DopContent->Enabled = TRUE;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N2Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	OpenDialog1->InitialDir = GetCurrentDir()+"\\Шаблоны";
	if (!OpenDialog1->Execute())
		return;

	ShabloniEdit->Text = OpenDialog1->FileName;
}
//---------------------------------------------------------------------------
#define INT32TO64(high,low) ((((__int64)(high))<<32)+((__int64)low))

wchar_t *AnsiToUTF16(char *strAnsi)
{
	wchar_t	*strUTF16 = NULL;
	int		length;

	// Get the length of the converted string
	length = MultiByteToWideChar(CP_ACP, 0, strAnsi, -1, NULL, 0);
	if (!length)
		return NULL;

	 strUTF16 = new wchar_t[ ( sizeof( wchar_t ) * ( length + 1 ) + 5 ) ];

	 memset( strUTF16, 0, sizeof( wchar_t ) );

	// Convert Ansi to Wide characters
	if (!MultiByteToWideChar(CP_UTF8, 0, strAnsi, -1, strUTF16, length))
	{
		delete[] strUTF16;
		return NULL;
	}

	strUTF16[length] = 0;

	return strUTF16;
}

BOOL ReadFileIntoBuffer( wchar_t **BufferPtr, const wchar_t *File)
{
	HANDLE			FileHandle;
	//DWORD			FileSizeLow, FileSizeHigh;
	BOOL			bResult = FALSE;
	DWORD			dw = 0;
	__int64			Size = 0;
	char			*AnsiBuffer = NULL;
	LARGE_INTEGER  	liFileSize = { 0 };  // размер файла
	wchar_t			Temp[128] = { 0 };

	//!открываем файл
	FileHandle = CreateFileW(File,
		GENERIC_READ,
		FILE_SHARE_READ,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL);

	//!Проверяем
	if (FileHandle == INVALID_HANDLE_VALUE)
	{
		CloseHandle(FileHandle);
		return FALSE;
	}

	if (!GetFileSizeEx(FileHandle, &liFileSize))
	{
		MessageBox(NULL, L"Ошибка в работе GetFileSizeEx", L"Внимание!", MB_ICONERROR);
		CloseHandle(FileHandle);
		return FALSE;
	}

	Size = INT32TO64(liFileSize.HighPart, liFileSize.LowPart);
	if (!Size)
	{
		MessageBox(NULL, L"Ошибка в вычислении размера файла", L"Внимание!", MB_ICONERROR);
		CloseHandle(FileHandle);
		return FALSE;
	}

	//!Выделяем память под буфер
	//AnsiBuffer = (char *) calloc(( size_t )Size + 5, sizeof(char) );
	AnsiBuffer = new char[ Size + 5 ];
	memset( AnsiBuffer, 0, Size + 5 );

	if (!AnsiBuffer)
	{
		MessageBox(NULL, L"Ошибка при выделении памяти", L"Внимание!", MB_ICONERROR);
		CloseHandle(FileHandle);
		return FALSE;
	}

	//!Читаем
	bResult = ReadFile(FileHandle, AnsiBuffer, ( DWORD )Size, &dw, NULL);

	if (!bResult)
	{
		MessageBox(NULL, L"Ошибка при чтении файла", L"Внимание!", MB_ICONERROR);
		CloseHandle(FileHandle);
		//free(AnsiBuffer);
		delete[] AnsiBuffer;
		return FALSE;
	}

	if (Size != dw)
	{
		MessageBox(NULL, L"Ошибка в чтении файла", L"Внимание!", MB_ICONERROR);
		CloseHandle(FileHandle);
		//free(AnsiBuffer);
		delete[] AnsiBuffer;
		return FALSE;
	}

	*BufferPtr = AnsiToUTF16(AnsiBuffer);

	//free(AnsiBuffer);
	delete[] AnsiBuffer;

	//!Закрываем
	CloseHandle(FileHandle);
	return TRUE;
}

static wchar_t *MyConst[] =
{
	NULL,
	L"%Лого%",
	L"%Постер%",
	L"%Дата%",
	L"%Жанр%",
	L"%Разраб%",
	L"%Издатель%",
	L"%Издание%",
	L"%Версия%",
	L"%Интерфейс%",
	L"%Озвучка%",
	L"%Лекарство%",
	L"%Система%",
	L"%Процессор%",
	L"%Оператива%",
	L"%Видео%",
	L"%Звук%",
	L"%Свободное место%"
	/*L"%Скрины инстала%",
	L"%Скрины игры%",           // 20
	L"%Описание%",
	L"%Доп контент%",           // 22
	L"%Особенности игры%",
	L"%Особенности репака%"     // 24  */
};

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	String 			ShPath;
	wchar_t 		*Buffer = NULL;
	int 			Total = 0;
	String 			Temp, Temp2, Temp3, Itogo;
	const wchar_t 	ConstScreens_v1[] = L"[url=\"%Big%\"][img]%Small%[/img][/url] ";
	const wchar_t 	ConstScreens_v2[] = L"[img]%Big%[/img] ";
	int 			i;

	ShPath = ShabloniEdit->Text;

	if( ShPath.Length() <= 3 )
	{
		MessageBox( 0, L"Ошибка в пути файла", L"Внимание!", MB_ICONERROR );
		return;
	}

	if( _waccess( ShPath.c_str(), 0 ) != 0 )
	{
		MessageBox( 0, L"Не найден файл шаблона", L"Внимание!", MB_ICONERROR );
		return;
    }

	ReadFileIntoBuffer( &Buffer, ShPath.c_str() );

	MyBuf = Buffer;
	delete[] Buffer;

	for( i = 1; i <= 16; ++i )
	{
		MyBuf = StringReplace( MyBuf, MyConst[ i ], ValueListEditor->Values[ ValueListEditor->Keys[ i ] ], TReplaceFlags()<< rfReplaceAll << rfIgnoreCase );
	}

	if( StrToInt( Setting.Screen ) == 1 )
	{
		// Обрабатываем скрины инстала
		Total = ScreenInst->Lines->Count;
		for( int i = 0; i < Total; ++i )
		{
			Temp = ScreenInst->Lines->Strings[ i ];

			if( Temp.Pos( L"fastpic." ) == 0 )
				continue;
			//Temp.Delete( Temp.Length(), 1 );

			while( Temp[ Temp.Length() ] == '\n' )
			{
				Temp.Delete( Temp.Length() - 1, 1 );
				Temp.Delete( Temp.Length(), 1 );
			}

			Temp2 = ConstScreens_v1;

			Temp2 = StringReplace( Temp2, L"%Big%", Temp, TReplaceFlags()<< rfReplaceAll << rfIgnoreCase );

			Temp =  StringReplace( Temp, L"big", L"thumb", TReplaceFlags()<< rfReplaceAll << rfIgnoreCase );
			Temp2 = StringReplace( Temp2, L"%Small%", Temp, TReplaceFlags()<< rfReplaceAll << rfIgnoreCase );

			Itogo.operator +=( Temp2 );
		}
		MyBuf = StringReplace( MyBuf, L"%Скрины инстала%", Itogo, TReplaceFlags()<< rfReplaceAll << rfIgnoreCase );

		/////////////////////////////////////////////////////////////


		// Обрабатываем скрины игры
		Itogo.operator =( L"" );
		Total = GameSkrin->Lines->Count;
		for( i = 0; i < Total; ++i )
		{
			Temp = GameSkrin->Lines->Strings[ i ];

			if( Temp.Pos( L"fastpic." ) == 0 )
				continue;

			while( Temp[ Temp.Length() ] == '\n' )
			{
				Temp.Delete( Temp.Length() - 1, 1 );
				Temp.Delete( Temp.Length(), 1 );
			}

			Temp2 = ConstScreens_v1;

			Temp2 = StringReplace( Temp2, L"%Big%", Temp, TReplaceFlags()<< rfReplaceAll << rfIgnoreCase );

			Temp =  StringReplace( Temp, L"big", L"thumb", TReplaceFlags()<< rfReplaceAll << rfIgnoreCase );
			Temp2 = StringReplace( Temp2, L"%Small%", Temp, TReplaceFlags()<< rfReplaceAll << rfIgnoreCase );

			//Itogo.operator +=( Temp2 );
			Itogo.operator +=( Temp2 );
			//Itogo.operator +=( Temp2 );
		}
		MyBuf = StringReplace( MyBuf, L"%Скрины игры%", Itogo, TReplaceFlags()<< rfReplaceAll << rfIgnoreCase );
	}
	if( StrToInt( Setting.Screen ) == 0 )
	{
		Itogo.operator =( L"" );
		Total = GameSkrin->Lines->Count;
		for( i = 0; i < Total; ++i )
		{
			Temp = ScreenInst->Lines->Strings[ i ];

			Temp2 = ConstScreens_v2;

			while( Temp[ Temp.Length() ] == '\n' )
			{
				Temp.Delete( Temp.Length() - 1, 1 );
				Temp.Delete( Temp.Length(), 1 );
			}

			Temp2 = StringReplace( Temp2, L"%Big%", Temp, TReplaceFlags()<< rfReplaceAll << rfIgnoreCase );

			Itogo.operator +=( Temp2 );
		}
		MyBuf = StringReplace( MyBuf, L"%Скрины инстала%", Itogo, TReplaceFlags()<< rfReplaceAll << rfIgnoreCase );

		Itogo.operator =( L"" );
		Total = GameSkrin->Lines->Count;
		for( i = 0; i < Total; ++i )
		{
			Temp = GameSkrin->Lines->Strings[ i ];

			Temp2 = ConstScreens_v2;

			while( Temp[ Temp.Length() ] == '\n' )
			{
				Temp.Delete( Temp.Length() - 1, 1 );
				Temp.Delete( Temp.Length(), 1 );
			}

			Temp2 = StringReplace( Temp2, L"%Big%", Temp, TReplaceFlags()<< rfReplaceAll << rfIgnoreCase );

			Itogo.operator +=( Temp2 );
		}
		MyBuf = StringReplace( MyBuf, L"%Скрины игры%", Itogo, TReplaceFlags()<< rfReplaceAll << rfIgnoreCase );
	}
	/////////////////////////////////////////////////////////////
	const wchar_t BedinEndList[] = L"[list]\r\n%List%\r\n[/list]";

	// Обрабатываем Описание
	Itogo.operator =( L"" );
	Total = DescriptionMemo->Lines->Count;
	if( StrToInt( Setting.Description ) == 1 )
	{
     	for( i = 0; i < Total; ++i )
		{
			Temp = DescriptionMemo->Lines->Strings[ i ];

			Temp3 = StringReplace( Setting.MyList, L"%Listing%", Temp, TReplaceFlags()<< rfReplaceAll << rfIgnoreCase );
			Itogo.operator +=( Temp3 );
			if( Total != i + 1 )
				Itogo.operator +=( "\r\n" );
		}
		Temp2 = BedinEndList;
		Temp2 = StringReplace( Temp2, L"%List%", Itogo, TReplaceFlags()<< rfReplaceAll << rfIgnoreCase );
		MyBuf = StringReplace( MyBuf, L"%Описание%", Temp2, TReplaceFlags()<< rfReplaceAll << rfIgnoreCase );
	}
	if( StrToInt( Setting.Description ) == 0 )
	{
		for( i = 0; i < Total; ++i )
		{
			Temp = DescriptionMemo->Lines->Strings[ i ];
			Itogo.operator +=( "[tab][/tab]" );
			Itogo.operator +=( Temp );
			if( Total != i + 1 )
				Itogo.operator +=( "\r\n" );
		}
	}
	MyBuf = StringReplace( MyBuf, L"%Описание%", Itogo, TReplaceFlags()<< rfReplaceAll << rfIgnoreCase );

	// Обрабатываем дополнительный контент
	Itogo.operator =( L"" );
	Total = DopContentMemo->Lines->Count;
	if( StrToInt( Setting.DopContent ) == 1 )
	{
		for( i = 0; i < Total; ++i )
		{
			Temp = DopContentMemo->Lines->Strings[ i ];

			Temp3 = StringReplace( Setting.MyList, L"%Listing%", Temp, TReplaceFlags()<< rfReplaceAll << rfIgnoreCase );
			Itogo.operator +=( Temp3 );
			if( Total != i + 1 )
				Itogo.operator +=( "\r\n" );
		}
		Temp2 = BedinEndList;
		Temp2 = StringReplace( Temp2, L"%List%", Itogo, TReplaceFlags()<< rfReplaceAll << rfIgnoreCase );
		MyBuf = StringReplace( MyBuf, L"%Доп контент%", Temp2, TReplaceFlags()<< rfReplaceAll << rfIgnoreCase );
	}
	if( StrToInt( Setting.DopContent ) == 0 )
	{
		Temp = DopContentMemo->Lines->GetText();
		MyBuf = StringReplace( MyBuf, L"%Доп контент%", Temp, TReplaceFlags()<< rfReplaceAll << rfIgnoreCase );
	}

	// Обрабатываем Особенности игры
	Itogo.operator =( L"" );
	Total = OsobeGameMemo->Lines->Count;
	if( StrToInt( Setting.OsobIgri ) == 1 )
	{
		for( i = 0; i < Total; ++i )
		{
			Temp = OsobeGameMemo->Lines->Strings[ i ];

			Temp3 = StringReplace( Setting.MyList, L"%Listing%", Temp, TReplaceFlags()<< rfReplaceAll << rfIgnoreCase );
			Itogo.operator +=( Temp3 );
			if( Total != i + 1 )
				Itogo.operator +=( "\r\n" );
		}
		Temp2 = BedinEndList;
		Temp2 = StringReplace( Temp2, L"%List%", Itogo, TReplaceFlags()<< rfReplaceAll << rfIgnoreCase );
		MyBuf = StringReplace( MyBuf, L"%Особенности игры%", Temp2, TReplaceFlags()<< rfReplaceAll << rfIgnoreCase );
	}
	if( StrToInt( Setting.DopContent ) == 0 )
	{
		Temp = OsobeGameMemo->Lines->GetText();
		MyBuf = StringReplace( MyBuf, L"%Особенности игры%", Temp, TReplaceFlags()<< rfReplaceAll << rfIgnoreCase );
	}

	// Обрабатываем Особенности репака
	Itogo.operator =( L"" );
	Total = OsobRepacka->Lines->Count;
	if( StrToInt( Setting.OsobRep ) == 1 )
	{
		for( i = 0; i < Total; ++i )
		{
			Temp = OsobRepacka->Lines->Strings[ i ];

			Temp3 = StringReplace( Setting.MyList, L"%Listing%", Temp, TReplaceFlags()<< rfReplaceAll << rfIgnoreCase );
			Itogo.operator +=( Temp3 );
			if( Total != i + 1 )
				Itogo.operator +=( "\r\n" );
		}
		Temp2 = BedinEndList;
		Temp2 = StringReplace( Temp2, L"%List%", Itogo, TReplaceFlags()<< rfReplaceAll << rfIgnoreCase );
		MyBuf = StringReplace( MyBuf, L"%Особенности репака%", Temp2, TReplaceFlags()<< rfReplaceAll << rfIgnoreCase );
	}
	if( StrToInt( Setting.DopContent ) == 0 )
	{
		Temp = OsobRepacka->Lines->GetText();
		MyBuf = StringReplace( MyBuf, L"%Особенности репака%", Temp, TReplaceFlags()<< rfReplaceAll << rfIgnoreCase );
	}

	Form2 = new TForm2(Application);
	Form2->ShowModal();
	delete Form2;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N5Click(TObject *Sender)
{
	Form3 = new TForm3(Application);
	Form3->ShowModal();
	delete Form3;
}
//---------------------------------------------------------------------------
