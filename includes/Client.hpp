#pragma once

#include "irc.hpp"
#include "Channel.hpp"
#include "Server.hpp"
#include <string>
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <map>

class Channel;
class Server;

class Client {
private:
	int _socket_fd;
	std::string _nick;
	std::string _username;
	std::string _realname;
	unsigned int _state;
	unsigned int _mode;
	bool _pass_match;
	bool _is_registered;
	bool _is_welcome_send;
	bool _is_quited;
	std::vector<Channel *> _channels;
	std::vector<std::vector<std::string> > _cmds;
	std::string cmdBuf;
	Server &_server;
	std::string replyCmd;
	std::string buf;

public:
	Client(int socket_fd, Server &server);
	~Client();

	//Getter
	std::string getNick()  {return this->_nick;}
	std::string getUsername()  {return this->_username;}
	std::string getRealname()  {return this->_realname;}
	unsigned int getState()  {return this->_state;}
	unsigned int getMode() {return this->_mode;}
	std::vector<Channel *> &getChannels() {return this->_channels;}
	int	getSocketFd() {return this->_socket_fd;}
	std::vector<std::vector<std::string> > &getCmds() {return this->_cmds;}
	bool getIsRegistered() {return this->_is_registered;}
	bool getPassMatch() {return this->_pass_match;}
	bool getIsWelcomeSend(){return this->_is_welcome_send;}
	Server &getServer(){return this->_server;}
	std::string getCmdBuf() {return this->cmdBuf;}
	bool getIsQuited() {return this->_is_quited;}

	//Setter
	void setNick(const std::string &nick)  {this->_nick = nick;}
	void setUsername(const std::string &username) {this->_username = username;}
	void setRealname(const std::string &realname) {this->_realname = realname;}
	void setState(const unsigned int &state)  {this->_state = state;}
	void setMode(const unsigned int &mode)  {this->_mode = mode;}
	void setIsRegistered(bool val) {this->_is_registered = val;}
	void setPassMatch(bool val) {this->_pass_match = val;}
	void setCmdBuf(std::string buf) {this->cmdBuf = buf;}
	void setIsQuited(bool val) {this->_is_quited = val;}
	
	//Functions
	void addReply(std::string msg) {this->replyCmd += msg;};
	void addChannel(Channel *channel); 
	void parseCmds();
	Client& operator=(const Client& other);
	bool cmdIsTerminated();
	void sendReply();
	void removeChannel(std::string channel);
};


