//
// Created by noituri on 8/23/20.
//

#ifndef DISHTML_COMMAND_H
#define DISHTML_COMMAND_H


#include <string>

class Command {
public:
    std::string name;
    std::string replyMessage;
    Command(std::string name, std::string reply);
};


#endif //DISHTML_COMMAND_H
