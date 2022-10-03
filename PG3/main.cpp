#include <iostream>
using namespace std;

template<typename T>
T Min(T a, T b)
{
	return static_cast<T>(a <= b ? a : b);
}

template<>
char Min(char a, char b)
{
	cout << "”ŽšˆÈŠO‚Í‘ã“ü‚Å‚«‚Ü‚¹‚ñ" << endl;
	return -1;
}

int main()
{
	int ai = 4, bi = 1;
	float af = 2.4, bf = 0.37;
	double ad = 2.553, bd = 3.7678;
	char ac = 'ac', bc = 'bc';

	cout << Min<int>(ai, bi) << endl;
	cout << Min<float>(af, bf) << endl;
	cout << Min<double>(ad, bd) << endl;
	Min<char>(ac, bc);

	return 0;
}