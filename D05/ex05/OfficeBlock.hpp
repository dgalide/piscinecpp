#ifndef OFFICEBLOCK_HPP
 #define OFFICEBLOCK_HPP

#include "Intern.hpp"

class OfficeBlock {

    public:

        class TeamNotComplete: public std::exception {
        
            public:
                TeamNotComplete(void);
                TeamNotComplete(TeamNotComplete const &ref);
                TeamNotComplete &operator=(TeamNotComplete const &ref);
                virtual ~TeamNotComplete(void) throw();
                virtual const char* what() const throw();
         };

        OfficeBlock(void);
        OfficeBlock(Intern *Intern, Bureaucrat *signingB, Bureaucrat *executingB);
        ~OfficeBlock(void);

        void        doBureaucracy(std::string formName, std::string target);

        void        setIntern(Intern *intern);
        void        setSigningBureaucrat(Bureaucrat *b);
        void        setExecutingBureaucrat(Bureaucrat *b);
        bool        isTeamComplete(void) const;
        bool        isSigningMissing(void) const;
        bool        isExecMissing(void) const;
        bool        isInternMissing(void) const;

    private:
        OfficeBlock(OfficeBlock &ref);
        OfficeBlock &operator=(OfficeBlock &ref);

        Intern          *intern;
        Bureaucrat      *signingBureaucrat;
        Bureaucrat      *executingBureaucrat;
        
};

#endif