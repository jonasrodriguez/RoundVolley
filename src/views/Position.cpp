#include "Position.h"
#include "logic/Types.h"

Position::Position()
    : xPos_(0), yPos_(0), rotation_(0), IsJumping_(false), IsFalling_(false) {}

double Position::getX() const { return xPos_; }
double Position::getY() const { return yPos_; }
int Position::getRot() const { return rotation_; }

void Position::SetX(double x) { xPos_ = x; }
void Position::SetY(double y) { yPos_ = y; }
void Position::SetRot(int r) { rotation_ = r; }

bool Position::IsJumping() { return IsJumping_; }
bool Position::IsFalling() { return IsFalling_; }
void Position::SetJump(bool j) { IsJumping_ = j; }
void Position::SetFall(bool f) { IsFalling_ = f; }

bool Position::IsBallOnTheGround() {
  // Y pos + ball diamter greater than play area
  if (getY() + rv::ballDiameter > rv::playAreaHeight)
    return true;
  else
    return false;
}

bool Position::IsBallOnMaxJump() {
  if (getY() < rv::maxBallJump)
    return true;
  else
    return false;
}
