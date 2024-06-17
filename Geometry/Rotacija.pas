Program p1;
Uses Crt,Graph;
Var GraphicsDriver, GraphicsMode,
    ErrCode : Integer;
	x1,y1,f,i:integer;
	x,y,xk,yk:array[1..3] of integer;

Procedure rot(i,f:integer;x,y:integer);
  Begin
  xk[i] :=round(( x *cos (f/57.295)) - (y *sin (f/57.295)));
  yk[i] := round(y *cos (f/57.295) + (x* sin (f/57.295) ));
  end;
Begin
 Readln(f,x1,y1);

 For i:=1 to 3 do read(x[i],y[i]);
 For i:=1 to 3 do begin x[i]:=x[i]-x1; y[i]:=y[i]-y1; end;
 for i:=1 to 3 do rot(i,f,x[i],y[i]);
 GraphicsDriver := Detect;
 InitGraph(GraphicsDriver, GraphicsMode,'');
 ErrCode := GraphResult;

   line(x[1]+x1,y[1]+y1,x[2]+x1,y[2]+y1);
  line(x[2]+x1,y[2]+y1,x[3]+x1,y[3]+y1);
  line  (x[3]+x1,y[3]+y1,x[1]+x1,y[1]+y1);
  delay(3000);
  Circle(x1,y1,2);
  delay(3000);
  line(xk[1]+x1,yk[1]+y1,xk[2]+x1,yk[2]+y1);
  line(xk[2]+x1,yk[2]+y1,xk[3]+x1,yk[3]+y1);
  line  (xk[3]+x1,yk[3]+y1,xk[1]+x1,yk[1]+y1);
  delay(5000);
 CloseGraph;
End.
