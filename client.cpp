#include "client.h"

void Client::onMessage(SleepyDiscord::Message message) {
    if (message.author.bot)
        return;

    for (auto& cmd : commands) {
        if (message.startsWith(prefix + cmd.name)) {
            std::cout << "Executing command: " << cmd.name << std::endl;
            message.reply(this, cmd.replyMessage);
            break;
        }
    }
}