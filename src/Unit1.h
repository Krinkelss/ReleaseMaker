/*
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

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <ValEdit.hpp>
#include <Menus.hpp>
#include <XPMan.hpp>
#include <Dialogs.hpp>
#include <DdeMan.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TValueListEditor *ValueListEditor;
	TLabel *Label1;
	TMemo *ScreenInst;
	TLabel *Label2;
	TMemo *GameSkrin;
	TLabel *Description;
	TMemo *DescriptionMemo;
	TMemo *DopContentMemo;
	TMemo *OsobeGameMemo;
	TCheckBox *DopContent;
	TCheckBox *OsobeGame;
	TLabel *Label3;
	TMemo *OsobRepacka;
	TMainMenu *MainMenu1;
	TMenuItem *N1;
	TMenuItem *N2;
	TMenuItem *N4;
	TMenuItem *N5;
	TXPManifest *XPManifest1;
	TLabel *Label4;
	TEdit *ShabloniEdit;
	TButton *Button1;
	TButton *Button2;
	TOpenDialog *OpenDialog1;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall DopContentClick(TObject *Sender);
	void __fastcall OsobeGameClick(TObject *Sender);
	void __fastcall N2Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall N5Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
extern String MyBuf;
//---------------------------------------------------------------------------
#endif
