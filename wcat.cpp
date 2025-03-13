#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void cat(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error: Cannot open file '" << filename << "'\n";
        return;
    }

    string line;
    while (getline(file, line)) {
        cout << line << '\n';
    }

    file.close();
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: cat <filename>\n";
        return 1;
    }

    cat(argv[1]);
    return 0;
}
