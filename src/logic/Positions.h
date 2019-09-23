#include "Types.h"
#include <QObject>

class KeyInput;

class Positions : public QObject {
  Q_OBJECT

public:
  Positions(const KeyInput *);

  rv::Position GetFirstBall() const;
  rv::Position GetSecondBall() const;
  rv::Position GetPlayBall() const;

signals:
  void UpdateP1Position();
  void UpdateP2osition();
  void UpdatePlayPosition();

public slots:
  void PlayerOneUp();
  void PlayerOneLeft();
  void PlayerOneRight();

private:
  rv::Position firstBall_;
  rv::Position secondBall_;
  rv::Position playBall_;
};
