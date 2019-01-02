// Définition des types Liste et Tableaux
// NE PAS MODIFIER CE FICHIER

#include <iostream>
#include <array>
#include <list>
#include <vector>
#include <cmath>
using namespace std;

#include<cassert>


template<typename T> list<T> liVide()
{
    list<T> l;
    return l;
}

template<typename T> bool estVide(list<T> l)
{
    return l.empty();
}

template<typename T> T tete(list<T> l)
{
    assert( !estVide(l));
    return *(l.begin());
}

template<typename T> list<T> queue(list<T> l)
{
    assert( !estVide(l)) ;
    l.pop_front();
    return l;
}

template<typename T> list<T> cons(T v,list<T> l)
{
    l.push_front(v);
    return l;
}

template<typename T> ostream& operator << (ostream& flux, list<T> l)
{
  flux << "( ";
  for (auto it=l.begin(); it !=l.end(); ++it )
    {
      flux<<*it<<" ";
    }
  flux << ")";
  return flux;
}

list<int> liste(list<int> li)
{
    return li;
}

template<typename T> int taille(vector<T> ta)
{
    return ta.size();
}

vector<int> tableau(vector<int> tab)
{
    return tab;
}


template<typename T> ostream& operator << (ostream& flux, vector<T> l)
{
    flux << "[ ";
    for (auto it=l.begin(); it !=l.end(); ++it )
    {
        flux<<*it<<" ";
    }
    flux << "]";
    return flux;
}

void ecrPoly(vector<int> po)
{
    bool prem;
    prem=true;
    for (size_t i=po.size()-1; i>0; i--)
    {
        if (po[i]!=0)
        {
            if (prem)
            {
                prem = false;
                if (po[i]!=1)
                {
                    if (po[i]!=-1) cout << po[i];
                    else cout << "-";
                }
            }
            else
            {
                if (po[i]>0) cout << " + ";
                else cout << " - ";
                if (abs(po[i]) !=1) cout << abs(po[i]);
            }
            cout << " X";
            if (i>1) cout<<"^"<<i<<" ";
        }
    }
    if (prem) cout <<po[0];
    else
    {
        if (po[0]!=0)
        {
            if (po[0]>0) cout << " + ";
            else cout << " - ";
            cout << abs(po[0]);

        }
    }
    cout<< endl;
    return ;
}







// Fichier dans lequel vous écrirez les fonctions que l'on vous demandera de définir


// Fonction moyenne
// Données: a : nombre, b : nombre
// Résultat: Nombre, la moyenne de a et b
// à vous de compléter
float moyenne(float a,float b)
{
  return (a+b)/2;
}

// Fonction max3
float max3(float x,float y,float z)
{
  return x>y ? x>z ? x : z : y>z ? y : z;
}

// Fonction multiple
bool multiple (int x, int y)
{
  return y==0 ? (x==0? true : false) : x%y==0 ? true : false;
}

// Fonction equilaterale
bool equilaterale (float a,float b,float c)
{
  return a==b ? (a==c? true : false) : false;
}

//Fonction triangle
bool triangle (float a,float b, float c)
{
  return a<=b+c ? (b<=a+c ? (c<=a+b ? true : false) : false) : false;
}

//Fonction triangleRect
bool triangleRect (float a,float b,float c)
{
  return triangle(a,b,c) ? ((a==sqrt(b*b)+sqrt(c*c))||(b=sqrt(c*c)+sqrt(a*a))||(c==sqrt(b*b)+sqrt(a*a))? true : false) : false;
}

//Fonction triangleIso
bool triangleIso (float a, float b, float c)
{
  return triangle(a,b,c) ? ((a==b||b==c||a==c) ? true : false) : false;
}  

//Fonction OuExcl
bool OuExcl (bool a,bool b)
{
  return a ?(b ? false : true) : (b ? true : false);
}

//Fonction mul2ou3
bool mul2ou3 (float n)
{
  return multiple(n,2)||multiple(n,3) ? (multiple(n,6) ? false : true) : false;
}

//Fonction memeDizaine
bool memeDizaine (int a, int b)
{
  return a/10 == b/10;
}  
  
//Fonction memeParite
bool memeParite (int a,int b)
{
  return a%2==0 ? (b%2==0 ? true : false) : (b%2==0 ? false : true) ;
}

//Roulette
int Roulette(int mise, int numJoue, int numSorti)
{
  return numJoue == numSorti ? 20*mise :(memeDizaine(numJoue, numSorti) ? 5*mise : (memeParite(numJoue, numSorti) ? 2*mise : 0 )) ;
}

//estPair
bool estPair(int n)
{
  return n==0? true : n<0 ? !estPair(n+1) : !estPair(n-1) ;
}

//existeMul11
bool existeMul11(int a, int b)
{
  return a>b ? false : (multiple(a, 11) ? true : multiple(a+1, 11)) ;
}

//maxMul11
int maxMul11(int a, int b)
{
  return b<a ? -1 : multiple(b,11) ? b : maxMul11(a,b-1);
}  

//nbMul11
int nbMul11(int a, int b)
{
  return a>b ? 0 : multiple(a,11) ? 1+(nbMul11(a+1, b)) : nbMul11(a+1, b) ;
}

//somMul11
int somMul11(int a, int b)
{
  return a>b ? 0 : multiple(a,11) ? a+(somMul11(a+1,b)) : (somMul11(a+1,b));
}

//nbChifDec
int nbChifDec(int a)
{
  return a<10 ? 1 :1+nbChifDec(a/10);
}

//Chifrang
int Chifrang(int n, int k)
{
  return n==0 ? 0 : k==1 ? n%10 : Chifrang(n/10, k-1);
}

//somChif
int somChif (int a)
{
  return a==0 ? 0 : (a%10)+somChif(a/10);
}

//Racnum
int Racnum (int a)
{
  return a<10 ? a  : Racnum(somChif(a));
}

//invChif
int invChif(int n)
{
  return n<10 ? n : (n%10)*pow(10,nbChifDec(n)-1)+invChif(n/10);
}


//2ème feuille

//mystere
int mystere(int n)
{
  int v;
  v=53+n;
  v=2*v;
  v=v-99;
  v=v/2-n;
  return v;
}

//Nombreracine
int nbracines(float a,float b, float c)
{
  int discr=b*b-4*a*c;
  int nbr=1;
    
  if (a==0)
        nbr=1;
    if(discr<0)
    {
      nbr=1;
    }  
    else
      if (discr==0)
	{
	  nbr=1;
	}
     else nbr=2;
  return nbr;
}

//racine
list<float> racine(float a,float b, float c)
{
  list<float>li=list<float>();
  if (nbracines(a,b,c)==1)
    {
      li=cons(-b/2*a,li);
    }
  else
    {
      li=cons((-b-sqrt(b*b-4*a*b))/(2*a),li);
      li=cons((-b+sqrt(b*b-4*a*c))/2*a,li);
    }
  return li;
}

//sompair
int sompair (int n)
{
  int a=0;
  for(int i=0; i<=n; i=i+2)
    a=a+i;
  return a;
}
		    
//somimpair
int somimpair (int n)
{
  int a=0;
  for(int i=1; i<=n; i=i+2)
    a=a+i;
  return a;
} 

//somdiv
int somdiv (int n)
{
  int som=0;
  for(int i=1;i<=n;i++)
    if(n%i==0)
      som=som+i;
  return som;
}


//estparfait
bool estparfait (int n)
{
  bool sol;
  if (somdiv(n)==2*n)
    sol= true;
    else
      sol=false;
	return sol;
}

//existeparf
bool existeparf (int a,int b)
{
  int sol;
  int rep;
  for(int i=a; i<=b; i++)
    if (estparfait(i))
      {
	    sol=sol+1;
      }
  if (sol>0)
    rep=true;
  return rep;
}

//parfaitSuiv
int parfaitSuiv (int n)
{
  while(!estparfait(n))
   n=n+1;
  return n;
}

//emeparfait
int emeparfait (int n)
{
  int solu=0;
  int t=0;
  while (t<=n)
    if (estparfait(solu))
    {
    solu=solu+1;
      t=t+1;
    }
  else
  solu=solu+1;
  return solu;
}


//sontamis
bool sontamis (int a,int b)
{
  return (somdiv(a)==(a+b) && somdiv(b)==(a+b));
}

//aUnamis
bool aunamis (int n)
{
  bool ahbon;
    if (sontamis(somdiv(n)-n,n))
      ahbon=true;
     else
      ahbon=false;
  return ahbon;
}


//liAmicaux
list<int> liAmicaux(int n)
{
  int cpt=0;
  list<int>chelsea=liVide<int>();
    while (cpt<=n)
    {
     cpt=cpt+1;
     if (aunamis(cpt))
        chelsea=cons(cpt,chelsea);
        }
  return chelsea;
}

//liAmis
list<list<int>> liAmis (int n)
{
  list <int> liste=liVide<int>();
  list<list<int>> grande=liVide<list<int>>();
  for(int i=0;i<=n;i++)
    if (aunamis(i))
    {
      liste=cons(i,liste);
      liste=cons(somdiv(i)-i,liste);
      grande=cons(liste,grande);
      liste=liVide<int>();
    }  
  return (grande);
}


//liCouples1
list<list<int>> liCouples1 (int n)
{
  list<list<int>>grande=liVide<list<int>>();
  list<int>petites=liVide<int>();
  for(int i=1;i<n;i++)
  {
  petites=cons(n-i,petites);
  petites=cons(i,petites);
  grande=cons(petites,grande);
  petites=liVide<int>();
  }
  return grande;
}

//liCouples2
list<list<int>> liCouples2 (int n)
{
  list<list<int>>grande=liVide<list<int>>();
  list<int>petites=liVide<int>();
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=n;j++)
      {
      
        petites=cons(j,petites);
        petites=cons(i,petites);
        grande=cons(petites,grande);
        petites=liVide<int>();
      }
    }
  return grande;
}


//liCouples3
list<list<int>> liCouples3 (int n)
{
list<list<int>>grande=liVide<list<int>>();
list<int>petites=liVide<int>();
  for(int j=1;j<n;j++)
  {
    for(int i=j;i<=n;i++)
    {
      if(j==i)
        {
        }
      else
        {
      petites=cons(j,petites);
      petites=cons(i,petites);
      grande=cons(petites,grande);
      petites=liVide<int>();
        }
    }
  }
  return grande;
}

//liCouples4
list<list<int>> liCouples4 (int n)
{
list<list<int>>grande=liVide<list<int>>();
list<int>petites=liVide<int>();
  for(int j=1;j<n;j++)
  {
    for(int i=j+1;i<=n;i++)
      {
        if((i%j==0))
          {
          petites=cons(j,petites);
          petites=cons(i,petites);
          grande=cons(petites,grande);
          petites=liVide<int>();
          }
      }
  }
return grande;
}

//liCouples5
list<list<int>> liCouples5 (int n)
{
list<list<int>>grande=liVide<list<int>>();
list<int>petites=liVide<int>();
int j=n;
  for(int i=1;i<=n;i++)
  
    {
      j=n;
      while(j%i!=0)
        {
          j--;
        }
      petites=cons(j,petites);
      petites=cons(i,petites);
      grande=cons(petites,grande);
      petites=liVide<int>();
    }
return grande;
}

//dansCercle
bool dansCercle (float x, float y)
{
bool rep=true;
if(sqrt(((x*x))+(y*y))<=1)
rep=true;
else
rep=false;
return rep;
}

//monteCarlo
float monteCarlo(int nTir)
{
float x; 
float y;
int nInt=0;
  for(int i=1;i<=nTir;i++)
    {
      x=(float) rand()/ RAND_MAX;
      y=(float) rand()/ RAND_MAX;
    if(dansCercle(x,y))
      {
        nInt++;
      }
    }
return 4 * (float) nInt / nTir;
}


//somtabl
int somTab(vector<int> T)
{
int som;
  for(int i=0;i<taille(T);i++)
  som=som+T.at(i);
return som;
}

//tabEgaux
bool tabEgaux(vector<int> t1, vector<int> t2)
{
bool rep=true;
int i=0;
  if(taille(t1)==taille(t2))
  {
    for(int i=0; i<taille(t1); i++)
      if(t1.at(i)==t2.at(i))
        rep=true;
      else
        rep=false;
        
  }
  else
  rep=false;
  
return rep;
}





// Fichier dans lequel vous écrirez les expressions à évaluer

#define EVAL(exp) cout << "Valeur de " << (#exp) <<" : "<< (exp) << endl


int main()
{
  srand(time(NULL));
  boolalpha(cout);

  cout << "\n=================================================================\n ";

  // Expressions à évaluer
  cout << "\n==== Prise en main =======\n";
  // commande pour évaluer l'expression 3+4
  EVAL( 3+4 );
  // A vous :
  EVAL(true || false);
  EVAL(3*3 );
  EVAL( abs(2) );
  //EVAL(2/(1-1));
  EVAL(8/2);
  EVAL(9/2);
  EVAL(8%4);
  EVAL(9%4);
  EVAL(8.5+1);
  EVAL(8.2/4.1);
  EVAL(8.2/2);
  EVAL((10.5+8+11.25)/3);
  EVAL(pow(3,2));
  EVAL(sqrt(25));
  EVAL(sqrt(pow(12.3,2)));
  EVAL(true);
  EVAL(2>3);
  EVAL(!(2>3));
  EVAL((2>3)&&true);
  EVAL((2>3)||true);
  //EVAL( ((2/0)>1)||true);
  EVAL(true||(2/0)>1);
  EVAL(2>3?5:7);
  EVAL(sqrt(2)>1.4?5:7);
  EVAL(moyenne(2.3,8));
  //EVAL(moyenne(2.3,8,7.7));
  EVAL(moyenne(11.4,8.5)>10?1:2);
  EVAL(max3(3,9,2.5));
  EVAL(multiple(2,0));
  EVAL(multiple(0,2));
  EVAL(multiple(0,0));
  EVAL(equilaterale(3,3,4));
  EVAL(equilaterale(15,15,15));
  EVAL(triangle(2,3,4));
  EVAL(triangle(19,2,2));
  EVAL(triangleRect(4,5,6));
  EVAL(triangleRect(12,96,1000934));
  EVAL(triangleIso(15,256654,14.2));
  EVAL(triangleIso(12,12,13));
  EVAL(triangleIso(12,12,12));
  EVAL(mul2ou3(9));
  EVAL(mul2ou3(12));
  EVAL(mul2ou3(23465466));
  EVAL(memeParite(4,17));
  EVAL(memeParite(6,18));
  EVAL(Roulette(100, 122, 125));
  EVAL(estPair(-344));
  EVAL(existeMul11(22,22));
  EVAL(existeMul11(22,2));
  EVAL(maxMul11(3,4));
  EVAL(nbMul11(3,4));
  EVAL(somMul11(3,4));
  EVAL(nbChifDec(34643));
  EVAL(Chifrang(335,2));
  EVAL(somChif(3249));
  EVAL(Racnum(3249));
  EVAL(invChif(3249));
  EVAL(mystere(23));
  EVAL(mystere(39));
  EVAL(nbracines(0.3,1,-3.5));
  EVAL(racine(1,43,5634));
  EVAL(sompair(5));
  EVAL(somimpair(5));
  EVAL(somdiv(6));
  EVAL(estparfait(6));
  EVAL(existeparf(1, 30));
  EVAL(parfaitSuiv(7));
  EVAL(emeparfait(2));
  EVAL(sontamis(220,284));
  EVAL(liAmicaux(10000));
  EVAL(liAmis(10000));
  EVAL(liCouples1(6));
  EVAL(liCouples2(3));
  EVAL(liCouples3(3));
  EVAL(liCouples4(6));
  EVAL(liCouples5(8));
  EVAL((float) rand()/ RAND_MAX);
  EVAL((float) rand()/ RAND_MAX);
  EVAL((float) rand()/ RAND_MAX);
  EVAL((dansCercle(0.0,0.1)));
  EVAL((monteCarlo(100000)));
  vector<int> ta (3); ta.at(0) = 1; ta.at(1) = 2; ta.at(2) = 6;
  EVAL( somTab(ta) );
  EVAL( somTab(tableau({3,1,7,2,1})) );
  EVAL( tabEgaux(ta, tableau({1,2,6})) );
  EVAL( tabEgaux(ta, tableau({1,10, 9})) );
  EVAL( tabEgaux(ta, tableau({1,10})) );


 
  cout << "\n=================================================================\n ";
  return 0;
}



  
