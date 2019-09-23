#include "BallPosition.h"
#include "logic/Positions.h"
#include <QDebug>

BallPosition::BallPosition(const Positions *positions) : positions_(positions) {

  connect(positions_, &Positions::UpdateP1Position, this,
          &BallPosition::UpdatePlayerOnePosition);
  connect(positions_, &Positions::UpdateP2osition, this,
          &BallPosition::UpdatePlayerTwoPosition);
  connect(positions_, &Positions::UpdatePlayPosition, this,
          &BallPosition::UpdatePlayBallPosition);

  // Initial ball positions
  UpdatePlayerOnePosition();
}

void BallPosition::UpdatePlayerOnePosition() {
  playerOne_ = positions_->GetFirstBall();
  emit PlayerOneMoved();
}
void BallPosition::UpdatePlayerTwoPosition() {
  playerTwo_ = positions_->GetSecondBall();
  emit PlayerTwoMoved();
}
void BallPosition::UpdatePlayBallPosition() {
  ball_ = positions_->GetPlayBall();
  emit PlayBallMoved();
}

// Player One positions
int BallPosition::getP1X() const { return playerOne_.posX; };
int BallPosition::getP1Y() const { return playerOne_.posY; };
int BallPosition::getP1Rot() const { return playerOne_.rotation; };

// Play Ball positions
int BallPosition::getBX() const { return ball_.posX; };
int BallPosition::getBY() const { return ball_.posY; };
int BallPosition::getBRot() const { return ball_.rotation; };
