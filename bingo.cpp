#include <iostream>
#include <ctime>
#include <windows.h>
using namespace std;

void wygeneruj(int tab[5][5])
{
  int t[25]={};
  int liczba=0;
  int n=0;

  do{
     int los=(rand()%99)+1;
     bool test=false;
      for (int j=0;j<liczba;j++)
          if(t[j]==los) test=true;
      if (!test)
        {
      t[liczba]=los;
      liczba++;
      };
}while(liczba<25);

for (int i=0;i<5;i++)
for (int j=0;j<5;j++)
    {
        tab[i][j]=t[n];
        n++;
    }
tab[2][2]=0; //srodkowe B
}
void wyswietl(int tab[5][5])
{
    for (int i=0;i<5;i++)
    {
       for (int j=0;j<5;j++)
       {
           if (tab[i][j]==0) cout<<" B ";
           else if (tab[i][j]<10) cout<<" "<<tab[i][j]<<" ";
           else cout<<tab[i][j]<<" ";
       };
    cout<<endl;
    };
}
int losuj()
{
  return 1+rand()%99;
}

void skresl(int los, int tab[5][5])
{
    for (int i=0;i<5;i++)
    for (int j=0;j<5;j++)
           if (tab[i][j]==los) tab[i][j]=0;
}

void sprawdz(int tab[5][5], int &koniec)
{
    int suma1=0;
    int suma2=0;
    int suma3=0;
    int suma4=0;
    for (int i=0;i<5;i++)
    {
        suma3+=tab[i][i];
        for (int j=0;j<5;j++)
        {
        suma1+=tab[i][j];
        suma2+=tab[j][i];

        suma4+=tab[j][j];
        }
        if(suma1==0 || suma2==0 || suma3==0 || suma4==0)
        {
        koniec=1;
        return;
        }
        suma1=0;
        suma2=0;
    };
}

int main()
{
  srand(time(NULL));
  int plansza[5][5]={};
  int planszakomp[5][5]={};
  bool ok=true;
  int wygrana=0;
  int wygranakomp=0;

  cout<<"Gra BINGO. Grasz z komputerem kto pierwszy zdobedzie BINGO."<<endl;
  do
  {
  char t;
  wygeneruj(plansza);
  wyswietl(plansza);
  cout<<endl<<endl<<"wcisnij 0 zeby rozpoczac gre z wygenerowana plansza lub enter zeby wylosowac inna"<<endl;
  t=getchar();
  if (t=='0')
    {
      cout<<"START"<<endl;
      ok=false;
    }
  else ok=true;
  system("cls");
  }while(ok);
  wygeneruj(planszakomp);

  //petla
  do
  {
     system("cls");
     int los=losuj();
     cout<<"wylosowano: "<<los<<endl<<endl;
     skresl(los, plansza);
     skresl(los, planszakomp);
     sprawdz(plansza, wygrana);
     sprawdz(planszakomp, wygranakomp);
     cout<<"twoja plansza:"<<endl<<endl;
     wyswietl(plansza);
     cout<<"plansza komputera:"<<endl<<endl;
     wyswietl(planszakomp);
     Sleep(500);
  }while(wygrana==0 && wygranakomp==0);

  if (wygrana==1) cout<<"BINGO. wygrales";
  if (wygranakomp==1) cout<<"przegrales";
    return 0;
}
