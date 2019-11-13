#pragma once

#include <QObject>

class Position : public QObject {

public:
  Position();

  double getX() const;
  double getY() const;
  int getRot() const;

  void SetX(double x);
  void SetY(double y);
  void SetRot(int r);

  void SetJump(bool j);
  void SetFall(bool f);
  bool IsJumping();
  bool IsFalling();

  bool IsBallOnTheGround();
  bool IsBallOnMaxJump();

private:
  double xPos_;
  double yPos_;
  int rotation_;

  bool IsJumping_;
  bool IsFalling_;
};
