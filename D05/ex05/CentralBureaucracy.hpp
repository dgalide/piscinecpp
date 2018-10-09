#ifndef CENTRALBUREAUCRACY_HPP
 #define CENTRALBUREAUCRACY_HPP

#include "OfficeBlock.hpp"

#define MAX_OFFICES 20
#define MAX_QUEUE 1080

typedef struct          s_task {
    std::string         typeform;
    std::string         target;
}                       t_task;

class CentralBureaucracy {

    public:

        class MaxQueue: public std::exception {
        
            public:
                MaxQueue(void);
                MaxQueue(MaxQueue const &ref);
                MaxQueue &operator=(MaxQueue const &ref);
                virtual ~MaxQueue(void) throw();
                virtual const char* what() const throw();
        };

        class MaxBureaucrat: public std::exception {
        
            public:
                MaxBureaucrat(void);
                MaxBureaucrat(MaxBureaucrat const &ref);
                MaxBureaucrat &operator=(MaxBureaucrat const &ref);
                virtual ~MaxBureaucrat(void) throw();
                virtual const char* what() const throw();
        };

        class NoFullTeamToWork: public std::exception {
        
            public:
                NoFullTeamToWork(void);
                NoFullTeamToWork(NoFullTeamToWork const &ref);
                NoFullTeamToWork &operator=(NoFullTeamToWork const &ref);
                virtual ~NoFullTeamToWork(void) throw();
                virtual const char* what() const throw();
        };

        CentralBureaucracy(void);
        ~CentralBureaucracy(void);

        void                feedSome(Bureaucrat *b);
        void                queueUp(std::string typeForm, std::string target);
        bool                isQueueMax(void);
        bool                isBureaucratMax(void);
        void                doBureaucracy(void);
        t_task              *isQueueEmpty(void);
        OfficeBlock         *getRandomOfficeBlock(void);
        void                removeTask(t_task *task);

    private:

        // Avoid Assignation && = operator
        CentralBureaucracy(CentralBureaucracy &ref);
        CentralBureaucracy      &operator=(CentralBureaucracy &ref);

        // Pre-Define, can't use Vector and lazy to make linked-chain
        OfficeBlock             *blocks[MAX_OFFICES];
        t_task                  *queue[MAX_QUEUE];
};

#endif