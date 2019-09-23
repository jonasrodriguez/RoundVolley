#include "logic/Types.h"
#include <QObject>

class Positions;

class BallPosition : public QObject {
  Q_OBJECT
  Q_PROPERTY(int p1PosX READ getP1X NOTIFY PlayerOneMoved)
  Q_PROPERTY(int p1PosY READ getP1Y NOTIFY PlayerOneMoved)
  Q_PROPERTY(int p1Rot READ getP1Rot NOTIFY PlayerOneMoved)

public:
  BallPosition(const Positions *);

  // PLayer One
  int getP1X() const;
  int getP1Y() const;
  int getP1Rot() const;

  // Ball
  int getBX() const;
  int getBY() const;
  int getBRot() const;

private:
  void TimerTrigger();

signals:
  void PlayerOneMoved();

public slots:
  void UpdateMovement();

private:
  rv::Position playerOne_;
  rv::Position ball_;
};
