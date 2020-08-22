#include "client.h"

void Client::onMessage(SleepyDiscord::Message message) {
    if (message.author.bot)
        return;

    if (message.startsWith(prefix + "test")) {
        message.reply(this, "It works");
    }
}