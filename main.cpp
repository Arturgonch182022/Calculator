#include "defoult.h"
#include "scientific.h"
#include "programmer.h"
#include "sorting.h"
#include "Date_Calculation.h"
#include<iomanip>

using std::cin;
using std::cout;
std::map<std::string, void(*)()> selects{ {"Date_Calculation",Date_Calculation},{"defoult",defoult},{"scientific",scientific},{"programmer",programmer},{"sorting",sorting}};

// Ctrl + Alt + A -- add file to commit

int main() {
        while (1) {
        	cout << "Choose the mode: Standart/Programmer/Scientific/Date Calculation/Sorting/Exit\n";
        	std::string s;
        	cin >> s;
            if (s=="Exit") { return 0;}
        	if (selects.count(s)) {
        		selects[s]();
        	}
        	else {
        		cout << "Wrong mode\n";
        	}
        }
}