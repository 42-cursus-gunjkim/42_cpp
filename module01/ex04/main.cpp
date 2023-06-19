#include <iostream>
#include <fstream>
#include <string>

std::string replaceAll(std::string &line, std::string &target, std::string &replace_str) {
    std::string result = line;
    size_t target_idx = 0;
    size_t pos = 0;

    if (target.empty())
        return result;

    while (1) {
        target_idx = result.find(target, pos);
        if (target_idx == std::string::npos)
            break;
        result.erase(target_idx, target.length());
        result.insert(target_idx, replace_str);
        pos = target_idx + replace_str.length();
    }
    return result;
}

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cerr << "ex04 needs 3 arguments..." << std::endl;
		return 0;
	}

	std::string infile = argv[1];
	std::string outfile = infile + ".replace";
	std::string target = argv[2];
	std::string replace_str = argv[3];

	std::ifstream reader;
	std::ofstream writer;

	reader.open(infile);
	if (reader.fail())
		return 0;
		
	writer.open(outfile);
	if (writer.fail()) {
		reader.close();
		return 0;
	}

	std::string line;
	std::string new_line;
	std::getline(reader, line);
	while (!reader.fail())
	{
		new_line = replaceAll(line, target, replace_str);
		writer << new_line << std::endl;
		std::getline(reader, line);
	}
	return 0;
}