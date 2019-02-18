#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void remove_spaces(string& str){
    for (int i = 0; i < str.length(); ++i){
        if (str[i] != ' ')
            continue;
        else {
            int start_pos = i;
            int cnt = 0;
            for (; str[i] == ' ' && i < str.length(); ++i, ++cnt);
            str.erase(start_pos, cnt - 1);
            i = start_pos;
        }
    }
}

int main(){
    string ipath;
    string opath;
    cout << "Enter the path to the input file: ";
    getline(cin, ipath);
    ifstream fin(ipath);
    if (!fin.is_open()){
        cout << "Cannot open the file\n";
        return 0;
    }
    cout << "Enter the path to the output file: ";
    getline(cin, opath);
    ofstream fout(opath);
    if (!fout.is_open()){
        cout << "Cannot open the file\n";
        return 0;
    }
    string buf;
    while (!fin.eof()){
        getline(fin, buf);
        if (buf.empty())
            continue;
        remove_spaces(buf);
        fout << buf << '\n';
    }
    cout << "Done\n";
    return 0;
}
