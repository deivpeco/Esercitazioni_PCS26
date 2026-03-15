#include <iostream>
#include <fstream> 


using namespace std;

int main(int argc, const char *argv[]) {
	if (argc < 2) {
		cerr << "Errore: è necessario inserire il nome del file\n";
		return 1;
	}
	string nomefile = argv[1];
	ifstream ifs(nomefile);
	if (ifs.is_open()) {
		while ( !ifs.eof()) {
			string location;
			double temp1, temp2, temp3, temp4;
			ifs >> location >> temp1 >> temp2 >> temp3 >> temp4;
			if (location == "") {
				break;
			}
			double temp_av = (temp1 + temp2 + temp3 + temp4)/4;
			cout << location << " " << temp_av << "\n";
		}
	} else {
		cerr << "Errore: impossibile aprire il file " << nomefile << "\n";
		return 1;
	}
	return 0;
}
