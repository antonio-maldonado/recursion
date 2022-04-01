#include <iostream>
#include<time.h>
#include<string.h>
using namespace std;
//Antonio Maldonado
class Recursion{
private:
	int *nums;
	int n;
	int suma=0;
	string cadinv;
public:
	Recursion(int);
	~Recursion();
	long potencia(int,int);
	void imprimeLista();
	void imprimeListaRec();
	int SumaRec();
	string CadenaInvertida(string,int);
	int MCD(int,int);
};

int Recursion::MCD(int a,int b){
	if(a==0)
		return b;
	return MCD(b%a,a);
}

string Recursion::CadenaInvertida(string s,int a){
	if(a==0){
		a=0;
	}else{
		cadinv=cadinv+s.at(a-1);
		a--;
		CadenaInvertida(s,a);
	}
	return cadinv;
}

int Recursion::SumaRec(){
	if(n==-1)
	n=1;
	else{
		suma=suma+*(nums+n);
		n--;
		SumaRec();
	}
return suma;
}

void Recursion::imprimeListaRec(){
	if(n==0){
		n=-1;
	}else{
		n--;
		imprimeListaRec();
	    n++;
		cout<<*(nums+n)<<endl;
	}
}

void Recursion::imprimeLista(){
	for(int i=0;i<n;i++)
		cout<<*(nums+i)<<endl;
}

long Recursion::potencia(int n,int x){
	if(n==1)
		x=1;
	else
		n=n*potencia(n,x-1);
	return n;
}

Recursion::~Recursion(){
	cout<<"\nLiberando el arreglo"<<endl;
	delete []nums;
}

Recursion::Recursion(int nn=10){
	n=nn;
	srand(time(NULL));
	nums=new int(n);
	for(int i=0;i<n;i++)
		*(nums+i)=rand()%100+1;
}

int main(int argc, char *argv[]) {
	int n=10;
Recursion *r=new Recursion(n);
r->imprimeLista();
cout<<endl;
r->imprimeListaRec();
cout<<endl<<r->SumaRec();
string h;
cout<<"\nIngrese una frase: ";
getline(cin,h);
int a=h.size();
cout<<endl<<r->CadenaInvertida(h,a);
int x,y;
cout<<"\nIngrese dos numeros a calcular el MCD: ";
cin>>x>>y;
cout<<endl<<"MCD: "<<r->MCD(x,y);
delete r;
	return 0;
}

