#pragma once

constexpr int screenWidth = 900;
constexpr int screenHeight = 512;
constexpr int baseHeight = 75;
constexpr int frameRate = 30;
constexpr int birdPosition = 60; // x-position of bird
constexpr double birdAcceleration = 30.0 / frameRate;
constexpr double flapVelocity = 300.0 / frameRate;
constexpr int pipeGap = 150;
constexpr int maxPipeHeight = screenHeight - pipeGap - baseHeight - 15; // Height of pipe sprite
static int speed = 180.0 / frameRate;                                // Speed at which pipes move
constexpr int collisionMargin = 5;
constexpr int pipeWidth = 52;
constexpr int scoreWidth = 16;
constexpr int scoreHeight = 36;
