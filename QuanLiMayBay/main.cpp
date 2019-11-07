#include "QueryManager.h"
using namespace std;


int main()
{
	QueryManager manager;
	int val;
	while (true)
	{
		val = displaymenu();
		if (val == 15)
		{
			cout << "Exiting ...\n";
			break;
		}
		manager.query(val);
	}
	return 0;
}