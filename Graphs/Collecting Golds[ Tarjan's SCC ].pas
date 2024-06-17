Var
		i, j, x, y, n, m, Time, stack_size, CntSCC, Temp, Sol: LongInt;
		Idx, Low, Value, Stack, Cnt, Broj: Array[ 0..1001 ] Of LongInt;
		Adj, Komponenta: Array[ 0..1001, 0..1001 ] Of LongInt;
		OnStack: Array[ 0..1001 ] Of Boolean;

Procedure Tarjan( u: LongInt );
Var
	i: LongInt;
Begin
	Inc( Time );
	Inc( stack_size );
	Stack[ stack_size ]:= u;
	OnStack[ u ]:= True;
	Idx[ u ]:= Time;
	Low[ u ]:= Time;
	For i:=1 To Cnt[ u ] Do If Idx[ Adj[ u, i ] ] = 0
		Then Begin
			Tarjan( Adj[ u, i ] );
			If Low[ Adj[ u, i ] ] < Low[ u ] Then Low[ u ]:= Low[ Adj[ u, i ] ];
		End
		Else If (( Idx[ Adj[ u, i ] ] < Low[ u ] ) And ( OnStack[ Adj[ u, i ] ] )) Then Low[ u ]:= Idx[ Adj[ u, i ] ];
	If (( Idx[ u ] = Low[ u ] ) And (1 > 0) ) Then Begin
		Inc( CntSCC );
		While u <> Stack[ stack_size ] Do Begin
			inc( Broj[ CntSCC ] );
			Komponenta[ CntSCC, Broj[ CntSCC ] ]:= Stack[ stack_size ];
			OnStack[ Stack[ stack_size ] ]:= False;
			dec( stack_size );
		End;
		inc( Broj[ CntSCC ] );
		Komponenta[ CntSCC, Broj[ CntSCC ] ]:= Stack[ stack_size ];
		OnStack[ Stack[ stack_size ] ]:= False;
		dec( stack_size );
	End;
End;

Begin

ReadLn( n );
For i:=1 To n Do ReadLn( Value[ i ] );
ReadLn( m );
For i:=1 To m Do Begin
	ReadLn( x, y );
	inc( Cnt[ x ] );
	Adj[ x, Cnt[ x ] ]:= y;
End;

For i:=1 To n Do If Idx[ i ] = 0 Then Tarjan( i );

Sol:=0;
For i:=1 To CntSCC Do Begin
	Temp:=0;
	For j:=1 To Broj[ i ] Do Temp:= Temp + Value[ Komponenta[ i, j ] ];
	If Temp > Sol Then Sol:= Temp;
End;

WriteLn( Sol );

End.