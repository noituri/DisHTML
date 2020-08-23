//
// Created by noituri on 8/23/20.
//

#include "command.h"

#include <utility>

Command::Command(std::string name, std::string reply) : name(std::move(name)), replyMessage(std::move(reply)) {}