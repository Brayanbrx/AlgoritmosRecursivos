//---------------------------------------------------------------------------

#include <vcl.h>
#include <algorithm>
#pragma hdrstop

#include "UFPrincipal.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
//Auxiliares

bool esPrimo(Cardinal num){
Byte i,c=0;
	for (i=1; i <= num; i++) {
		if (num%i==0)
			c++;
	}
	return (c>2) ? false : true;
}

Cardinal nMayor(Cardinal n1,Cardinal n2){
	return (n1>=n2) ? n1 : n2 ;
}

Cardinal nMen(Cardinal n1,Cardinal n2){
	return (n1>=n2 && (n1 && n2)!=0) ? n2 : n1 ;
}


//Algoritmos Numericos
Byte sumadig(Cardinal n){
	return n==0 ? 0 : (n%10) + sumadig(n/10);
}

Byte sumarPar(Cardinal n){
	return n == 0 ? 0 : (n % 10 % 2 == 0 ? n % 10 : 0) + sumarPar(n / 10);
}

Byte sumarImpar(Cardinal n){
	return n == 0 ? 0 : (n % 10 % 2 !=0 ? n % 10 : 0) + sumarImpar(n / 10);
}

Byte sumarPrimos(Cardinal n){
	return n == 0 ? 0 : (esPrimo(n%10) ? n%10 : 0) + sumarPrimos(n / 10) ;
}

Byte cantDig(Cardinal n){
	return n == 0 ? 0 : 1 + cantDig(n / 10);
}

Byte contarPar(Cardinal n){
	return n == 0 ? 0 : (n % 10 % 2 == 0 ? n % 10 : 0) + contarPar(n / 10) ;
}

Byte contarImpar(Cardinal n){
	return n == 0 ? 0 : (n % 10 % 2 != 0 ? n % 10 : 0) + contarImpar(n / 10);
}

Byte contarPrimos(Cardinal n){
	return n == 0 ? 0: (esPrimo(n % 10) ? n % 10 : 0) + contarPrimos(n / 10) ;
}

Byte digMayor(Cardinal n){
	return n == 0 ? 0 : nMayor(n%10,digMayor(n/10));
}

Byte digMenor(Cardinal n){
	return n == 0 ? 0 : nMen(n % 10,digMenor(n / 10));
}

void elimDigPar(Cardinal &num){
	if (num>0) {
		byte dig = num%10;
		num /= 10;
		elimDigPar(num);
			num = (dig % 2 != 0) ? num * 10 + dig : num;
	}
}

void elimDigImpar(Cardinal &num){
	if (num>0) {
		byte dig = num%10;
		num = num/10;
		elimDigImpar(num);
			if ((dig%2==0) && (dig!=0) ) num = num * 10 + dig;
	}
}

void moverDigMayorFin(Cardinal &num){
	if (num>9) {
		byte dig = num%10;
		num = num/10;
			moverDigMayorFin(num);
			if (num%10>dig) {
				Byte aux = num%10;
				num = num / 10;
				num = (num * 10 + dig) * 10 + aux;
			} else
				num = num * 10 + dig;
	}
}

void moverDigMenorFin(Cardinal &num){
	if (num>9) {
		byte dig=num%10;
		num=num/10;
		moverDigMenorFin(num);
			if (num%10<dig) {
				Byte aux = num%10;
				num = num/10;
				num = (num*10 + dig) * 10 + aux;
			} else
				num = num * 10 + dig;
	}
}

void ordenarAscendente(Cardinal &num){
Byte dig;
	if (num>9) {
		moverDigMayorFin(num);
		dig = num%10;
		num = num/10;
		ordenarAscendente(num);
            num = num * 10 + dig;
	}
}

void ordenarDescendente(Cardinal &num){
Byte dig;
	if (num>9) {
		moverDigMenorFin(num);
		dig = num%10;
		num = num/10;
		ordenarDescendente(num);
			num = num * 10 + dig;
	}
}

Byte sumaPosImpar(Cardinal num, Byte pos){
Byte dig;
	if (num>0) {
		dig = num%10;
		pos++;
		num = sumaPosImpar(num/10,pos);
			if (pos%2!=0) num = num + dig;
	}
	return num;
}

Cardinal factorial(Cardinal num){
	return (num>1) ? num * factorial(num-1) : 1;
}

void rotarDig(Cardinal &num){
Byte dig;
	if (num>9) {
		dig = num%10;
		num = num/10;
		rotarDig(num);
			if (num%10 != dig) {
				Byte aux = num%10;
				num = num/10;
				num = (num * 10 + dig) *10 + aux;
			} else
				num = num * 19 + dig;
	}
}

bool estaOrdenado(Cardinal n){
	return n<10 ? true : estaOrdenado(n/10) && (n/10%10<=n%10) ;
}

void elimDigN(Cardinal &n, Byte d){
	if (n>0) {
		byte dig = n%10;
		n/=10;
		elimDigN(n,d);
			if (dig!=d)
				n=n*10+dig;
	}
}


//Algoritos con Cadenas

Byte sumarDigCad (String cad){
char letra;
Byte sum;
	if (cad.Length()<=1) {
		sum = (isdigit(cad[1])>0) ? sum = StrToInt(cad) : sum = 0;
	} else {
		letra = cad[cad.Length()];
		cad.Delete(cad.Length(),1);
		sum = sumarDigCad(cad);
			if (isdigit(letra) > 0) sum = sum + StrToInt(letra);
	}
	return sum;
}

bool isvocal(char letra){
String vocales = "AEIOUÁÉÍÓÚ";
	return vocales.Pos(UpperCase(letra))>0;
}

Byte cantLet(String cad){
char letra;
Byte contador;
	if (cad.Length()<=1) {
		contador = (isalpha(cad[1])>0) ? 1 : 0;
	} else {
		letra = cad[cad.Length()];
		cad.Delete(cad.Length(),1);
		contador = cantLet(cad);
			if (isalpha(letra)>0) contador++;
	}
    return contador;
}

Cardinal sacarNum(String cad){
char letra;
Cardinal num;
	if (cad.Length()<=1)
		num = (isdigit(cad[1])>0) ? StrToInt(cad) : 0;
	 else{
		letra = cad[cad.Length()];
		cad.Delete(cad.Length(),1);
		num = sacarNum(cad);
			if (isdigit(letra)>0) num = (num * 10) + StrToInt(letra);
	}
	return num;
}

void elimVocal(String &cad){
char letra;
Byte len = cad.Length();
	if (len>0) {
		letra = cad[len];
		cad.Delete(len,1);
		elimVocal(cad);
				if (!isvocal(letra)) cad = cad + letra;
	}
}

void inverCad(String &cad){
char letra;
Byte len = cad.Length();
	if (len>0) {
		letra=cad[len];
		cad.Delete(len,1);
		inverCad(cad);
			cad = String(letra) + cad;
	}
}



//Algoritmos con Vectores

//Algoritmos con Matrices


//---------------------------------------------------------------------------

void __fastcall TForm1::SumaDigClick(TObject *Sender)
{
	Cardinal num = StrToInt(Ed1->Text);
	Byte res = sumadig(num);
	ShowMessage(res);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ContarDigitosPares1Click(TObject *Sender)
{
	Cardinal num = StrToInt(Ed1->Text);
	Byte res = contarPar(num);
	ShowMessage(res);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SumarDigitosPares1Click(TObject *Sender)
{
	Cardinal num = StrToInt(Ed1->Text);
	Byte res = sumarPar(num);
	ShowMessage(res);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SumarDigitosImpares1Click(TObject *Sender)
{
    Cardinal num = StrToInt(Ed1->Text);
	Byte res = sumarImpar(num);
	ShowMessage(res);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::EsPrimo1Click(TObject *Sender)
{
	Cardinal num = StrToInt(Ed1->Text);
	String res = (esPrimo(num)) ? "Es Primo" : "No es Primo";
	ShowMessage(res);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CantidadDigitosClick(TObject *Sender)
{
	Cardinal num=StrToInt(Ed1->Text);
	Byte res = cantDig(num);
	ShowMessage(res);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ContarDigitosImpares1Click(TObject *Sender)
{
	Cardinal num = StrToInt(Ed1->Text);
	Byte res = contarImpar(num);
	ShowMessage(res);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RetornarDigitoMayor1Click(TObject *Sender)
{
    Cardinal num = StrToInt(Ed1->Text);
	Byte res = digMayor(num);
	ShowMessage(res);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SumarDigitosPrimos1Click(TObject *Sender)
{
	Cardinal num = StrToInt(Ed1->Text);
	Byte res = sumarPrimos(num);
	ShowMessage(res);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ContarDigitosPrimos1Click(TObject *Sender)
{
	Cardinal num = StrToInt(Ed1->Text);
	Byte res = contarPrimos(num);
	ShowMessage(res);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RetornarDigitoMenor1Click(TObject *Sender)
{
	Cardinal num = StrToInt(Ed1->Text);
	Byte res = digMenor(num);
	ShowMessage(res);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::EliminarDigitosPares1Click(TObject *Sender)
{
	Cardinal num = StrToInt(Ed1->Text);
	elimDigPar(num);
	ShowMessage(num);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::EliminarDigitosImpares1Click(TObject *Sender)
{
	Cardinal num = StrToInt(Ed1->Text);
	elimDigImpar(num);
	ShowMessage(num);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::MoverDigMayorFinalClick(TObject *Sender)
{
	Cardinal num = StrToInt(Ed1->Text);
	moverDigMayorFin(num);
	ShowMessage(num);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::MoverDigitoMenoralFinal1Click(TObject *Sender)
{
	Cardinal num = StrToInt(Ed1->Text);
	moverDigMenorFin(num);
	ShowMessage(num);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::OrdenarDigitosAscendente1Click(TObject *Sender)
{
	Cardinal num = StrToInt(Ed1->Text);
	ordenarAscendente(num);
	ShowMessage(num);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::OrdenarDigitosDescendente1Click(TObject *Sender)
{
    Cardinal num = StrToInt(Ed1->Text);
	ordenarDescendente(num);
	ShowMessage(num);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CalcularSumadeDigitosenPosicionImpar1Click(TObject *Sender)

{
	Cardinal num = StrToInt(Ed1->Text);
	Byte res = sumaPosImpar(num, 0);
	ShowMessage(res);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Factorial1Click(TObject *Sender)
{
	Cardinal num = StrToInt(Ed1->Text);
	Cardinal res = factorial(num);
	ShowMessage(res);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Rotar1erDigito1Click(TObject *Sender)
{
	Cardinal num = StrToInt(Ed1->Text);
	rotarDig(num);
	ShowMessage(num);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SumarDigitosdeCadena1Click(TObject *Sender)
{
	Byte res = sumarDigCad(Ed1->Text);
	ShowMessage(res);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::VersiEsVocal1Click(TObject *Sender)
{
	String res = (isvocal(Ed1->Text[1])) ? "Es Vocal" : "No es Vocal";
	ShowMessage(res);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ContarLetras1Click(TObject *Sender)
{
	String res = cantLet(Ed1->Text);
	ShowMessage(res);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::SacarNumerodeCad1Click(TObject *Sender)
{
	String cad = Ed1->Text;
	Cardinal res = sacarNum(cad);
	ShowMessage(res);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::EliminarVocales1Click(TObject *Sender)
{
	String cad = Ed1->Text;
	elimVocal(cad);
	ShowMessage(cad);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::InvertirCadena1Click(TObject *Sender)
{
	String cad = Ed1->Text;
	inverCad(cad);
	ShowMessage(cad);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::EstaOrdenado1Click(TObject *Sender)
{
	if (estaOrdenado(StrToInt(Ed1->Text)))
		ShowMessage("Esta Ordenado");
	else
		ShowMessage("No esta Ordenado");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Mayor1Click(TObject *Sender)
{
	Cardinal num = nMayor(StrToInt(Ed1->Text),StrToInt(Ed2->Text));
	ShowMessage(num);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Menor1Click(TObject *Sender)
{
	Cardinal num = nMen(StrToInt(Ed1->Text),StrToInt(Ed2->Text));
	ShowMessage(num);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::EliminarDigitosenviadosporParametro1Click(TObject *Sender)

{
	Cardinal res =  StrToInt(Ed1->Text);
	elimDigN(res, StrToInt(Ed2->Text));
	ShowMessage(res);
}
//---------------------------------------------------------------------------
