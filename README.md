# Fantasy War console edition
Remastered version of my very first game.
Written in C++. UI is represented by CLI and Telegram bot.

## Building

#### Using Cmake GUI

```
git clone https://github.com/andev0/FantasyWar
cd FantasyWar
mkdir build
cd build
cmake-gui ..
```

#### Using Cmake CLI

```
git clone https://github.com/andev0/FantasyWar
cd FantasyWar
mkdir build
cd build
cmake .. [-D targetPlatform:STRING=[Linux/Windows/Telegram]]
cmake --build .
```
Note that Linux is used by default so you can not specify target platform if you are building the game for Linux.
