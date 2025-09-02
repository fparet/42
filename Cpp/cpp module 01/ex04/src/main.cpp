// ************************************************************************** //
//                                                                            //
//                          Sed is for losers (ex04)                          //
//                          42 C++ Module 01 - C++98                          //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <fstream>
#include <string>

static void usage(const char* prog) {
    std::cerr << "Usage: " << prog << " <filename> <s1> <s2>" << std::endl;
}

// Replace all occurrences of s1 by s2 in 'input' without using regex.
static std::string replace_all(const std::string& input, const std::string& s1, const std::string& s2) {
    if (s1.empty())
        return input; // guard, actual check is in main (we treat empty s1 as error)
    std::string out;
    out.reserve(input.size());
    std::string::size_type pos = 0;
    const std::string::size_type n1 = s1.size();
    while (true) {
        std::string::size_type idx = input.find(s1, pos);
        if (idx == std::string::npos) {
            out.append(input, pos, std::string::npos);
            break;
        }
        out.append(input, pos, idx - pos);
        out.append(s2);
        pos = idx + n1;
    }
    return out;
}

static int replace_file(const std::string& filename, const std::string& s1, const std::string& s2) {
    std::ifstream in(filename.c_str());
    if (!in) {
        std::cerr << "Error: cannot open input file: " << filename << std::endl;
        return 1;
    }
    std::string content;
    std::string line;
    while (std::getline(in, line)) {
        content += line;
        if (!in.eof())
            content += '\n';
    }
    in.close();

    std::string replaced = replace_all(content, s1, s2);

    std::string outname = filename + ".replace";
    std::ofstream out(outname.c_str());
    if (!out) {
        std::cerr << "Error: cannot open output file: " << outname << std::endl;
        return 1;
    }
    out << replaced;
    out.close();
    return 0;
}

int main(int argc, char** argv) {
    if (argc != 4) {
        usage(argv[0]);
        return 1;
    }
    const std::string filename = argv[1];
    const std::string s1 = argv[2];
    const std::string s2 = argv[3];

    if (s1.empty()) {
        std::cerr << "Error: s1 must not be empty." << std::endl;
        return 1;
    }
    return replace_file(filename, s1, s2);
}
