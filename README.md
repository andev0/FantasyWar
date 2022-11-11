# Fantasy War console edition
Remastered version of my very first game.
Written in C++. UI is planned to be represented by CLI and Telegram bot.
Development is not focused on the result but on the learning process so there are few external libraries and progress is slow.

- [Building](#Building)
  - [Using Cmake](#Using-Cmake)
    - [Cmake variables](#Cmake-variables)
  - [Using build script](#Using-build-script)
- [Running the game](#Running-the-game)

## Building

### Using Cmake
```
mkdir build
cd build
cmake ..
cmake --build .
```

#### Cmake variables
Use BUILD_MODE to specify either Release or Debug build mode:
```
cmake .. -DBUILD_MODE=Debug
```
> Release build mode is used by default.

### Using build script
```
./build [debug]
```
> `debug` is optional argument, release build mode is used by default.

## Running the game
The game can be launched from the build directory with
```
chmod +x ./FantasyWar
./FantasyWar
```
