#include <iostream>
#include <list>
using namespace std;

int main()
{
	list<const char*> yamanoteLine;

	yamanoteLine.push_back("Tokyo Station");
	yamanoteLine.push_back("Kanda Station");
	yamanoteLine.push_back("Akibahara Station");
	yamanoteLine.push_back("Okatimati Station");
	yamanoteLine.push_back("Ueno Station");
	yamanoteLine.push_back("Uguizudani Station");
	yamanoteLine.push_back("Nippori Station");
	yamanoteLine.push_back("Tabata Station");
	yamanoteLine.push_back("Komagoe Station");
	yamanoteLine.push_back("Sugamo Station");
	yamanoteLine.push_back("Ootuka Station");
	yamanoteLine.push_back("Ikebukuro Station");
	yamanoteLine.push_back("Mejiro Station");
	yamanoteLine.push_back("Takadanobaba Station");
	yamanoteLine.push_back("Sinookubo Station");
	yamanoteLine.push_back("Sinjyuku Station");
	yamanoteLine.push_back("Yoyogi Station");
	yamanoteLine.push_back("Harajyuku Station");
	yamanoteLine.push_back("Sibuya Station");
	yamanoteLine.push_back("Ebisu Station");
	yamanoteLine.push_back("Meguro Station");
	yamanoteLine.push_back("Gotanda Station");
	yamanoteLine.push_back("Oosaki Station");
	yamanoteLine.push_back("Sinagawa Station");
	yamanoteLine.push_back("Tamati Station");
	yamanoteLine.push_back("Hamamatutyou Station");
	yamanoteLine.push_back("Sinnbasi Station");
	yamanoteLine.push_back("Yuurakutyou Station");

	// �o��
	cout << "1970�N�R����w�ꗗ" << endl;
	for (const char* temp : yamanoteLine)
	{
		cout << temp << endl;
	}

	// �v�f��}��
	decltype(yamanoteLine)::iterator it = next(yamanoteLine.begin(), 7);
	yamanoteLine.insert(it, "NisiNippori Station");

	// �o��
	cout << "\n2019�N�R����w�ꗗ" << endl;
	for (const char* temp : yamanoteLine)
	{
		cout << temp << endl;
	}

	// �v�f��}��
	it = next(yamanoteLine.begin(), 26);
	yamanoteLine.insert(it, "TakanawaGateway Station");

	// �o��
	cout << "\n2020�N�R����w�ꗗ" << endl;
	for (const char* temp : yamanoteLine)
	{
		cout << temp << endl;
	}

	return 0;
}