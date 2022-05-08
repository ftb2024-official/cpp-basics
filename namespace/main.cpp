#include <iostream>
#include "foo.h"
#include "bar.h"

using namespace std;

namespace fbb = foo::bar::baz;

int main() {
	cout << fbb::doSmth(4, 5) << endl;
	cout << bar::doSmth(4, 5) << endl;

	return 0;
}