#include <iostream>
#include "QueuePriority.h"
using namespace std;
#include <string>

int main() {
	QueuePriority<string, int> q(20);
	q.Add("Low", 1);
	q.Add("High", 10);
	q.Add("Medium", 5);

	q.Print();

	while (!q.isEmpty()) {
		cout << "extract Item: " << q.Extract() << endl;
	}
}