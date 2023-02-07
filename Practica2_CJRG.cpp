#include <iostream>

using namespace std;

class Mamifero{
	protected:
		int Ano_Nac;
		string Lugar_Nac;
		string Dieta;
	public:
		Mamifero(int A,string L,string D){
			Ano_Nac = A;
			Lugar_Nac = L;
			Dieta = D;
		}
		void Imprimedatos_Nac(){
			cout << "Fecha de Nacimiento: " << Ano_Nac << endl;
			cout << "Lugar de Nacimiento: " << Lugar_Nac << endl;
		}
};


class Felino: public Mamifero{
	private:
		string Raza;
		string Nom_Circo;
	public:
		Felino(int A,string L,string D,string R, string N_C): Mamifero(A,L,D){
			Raza = R;
			Nom_Circo = N_C; 		
		}
		
		void imprime_dieta(){
			cout << "Dieta: " << Dieta << endl;
		}
		
		void imprime_Raza(){
			cout << "Raza: " << Raza << endl;
		}
		void Cambiar_Circo(){
			cout << "Ingrese el nuevo Circo del Felino: ";
			getline(cin,Nom_Circo);
		}	
};

class Gato_Domestico: public Felino{
	private:
		string Dueno;
	public:
		Gato_Domestico(int A,string L,string D,string R, string N_C,string Du): Felino(A,L,D,R,N_C){
			Dueno = Du;
		}
		
		void Cambiar_Dueno(){
			cout << "Ingrese el nuevo dueno del gato domestico: ";
			getline(cin,Dueno);
		}
		 
		Gato_Domestico operator + (Gato_Domestico S){
			Gato_Domestico Nuevo_Gato(0,"Nada","Nada","Nada","Nada","Nada");
			 Nuevo_Gato.Ano_Nac = Ano_Nac + S.Ano_Nac;
			 return Nuevo_Gato;
		}
				
		int operator != (Gato_Domestico D){
			int valor;
			if(D.Ano_Nac !=  Ano_Nac){
				valor = 1;
			}
			else{
				valor = 0;
			}
			return valor;	
		}
		
		int operator == (Gato_Domestico I){
			int valor;
			if(I.Ano_Nac ==  Ano_Nac){
				valor = 1;
			}
			else{
				valor = 0;
			}
			return valor;	
		}
		
		string operator > (Gato_Domestico M){
			string valor;
			if(M.Ano_Nac > Ano_Nac){
				valor = "El valor es mayor";
			}
			else{
				valor = "El valor es menor";
			}
			return valor;
		}
		
		string operator < (Gato_Domestico m){
			string valor;
			if(m.Ano_Nac < Ano_Nac){
				valor = "El valor es menor";
			}
			else{
				valor = "El valor es mayor";
			}
			return valor;
		}
		
		void ImprimeNac(){
			cout << "Fecha de Nacimiento: " << Ano_Nac << endl << endl;
		}				
};



int main(){
	Gato_Domestico Minino(2014,"GDL","Croquetas","Egipcia","Sin Circo","Danny");
	Felino EstrellaCirco(2022,"Tepic","Carne Humana","Pardo","Los hermanos garza");
	
	cout << "///////Datos del los animales//////"<< endl;
	cout << endl << "Minino" << endl;
	Minino.imprime_dieta();
	Minino.Imprimedatos_Nac();
	Minino.imprime_Raza();
	Minino.Cambiar_Dueno();	
	
	cout << endl << "Estrella de Circo" << endl;
	EstrellaCirco.imprime_dieta();
	EstrellaCirco.Imprimedatos_Nac();
	EstrellaCirco.imprime_Raza();	
	EstrellaCirco.Cambiar_Circo();
	cout << endl;
	
	cout << "/////Prueba sobrecarga de operadores/////" <<  endl << endl;
	
	cout << "Suma + " << endl;
	Gato_Domestico Resultadosuma(0,"Nada","Nada","Nada","Nada","Nada");
	int Resultado;
	string Resultado2;
	Gato_Domestico Prueba(2022,"Tepic","Carne Humana","Pardo","Los hermanos garza","Nada");
	Resultadosuma = Prueba + Minino;
	Resultadosuma.ImprimeNac();
	
	cout << "Diferencia != : 1 = Verdadero, 0 = Falso" << endl;
	Resultado = Prueba != Minino;
	cout << "Resultado: " << Resultado << endl;
	
	cout << "Comparacion == : 1 = Verdadero, 0 = Falso" << endl;
	Resultado = Prueba == Minino;
	cout << "Resultado: " << Resultado << endl << endl;
	
	cout << "Mayor que >" << endl;
	Resultado2 = Prueba > Minino;
	cout << "Resultado: " << Resultado2 << endl;
	
	cout << "Menor que <" << endl;
	Resultado2 = Prueba < Minino;
	cout << "Resultado: " << Resultado2 << endl;
	
	
	return 0;
}
