#pragma once

#define INVITE(client, nick, channel) (":" + client + "!localhost INVITE " + nick + " " + channel + "\r\n")
#define KICK(client, nick, channel, msg) (":" + client + "!localhost  KICK " + channel + " " + nick + " " + msg + "\r\n")
#define MODES(client, channel,modes, arg) (":" + client + "!localhost MODE " + channel + " " + modes + " " + arg + "\r\n")
#define JOIN(client, channel) (":" + client + "!localhost JOIN " + channel + "\r\n")
#define NICK(client, nick) (":" + client + "!localhost NICK " + nick + "\r\n")
#define PART(client, channel) (":" + client + "!localhost PART " + channel + "\r\n")
#define PONG(msg) ("PONG " + msg + "\r\n")
#define TOPIC(client, channel, newTopic) (":" + client + "!localhost TOPIC " + channel + " " + newTopic + "\r\n")

//Welcome Replys

#define RPL_WELCOME(nick, user) (":localhost 001 " + nick + " :Welcome to the 42 Vienna Network, " + nick + "\r\n")
#define RPL_YOURHOST(servername, version, nick) (":localhost 002 " + nick + " :Your host is " + servername + ", running version " + version + "\r\n")
#define RPL_CREATED(datetime, nick) (":localhost 003 " + nick + " :This server was created " + datetime + "\r\n")
#define RPL_MYINFO(servername, version, usermodes, channelmodes, nick) (":localhost 004 " + nick + " " + servername + " " + version + " " + usermodes + " " + channelmodes + "\r\n")
#define RPL_ISUPPORT(tokens, nick) (":localhost 005 " + nick + " " + tokens + " :are supported by this server\r\n")
//":localhost 372 " + client.getNick() + " " + line + "\r\n"
#define MESSAGE_OF_THE_DAY(nick, line) (":localhost 372 " + nick + " :" + line + "\r\n")

//Nick ErrorMsgs

#define ERR_NONICKNAMEGIVEN(client) (":localhost 431 " + client + " :No nickname given\r\n")
#define ERR_ERRONEUSNICKNAME(client ,newNick) (":localhost 432 " + client + " " + newNick + " :Erroneus nickname\r\n")
#define ERR_NICKNAMEINUSE(client, newNick) (":localhost 433 " + client + " " + newNick + " :Nickname is already in use\r\n")

//Pass ErrorMsg

#define ERR_PASSWDMISMATCH(client) (":localhost 464 " + client + " :Password incorrect\r\n")
#define ERR_ALREADYREGISTERED(client) (":localhost 462 " + client + " :You may not reregister\r\n")

//Join

#define ERR_NOTREGISTERED(client) (":localhost 451 " + client + " :You have not registered\r\n")
#define ERR_NEEDMOREPARAMS(client, command) (":localhost 461 " + client + " " + command + " :Not enough parameters\r\n")
#define ERR_CHANNELISFULL(client, channel) (":localhost 471 " + client + " " + channel + " :Cannot join channel (+l)\r\n")
#define ERR_INVITEONLYCHAN(client, channel) (":localhost 473 " + client + " " + channel + " :Cannot join channel (+i)\r\n")
#define ERR_BADCHANNELKEY(client, channel) (":localhost 475 " + client + " " + channel + " :Cannot join channel (+k)\r\n")
#define ERR_TOOMANYCHANNELS(client, channel) (":localhost 405 " + client + " " + channel + " :You have joined too many channels\r\n") 
#define JOIN_MSG(client, channel) (":" + client + "!localhost JOIN " + channel + "\r\n")

#define RPL_TOPIC(client, channel, topic) (":localhost 332 " + client + " " + channel + " :" + topic + "\r\n") 
#define RPL_NAMREPLY(client, channel) (":localhost 353 " + client + " = " + channel + " :")
#define RPL_ENDOFNAMES(client, channel) (":localhost 366 " + client + " " + channel + " :End of /NAMES list\r\n")

//Kick
#define ERR_NOSUCHCHANNEL(client, channel) (":localhost 403 " + client + " " + channel + " :No such channel\r\n")
#define ERR_CHANOPRIVSNEEDED(client, channel) (":localhost 482 " + client + " " + channel + " :You're not channel operator\r\n")
#define ERR_USERNOTINCHANNEL(client, nick, channel) (":localhost 441 " + client + " " + nick + " " + channel + " :They aren't on that channel\r\n")

//PrivMsg
#define SENDPRIVMSG(nickname, username, recipient, message)(":" + nickname + "!" + username + "@localhost PRIVMSG " + recipient + " " + message + "\r\n")
#define ERR_NOSUCHNICK(client, nickname) (":localhost 401 " + client + " " + nickname + " :No such nick/channel" + "\r\n")
#define ERR_CANNOTSENDTOCHAN(client, channel) (":localhost 404 " + client + " " + channel + " :Cannot send to channel" + "\r\n")
#define ERR_NORECIPIENT(client, command) (":localhost 411 " + client + " :No recipient given (" + command + ")" + "\r\n")
#define ERR_NOTEXTTOSEND(client) (":localhost 412 " + client + " :No text to send" + "\r\n")
#define ERR_NORECIPIENT(client, command) (":localhost 411 " + client + " :No recipient given (" + command + ")" + "\r\n")
#define ERR_NOTEXTTOSEND(client) (":localhost 412 " + client + " :No text to send" + "\r\n")

//Notice
#define SENDNOTICE(nickname, username, recipient, message)(":" + nickname + "!" + username + "@hostname NOTICE " + recipient + " " + message + "\r\n")

//Invite
#define ERR_NOSUCHCHANNEL(client, channel) (":localhost 403 " + client + " " + channel + " :No such channel\r\n")
#define ERR_USERONCHANNEL(client, nick, channel) (":localhost 443 " + client +  " " + nick + " " + channel + " :is already on channel\r\n")
#define ERR_NOTONCHANNEL(client, channel) (":localhost 442 " + client + " " +  channel + " :You're not on that channel\r\n")
#define ERR_CHANOPRIVSNEEDED(client, channel) (":localhost 482 " + client + " " + channel + " :You're not channel operator\r\n")

#define RPL_INVITING(client, nick, channel) (":localhost 341 " + client + " " + nick + " " + channel + "\r\n") 

//Topic
#define RPL_NOTOPIC(client, channel) (":localhost 331 " + client + " " + channel + " :No topic is set\r\n")

//Mode
#define RPL_CHANNELMODEIS(client, channel, modestring, arguments) (":localhost 324 " + client + " " + channel + " " + modestring + " " + arguments + "\r\n")

//Quit
#define SENDQUIT(nickname, username, message)(":" + nickname + "!" + username + "@localhost QUIT " + message + "\r\n")