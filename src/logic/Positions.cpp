#include "Positions.h"
#include "KeyInput.h"
#include <QDebug>

Positions::Positions(const KeyInput *keyInput) {
  connect(keyInput, &KeyInput::P1MoveUp, this, &Positions::PlayerOneUp);
  connect(keyInput, &KeyInput::P1MoveLeft, this, &Positions::PlayerOneLeft);
  connect(keyInput, &KeyInput::P1MoveRight, this, &Positions::PlayerOneRight);

  // Player One initial position
  firstBall_.posX = (rv::playAreaWidth / 2) - (rv::ballDiameter / 2);
  firstBall_.posY = rv::playAreaHeight - rv::ballDiameter;
  firstBall_.rotation = 0;

  //  QTimer *timer = new QTimer(this);
  //  connect(timer, &QTimer::timeout, this, &BallPosition::TimerTrigger);
  //  timer->start(10);
}

rv::Position Positions::GetFirstBall() const { return firstBall_; }

rv::Position Positions::GetSecondBall() const { return secondBall_; }

rv::Position Positions::GetPlayBall() const { return playBall_; }

void Positions::PlayerOneUp() {
  firstBall_.posY -= 5;
  emit UpdateP1Position();
}

void Positions::PlayerOneLeft() {
  firstBall_.posX -= 5;
  firstBall_.rotation -= 5;
  emit UpdateP1Position();
}

void Positions::PlayerOneRight() {
  firstBall_.posX += 5;
  firstBall_.rotation += 5;
  emit UpdateP1Position();
}
