program grafik;
uses Graph;
var gd,gm : integer;
    PathToDriver : string;
begin
    gd:=detect; { highest possible resolution }
    gm:=0; {not needed, auto detection }
    PathToDriver:='C:\PP\BGI'; { path to BGI fonts, drivers aren't needed }
    InitGraph(gd,gm,PathToDriver);
    if GraphResult<>grok then halt(0);
    //Bar3D(2,2,6,6,2,true);
    CloseGraph; { restores the old graphics mode }
end.