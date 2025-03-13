#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: touch <filename>\n";
        return 1;
    }

    ofstream file(argv[1], ios::app);
    if (!file) {
        cerr << "Error: Cannot create file '" << argv[1] << "'\n";
        return 1;
    }
    
    file.close();
    cout << "Created file: " << argv[1] << "\n";
    return 0;
}
