#include <QObject>

class BallPosition : public QObject {
  Q_OBJECT
  Q_PROPERTY(int posX MEMBER posX_ NOTIFY BallMoved)
  Q_PROPERTY(int posY MEMBER posY_ NOTIFY BallMoved)

public:
  BallPosition();

signals:
  void BallMoved();

private:
  void TimerTrigger();

private:
  int posX_;
  int posY_;
};
