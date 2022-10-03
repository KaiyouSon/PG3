#include <iostream>
using namespace std;

template<typename T>
T Min(T a, T b)
{
	if (typeid(T) == typeid(char))
	{
		cout << "”Žš‚Í‘ã“ü‚Å‚«‚Ü‚¹‚ñ" << endl;
		return 0;
	}
	else
	{
		return static_cast<T>(a < b ? a : b);
	}
}

int main()
{
	int ai = 4, bi = 1;
	float af = 2.4, bf = 0.37;
	double ad = 2.553, bd = 3.7678;
	char ac = 'ac', bc = 'bc';

	Min<int>(ai, bi);
	Min<float>(af, bf);
	Min<double>(ad, bd);
	Min<char>(ac, bc);

	return 0;
}