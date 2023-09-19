//---------------------------------------------------------------------------

#ifndef UFPrincipalH
#define UFPrincipalH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>


//probando
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MainMenu1;
	TMenuItem *Numeros1;
	TMenuItem *Numeros2;
	TMenuItem *Vectores1;
	TMenuItem *Vectores2;
	TMenuItem *SumaDig;
	TEdit *Ed1;
	TLabel *lb1;
	TStringGrid *SGVector;
	TMenuItem *ContarDigitosPares1;
	TMenuItem *SumarDigitosPares1;
	TMenuItem *SumarDigitosImpares1;
	TMenuItem *Auxiliares1;
	TMenuItem *EsPrimo1;
	TMenuItem *CantidadDigitos;
	TMenuItem *ContarDigitosImpares1;
	TMenuItem *RetornarDigitoMayor1;
	TMenuItem *SumarDigitosPrimos1;
	TMenuItem *ContarDigitosPrimos1;
	TMenuItem *RetornarDigitoMenor1;
	TMenuItem *EliminarDigitosPares1;
	TMenuItem *EliminarDigitosImpares1;
	TEdit *Ed2;
	TLabel *lb2;
	TMenuItem *MoverDigMayorFinal;
	TMenuItem *MoverDigitoMenoralFinal1;
	TMenuItem *OrdenarDigitosAscendente1;
	TMenuItem *OrdenarDigitosDescendente1;
	TMenuItem *CalcularSumadeDigitosenPosicionImpar1;
	TMenuItem *Factorial1;
	TMenuItem *Rotar1erDigito1;
	TMenuItem *SumarDigitosdeCadena1;
	TMenuItem *VersiEsVocal1;
	TMenuItem *ContarLetras1;
	TMenuItem *SacarNumerodeCad1;
	TMenuItem *EliminarVocales1;
	TMenuItem *InvertirCadena1;
	TMenuItem *EstaOrdenado1;
	TMenuItem *Mayor1;
	TMenuItem *Menor1;
	TMenuItem *EliminarDigitosenviadosporParametro1;
	TMenuItem *Cantidaddedigimparesantesdeunpar1;
	TMenuItem *HayundigitoPar1;
	TMenuItem *SeriesNumeros1;
	TMenuItem *Fibonacci1;
	TMenuItem *N1236714130311;
	TMenuItem *N02468101214161;
	TMenuItem *N1371531631272551;
	TMenuItem *N1245101213262829sumaPar1;
	TMenuItem *CantidaddePalabras1;
	void __fastcall SumaDigClick(TObject *Sender);
	void __fastcall ContarDigitosPares1Click(TObject *Sender);
	void __fastcall SumarDigitosPares1Click(TObject *Sender);
	void __fastcall SumarDigitosImpares1Click(TObject *Sender);
	void __fastcall EsPrimo1Click(TObject *Sender);
	void __fastcall CantidadDigitosClick(TObject *Sender);
	void __fastcall ContarDigitosImpares1Click(TObject *Sender);
	void __fastcall RetornarDigitoMayor1Click(TObject *Sender);
	void __fastcall SumarDigitosPrimos1Click(TObject *Sender);
	void __fastcall ContarDigitosPrimos1Click(TObject *Sender);
	void __fastcall RetornarDigitoMenor1Click(TObject *Sender);
	void __fastcall EliminarDigitosPares1Click(TObject *Sender);
	void __fastcall EliminarDigitosImpares1Click(TObject *Sender);
	void __fastcall MoverDigMayorFinalClick(TObject *Sender);
	void __fastcall MoverDigitoMenoralFinal1Click(TObject *Sender);
	void __fastcall OrdenarDigitosAscendente1Click(TObject *Sender);
	void __fastcall OrdenarDigitosDescendente1Click(TObject *Sender);
	void __fastcall CalcularSumadeDigitosenPosicionImpar1Click(TObject *Sender);
	void __fastcall Factorial1Click(TObject *Sender);
	void __fastcall Rotar1erDigito1Click(TObject *Sender);
	void __fastcall SumarDigitosdeCadena1Click(TObject *Sender);
	void __fastcall VersiEsVocal1Click(TObject *Sender);
	void __fastcall ContarLetras1Click(TObject *Sender);
	void __fastcall SacarNumerodeCad1Click(TObject *Sender);
	void __fastcall EliminarVocales1Click(TObject *Sender);
	void __fastcall InvertirCadena1Click(TObject *Sender);
	void __fastcall EstaOrdenado1Click(TObject *Sender);
	void __fastcall Mayor1Click(TObject *Sender);
	void __fastcall Menor1Click(TObject *Sender);
	void __fastcall EliminarDigitosenviadosporParametro1Click(TObject *Sender);
	void __fastcall Cantidaddedigimparesantesdeunpar1Click(TObject *Sender);
	void __fastcall HayundigitoPar1Click(TObject *Sender);
	void __fastcall Fibonacci1Click(TObject *Sender);
	void __fastcall N1236714130311Click(TObject *Sender);
	void __fastcall N1371531631272551Click(TObject *Sender);
	void __fastcall N02468101214161Click(TObject *Sender);
	void __fastcall N1245101213262829sumaPar1Click(TObject *Sender);
	void __fastcall CantidaddePalabras1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
