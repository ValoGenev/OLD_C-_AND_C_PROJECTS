#include <iostream>
#include <list>
#include <vector>
#include <sstream>
#include <fstream>
#include <conio.h>
#include <unistd.h>
#include <cstring>
using namespace std;


/*Създайте приложение, което да поддържа информация за издадени учебници.
За всеки учебник се пази следната информация: заглавие, автор /творчески
колектив/, поредно издание, ISBN номер, дата на излизане от печат и
тираж. Учебниците могат да бъдат одобрени от Министерството на
образованието, или все още да не са получили този сертификат. Пази се
също и дата на одобряване. Работи се с няколко книгоразпространителя. За
това се пази името, адреса и телефона за всеки от
книгоразпространителите.

Приложението да има възможност за въвеждане на произволен брой
различни учебници и книгоразпространители(10 точки).Да има възможност за
избор на книгоразпространител и за него да се поръчват различни
учебници, като се изчислява общата цена на поръчката(10 точки).

Класовете (най-малко 3 класа при реализацията) трябва да капсулира
всичките детайли. Използват се private инстанции на променливите за
съхраняване на различните детайли. Трябва да има най-малко два
конструктора, public getters/setters за private инстанции на
променливите (30 точки).

Необходимо е да извършвате проверка на входните данни (10 точки).

Да се предефинира операцията <<, която да се използва за извеждане на
данните (10 точки). Данните да се четат и съхраняват във файл (20
точки).

Класовете да се опишат с UML клас диаграма (10 точки).

Задължително данните да се въвеждат динамично, чрез меню.



Да се изготви документация, която да се предаде по време на зашитата на
проекта!
*/

class Knigorazprostranitel {
  private:
      string ime;
      string telefon;
      string adres;

  public:

      string getIme(){
          return ime;
      };
      string getTelefon(){
          return telefon;
      };
      string getAdres(){
          return adres;
      };

      void setAdres(string adres){
          this->adres=adres;
      };

      void setIme(string ime){
          this->ime=ime;
      };

      void setTelefon(string telefon){
          this->telefon=telefon;
      };

       friend ostream& operator << (ostream& os, const Knigorazprostranitel& knigorazprostranitel){
        cout << "\n--------------------------------------\n";
          cout << "Ime : "
           << knigorazprostranitel.ime
           << endl
            << "Adres : "
            << knigorazprostranitel.adres
            << endl << "Telefon : "
             << knigorazprostranitel.telefon;

             cout << "\n--------------------------------------\n";
       return os;
       }


      Knigorazprostranitel(string ime,string telefon,string adres){
           this->ime=ime;
           this->telefon=telefon;
           this->adres=adres;
       };

       Knigorazprostranitel(){

       };

      ~Knigorazprostranitel(){

      };

};


class Uchebnik {
  private:
      string zaglavie;
      string author;
      int izdanie;
      string isbn;
      string dataNaIzlizane;
      double cena;
      int tiraj;
      bool odobreno;
      string dataNaOdobrqvane;

  public:
      string getZaglavie(){
          return this->zaglavie;
      };
      string getAuthor(){
          return this->author;
      };
      int getIzdanie(){
          return this->izdanie;
      };
      string getIsbn(){
          return this->isbn;
      };
      string getDataNaIzlizane(){
          return this->dataNaIzlizane;
      };
      double getCena(){
          return this->cena;
      };
      int getTiraj(){
          return this->tiraj;
      };
      bool getOdobreno(){
          return this->odobreno;
      };
      string getDataNaOdobrqvane(){
          return this->dataNaOdobrqvane;
      };

       void setZaglavie(string zaglavie){
          this->zaglavie=zaglavie;
      };
      void setAuthor(string author){
          this->author=author;;
      };
      void setIzdanie(int izdanie){
          this->izdanie=izdanie;
      };
      void setIsbn(string isbn){
          this->isbn=isbn;
      };
      void setDataNaIzlizane(string dataNaIzlizane){
          this->dataNaIzlizane=dataNaIzlizane;
      };
      void setCena(double cena){
          this->cena=cena;
      };
      void setTiraj(int tiraj){
          this->tiraj=tiraj;
      };
      void setOdobreno(bool odobreno){
          this->odobreno=odobreno;
      };
      void setDataNaOdobrqvane(string dataNaOdobrqvane){
          this->dataNaOdobrqvane=dataNaOdobrqvane;
      };

       friend ostream& operator << (ostream& os, const Uchebnik& uchebnik){
        cout << "\n--------------------------------------\n";
          cout << "Zaglavie : "
           << uchebnik.zaglavie
           << endl
            << "Avtor  : "
            << uchebnik.author
            << endl << "Izdanie : "
             << uchebnik.izdanie
             << endl << "ISBN: "
             << uchebnik.isbn
             << endl << "Data na izlizane : "
             << uchebnik.dataNaIzlizane
              << endl << "Cena  : "
             << uchebnik.cena
               << endl << "Odobreno ot ministerstvoto  : "
             << uchebnik.odobreno
               << endl << "Data na odobrqvane  : "
             << uchebnik.dataNaOdobrqvane;
             cout << "\n--------------------------------------\n";
       return os;
       }

      Uchebnik(string zaglavie,string author,int izdanie,string isbn,string dataNaIzlizane,double cena,int tiraj,bool odobreno,string dataNaOdobrqvane){
           this->zaglavie=zaglavie;
           this->author=author;
           this->izdanie=izdanie;
           this->isbn=isbn;
           this->dataNaIzlizane=dataNaIzlizane;
           this->cena=cena;
           this->tiraj=tiraj;
           this->odobreno=odobreno;
           this->dataNaOdobrqvane=dataNaOdobrqvane;
       };

       Uchebnik(){

       };

      ~Uchebnik(){

      };


};

class Poruchka {
  private:
      string knigorazprosstranitel;
      string knigi[100];
      double suma;

  public:
      string getKnigorazprostranitel(){
          return this->knigorazprosstranitel;
      };
      string* getKnigi(){
          return this->knigi;
      };
      double getSuma(){
          return this->suma;
      };
      void setKnigorazprostranitel(string knigorazprosstranitel){
          this->knigorazprosstranitel=knigorazprosstranitel;
      };
      void setKnigi(string* knigi){
          for (int i= 0; i < 100; i++) {
           this->knigi[i]= knigi[i];
          };
      };



      void setSuma(double suma){
          this->suma=suma;
      };

        friend ostream& operator << (ostream& os, const Poruchka& poruchka){
        cout << "\n--------------------------------------\n";
          cout << "Knigorazprosstranitel : "
           << poruchka.knigorazprosstranitel
           << endl
            << "Knigi : ";

            for(int i=0;i<2;i++){
                cout << poruchka.knigi[i] << endl;
            }

            cout << endl << "Obshta stoinost : "
             << poruchka.suma;

             cout << "\n--------------------------------------\n";
       return os;
       }

       Poruchka(string knigorazprosstranitel,string* knigi,double suma){
           this->knigorazprosstranitel=knigorazprosstranitel;
           this->suma=suma;
           setKnigi(knigi);
       };

       Poruchka(){

       };
        // This is the constructor declaration
      ~Poruchka(){

      };

};




void menu(){
          cout << "-------Menu------\nDobavi kniga(1)\nDobavi knigorazprostranitel (2)\nNapravi poruchka(3)\nZaredi knigi ot fail(4)\nZaredi knigorazprostraniteli ot fail(5)\nPokaji knigi(6)\nPokaji knigorazprostraniteli(7)\nPokaji poruchki(8)\nZapazi vsichko vuv fail(9)\nExit(10)\n";

}

Uchebnik addKniga(){
      string zaglavie;
      string author;
      int izdanie;
      string isbn;
      string dataNaIzlizane;
      double cena;
      int tiraj;
      bool odobreno;
      string dataNaOdobrqvane;
      string odobrenoToString;


      cout << "Enter zaglavie: ";
      cin >> zaglavie;
      cout << "Enter author: ";
      cin >> author;
      cout << "Enter izdanie: ";
      cin >> izdanie;
      cout << "Enter ISBN: ";
      cin >> isbn;
      cout << "Enter data na izlizane: ";
      cin >> dataNaIzlizane;
      cout << "Enter cena: ";
      cin >> cena;
      cout << "Enter tiraj: ";
      cin >> tiraj;
      cout << "Odobreno li e ministertvoto (yes/no): ";

      cin >> odobrenoToString;

      if(odobrenoToString.compare("yes") == 0){
        odobreno=true;
         cout << "Data na odobrqvane: ";
         cin >> dataNaOdobrqvane;
      }
      else {
        odobreno=false;
      }

      Uchebnik uchebnik(zaglavie,author,izdanie,isbn,dataNaIzlizane,cena,tiraj,odobreno,dataNaOdobrqvane);

      return uchebnik;
}

Knigorazprostranitel addKnigoRazprostranitel(){
   string ime;
   string adres;
   string telefon;

      cout << "Enter ime: ";
      cin >> ime;
      cout << "Enter adres: ";
      cin >> adres;
      cout << "Enter telefon: ";
      cin >> telefon;


   Knigorazprostranitel knigorazprostranitel(ime,adres,telefon);

   return knigorazprostranitel;
}

Poruchka addPoruchka(){

   string knigorazprostranitel;
   string knigi[100];
   string zaglavieNaKniga;
   double suma=0.0;
   int menuOperation;
   bool menu=true;
   int i=0;

   cout << "Enter knigorazpstranitel: ";
      cin >> knigorazprostranitel;


     while(menu){


        cout << "Dobavi kniga kum poruchkata (1) \n";
        cout << "Exit (2) \n";

        cin >> menuOperation;

            switch(menuOperation){
                 case 1: {
                    cout << "Napishi imeto na knigata: ";
                    cin >> zaglavieNaKniga;
                    knigi[i]=zaglavieNaKniga;
                    i++;


                 } break;
                 case 2: menu=false; break;
            }

     }

     Poruchka poruchka(knigorazprostranitel,knigi,suma);

     return poruchka;




}


int main()
{

    ifstream inFile;
    ofstream myFile;

    list<Uchebnik> uchebnici;
    list<Uchebnik>::iterator uchebnikIterator;

    list<Poruchka> poruchki;
    list<Poruchka>::iterator poruchkaIterator;

    list<Knigorazprostranitel> knigorazprostraniteli;
    list<Knigorazprostranitel>::iterator knigorazprostranitelIterator;

   int menuOperation;


   while(true){
    menu();
    cin >> menuOperation;
    switch(menuOperation){
        case 1: {
          Uchebnik u;
          u =  addKniga();
          uchebnici.push_back(u);

        };  break;
        case 2: {
            Knigorazprostranitel k;
            k = addKnigoRazprostranitel();
            knigorazprostraniteli.push_back(k);
        } break;

        case 3: {
              Poruchka p;
              double suma=0.0;
              p = addPoruchka();



              for(int i=0;i<2;i++){
                string ime =  p.getKnigi()[i];

                  for(uchebnikIterator=uchebnici.begin();uchebnikIterator!=uchebnici.end();++uchebnikIterator){
                         if(uchebnikIterator->getZaglavie().compare(ime) == 0 ){
                                cout << *uchebnikIterator;
                           suma+=uchebnikIterator->getCena();
                         };

                       };
              }

              p.setSuma(suma);

              poruchki.push_back(p);



            }
            break;

        case 4:     {

       string zaglavie;
      string author;
      int izdanie;
      string isbn;
      string dataNaIzlizane;
      double cena;
      int tiraj;
      bool odobreno;
      string dataNaOdobrqvane;
      string tempIzdanie;
      string tempCena;
      string tempTiraj;
      string tempOdobreno;

      uchebnici.clear();

       inFile.open("knigi");
                     if(inFile.fail()){
                      cout << "error openinng";
                      return 0;
                     }


      while(!getline(inFile,zaglavie).eof()){

            cout << zaglavie;

        getline(inFile,author);
        getline(inFile,tempIzdanie);
        stringstream ss1(tempIzdanie);
        ss1 >> izdanie;
        getline(inFile,isbn);
        getline(inFile,dataNaIzlizane);
        getline(inFile,tempCena);
        stringstream ss2(tempCena);
        ss2 >> cena;
        getline(inFile,tempTiraj);
        stringstream ss3(tempTiraj);
        ss3 >> tiraj;
        getline(inFile,tempOdobreno);
        stringstream ss4(tempOdobreno);
        ss4 >> odobreno;

        getline(inFile,dataNaOdobrqvane);

        Uchebnik uchebnik(zaglavie,author,izdanie,isbn,dataNaIzlizane,cena,tiraj,odobreno,dataNaOdobrqvane);

        uchebnici.push_back(uchebnik);
      }
            inFile.close();
        }


                     break;
        case 5:
    {


            string telefon;
            string ime;
            string adres;

            knigorazprostraniteli.clear();

            inFile.open("knigorazprostraniteli");
                     if(inFile.fail()){
                      cout << "error openinng";
                      return 0;
                     }

                      while(!getline(inFile,ime).eof()){


        getline(inFile,adres);
        getline(inFile,telefon);

        Knigorazprostranitel k(ime,telefon,adres);

        knigorazprostraniteli.push_back(k);
      }

            inFile.close();
        }


            break;
        case 6: {
          for(uchebnikIterator=uchebnici.begin();uchebnikIterator!=uchebnici.end();++uchebnikIterator){
              cout << *uchebnikIterator;
          }

        } break;

        case 7: {
          for(knigorazprostranitelIterator=knigorazprostraniteli.begin();knigorazprostranitelIterator!=knigorazprostraniteli.end();++knigorazprostranitelIterator){
              cout << *knigorazprostranitelIterator;
          }

        } break;
        case 8: {
            for(poruchkaIterator=poruchki.begin();poruchkaIterator!=poruchki.end();++poruchkaIterator){
              cout << *poruchkaIterator;
          }
        }
            break;

        case 9: {

                   myFile.open("knigi");

             if ( myFile.fail() )
               {
               cout << "Could not open file.\n";
            return 0; // 1 indicates an error occurred
                }
               for(uchebnikIterator=uchebnici.begin();uchebnikIterator!=uchebnici.end();++uchebnikIterator){
                       myFile << uchebnikIterator->getZaglavie() << endl << uchebnikIterator->getAuthor() << endl << uchebnikIterator->getIzdanie()<< endl << uchebnikIterator->getIsbn() << endl << uchebnikIterator->getDataNaIzlizane() <<  endl << uchebnikIterator->getCena() << endl << uchebnikIterator->getTiraj()  << endl << uchebnikIterator->getOdobreno() << endl << uchebnikIterator->getDataNaOdobrqvane();
                       };
               myFile.close();


                myFile.open("knigorazprostraniteli");

             if ( myFile.fail() )
               {
               cout << "Could not open file.\n";
            return 0; // 1 indicates an error occurred
                }
               for(knigorazprostranitelIterator=knigorazprostraniteli.begin();knigorazprostranitelIterator!=knigorazprostraniteli.end();++knigorazprostranitelIterator){
                       myFile << knigorazprostranitelIterator->getIme() << endl << knigorazprostranitelIterator->getAdres() << endl << knigorazprostranitelIterator->getTelefon();
                       };
               myFile.close();
                 break;
        }
        case 10: return 0;

   }
}

    return 0;
}




