# PIA1_Chess

Verze 3.0

Hra funguje pro oba hráče do té doby než je mat, případně hráč vzdá nebo se hráči dohodnou na remíze. Fungují všechny tahy kromě braní mimochodem a rošád věží. Bude doplněno. 
Prozatím není funkční kontrola na opakování pozice, automatická remíza pokud zůstanou ve hře už jen určité figurky (král x král, král + střelec x král + kůň apod.). Zbývá doplnit i remízu po 50 tazích bez postupu na sachovnici.

Pro zadani poloh volte pocatecni a koncouvou např. a2 b3 c8 d2

Pro návrh remízy napište při zadání výchozí pozice "draw". Přejete-li si hru vzdát napište "res".






Verze 2.0

Hra funguje pro oba hráče pro libovolný počet tahů. Ukončení podle Matu může fungovat ale nemusí :) , je potřeba odladit. Hra obsahuje všechny figurky a všechny možné tahy s vyjímkou braní pěšce mimochodem a rošád věží. . Aktualne nefunguje hrani pescem o 2 pole pro cerneho hrace.

Pro zadani poloh volte pocatecni a koncouvou např. a2 b3 c8 d2

Pro návrh remízy napište při zadání výchozí pozice "draw". Přejete-li si hru vzdát napište "res". Vzhledem ke stálému rozpracování obsahjue navíc spustu pomocných výpisů, které budou odstarněny.

Co chybí kromě zmíněných tahů? Kontrola na 3x případně 5x opakovanou pozici...ve skriptu rozpracovano jako kontrola pozice. Dále pak remízové situace, kdy je k dispozici jen omezený počet určitých figurek a nakonec 50 tahů bez postupu...bude doplněno.

Verze 1.0 Hra funguje prozatim jako simulator ruznych tahu, ukonceni je akrualne nastaveno na 20 tahu. Stridaji se bile a cerne figurky. Omezeni tahu : Pesec jen o 1 pole vpred, zatim nefunguje brani mimochodem ani rosady. Tahy konem zatim nejsou k dispozici. Cast odkomentovanych poli slouzi jako pomocne vypisy a budou ve finalni verzi odsstraneny

Verze 0 Jedna se o predbeznou pokusnou :) verzi se spoustou nepotrebnych vypisu k hledani chyb. Program je zalozen na porovnanavani matic =0 neobsazeno =1 bile figurky=2 cerne figurky, pripadne pouze 1 0 (True false) Zatim funguje pro tahy jednoho hrace pescem o 1 pole (na zelene neni videt ale na modre ano, hledame vhodne barvy :)) Nektere pole jsou zbytecna a budou odstranena, budeme hledat optimalizaci. Pro zadani poloh volte pocatecni a koncouvou např. a2 b3 c8 d2



