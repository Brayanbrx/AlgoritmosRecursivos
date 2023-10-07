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

bool hayUnPar(Cardinal num){
	return (num==0) ? false : hayUnPar(num/10) || (num%10%2==0 && num%10!=0) ;
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
		num /= 10;
			moverDigMayorFin(num);
			if (num%10>dig) {
				Byte aux = num%10;
				num /= 10;
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
				num /= 10;
				num = (num*10 + dig) * 10 + aux;
			} else
				num = num * 10 + dig;
	}
}

void ordenarAscendente(Cardinal &num){
	if (num>9) {
		moverDigMayorFin(num);
		byte dig = num%10;
		num /= 10;
		ordenarAscendente(num);
            num = num * 10 + dig;
	}
}

void ordenarDescendente(Cardinal &num){
Byte dig;
	if (num>9) {
		moverDigMenorFin(num);
		dig = num%10;
		num /= 10;
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

Byte cantDigImparAntesPar(Cardinal num){
	return (num<10 || num%10%2==0 || !(hayUnPar(num))) ? 0 : cantDigImparAntesPar(num/10) + 1;
	  /*if (num<10 || num%10%2==0 || !(hayUnPar(num))) {
		  cont=0;
	  } else{
		 cont= cantDigImparAntesPar(num/10);
			cont++;
	  } */
}

//Algoritmos Series Numericas

Byte fiboEne(Byte n){
	return (n<2) ? n : fiboEne(n-1) + fiboEne(n-2) ;
}

Byte serie1(Byte num){
/*Byte res;
	if (num<=1) {
		res= 1;
	}else {
		res = serie1(num-1);
			res = (num%2==0) ? res*2 : res+1;
	}
	return res;*/
return (num == 0) ? 0 : (num <= 1) ? 1 : ((num % 2 == 0) ? (serie1(num - 1) * 2) : (serie1(num - 1) + 1));
}

Cardinal serie2(Byte num){
	return (num == 0) ? 0 : ((num <= 1) ? 1 : serie2(num - 1) * 2 + 1);
}

Byte SumaPar(Byte num){
	return (num<=1) ? 0: SumaPar(num-1) + 2 ;
}

Byte SumaSerie(Byte num){
	return (num>0) ? SumaSerie(num-1) + SumaPar(num) : 0 ;
}

Byte serie3(Byte num, Byte &con){
Byte res;
	if(num<=1){
		res=1;
	} else{
		res = serie3(num-1, con);
		con++;
			if(con%3==0){
				res=res+1;
				con=0;
			} else if(con%2==0 && con%3!=0){
				res=  res+2;
			} else{
				res=res*2;
			}
	}
	return res;
}


Byte SumaSeriePar(Byte num){
Byte res, con=0, serie;
	if(num<=1){
		res=0;
	} else{
		serie = serie3(num,con);
		res = SumaSeriePar(num-1);
			if(serie%2==0)
				res=res+serie;
	}
	return res;
}

Cardinal invertirNum(Cardinal num, Cardinal &c){
Cardinal res;
Byte dig;
	if (num < 10){
		res= num;
		c=1;
	}
	 else{
	dig = num % 10;
	res = invertirNum(num/10,c);
		c*=10;
		res =  dig * c + res;
	}
	return res;
}

Cardinal potencia(Cardinal x, byte n){
/*Cardinal p;
	if (n==0) {
		p=1;
	} else{
		p=potencia(x,n-1);
		p=p*x;
	}
	return p; */
	return (n==0) ? 1 : potencia(x,n-1) * x ;
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

void elimVocal(AnsiString &cad){
char letra;
Byte len = cad.Length();
	if (len>0) {
		letra = cad[len];
		cad.Delete(len,1);
		elimVocal(cad);
				if (!isvocal(letra)) cad = cad + letra;
	}
}

void inverCad(AnsiString &cad){
char letra;
Byte len = cad.Length();
	if (len>0) {
		letra=cad[len];
		cad.Delete(len,1);
		inverCad(cad);
			cad = String(letra) + cad;
	}
}

Byte CantPal(String cad){
Byte len = cad.Length(),cont, p;
String pal;
	if (len > 0) {
		cad = cad.Trim();
		p = cad.LastDelimiter(' ');
		pal = cad.SubString(p+1,len-p);
		cad.Delete(p + 1,len-p);
		cont = CantPal(cad);
			cont++;
	}
	return cont;
}

AnsiString cadMasLarga(AnsiString cad){
AnsiString pal,res;
Byte len = cad.Length(), p;
	if (len>0) {
		cad = cad.Trim();
		p = cad.LastDelimiter(' ');
		pal = cad.SubString(p+1,len-p);
		cad.Delete(p+1,len-p);
		res = cadMasLarga(cad);
			if (pal.Length()>res.Length())
				res = pal;
	}
	return res;
}

AnsiString InvPalabras(AnsiString cad){
AnsiString pal, res;
Byte len = cad.Length(), p;
	if (len>0) {
		cad = cad.Trim();
		p = cad.LastDelimiter(' ');
		pal = cad.SubString(p+1,len-p);
		cad.Delete(p+1,len-p);
		res = InvPalabras(cad);
			inverCad(pal);
			res = res + pal + ' ';;
	}
	return res;
}

AnsiString ElimPrimLetra(AnsiString cad){
AnsiString pal, res;
Byte len = cad.Length(), pos;
	if (len>0) {
		cad = cad.Trim();
		pos = cad.LastDelimiter(' ');
		pal = cad.SubString(pos+1,len-pos);
		cad.Delete(pos+1,len-pos);
		res = ElimPrimLetra(cad);
			pal.Delete(1,1);
			res = res + pal + ' ';
	}
	return res;
}


//Algoritmos con Vectores

Byte ContNPares(TStringGrid *v, Byte Col){
Byte res;
	if (Col==1) {
		res = (StrToInt(v->Cells[Col-1][0]) % 2 == 0) ? 1 : 0;
	} else{
		res = ContNPares(v, Col-1);
			if (StrToInt(v->Cells[Col-1][0]) % 2 == 0)
				res++;
	}
	return res;
}


//Metodos de Ordenacion
/*void merge(unsigned int arr[], Byte inicio, Byte mitad, Byte fin){
	int n1 = mitad - inicio+1;
	int n2 = fin - mitad;
	unsigned int tempLeft[n1];
	unsigned int tempRight[n2];

	for (int i = 0; i < n1; i++)
		tempLeft[i] = arr[inicio + i];
	for (int j = 0; j < n2; j++)
		tempRight[j] = arr[mitad + 1 + j];

	int i = 0, j = 0, k = inicio;

	while (i < n1 && j < n2) {
		if (tempLeft[i] <= tempRight[j]) {
			arr[k] = tempLeft[i];
			i++;
		} else {
			arr[k] = tempRight[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		arr[k] = tempLeft[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = tempRight[j];
		j++;
		k++;
	}
} */


/*void mergeSort(unsigned int arr[], Byte inicio, Byte fin) {
	if (inicio < fin) {
		Byte mitad = inicio + (fin - inicio) / 2;
		mergeSort(arr, inicio, mitad);
		mergeSort(arr, mitad + 1, fin);
		merge(arr, inicio, mitad, fin);
	}
}   */

void intercambiarV(TStringGrid *v, Byte i, Byte j){
	String aux = v->Cells[i][0];
	v->Cells[i][0] = v->Cells[j][0];
	v->Cells[j][0] = aux;
}

void Burbujear(TStringGrid *v, Byte n, Byte i) {
	if (n == 1)
		return;
	else if (i < n - 1) {
		if (v->Cells[i][0].ToInt() > v->Cells[i + 1][0].ToInt())
			intercambiarV(v,i,i+1);
		Burbujear(v, n, i + 1);
	}
	else
		Burbujear(v, n - 1, 0);
}

void BubbleSort(TStringGrid *v, Byte n) {
	if(n>1){
		Burbujear(v, n, 0);
		BubbleSort(v, n - 1);
	}
}


Byte PosMayor(TStringGrid *v, Byte n){
/*Byte pos;
	if (n==1) {
		pos=0;
	} else{
		pos=PosMayor(v,n-1);
			if (v->Cells[pos][0].ToInt() < v->Cells[n-1][0].ToInt()) {
				pos=n-1;
			}
	}
	return pos;    */
	return (n == 1) ? 0 : (v->Cells[PosMayor(v, n - 1)][0].ToInt() < v->Cells[n - 1][0].ToInt() ? n - 1 : PosMayor(v, n - 1));
}

void SelectionSort(TStringGrid *v, Byte n){
	if (n>1) {
		Byte pMay = PosMayor(v,n);
		intercambiarV(v,n-1,pMay);
		SelectionSort(v,n-1);
	}
}

void InsertionSortRecursive(TStringGrid *v, Byte n) {
	if (n <= 1)
		return;
	else{
		InsertionSortRecursive(v, n - 1);
		Byte i = n - 1;
		Byte prevIndex = i - 1;

		if (prevIndex >= 0 && StrToInt(v->Cells[prevIndex][0]) > StrToInt(v->Cells[i][0])) {
			intercambiarV(v, prevIndex, i);
			InsertionSortRecursive(v, n - 1);
		}
	}
}

void InsertionSort(TStringGrid *v, Byte n) {
	if (n <= 1)
		return;
	else
		InsertionSortRecursive(v, n);
}

/*void Merge(TStringGird *v, Byte inicio, Byte medio, Byte fin){

}

void MergeSort(TStringGrid *v, Byte inicio, Byte fin){
	if (inicio < fin) {
		Byte mitad = inicio + (fin-inicio) / 2;
		MergeSort(v,inicio,mitad);
		MergeSort(v,mitad+1,fin);
		Merge(v,inicio,mitad,fin);
	}
}  */

void FusionRecursiva(TStringGrid *v, Byte inicio, Byte medio, Byte fin, Byte i, Byte j) {
    // Condición de parada de la recursión
    if (i >= medio + 1 || j >= fin + 1)
        return;

    if (StrToInt(v->Cells[i][0]) <= StrToInt(v->Cells[j][0])) {
        // Si el elemento en el subarreglo izquierdo es menor o igual, lo colocamos en su posición
        v->Cells[inicio][0] = v->Cells[i][0];
        FusionRecursiva(v, inicio + 1, medio, fin, i + 1, j);
    } else {
        // Si el elemento en el subarreglo derecho es menor, lo colocamos en su posición
        v->Cells[inicio][0] = v->Cells[j][0];
        FusionRecursiva(v, inicio + 1, medio, fin, i, j + 1);
    }
}

void Merge(TStringGrid *v, Byte inicio, Byte medio, Byte fin) {
    // Condición de parada de la recursión
    if (inicio >= fin)
        return;

    // Llamadas recursivas para fusionar ambos subarreglos
    Merge(v, inicio, inicio + (medio - inicio) / 2, medio);
    Merge(v, medio + 1, medio + 1 + (fin - medio - 1) / 2, fin);

    // Fusionamos los subarreglos
    FusionRecursiva(v, inicio, medio, fin, inicio, medio + 1);
}

void MergeSort(TStringGrid *v, Byte inicio, Byte fin) {
    if (inicio < fin) {
        Byte mitad = inicio + (fin - inicio) / 2;
        MergeSort(v, inicio, mitad);
        MergeSort(v, mitad + 1, fin);
        Merge(v, inicio, mitad, fin);
    }
}

void limpiarV(TStringGrid *v, Byte Col, Byte Row){
	if (Col > 1) {
		v->Cells[Col-1][Row-1] = ' ';
		limpiarV(v, Col-1 , Row);
	} else
		v->Cells[Col-1][Row-1] = ' ';
}

// Auxiliares
void llenarHorizontal(TStringGrid *m, Byte Fila, Byte ini, Byte fin, Byte num){
	byte n = fin-ini+1;
	if (n==1)
		m->Cells[ini][Fila]=num;
	else if(n>1){
		llenarHorizontal(m,Fila,ini+1,fin-1,num);
		m->Cells[ini][Fila] = num;
		m->Cells[fin][Fila] = num;
	}
}

void llenarVertical(TStringGrid *m, Byte Columna, Byte ini, Byte fin, Byte num){
	byte n = fin-ini+1;
	if (n==1)
		m->Cells[Columna][ini]=num;
	else if(n>1){
		llenarVertical(m,Columna,ini+1,fin-1,num);
		m->Cells[Columna][ini] = num;
		m->Cells[Columna][fin] = num;
	}
}

//Algoritmos con Matrices
void limpiarM(TStringGrid *m, Byte Col, Byte Row){
	if (Row>1) {
		limpiarV(m,Col,Row);
		limpiarM(m,Col,Row-1);
	} else
	   limpiarV(m,Col,Row);
}

void llenarCuadrado(TStringGrid *m, byte ini, byte fin){
	byte n = fin-ini+1;
	if (n==1)
		m->Cells[ini][ini]= 1;
	else if(n>1){
		llenarCuadrado(m,ini+1,fin-1);
		llenarHorizontal(m,ini,ini,fin,(n+1)/2);
		llenarHorizontal(m,fin,ini,fin,(n+1)/2);
		llenarVertical(m,ini,ini,fin,(n+1)/2);
		llenarVertical(m,fin,ini,fin,(n+1)/2);
	}
}


//Modelos de Examenes
void cargarVectorDig(TStringGrid *v, Cardinal num){
	if (num==0) {
		v->Cells[v->ColCount-1][0] = num;
	}
	else if (num<10) {
		v->Cells[v->ColCount-1][0] = num;
	} else{
		byte deci = num%100;
		//num = num / 100;
		cargarVectorDig(v,num/100);
			v->ColCount++;
			v->Cells[v->ColCount-1][0] = deci;
    }
}

void cargarVec2carac(TStringGrid *v, AnsiString cad){
	cad = cad.Trim();
	if (cad.Length()>1) {
		byte pos = cad.LastDelimiter(' ');
		AnsiString pal = cad.SubString(pos+1,cad.Length()-pos);
		cad.Delete(pos+1,cad.Length()-pos);
		cargarVec2carac(v,cad);
			v->Cells[v->ColCount-1][0] = (pal.Length()>1) ? pal.SubString(0,2) : pal[0];
			v->ColCount++;
	} else
		v->Cells[v->ColCount-1][v->RowCount-1] = cad;
}

/*void llenarMatriz(TStringGrid *m ,Byte Col,Byte Row, Byte *In,Byte *num){
	if (Col > 1 && Row > 1 ) {
		llenarHorizontal(m,Col,*In,*num);
		llenarVertical(m,Col,Row,*num);
		*num = *num + 1;
		llenarHorizontal(m,Col,Row,*num);
		llenarVertical(m,*In,Row,*num);
	} else{
		m->Cells[0][0] = *num;
	}
}  */

//Retos Celeste

AnsiString sacarVoc(AnsiString cad){
AnsiString cade; char letra;
	if (cad.Length() > 0) {
		letra = cad[cad.Length()];
		cad = cad.Delete(cad.Length(), 1);
		if (isvocal(letra)) {
			cade = sacarVoc(cad);
			cade = cade + letra;
		} else
			cade = sacarVoc(cad);
	}
	return cade;
}


void vectorConVocales(TStringGrid *v, AnsiString cad){
	cad = cad.Trim();
	AnsiString pal;
	if (cad.Length()>1) {
		byte pos = cad.LastDelimiter(' ');
		pal = cad.SubString(pos+1,cad.Length()-pos);
		cad.Delete(pos+1,cad.Length()-pos);
		vectorConVocales(v,cad);
			v->Cells[v->ColCount-1][0] = sacarVoc(pal);
			v->ColCount++;
	} else
		v->Cells[v->ColCount-1][0] = sacarVoc(pal);
}

AnsiString cadConUlt(TStringGrid *v,Byte Col){
AnsiString res;
	if (Col>1) {
		AnsiString pal = v->Cells[Col-1][0];
		res = cadConUlt(v,Col-1);
			pal = pal.Trim();
			res = res + pal[pal.Length()];
	} else{
		res = v->Cells[0][0];
		res = res.Trim();
		res = res[res.Length()];
	}
	return res;
}

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
	AnsiString cad = Ed1->Text;
	elimVocal(cad);
	ShowMessage(cad);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::InvertirCadena1Click(TObject *Sender)
{
	AnsiString cad = Ed1->Text;
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


void __fastcall TForm1::Cantidaddedigimparesantesdeunpar1Click(TObject *Sender)
{
	Cardinal num = StrToInt(Ed1->Text);
	Byte res = cantDigImparAntesPar(num);
	ShowMessage(res);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::HayundigitoPar1Click(TObject *Sender)
{
	Cardinal num = StrToInt(Ed1->Text);
	if(hayUnPar(num))
		ShowMessage("Hay un digito par");
	else
		ShowMessage("No hay un digito par");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Fibonacci1Click(TObject *Sender)
{
Byte num = StrToInt(Ed1->Text), res;
res = (num!=0) ? fiboEne(num-1) : fiboEne(num);
ShowMessage(res);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N1236714130311Click(TObject *Sender)
{
Byte num = StrToInt(Ed1->Text), res = serie1(num);
ShowMessage(res);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::N1371531631272551Click(TObject *Sender)
{
Byte num = StrToInt(Ed1->Text);
Cardinal res = serie2(num);
ShowMessage(res);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::N02468101214161Click(TObject *Sender)
{
Byte num = StrToInt(Ed1->Text), res = SumaSerie(num);
ShowMessage(res);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N1245101213262829sumaPar1Click(TObject *Sender)
{
	//Byte con=0;
	Byte num = StrToInt(Ed1->Text), res = SumaSeriePar(num);
	ShowMessage(res);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CantidaddePalabras1Click(TObject *Sender)
{
	String cad = Ed1->Text;
	Byte res= CantPal(cad);
	ShowMessage(res);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::PalabramasLarga1Click(TObject *Sender)
{
	AnsiString cad = Ed1->Text;
	AnsiString res = cadMasLarga(cad);
	ShowMessage(res);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::InvertirCadapalabraenunacadena1Click(TObject *Sender)
{
	AnsiString cad = Ed1->Text;
	AnsiString res = InvPalabras(cad);
	ShowMessage(res);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ElimPrimLetra1Click(TObject *Sender)
{
	AnsiString cad = Ed1->Text, res = ElimPrimLetra(cad);
	ShowMessage(res);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::edFilaChange(TObject *Sender)
{
	SG1->RowCount = StrToInt(edFila->Text);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::edColumnaChange(TObject *Sender)
{
    SG1->ColCount = StrToInt(edColumna->Text);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SG1DrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
		  TGridDrawState State)
{
    TColor borderColor = clHighlight; // Cambia este color según tus preferencias
	SG1->Canvas->Pen->Color = borderColor;
	SG1->Canvas->Brush->Style = bsClear;
	SG1->Canvas->Rectangle(Rect);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Cantidaddenumerosparesdelvector1Click(TObject *Sender)
{
 Byte res = ContNPares(SG1, SG1->ColCount);
 ShowMessage(res);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::MergeSortOrdenar1Click(TObject *Sender)
{
	/*Byte arraySize = SG1->ColCount;

	unsigned int arr[arraySize];
	for (Byte i = 0; i < arraySize; i++) {
		arr[i] = StrToInt(SG1->Cells[i][0]);
	}

	mergeSort(arr, 0, arraySize - 1);

	for (Byte i = 0; i < arraySize; i++) {
		SG1->Cells[i][0] = (arr[i]);
	} */
}
//---------------------------------------------------------------------------

void __fastcall TForm1::InvertirNumero1Click(TObject *Sender)
{
	Cardinal num = StrToInt(Ed1->Text), c=1;
	Cardinal res = invertirNum(num,c);
	ShowMessage(res);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Potenciadeunnumero1Click(TObject *Sender)
{
 Cardinal num = StrToInt(Ed1->Text), res = potencia(num, StrToInt(Ed2->Text));
 ShowMessage(res);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BubbleSort1Click(TObject *Sender)
{
	//Byte res = CantVecMov(SG1,SG1->ColCount,SG1->ColCount-1);
	//ShowMessage(res);
	BubbleSort(SG1,SG1->ColCount);
	
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SelectionSort1Click(TObject *Sender)
{
	SelectionSort(SG1,SG1->ColCount);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::InsertionSort1Click(TObject *Sender)
{
	InsertionSort(SG1,SG1->ColCount);	
}
//---------------------------------------------------------------------------

void __fastcall TForm1::MergeSort1Click(TObject *Sender)
{
	//MergeSort(SG1,SG1->ColCount);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LimpiarMatriz1Click(TObject *Sender)
{
	limpiarM(SG1, SG1->RowCount, SG1->ColCount);
	//limpiarV(SG1, SG1->ColCount, SG1->RowCount);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CargarunVectorconparesdeDigitosdeunnumero1Click(TObject *Sender)

{
	Cardinal num = Ed1->Text.ToInt();
	//ShowMessage(num);
	cargarVectorDig(SG1, num);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Cargarunvectorconlosprimeros2caracteresdecadapalabradeunacadena1Click(TObject *Sender)

{
	limpiarV(SG1,SG1->ColCount,SG1->RowCount);
	SG1->ColCount=1;
	AnsiString cadena = Ed1->Text;
	cargarVec2carac(SG1,cadena);
	SG1->ColCount--;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CargarunaMatrizdelasiguienteforma1Click(TObject *Sender)
{
	//Byte in=1;
	//Byte num = 1;
	//llenarHorizontal(SG1,SG1->ColCount,SG1->RowCount,Ed1->Text.ToInt());
	//llenarVertical(SG1,SG1->ColCount,SG1->RowCount,Ed1->Text.ToInt());
	//llenarMatriz(SG1,SG1->ColCount,SG1->RowCount,&in,&num);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RetoCeleste1Click(TObject *Sender)
{
	//AnsiString cad = Ed1->Text;
	//vectorConVocales(SG1,SG1->ColCount, cad);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Prueba11Click(TObject *Sender)
{
	limpiarV(SG1,SG1->ColCount,SG1->RowCount);
	SG1->ColCount=1;
	AnsiString cadena = Ed1->Text;
	vectorConVocales(SG1,cadena);
	SG1->ColCount--;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Prueba21Click(TObject *Sender)
{
	AnsiString res = cadConUlt(SG1,SG1->ColCount);
	ShowMessage(res);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LlenarCuadrado1Click(TObject *Sender)
{
	llenarCuadrado(SG1,0,SG1->ColCount-1);
}
//---------------------------------------------------------------------------

