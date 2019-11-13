#pragma once

#include "Position.h"
#include <QObject>

class PlayBall : public Position {
  Q_OBJECT

  Q_PROPERTY(double posX READ getX NOTIFY PlayBallMoved)
  Q_PROPERTY(double posY READ getY NOTIFY PlayBallMoved)
  Q_PROPERTY(int rot READ getRot NOTIFY PlayBallMoved)

public:
  PlayBall();

signals:
  void PlayBallMoved();
};
