#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>

std::vector<std::string> readFile(std::ifstream& instr);
void remove_repeats(std::vector<std::string>& obj);

int main(int argc, char* argv[]){
    std::ifstream fin("text.txt");
    if (!fin.is_open()){
        std::cout << "Error\n";
        return 0;
    }
    auto str = readFile(fin);
    remove_repeats(str);
    for (auto i: str){
        std::cout << i << ' ';
    }
    std::cout << std::endl;
    fin.close();
    return 0;
}

std::vector<std::string> readFile(std::ifstream& instr){
    std::vector<std::string> res;
    std::string buff;
    while (instr >> buff)
        res.push_back(buff);
    return res;
}

void remove_repeats(std::vector<std::string>& obj){
    for (int i = 0; i < obj.size() - 1; ++i)
        if (obj[i] == obj[i + 1])
            i = obj.erase(obj.begin() + i) - obj.begin();
}
