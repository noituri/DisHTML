#ifndef DISHTML_CLIENT_H
#define DISHTML_CLIENT_H

#include <sleepy_discord/websocketpp_websocket.h>
#include "command.h"

class Client : public SleepyDiscord::DiscordClient {
public:
    using SleepyDiscord::DiscordClient::WebsocketppDiscordClient;
    std::string prefix;
    std::vector<Command> commands;
    void onMessage(SleepyDiscord::Message message) override;
};


#endif //DISHTML_CLIENT_H
