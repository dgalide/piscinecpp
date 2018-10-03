#ifndef LOGGER_HPP
 #define LOGGER_HPP

#include <iostream>
#include <fstream>
#include <ctime>

class Logger {

public:
	Logger(std::string filename);
	~Logger(void);

	void 			log(std::string const & dest, std::string const & message);

private:

	// Method
	void 			logToConsole(std::string);
	void 			logToFile(std::string);
	std::string		formatLogDate(void);
	std::string 	makeLogEntry(std::string);

	// Property
	std::string		filename;
};

#endif