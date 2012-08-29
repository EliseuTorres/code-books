/** @copyright (C) Andre Duarte Bueno @file List-D-4-switch.cpp */

#include <vector>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
  vector <string> time;

  time.push_back (string ("Palmeiras"));
  time.push_back (string ("Corintians"));
  time.push_back (string ("S�o Paulo"));
  time.push_back (string ("Santos"));

  cout << "Para encerrar, digite o caractere de fim de arquivo." << endl
       << "No Windows/DOS (ctrl+z) no GNU/Linux, Unix (ctrl+d):\n" << endl
       << "--> Qual o seu time do cora��o <--:" << endl;
  for (int i = 0; i < time.size(); i++)
    cout << setw(20) << time[i] << " (" << setw(2) << i << ") :" << endl;

  int resp;
  while (cin >> resp)
    {
      cin.get();
      string osite ("O site de seu time est� em: ");
      
      switch (resp)
	{
	case 0:
	  cout << "Parab�ns, voc� escolheu um tetracampe�o Brasileiro." <<  endl;
	  cout << osite << "http://www.palmeiras.com.br/" << endl;
	  break;

	case 1:
	  cout << "Parab�ns, voc� escolheu um tricampe�o Brasileiro." << endl;
	  cout << osite << "http://www.corinthians.com.br/" << endl;
	  break;

	case 2:
	  cout << "Parab�ns, voc� escolheu um tricampe�o Brasileiro" << endl;
	  cout << osite << "http://www.spfc.com.br/" << endl;
	  break;

	case 3:
	  cout << "Parab�ns, voc� escolheu um campe�o Brasileiro." << endl;
	  cout << osite << "http://www.santosfutebolclube.com.br/" << endl;
	  break;

	default:
	  cout << "Entrou na op��o default do switch, ou seja, voc� entrou "
	       << "com uma op��o errada, repita a opera��o." << endl;
	  break;		// Break opcional
	}
    }

  return 0;
}
