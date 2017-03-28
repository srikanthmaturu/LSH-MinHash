#ifndef COMMANDRUN_H
#define COMMANDRUN_H

#include "Command.h"

class CommandRun : public Command
{
public:
    CommandRun();
    int run() const;

};

#endif // COMMANDRUN_H
