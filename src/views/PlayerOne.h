#pragma once

#include "Position.h"
#include <QObject>

class PlayerOne : public Position {
  Q_OBJECT

  Q_PROPERTY(double posX READ getX NOTIFY PlayerOneMoved)
  Q_PROPERTY(double posY READ getY NOTIFY PlayerOneMoved)
  Q_PROPERTY(int rot READ getRot NOTIFY PlayerOneMoved)

public:
  PlayerOne();
  void Paint();

signals:
  void PlayerOneMoved();

private:
  bool IsJumping_;
};
