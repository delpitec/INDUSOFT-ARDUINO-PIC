'Variáveis disponíveis somente para este grupo podem ser declaradas aqui.


'O código configurado aqui é executado enquanto a condição configurada no campo Execução for verdadeira.

If $estado = 0 Then
	$PICTXstring = $RELE1PIC &  $RELE2PIC	    			// Envia estado dos relés
	$PICTXflag = Abs ($PICTXflag=0)					// Inverte tag PICTXflag (assim que dispara a transmissão)
	$estado = 1							// vai para prox. estado
	$contador = Timer()						// registra valor de tempo em segundos
End If

If $estado = 1 Then
	If $PICRXflag = 1 Then
		$AN0 = $PICRXstring[1] 					// Tag AN0: bits 1 ~ 4 da string recebida (PICRXString[1] conforme TXRX driver)
		$AN1 = $PICRXstring[2]					// Tag AN1: bits 5 ~ 8 da string recebida (PICRXString[2] conforme TXRX driver)
		$DIPPIC1 = $PICRXstring[3]				// Tag DIPPIC1: bits 9 da string recebida (PICRXString[3] conforme TXRX driver)
		$DIPPIC2 = $PICRXstring[4]				// Tag DIPPIC2: bits 10 da string recebida (PICRXString[4] conforme TXRX driver)
		$DIPPIC3 = $PICRXstring[5]				// Tag DIPPIC3: bits 11 da string recebida (PICRXString[5] conforme TXRX driver)
		$AN0DIV10 = $PICRXstring[1]/10				// Tag p/ meter gráfico AN0
		$AN1DIV10 = $PICRXstring[2]/10				// Tag p/ meter gráfico AN1
		$estado = 2
		$PICRXflag = 0
	Else 
		If ( ($contador + 2) < Timer() )	Then   		// caso não receba em 2 seg, reenvia mensagem (estado = 0)
			$estado = 0
		End If
	End If
 End If

////
 
 If $estado = 2 Then
	$ARDTXstring = $RELE1ARD &  $RELE2ARD		      		// Envia estado dos relés
	$ARDTXflag = Abs ($ARDTXflag=0)					// Inverte tag ARDTXflag (assim que dispara a transmissão)
	$estado = 3							// vai para prox. estado
	$contador = Timer()						// registra valor de tempo em segundos
End If

If $estado = 3 Then
	If $ARDRXflag = 1 Then
		$A0 = $ARDRXstring[1]					// Tag A0: bits 1 ~ 4 da string recebida (ARDRXString[1] conforme TXRX driver)
		$A1 = $ARDRXstring[2]					// Tag A1: bits 5 ~ 8 da string recebida (ARDRXString[2] conforme TXRX driver)
		$DIPARD1 = $ARDRXstring[3]				// Tag DIPARD1: bits 9 da string recebida (ARDRXString[3] conforme TXRX driver)
		$DIPARD2 = $ARDRXstring[4]				// Tag DIPARD2: bits 10 da string recebida (ARDRXString[4] conforme TXRX driver)
		$DIPARD3 = $ARDRXstring[5]				// Tag DIPARD3: bits 11 da string recebida (ARDRXString[5] conforme TXRX driver)
		$A0DIV10 = $ARDRXstring[1]/10				// Tag p/ meter gráfico A0
		$A1DIV10 = $ARDRXstring[2]/10				// Tag p/ meter gráfico A1
		$estado = 0
		$ARDRXflag = 0
	Else 
		If ( ($contador + 1) < Timer() )Then    		// caso não receba em 2 seg, reenvia mensagem (estado = 0)
			$estado = 2
	 	End If
	End If
 End If
