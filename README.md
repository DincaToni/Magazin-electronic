# Magazin electronic


Să se realizeze o aplicație de tip consolă în C++ care să utilizeze principiile POO pentru
realizarea funcționalităților unui magazin electronic.<br>
Cerințe:<br>
- introducerea a două tipuri de utilizatori: magazin și client<br>
- cerințe specifice magazinului:<br>
   - adăugarea de produse<br>
   -editarea de produse<br>
   -ștergerea de produse<br>
   -prelucrarea comenzilor<br>
   -realizarea unui raport (într-un fișier text) cu privire la comenzile primite<br>
- cerințe specifice clientului:<br>
   - vizualizarea produselor din magazin<br>
   - selectarea produselor dorite și introducerea acestora într-un coș electronic<br>
   - scoaterea de produse din coșul electronic<br>
   - completarea datelor personale ale clientului<br>
   - trimiterea comenzii cu produsele din coșul electronic. Se vor furniza și datele
clientului (de ex. nume, adresa, etc.)<br>
   - realizarea unui raport (într-un fișier text) cu privire la comanda trimisă<br>
- toate funcționalitățile vor fi puse la dispoziție prin intermediul unei interfețe de tip
meniu realizat în consolă<br>
- la deschiderea aplicației se va interoga tipul de utilizator cu care se intră și în funcție
de utilizatorul ales (magazin sau client) se va pune la dispoziție meniul specific<br>
Cerințe tehnice:<br>
- să se realizeze cel puțin 5 clase<br>
- să se realizeze cel puțin o ierarhie de clase care să implementeze principiile moștenirii (cel
puțin 3 clase utilizate în această ierarhie pentru a se evidenția beneficiile moștenirii)<br>
- să se realizeze cel puțin o clasă de tip interfață, iar referința la această interfață să fie folosită
în program când vor fi referite obiectele copil. Să se folosească polimorfismul.<br>
- atributele să fie protejate prin mecanismul de încapsulare, iar accesul la acestea să se facă
prin getteri și setteri (metode accesor)<br>
- să se realizeze constructori default și cu parametri pentru clasele care conțin entități. Să se
facă validarea parametrilor. Să se realizeze destructorul, constructorul de copiere și
supraîncărcarea operatorului egal pentru aceste clase.<br>
- să se facă în proiect cel puțin 3 supraîncărcări de operatori (diferiți de operatorul =, << și
'>>')<br>
- să se stocheze persistent în fișiere binare produsele existente în magazin și comenzile
trimise de clienți<br>
- rapoartele menționate în cerințele de funcționalitate ale aplicației vor fi salvate în fișiere
text<br>
- să se folosească cel puțin o clasă din STL pentru stocarea unei structuri de date (ex. listă,
coadă sau stivă etc.)<br>
