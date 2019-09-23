#include "logic/Types.h"
#include <QObject>

class Positions;

class BallPosition : public QObject {
  Q_OBJECT
  Q_PROPERTY(int p1PosX READ getP1X NOTIFY PlayerOneMoved)
  Q_PROPERTY(int p1PosY READ getP1Y NOTIFY PlayerOneMoved)
  Q_PROPERTY(int p1Rot READ getP1Rot NOTIFY PlayerOneMoved)
  //  Q_PROPERTY(int getBX READ getP2X NOTIFY PlayBallMoved)
  //  Q_PROPERTY(int getBY READ getP2Y NOTIFY PlayBallMoved)
  //  Q_PROPERTY(int getBRot READ getP2Rot NOTIFY PlayBallMoved)

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
  void PlayerTwoMoved();
  void PlayBallMoved();

public slots:
  void UpdatePlayerOnePosition();
  void UpdatePlayerTwoPosition();
  void UpdatePlayBallPosition();

private:
  const Positions *positions_;
  rv::Position playerOne_;
  rv::Position playerTwo_;
  rv::Position ball_;
};
