#include "CentralBureaucracy.hpp"

/**
 * Central Burreaucracy
 */

CentralBureaucracy::CentralBureaucracy(void) {
    for (int i = 0; i < MAX_QUEUE; i++) {
        this->queue[i] = nullptr;
    }
    for (int i = 0; i < MAX_OFFICES; i++) {
        this->blocks[i] = new OfficeBlock();
    }
}

CentralBureaucracy::~CentralBureaucracy(void) {}

bool        CentralBureaucracy::isQueueMax(void) {

    for (int i = 0; i < MAX_QUEUE; i++) {
        if (!(this->queue[i])) {
            return false;
        }
    }
    return true;
}

bool        CentralBureaucracy::isBureaucratMax(void) {

    for (int i = 0; i < MAX_OFFICES; i++) {
        if (!(this->blocks[i]->isTeamComplete())) {
            return false;
        }
    }
    return true;
}

void          CentralBureaucracy::feedSome(Bureaucrat *b) {
    if (this->isBureaucratMax()) {
        throw CentralBureaucracy::MaxBureaucrat();
    }
    for (int i = 0; i < MAX_OFFICES; i++) {
        if (!(this->blocks[i]->isTeamComplete())) {
            if (this->blocks[i]->isExecMissing())
                this->blocks[i]->setExecutingBureaucrat(b);
            else if (this->blocks[i]->isSigningMissing())
                this->blocks[i]->setSigningBureaucrat(b);
            if (this->blocks[i]->isInternMissing()) {
                this->blocks[i]->setIntern(new Intern());
            }
            break;
        }
    }
}

void            CentralBureaucracy::queueUp(std::string typeForm, std::string target) {
    t_task      *t = new t_task;
    bool        added = false;

    t->target = target;
    t->typeform = typeForm;

    for (int i = 0; i < MAX_QUEUE; i++) {
        if (!(this->queue[i])) {
            this->queue[i] = t;
            added = true;
            break;
        }
    }

    if (!added)
        throw CentralBureaucracy::MaxQueue();
}

OfficeBlock     *CentralBureaucracy::getRandomOfficeBlock(void) {
    OfficeBlock *ob[MAX_OFFICES];
    int         nbFull = 0;
    srand(time(nullptr));

     for (int i = 0; i < MAX_OFFICES; i++) {
         if (this->blocks[i]->isTeamComplete()) {
             ob[nbFull++] = this->blocks[i];
         }
     }

    if (!nbFull)
        throw CentralBureaucracy::NoFullTeamToWork();

     return ob[(rand() % nbFull)];
}

t_task           *CentralBureaucracy::isQueueEmpty(void) {
    for (int i = 0; i < MAX_QUEUE; i++) {
        if ((this->queue[i]))
            return this->queue[i];
    }
    return nullptr;
}

void            CentralBureaucracy::removeTask(t_task *task) {
    for (int i =0;i < MAX_QUEUE;i++) {
        if (this->queue[i] == task) {
            delete this->queue[i];
            this->queue[i] = nullptr;
        }
    }
}

void            CentralBureaucracy::doBureaucracy(void) {
    t_task      *task;
    OfficeBlock *ob;
    srand(time(nullptr));

    while ((task = this->isQueueEmpty()) != nullptr) {
        ob = this->getRandomOfficeBlock();
        ob->doBureaucracy(task->typeform, task->target);
        this->removeTask(task);
    }
}

/**
 * Exceptions
 */

CentralBureaucracy::MaxBureaucrat::~MaxBureaucrat(void) throw() {}
CentralBureaucracy::MaxBureaucrat::MaxBureaucrat(void) {}
CentralBureaucracy::MaxBureaucrat::MaxBureaucrat(MaxBureaucrat const &e) {
    (void)e;
}

CentralBureaucracy::MaxBureaucrat &CentralBureaucracy::MaxBureaucrat::operator=(MaxBureaucrat const &e) {
    (void)e;
    return *this;
}

const char          *CentralBureaucracy::MaxBureaucrat::what() const throw() {
    return ("We Already Have Enough Bureaucrat, come with your resume later ...");
}

CentralBureaucracy::MaxQueue::~MaxQueue(void) throw() {}
CentralBureaucracy::MaxQueue::MaxQueue(void) {}
CentralBureaucracy::MaxQueue::MaxQueue(MaxQueue const &e) {
    (void)e;
}

CentralBureaucracy::MaxQueue &CentralBureaucracy::MaxQueue::operator=(MaxQueue const &e) {
    (void)e;
    return *this;
}

const char          *CentralBureaucracy::MaxQueue::what() const throw() {
    return ("The Queue Is Full Right Now, please come later ...");
}

CentralBureaucracy::NoFullTeamToWork::~NoFullTeamToWork(void) throw() {}
CentralBureaucracy::NoFullTeamToWork::NoFullTeamToWork(void) {}
CentralBureaucracy::NoFullTeamToWork::NoFullTeamToWork(NoFullTeamToWork const &e) {
    (void)e;
}

CentralBureaucracy::NoFullTeamToWork &CentralBureaucracy::NoFullTeamToWork::operator=(NoFullTeamToWork const &e) {
    (void)e;
    return *this;
}

const char          *CentralBureaucracy::NoFullTeamToWork::what() const throw() {
    return ("None Of The Teams Are Complete, We May Miss Some Bureaucrat here, please feed some...");
}