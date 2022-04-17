#include "System.h"

System::System() {
	int n;
	cout << "enter 1";
	cin >> n;
	if (n == 1) {
		Showroom s;
		sysRoom.push_back(s);
	}
}