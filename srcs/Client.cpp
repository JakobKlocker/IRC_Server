#include "../includes/Client.hpp"
#include "../includes/irc.hpp"

Client::Client(int socket_fd, Server &server): _socket_fd(socket_fd), _state(0), _mode(0), _pass_match(false), _is_registered(false), _is_welcome_send(false), _is_quited(false), _server(server)
{
    std::cout << "Client Created" << std::endl;
}

Client::~Client()
{
	if(this->_socket_fd > 0)
		close(_socket_fd);
}

void Client::addChannel(Channel *channel)
{
    this->_channels.push_back(channel);
}

void Client::parseCmds()
{
    std::vector<std::string> lines;
    
    lines = split(cmdBuf, "\n", false);
    for (size_t i = 0; i < lines.size(); ++i)
    {
        std::vector<std::string> split_line = split(lines[i], " ", false);
        if (!split_line.empty())
            this->_cmds.push_back(split_line);
    }
}

void Client::sendReply()
{
	if(this->replyCmd.empty() == false)
	{
    	send(this->_socket_fd, this->replyCmd.c_str(), this->replyCmd.size(), MSG_NOSIGNAL);
		std::cout << "Reply sent: " << this->replyCmd << std::endl;
    	this->replyCmd.clear();
	}
}

Client& Client::operator=(const Client& other) {
	_socket_fd = other._socket_fd;
	_nick = other._nick;
	_username = other._username;
	_realname = other._realname;
	_state = other._state;
	_mode = other._mode;
	_pass_match = other._pass_match;
	_is_registered = other._is_registered;
	_channels = other._channels;
	_cmds = other._cmds;
	cmdBuf = other.cmdBuf;
	_server = other._server;
	
	return *this;
}

bool Client::cmdIsTerminated()
{
    std::size_t pos;
	while ((pos = this->cmdBuf.find("\r\n")) != std::string::npos)
        this->cmdBuf.replace(pos, 2, "\n");
	if (this->cmdBuf.find("\n") != std::string::npos)
		return true;
	return false;
}

void Client::removeChannel(std::string channel)
{
	for(size_t i = 0; this->getChannels().size(); i++)
	{
		if(this->getChannels()[i]->getName() == channel)
		{
			this->getChannels().erase(this->getChannels().begin() + i);
			return;
		}
	}
}