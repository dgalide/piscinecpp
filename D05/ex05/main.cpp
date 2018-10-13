#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"
#include "CentralBureaucracy.hpp"

class Form;
class Bureaucrat;

int main(void)
{
        Bureaucrat              *b[120];
        CentralBureaucracy      cb;
        std::string     names[20] = {"Misha Antonio",
                                        "Jonell Neidert",
                                        "Cristi Guillory",
                                        "Brigid Welsh",
                                        "Veta Ottley",
                                        "Claudia Arzu",
                                        "Alix Brazan",
                                        "Lavelle Argento",
                                        "Levi Hinkle",
                                        "Junior Bhatia",
                                        "Ara Bumpus",
                                        "Beatrice Echavarria",
                                        "Demetrius Friedlander",
                                        "Pandora Hallinan",
                                        "Sammy Cromwell",
                                        "Etta Hastings",
                                        "Lizzie Vitela",
                                        "Meghann Shires",
                                        "Genna Miedema",
                                        "Henry Salvas"};
        
        std::string target[] = {"Brooks",
                    "Rachel","Edwards",
                    "Christopher","Perez",
                    "Thomas","Baker",
                    "Sara","Moore",
                    "Chris","Bailey",
                    "Roger","Johnson",
                    "Marilyn","Thompson",
                    "Anthony","Evans",
                    "Julie","Hall",
                    "Paula","Phillips",
                    "Annie","Hernandez",
                    "Dorothy","Murphy",
                    "Alice","Howard"};

        srand(time(nullptr));

        for (int i = 0; i < 100;i++) {

                b[i] = new Bureaucrat(names[rand() % 20], 1);

                try {
                        cb.feedSome(b[i]);
                } catch (CentralBureaucracy::MaxBureaucrat e) {
                        std::cout << e.what() << std::endl;
                } 
        }

        for (int j =0; j < 1200;j++) {

                try {
                        cb.queueUp("president", target[(rand() % 25)]);
                } catch (CentralBureaucracy::MaxQueue e) {
                         std::cout << e.what() << std::endl;
                }
        }

        try {
                cb.doBureaucracy();
        } catch (CentralBureaucracy::MaxQueue e) {
                std::cout << e.what() << std::endl;
        } catch (CentralBureaucracy::MaxBureaucrat e) {
                std::cout << e.what() << std::endl;
        } catch (CentralBureaucracy::NoFullTeamToWork e) {
                std::cout << e.what() << std::endl;
        } catch (Form::GradeTooLowException e) {
                std::cout << e.what() << std::endl;
        } catch (Form::GradeTooHighException e) {
                std::cout << e.what() << std::endl;
        } catch (Form::alreadySignedException e) {
                std::cout << e.what() << std::endl;
        } catch (std::exception e) {
                std::cout << e.what() << std::endl;
        }


        return 0;
}

