![FT_IRC Logo](https://your_project_logo_url_here.png)

# FT_IRC - 42 School Project

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)

## Introduction

FT_IRC is a collaborative project developed as part of the curriculum at 42, a coding school. This project aims to create a simple Internet Relay Chat (IRC) server implementation. IRC is a widely used protocol for real-time text-based communication, allowing users to participate in group discussions or private conversations over the internet.

## Features

FT_IRC comes with the following features:

- Multiple users can connect to the server simultaneously.
- Users can create or join different channels to participate in group conversations.
- Public messages sent to a channel will be visible to all its members.
- Users can send private messages to other users connected to the same server.
- Moderators can kick or ban users from a channel.
- Built-in admin commands for server management.
- Password-protected channels for private discussions.
- Nickname management: users can change their nicknames while connected.

## Requirements

To run FT_IRC, you need the following prerequisites:

- C compiler (e.g., GCC)
- Unix-based operating system (Linux, macOS, or similar)
- A terminal emulator

## Installation

Clone the FT_IRC repository from GitHub:

```bash
git clone https://github.com/JakobKlocker/IRC_Server.git
```

Navigate to the project directory:
```bash
cd IRC_Server
```
Compile the server executable:
```bash
make
```

## Usage
Start the server:
```bash
./ircserv [PORT] [PASSWORD]
```

Now you can connect to the server with a Client of your choice.
