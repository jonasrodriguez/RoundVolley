#include "BallPosition.h"
#include <QDebug>
#include <QTimer>

BallPosition::BallPosition() : posX_(0), posY_(0), rotation_(0) {

  QTimer *timer = new QTimer(this);
  connect(timer, &QTimer::timeout, this, &BallPosition::TimerTrigger);
  timer->start(10);
}

void BallPosition::TimerTrigger() {
  posX_ += 5;
  rotation_ += 5;
  emit BallMoved();
}
