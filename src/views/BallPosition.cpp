#include "BallPosition.h"
#include <QDebug>
#include <QTimer>

BallPosition::BallPosition() : posX_(0), posY_(0), rotFrom_(0), rotTo_(0) {

  QTimer *timer = new QTimer(this);
  connect(timer, &QTimer::timeout, this, &BallPosition::TimerTrigger);
  timer->start(1000);
}

void BallPosition::TimerTrigger() {
  posX_ += 5;
  emit BallMoved();
  qDebug() << "Hola!";
}
