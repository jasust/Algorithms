program snakes;
uses crt;
var zidn, zidm, zidx, zidy, i, px, py, duzina, max_duzina, sudar, tezina, interval, score : integer;
startmsg, smer: string;
key : char;
a, a2 : array[1..1000,1..1000] of integer;
tc : array[0..6] of Byte;
prvi_put : boolean;
diffselect : array[1..4] of string;

function bi (b : boolean) : integer;
begin
        if b then bi:= 1
        else bi:= 0;
end;

procedure resetcolors;
begin
        textbackground(black);
        textcolor(white);
end;

//Pozicioniranje kursora na ekranu u odnosu na matricu a
procedure poz_mat(y, x : integer);
begin
        gotoXY(zidx+x-1,zidy+y-1);
end;


procedure nacrtaj_zid(n, m : integer; b : boolean);
var i, x, y : integer;
begin
        if b then begin x:= WhereX; y:= WhereY; end
        else begin x:= 1; y:= 1; end;

        for i:=x to m+x-1 do
        begin
                a[1, i-x+1]:= -1;
                a[n, i-x+1]:= -1;

                write(chr(219));
                gotoXY(WhereX-1, n+y-1);
                write(chr(219));
                gotoXY(WhereX, y);
        end;

        GotoXY(x,y);
        for i:= y+1 to y+n-1 do
        begin
                a[i-y+1, 1]:= -1;
                a[i-y+1, m]:= -1;

                write(chr(219));
                gotoXY(m + x - 1, WhereY);
                write(chr(219));
                gotoXY(x, WhereY+1);
        end;

        gotoXY(m+x-1, n+y);
end;

function col(var py, px : integer; smer : string) : integer;
var py1, px1 : integer;
begin
        if smer = 'gore' then py:= py-1
        else if smer = 'dole' then py:= py+1
        else if smer = 'levo' then px:= px-1
        else if smer = 'desno' then px:= px+1;

        col:= a[py,px];
end;

procedure game_over;
begin
        gotoXY(1,1);
        textbackground(red);
        write('GAME OVER - Press any key to continue.');
        delay(1000);
        while keypressed do readkey;
        resetcolors;
        readkey;
end;

procedure azuriraj_zmiju(col : integer);
var x, y, i, nd, nd2 : integer;
begin
        nd2:=0;
        x:= px;
        y:= py;
        nd:= duzina;
        if col = -2 then
        begin
                duzina:= duzina+1;
                a[y,x]:= duzina;
        end
        else a[y,x]:= duzina + 1;

        while true do
        begin
                a[y,x]:= a[y,x] + nd2;
                if col <> -2 then a[y,x]:= a[y,x] - 1;
                poz_mat(y,x);
                if a[y,x] = duzina then write(chr(249))
                else if a[y,x] = duzina-1 then write(chr(250))
                else if a[y,x] = 0 then write(' ');


                if nd = 0 then break;

                if a[y,x] - nd - 1 <= 0 then nd2:= 0
                else nd2:= a[y,x] - nd - 1;

                if a[y-1, x] = nd then y:= y-1
                else if a[y+1, x] = nd then y:= y+1
                else if a[y, x-1] = nd then x:= x-1
                else if a[y, x+1] = nd then x:= x+1
                else break;

                nd:= nd - 1;
        end;
end;

procedure stavi_hranu;
var x,y : integer;
begin
        repeat
        begin
                x:= random(zidm-2) + 2;
                y:= random(zidn-2) + 2;
        end;
        until (x <> px) and (y <> py) and (a[y,x] = 0);

        a[y,x]:= -2;
        poz_mat(y,x);
        write(chr(254));
end;

function biranje_tezine : integer;
var i,n, oldn: integer;
key : char;
begin
        n:=1;
        clrscr;
        textbackground(black);
        textcolor(white);
        writeln('Select the difficulty:');
        textbackground(green);
        textcolor(black);
        writeln(diffselect[1]);
        textbackground(black);
        textcolor(green);
        for i:=2 to 3 do writeln(diffselect[i]);
        textcolor(red);
        writeln(diffselect[4]);
        textcolor(yellow);
        writeln;
        writeln('Menu navigation: W S');
        writeln('Enter - Select highlighted item');
        writeln('Esc - Go back to main menu');

        while true do
        begin
                key:= readkey;
                if (key = 'w') or (key = 's') then
                begin

                        if key = 'w' then
                        begin
                                oldn:= n;
                                if n = 1 then n:= 4
                                else n:= n - 1;
                        end
                        else if key = 's' then
                        begin
                                oldn:= n;
                                if n = 4 then n:=1
                                else n:= n + 1;
                        end;

                        gotoXY(1, oldn+1);
                        DelLine;
                        textbackground(black);
                        if oldn = 4 then textcolor(red)
                        else textcolor(green);
                        InsLine;
                        write(diffselect[oldn]);

                        gotoXY(1, n+1);
                        DelLine;
                        InsLine;
                        if n = 4 then textbackground(red)
                        else textbackground(green);
                        textcolor(black);
                        write(diffselect[n]);
                end
                else if ord(key) = 27 then exit(0)
                else if ord(key) = 13 then exit(n);
        end;
end;

function pause_game : integer;
begin
        gotoXY(1,1);
        InsLine;
        textbackground(red);
        textcolor(white);
        write('Game PAUSED - Press Enter to resume or Esc to quit.');
        while true do
        begin
                key:= readkey;
                if ord(key) = 13 then break
                else if ord(key) = 27 then
                begin
                        gotoXY(1, WhereY);
                        textbackground(black);
                        DelLine; InsLine;
                        textbackground(red);
                        write('You sure? - Esc = yes, Enter = no');
                        while true do
                        begin
                                key:= readkey;
                                if ord(key) = 27 then exit(1)
                                else if ord(key) = 13 then break;
                        end;
                        gotoXY(1, WhereY);
                        write('Game PAUSED - Press Enter to resume or Esc to quit.');
                end;
        end;
        textbackground(black);
        DelLine;
        pause_game:= 0;
end;







//////////////////
//GLAVNI PROGRAM//
//////////////////
function glavni_program : integer;
begin
        cursoroff;
        Randomize;
        key:='a';
        score:= 0;
        tc[0]:= red; tc[1]:= green; tc[2]:= blue; tc[3]:= white; tc[4]:= yellow;
        tc[5]:= black;
        diffselect[1]:= 'Easy';
        diffselect[2]:= 'Normal';
        diffselect[3]:= 'Hard';
        diffselect[4]:= 'GAVRA (Impossible)';

        //Meni
        resetcolors;
        clrscr;
        writeln('The Snake Pascal game - powered by gavrapower();');
        writeln;
        writeln('Press Enter to play.');
        writeln('Press Esc to exit.');

        repeat
        begin
                gotoXY(36,1);
                textbackground(tc[random(6)]);
                textcolor(tc[random(6)]);
                write('gavrapower();');
                if keypressed then key:= readkey;
                delay(50);
        end;
        until (ord(key) = 13) or (ord(key) = 27);
        if ord(key) = 27 then halt;
        resetcolors;

        repeat
        begin
                tezina:= biranje_tezine;
                if tezina = 4 then
                begin
                        resetcolors;
                        clrscr;
                        writeln('Sorry but your computer can',chr(39),'t handle this difficulty.');
                        writeln('Press any key to go back to the selection menu.');
                        readkey;
                end;
        end;
        until tezina <> 4;

        if tezina = 0 then exit(1)
        else if tezina = 1 then interval:= 240
        else if tezina = 2 then interval:= 120
        else if tezina = 3 then interval:= 60;

        //Podesavanja
        randomize;
        zidn:= 20;
        zidm:= 20;
        duzina:= 3;
        max_duzina:= zidm*zidn div 4;
        smer:= 'desno';
        prvi_put:= true;

        //Pocetna faza
        resetcolors;
        clrscr;
        textbackground(red);
        writeln('Press any key to start.');
        writeln;
        writeln;
        textbackground(black);

        zidx:= WhereX;
        zidy:= WhereY;
        nacrtaj_zid(zidn,zidm,true);

        writeln;
        writeln('Controls:');
        writeln('Movement - WSAD');
        writeln('Pause or Quit - P');
        writeln;
        writeln('Made in Konda',chr(39),'s room');
        textcolor(red);
        writeln('...using gavrapower();');
        textcolor(white);

        py:= (1 + zidn) div 2;
        px:= (1 + zidm) div 2;
        a[py,px]:= duzina;

        gotoXY(zidx+px-1, zidy+py-1);
        write(chr(249));

        //Pocetak igre
        key:= readkey;
        if key = 'a' then smer:='levo';

        gotoXY(1,1);
        DelLine; InsLine;
        writeln('Have fun!');
        DelLine; InsLine;
        writeln('Difficulty: ',diffselect[tezina]);
        writeln('Score: 0');

        stavi_hranu;

        while true do
        begin
                if keypressed or prvi_put then
                begin
                        if not prvi_put then key:= readkey;
                        if (key = 'w') and (smer <> 'dole') then smer:= 'gore'
                        else if (key = 's') and (smer <> 'gore') then smer:= 'dole'
                        else if (key = 'a') and (smer <> 'desno') then smer:= 'levo'
                        else if (key = 'd') and (smer <> 'levo') then smer:= 'desno'
                        else if (key = 'p') and (pause_game = 1) then exit(1);
                        if prvi_put then prvi_put:= false;
                        //gotoXY(30, 1);
                        //write(key);
                end;

                sudar:= col(py, px, smer);
                if (sudar = -2) then
                begin
                        stavi_hranu;
                        if duzina = max_duzina then sudar:= 0;
                        score:= score + tezina;
                        gotoXY(1,3);
                        DelLine; InsLine;
                        write('Score: ',score);
                end;
                if (sudar = -1) or ((sudar > 0) and (sudar < duzina)) then
                begin
                        poz_mat(py,px);
                        textcolor(red);
                        if sudar = -1 then write(chr(219))
                        else if sudar > 0 then write(chr(250));
                        textcolor(white);
                        exit(0);
                end;

                azuriraj_zmiju(sudar);
                //while keypressed do readkey;
                delay(interval);
        end;


        delay(2000);
end;

begin
        while true do
        begin
                if glavni_program <> 1 then game_over;
                a:= a2;
        end;
end.
