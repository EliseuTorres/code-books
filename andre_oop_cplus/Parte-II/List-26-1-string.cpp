/** @copyright (C) Andre Duarte Bueno @file List-26-1-string.cpp */

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main ()
{
  string s1;			// Cria string com nome s1
  s1 = "Oi, tudo bem";

  // Cria string com nome s2 e armazena " C++ � legal"
  string s2 (" C++ � legal");

  // Cria string com nome s3 e inicializa com " demais"
  string s3 = " demais";

  // Cria string com nome s4 uma c�pia de s3 (usa construtor de c�pia)
  string s4 (s3);

  // Cria string com nome s5 e define tamanho como sendo 100 caracteres
  string s5 = "eu tenho espa�o para 100 caracteres";

  s5.resize (100);
  cout << "Conte�do das strings:\ns1=" << s1 << "\ns2=" << s2 << "\ns3=" << s3 << "\ns4=" 
       << s4 << "\ns5=" << s5 << endl;

  // Tamanho, capacidade e tamanho m�ximo da string s5
  cout << "s5.size()=" << s5.size () << endl;
  cout << "s5.capacity()=" << s5.capacity () << endl;
  cout << "s5.max_size()=" << s5.max_size () << endl;

  // Cria a string s7 e preenche com o caractere 'a' 
  string s7 (10, 'a');

  cout << "s7.size()=" << s7.size () << " s7= " << s7 << endl;
  s7.resize (15, 't');
  cout << "Depois de s7.resize(15, 't');  s7.size()=" << s7.size ();
  cout << " s7.length()=" << s7.length () << " s7=" << s7  << endl;

  // Retorna true se estiver vazia 
  if (s7.empty ())
    cout << "A string s7 esta vazia" << endl;

  // C�pia de strings
  s1 = s2;
  cout << "Ap�s s1 = s2, s1=" << s1 << ", s2=" << s2 << endl;

  // Atribui��o de uma string de C
  s4 = "- profissional ";

  // Atribui��o de um �nico caractere
  s5 = '-';
  cout << "s4=" << s4 << "\t s5=" << s5 << endl;

  // Adicionar a string existente (concatenar)
  s5 += " Inclue a STL- e � ";
  cout << "s4=" << s4 << "\t s5=" << s5 << endl;

  // Adiciona ao final de s5, 6 caracteres de s3, a partir da posi��o 1 de s3.
  s5.append (s3, 1, 6);
  cout << "Ap�s s5.append (s3, 1, 6); s5=" << s5 << endl;

  // Cria uma c�pia de s2, adiciona s4, s5, e mostra na tela
  cout << "(s2 + s4 + s5)=" << (s2 + s4 +s5) << endl;

  // Troca o conte�do das strings s1 e s5
  s5.swap (s1);
  cout << "Ap�s  s5.swap (s1);" << endl;
  cout << "s1=" << s1 << "\ns5=" << s5 << "\nDo caracter s1[11] at� s1[14]=";
 
  // Acessa a posi��o i da string (como em vetores)
  for(int i = 11; i < 14; i++)
    cout << s1[i];
  cout << endl;

  // Coloca a letra P na posi��o 2
  s4[2] = 'P';
  cout << "Ap�s s4[2]= P , s4[2]=" << s4[2] <<" s4=" << s4 << endl;

  // O mesmo que s4[2], acessa posi��o 2 (verifica acesso)
  cout << "s4.at(2)=" << s4.at(2) << endl;

  // Cria uma string no padr�o C
  char cstring[256];

  // Copia a string s4 para cstring, usa fun��o strcpy do arquivo de cabe�alho  <cstring>
  strcpy (cstring, s4.c_str());
  cout << "cstring =" << cstring << endl;

  // Uso de replace e insert
  s5.replace (9, 1, "t");
  s4 = " para as outras linguagens";
  s3.insert (s3.end() , s4.begin (), s4.end ());
  cout << s5 << s3 << endl;

  s5 = " tem ";

  // Substitue caracteres de s1[17] at� s1[22] por s5
  s1.replace (s1.begin()+17, s1.begin()+22, s5.begin(), s5.end());
  cout << s1 + "- � multiplataforma"  << endl;

  // Adiciona  "programa��o gen�rica e "
  s1.insert (10, " programa��o gen�rica e ");
  cout << s1 << endl;

  // Cria uma substring de s1, a partir da posi��o 10 at� o final de s1
  cout << "s1.substr(10)=" << s1.substr(10) << endl;

  // Cria uma substring de s4, a partir da posi��o 3, 3 e 4
  cout << "s1.substr(10, 12)=" << s1.substr(10, 12) << endl;

  s1 = "cascavel/parana";	// s1[0]=c, s1[1]=a,..
  cout << "s1=" << s1 << endl;
  cout << "s1.find (\"ca\")= " << s1.find ("ca") << '\t';
  cout << "s1.find (\"ca\", 1)= " << s1.find ("ca", 1) << endl;
  cout << "s1.rfind (\"ca\")=  " << s1.rfind ("ca") << '\t';
  cout << "s1.rfind (\"ca\", 2)= " << s1.rfind ("ca", 2) << endl;

  // Procura a primeira ocorr�ncia de aeiou
  int i = s1.find_first_of ("aeiou");

  // Pr�xima n�o vogal
  int j = s1.find_first_not_of ("aeiou", i);
  cout << "find_first_of aeiou = " << i << "\nfind_first_not_of aeiou = " << j  <<endl;

  return 0;
}
