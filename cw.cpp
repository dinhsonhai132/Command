#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void create_and_write_file(const string& file_name, const string& content, bool append = false) {
    ofstream file(file_name, append ? ios::app : ios::out);
    if (!file) {
        cerr << "Error: Could not create/open file " << file_name << '\n';
        return;
    }
    file << content << '\n';
    cout << "File '" << file_name << "' has been " << (append ? "appended" : "written") << " successfully.\n";
}

void read_file(const string& file_name) {
    ifstream file(file_name);
    if (!file) {
        cerr << "Error: Could not open file " << file_name << '\n';
        return;
    }

    string line;
    bool is_empty = true;
    while (getline(file, line)) {
        cout << line << '\n';
        is_empty = false;
    }

    if (is_empty) {
        cout << "The file is empty.\n";
    }
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        cerr << "Usage:\n"
             << "  " << argv[0] << " <file_name> <content>\n"
             << "  " << argv[0] << " <file_name> -r\n"
             << "  " << argv[0] << " <file_name> -a <content>\n";
        return 1;
    }

    string file_name = argv[1];
    string op = argv[2];

    if (op == "-r") {
        read_file(file_name);
    } else if (op == "-a" && argc > 3) {
        string content;
        for (int i = 3; i < argc; ++i) {
            if (i > 3) content += " ";
            content += argv[i];
        }
        create_and_write_file(file_name, content, true);
    } else {
        string content;
        for (int i = 2; i < argc; ++i) {
            if (i > 2) content += " ";
            content += argv[i];
        }
        create_and_write_file(file_name, content, false);
    }

    return 0;
}
