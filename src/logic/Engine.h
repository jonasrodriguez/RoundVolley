#pragma once

#include "Types.h"
#include "views/PlayBall.h"
#include "views/PlayerOne.h"
#include <QObject>
#include <memory>

class KeyInput;

class Engine : public QObject {
  Q_OBJECT

public:
  Engine(const KeyInput *, std::shared_ptr<PlayBall> playBall,
         std::shared_ptr<PlayerOne> playerOne);

private:
  void ProcessTimeout();
  void InitialBallPositions();
  void MovePlayBall();
  void MovePlayerOne();
  void MovePlayerTwo();

private:
  const KeyInput *keyInput_;
  std::shared_ptr<PlayBall> playBall_;
  std::shared_ptr<PlayerOne> playerOne_;
};
