#include <iostream>
#include <fstream>

std::string readFile(std::string filename)
{
    std::string final;

    std::ifstream myReadFile;
        myReadFile.open(filename);
    char output[100];
    if (myReadFile.is_open())
    {
        while (!myReadFile.eof())
        {
            myReadFile  >> output;
            final += output;
            if (!myReadFile.eof())
                final += " ";
        }
        return final;
    }
    else
        std::cout << "Fail open" << std::endl;
    myReadFile.close();
    return NULL;
}

void findAndReplaceAll(std::string &buffer, std::string s1, std::string s2)
{
	// Get the first occurrence
	size_t pos = buffer.find(s1);
 
	// Repeat till end is reached
	while( pos != std::string::npos)
	{
		// Replace this occurrence of Sub String
		buffer.replace(pos, s1.size(), s2);
		// Get the next occurrence from the current position
		pos = buffer.find(s1, pos + s1.size());
	}
}

void writeTo(std::string fileName,std::string buff) {
	std::ofstream myfile;

	myfile.open ((fileName + ".replace"));
	if (myfile.is_open()) {
	  	myfile << buff;
	  	myfile.close();
  	} else {
  		std::cout << "Something went wrong at the opening" << std::endl;
  	}
}


int main(int ac, char **av) {

	if (ac != 4)
		return (0);

	std::string filename = std::string(av[1]);
	std::string s1 = std::string(av[2]);
	std::string s2 = std::string(av[3]);

	std::cout << "File Name :::" << filename << std::endl;
	std::cout << "S1 :::" << s1 << std::endl;
	std::cout << "S2 :::" << s2 << std::endl;

	std::string buff = readFile(filename);
	findAndReplaceAll(buff, s1, s2);
	std::cout << buff << std::endl;
	writeTo(filename, buff);


	return (0);
}