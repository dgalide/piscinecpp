#include "Logger.hpp"

typedef void (Logger::*t_loggerFunctions)(std::string logEntry);

Logger::Logger(std::string filename): filename(filename) {}

Logger::~Logger(void) {}

std::string 		Logger::formatLogDate(void) {
    time_t 			rawtime;
  	struct tm 		*timeinfo;

  	char *buffer = new char [20];

  	time (&rawtime);
  	timeinfo = localtime (&rawtime);

  	strftime (buffer,80,"[%Y_%m_%d_%H%M]",timeinfo);

  	return std::string(buffer);
}

std::string			Logger::makeLogEntry(std::string entry) {
    if (!entry.empty()) {
		return this->formatLogDate().append(entry) + "\n";
	} else {
		return NULL;
	}
}

void				Logger::log(std::string const & dest, std::string const & message) {

	if (!dest.empty() && !message.empty()) {
		t_loggerFunctions	logFuncs[2] = {&Logger::logToConsole, &Logger::logToFile};
		std::string			funcName[2] = {"console", "file"};

		for (int i = 0; i < 2; i++) {
			if (dest == funcName[i]) {
				(*this.*logFuncs[i])(message);
			}
		}
	};
}

void				Logger::logToConsole(std::string logEntry) {
	std::cout << this->makeLogEntry(logEntry);
}

void 				Logger::logToFile(std::string logEntry) {

	std::ofstream 	myfile;

	myfile.open (this->filename, std::ios::app | std::ios::out);
	if (myfile.is_open()) {
	  	myfile << this->makeLogEntry(logEntry);
	  	myfile.close();
  	} else {
  		std::cout << "Something went wrong at the opening" << std::endl;
  	}
}