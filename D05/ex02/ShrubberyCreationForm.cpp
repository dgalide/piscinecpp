#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
Form("ShrubberyCreationForm", 145, 137, target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &ref):
Form(ref.getName(), ref.getSignGrade(), ref.getExecGrade(), ref.getTarget())
{}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

void            ShrubberyCreationForm::action(void) {
    std::ofstream 	myfile;

	myfile.open (this->getTarget() + "_shrubbery", std::ios::app | std::ios::out);
	if (myfile.is_open()) {
	  	myfile << "  __" << std::endl;
        myfile << "_/  |________   ____   ____ " << std::endl;
        myfile << "\\   __\\_  __ \\_/ __ \\_/ __ \\ " << std::endl;
        myfile << " |  |  |  | \\/\\  ___/\\  ___/\\/ " << std::endl;
        myfile << " |__|  |__|    \\___  >\\___  >" << std::endl;
        myfile << "                   \\/     \\/ " << std::endl;
	  	myfile.close();
  	} else {
  		std::cout << "Something went wrong at the opening" << std::endl;
  	}
}