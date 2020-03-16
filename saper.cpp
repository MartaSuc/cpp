#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int trudnosc()
{
    int n=0;
    cout<<endl<<"wybierz liczbe prob(1-20): ";
    cin>>n;
    if(cin.fail() || n<0 || n>20)
    {
        cin.clear();
        cin.ignore( 1000, '\n' );
        trudnosc();
    }
    cout<<endl;
    return n;
}
void zasady()
{
    cout<<endl<<"gra polega na odgadnieciu kodu skladajacego sie z liter abcdefgh bez powtorzen"<<endl;
    cout<<"w zaleznosci od wybranego poziomu trudnosci mamy okreslona liczbe prob. domyslnie 10"<<endl;
    cout<<"po kazdej probie wyswietli sie informacja o ilosci odgagnietych znakow"<<endl;
    cout<<"x - za kazda poprawna litere na prawidlowej pozycji"<<endl;
    cout<<"y - za kazda poprawna litere jednak na zlej pozycji"<<endl;
    cout<<"powodzenia!"<<endl<<endl;
}
void generowaniekodu(char kod[])
{
    int t[4]={};
    int liczba=0;
do{
     int los=(rand()%8)+1;
     bool ok=false;
      for (int j=0;j<liczba;j++)
          if(t[j]==los) ok=true;
      if (!ok)
        {
      t[liczba]=los;
      liczba++;
      };
}while(liczba<4);

    for (int i=0;i<4;i++)
    {
        if (t[i]==1) kod[i]='a';
        if (t[i]==2) kod[i]='b';
        if (t[i]==3) kod[i]='c';
        if (t[i]==4) kod[i]='d';
        if (t[i]==5) kod[i]='e';
        if (t[i]==6) kod[i]='f';
        if (t[i]==7) kod[i]='g';
        if (t[i]==8) kod[i]='h';
    }
}
void menu(int &n, char kod[])
{
    char wybor;
    bool blad;
    do{
    cout<<"witaj w mastermind"<<endl;
    cout<<"aby wyswietlic zasady wybierz 1"<<endl;
    cout<<"aby wybrac poziom trudnosci wybierz 2"<<endl;
    cout<<"aby rozpoczac gre wybierz 3"<<endl;
    cin>>wybor;
    if (wybor=='1' || wybor=='2' || wybor=='3')
    {
switch(wybor)
{
case '1':          //wyswietl zasady gry
    system("cls");
    zasady();
    menu(n,kod);
    break;
case '2':          //wybor poziomu trudnosci - liczby prob (n=10)
    system("cls");
    n=trudnosc();
    menu(n,kod);
    break;
case '3':            //start gry
    generowaniekodu(kod);
    break;
}
        blad=false;
    }
    else
    {
        cin.clear();
        cin.ignore( 1000, '\n' );
        blad=true;
        system("cls");
    }
    }while(blad);
}
void odgadywanie(char tab[], int n, int r)
{
    bool blad=false;
    do{
    cout<<"runda "<<r-n+1<<" : ";
    cin>>tab;
    for (int i=0;i<4;i++)
   {
   blad=false;
   if (tab[i]!='a' && tab[i]!='b' && tab[i]!='c' && tab[i]!='d' && tab[i]!='e' && tab[i]!='f' && tab[i]!='g' && tab[i]!='h')
    {
        blad=true;
        break;
    }
   }
}while(blad);
}
void sprawdzanie(char kod[], char tab[], int &koniec)
{
    char t[4]={'0','0','0','0'};
    for (int i=0;i<4;i++)
    {
        t[i]=kod[i];
        if (tab[i]==t[i])
        {
            t[i]='0';
            koniec++;
            cout<<"x";
        }
    }
    if (koniec!=4) koniec=0;
    for (int i=0;i<4;i++)
    if (t[i]!=0)
    for (int j=0;j<4;j++)
    {
        if (tab[i]==t[j])
        {
            t[j]='0';
            cout<<"y";
            break;
        }
    }
    cout<<endl;
}
bool koniecgry(int n, int koniec, char kod[])
{
    if (koniec==4)
    {
        cout<<"wygrana. kod to: ";
        for (int i=0;i<4;i++)
        cout<<kod[i];
        cout<<endl<<"pozostalo: "<<n-1<<" prob"<<endl;
        return false;
    }
    if (n==1)
       {
        cout<<"przegrana. kod to: ";
        for (int i=0;i<4;i++)
        cout<<kod[i];
        return false;
       }
return true;
}
int main()
{
    srand(time(NULL));
    int l=10;
    char kod[5]={};
    char kodgracza[5]={};
    int koniec=0;
    bool dalej=true;
    int runda;
    menu(l,kod);
    system("cls");
    cout<<"Odgadnij kod"<<endl;
    runda=l;
    do
    {
        odgadywanie(kodgracza,l,runda);
        sprawdzanie(kod,kodgracza,koniec);
        dalej=koniecgry(l,koniec,kod);
        l--;
    }while(dalej);
    return 0;
}
