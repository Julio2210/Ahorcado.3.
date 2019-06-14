#include <string>
#include <iostream>
using namespace std;

string linealetra(int palabratamano)
{
	int i = 0;
	string linea;
	while (i < palabratamano)
	{
		linea += "_";
		i++;
	}
	return linea;
}

bool checarletra(string palabra, char letra) {

	int palabratamano= (int)palabra.length();
	bool existe = false;
	int i = 0;

	while (i < palabratamano) {
		if (palabra[i] == letra) {
			existe = true;
		}
		i++;
	}

	return existe;
}
void cambiarLineaPorLetra(string linea, char letra, string palabra) {

	int i = 0;
	int tamanoLinea = (int)linea.length();

	while (i < tamanoLinea) {

		if (palabra[i] == letra) {
			linea[i] = letra;
		}

		i++;
	}
}
string obtenerLineaParaComparar(string& linea) {

	int i = 0;
	int tamanioLinea = (int)linea.length();
	string lineaComparar;

	while (i < tamanioLinea) {
		if (linea[i] != ' ') {
			lineaComparar += linea[i];
		}
		i++;
	}

	return lineaComparar;
}

string obtenerCadenaDeLineaParaMostrar(string& linea) {

	string lineaParaMostrar;
	int tamanioLinea = (int)linea.length();
	int i = 0;

	while (i < tamanioLinea) {

		lineaParaMostrar += linea[i];
		lineaParaMostrar += ' ';
		i++;
	}

	return lineaParaMostrar;
}
int main()
{
	cout << "Descubre la palabra secreta: ";
	string palabra = "algo-chido";
	string linea;
	char letra = '\0';
	bool existeletraenpalabra, juegocontinua = true;
	int vidas = 6;
	linea = linealetra((int)palabra.length());
	cout << "tienes " << vidas << " vidas restantes \n";
	
	while (juegocontinua)
	{
		if (vidas != 0)
		{
			string lineamostrar = obtenerCadenaDeLineaParaMostrar(linea);
			cout << lineamostrar << '\n';
			string linearevisar = obtenerLineaParaComparar(linea);

			if (linearevisar == palabra) {
				cout << "Ganaste prro \n";
				juegocontinua = false;
			}
			else {
				cout << "\n pon una letra:  ";
				cin.get(letra);
				cin.ignore();

			}
		}
		else {
			juegocontinua = false;
		}

		if (juegocontinua) {
			existeletraenpalabra = checarletra(palabra, letra);
			if (existeletraenpalabra) {

				cambiarLineaPorLetra(linea, letra, palabra);
			}
			else {
				vidas--;

				if (vidas == 0) {
					cout << "Perdiste prrooooouu \n";
				}
				else {
					cout << "\nIncorrecto\n";
					cout << "Te queda " << vidas << " vida(s)\n";
				}

			}
		}

	}

	return 0;
}

//solo me detecta los errores xD, asi que en cada error se pierde una vida.
//en cambio si se acierta una palabra no quita puntos, pero no te dice si esta bien o no :c 
//se hizo lo que se pudo con las herramientas que creia ocupar y que encontre en el interneist :v 