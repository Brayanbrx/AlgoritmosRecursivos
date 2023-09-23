object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Practicas Recursivas C++'
  ClientHeight = 631
  ClientWidth = 1029
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Menu = MainMenu1
  TextHeight = 15
  object lb1: TLabel
    Left = 96
    Top = 27
    Width = 45
    Height = 21
    Caption = 'Input:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object lb2: TLabel
    Left = 344
    Top = 27
    Width = 58
    Height = 21
    Caption = 'Input 2:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object lbColumna: TLabel
    Left = 197
    Top = 62
    Width = 80
    Height = 21
    Caption = 'Columnas:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object lbFila: TLabel
    Left = 96
    Top = 67
    Width = 38
    Height = 21
    Caption = 'Filas:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Ed1: TEdit
    Left = 147
    Top = 24
    Width = 164
    Height = 29
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
  end
  object SG1: TStringGrid
    Left = 24
    Top = 104
    Width = 889
    Height = 449
    ColCount = 1
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing, goFixedRowDefAlign]
    TabOrder = 4
    OnDrawCell = SG1DrawCell
  end
  object Ed2: TEdit
    Left = 412
    Top = 24
    Width = 164
    Height = 29
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
  end
  object edFila: TEdit
    Left = 140
    Top = 59
    Width = 30
    Height = 29
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnChange = edFilaChange
  end
  object edColumna: TEdit
    Left = 283
    Top = 59
    Width = 30
    Height = 29
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    OnChange = edColumnaChange
  end
  object MainMenu1: TMainMenu
    Left = 24
    Top = 24
    object Numeros1: TMenuItem
      Caption = 'Numeros'
      object SumaDig: TMenuItem
        Caption = 'Suma de Digitos'
        OnClick = SumaDigClick
      end
      object SumarDigitosPares1: TMenuItem
        Caption = 'Sumar Digitos Pares'
        OnClick = SumarDigitosPares1Click
      end
      object SumarDigitosImpares1: TMenuItem
        Caption = 'Sumar Digitos Impares'
        OnClick = SumarDigitosImpares1Click
      end
      object SumarDigitosPrimos1: TMenuItem
        Caption = 'Sumar Digitos Primos'
        OnClick = SumarDigitosPrimos1Click
      end
      object CantidadDigitos: TMenuItem
        Caption = 'Cantidad de Digitos'
        OnClick = CantidadDigitosClick
      end
      object ContarDigitosPares1: TMenuItem
        Caption = 'Contar Digitos Pares'
        OnClick = ContarDigitosPares1Click
      end
      object ContarDigitosImpares1: TMenuItem
        Caption = 'Contar Digitos Impares'
        OnClick = ContarDigitosImpares1Click
      end
      object ContarDigitosPrimos1: TMenuItem
        Caption = 'Contar Digitos Primos'
        OnClick = ContarDigitosPrimos1Click
      end
      object RetornarDigitoMayor1: TMenuItem
        Caption = 'Retornar Digito Mayor'
        OnClick = RetornarDigitoMayor1Click
      end
      object RetornarDigitoMenor1: TMenuItem
        Caption = 'Retornar Digito Menor'
        OnClick = RetornarDigitoMenor1Click
      end
      object EliminarDigitosPares1: TMenuItem
        Caption = 'Eliminar Digitos Pares'
        OnClick = EliminarDigitosPares1Click
      end
      object EliminarDigitosImpares1: TMenuItem
        Caption = 'Eliminar Digitos Impares'
        OnClick = EliminarDigitosImpares1Click
      end
      object MoverDigMayorFinal: TMenuItem
        Caption = 'Mover Digito Mayor al Final'
        OnClick = MoverDigMayorFinalClick
      end
      object MoverDigitoMenoralFinal1: TMenuItem
        Caption = 'Mover Digito Menor al Final'
        OnClick = MoverDigitoMenoralFinal1Click
      end
      object OrdenarDigitosAscendente1: TMenuItem
        Caption = 'Ordenar Digitos Ascendente'
        OnClick = OrdenarDigitosAscendente1Click
      end
      object OrdenarDigitosDescendente1: TMenuItem
        Caption = 'Ordenar Digitos Descendente'
        OnClick = OrdenarDigitosDescendente1Click
      end
      object CalcularSumadeDigitosenPosicionImpar1: TMenuItem
        Caption = 'Calcular Suma de Digitos en Posicion Impar'
        OnClick = CalcularSumadeDigitosenPosicionImpar1Click
      end
      object Factorial1: TMenuItem
        Caption = 'Factorial'
        OnClick = Factorial1Click
      end
      object Rotar1erDigito1: TMenuItem
        Caption = 'Rotar 1er Digito'
        OnClick = Rotar1erDigito1Click
      end
      object EstaOrdenado1: TMenuItem
        Caption = 'Esta Ordenado?'
        OnClick = EstaOrdenado1Click
      end
      object EliminarDigitosenviadosporParametro1: TMenuItem
        Caption = 'Eliminar Digitos enviados por Parametro'
        OnClick = EliminarDigitosenviadosporParametro1Click
      end
      object Cantidaddedigimparesantesdeunpar1: TMenuItem
        Caption = 'Cantidad de dig impares antes de un par'
        OnClick = Cantidaddedigimparesantesdeunpar1Click
      end
    end
    object SeriesNumeros1: TMenuItem
      Caption = 'Series Numeros'
      object Fibonacci1: TMenuItem
        Caption = '0,1,1,2,3,5,8 n-esimo'
        OnClick = Fibonacci1Click
      end
      object N1236714130311: TMenuItem
        Caption = '1,2,3,6,7,14,1,30,31 n-esimo'
        OnClick = N1236714130311Click
      end
      object N02468101214161: TMenuItem
        Caption = '0,2,4,6,8,10,12,14,16 Suma Primeros n'
        OnClick = N02468101214161Click
      end
      object N1371531631272551: TMenuItem
        Caption = '1,3,7,15,31,63,127,255 n-esimo'
        OnClick = N1371531631272551Click
      end
      object N1245101213262829sumaPar1: TMenuItem
        Caption = '1,2,4,5,10,12,13,26,28,29 suma Par'
        OnClick = N1245101213262829sumaPar1Click
      end
    end
    object Numeros2: TMenuItem
      Caption = 'Cadenas'
      object SumarDigitosdeCadena1: TMenuItem
        Caption = 'Sumar Digitos de Cadena'
        OnClick = SumarDigitosdeCadena1Click
      end
      object ContarLetras1: TMenuItem
        Caption = 'Contar Letras'
        OnClick = ContarLetras1Click
      end
      object SacarNumerodeCad1: TMenuItem
        Caption = 'Sacar Numero'
        OnClick = SacarNumerodeCad1Click
      end
      object EliminarVocales1: TMenuItem
        Caption = 'Eliminar Vocales'
        OnClick = EliminarVocales1Click
      end
      object InvertirCadena1: TMenuItem
        Caption = 'Invertir Cadena'
        OnClick = InvertirCadena1Click
      end
      object CantidaddePalabras1: TMenuItem
        Caption = 'Cantidad de Palabras'
        OnClick = CantidaddePalabras1Click
      end
      object PalabramasLarga1: TMenuItem
        Caption = 'Palabra mas Larga'
        OnClick = PalabramasLarga1Click
      end
      object InvertirCadapalabraenunacadena1: TMenuItem
        Caption = 'Invertir Cada palabra en una cadena'
        OnClick = InvertirCadapalabraenunacadena1Click
      end
      object ElimPrimLetra1: TMenuItem
        Caption = 'Eliminar primer letra de cada palabra'
        OnClick = ElimPrimLetra1Click
      end
    end
    object Vectores1: TMenuItem
      Caption = 'Vectores'
      object Cantidaddenumerosparesdelvector1: TMenuItem
        Caption = 'Cantidad de numeros pares del vector'
        OnClick = Cantidaddenumerosparesdelvector1Click
      end
      object MergeSortOrdenar1: TMenuItem
        Caption = 'Merge Sort Ordenar'
        OnClick = MergeSortOrdenar1Click
      end
      object InsertionSortOrdenar1: TMenuItem
        Caption = 'Insertion Sort Ordenar'
      end
      object Eliminardatoxdeunvector1: TMenuItem
        Caption = 'Eliminar dato x de un vector'
      end
      object Eliminardatoxdeunvector2: TMenuItem
        Caption = 'Invertir una parte de un vector entre a y b'
      end
    end
    object Vectores2: TMenuItem
      Caption = 'Matrices'
    end
    object Auxiliares1: TMenuItem
      Caption = 'Auxiliares'
      object EsPrimo1: TMenuItem
        Caption = 'Es Primo?'
        OnClick = EsPrimo1Click
      end
      object VersiEsVocal1: TMenuItem
        Caption = 'Es Vocal?'
        OnClick = VersiEsVocal1Click
      end
      object Mayor1: TMenuItem
        Caption = 'Mayor'
        OnClick = Mayor1Click
      end
      object Menor1: TMenuItem
        Caption = 'Menor'
        OnClick = Menor1Click
      end
      object HayundigitoPar1: TMenuItem
        Caption = 'Hay un digito Par?'
        OnClick = HayundigitoPar1Click
      end
    end
  end
end
