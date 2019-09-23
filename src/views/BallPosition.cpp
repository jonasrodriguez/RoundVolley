#include "BallPosition.h"
#include "logic/KeyInput.h"
#include <QDebug>
#include <QTimer>

// Playable Area 630x * 600y
// Bola 100 * 100

BallPosition::BallPosition(const Positions *) {
  //  QTimer *timer = new QTimer(this);
  //  connect(timer, &QTimer::timeout, this, &BallPosition::TimerTrigger);
  //  timer->start(10);
}

void BallPosition::TimerTrigger() {
  //  posX_ += 5;
  //  rotation_ += 5;
  //  emit PlayerOneMoved();
}

int BallPosition::getP1X() const { return playerOne_.posX; };
int BallPosition::getP1Y() const { return playerOne_.posY; };
int BallPosition::getP1Rot() const { return playerOne_.rotation; };

int BallPosition::getBX() const { return ball_.posX; };
int BallPosition::getBY() const { return ball_.posY; };
int BallPosition::getBRot() const { return ball_.rotation; };
