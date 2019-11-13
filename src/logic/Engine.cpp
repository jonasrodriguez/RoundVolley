#include "Engine.h"
#include <QDebug>
#include <QTimer>

#include "KeyInput.h"
#include "Types.h"

Engine::Engine(const KeyInput *keyInput, std::shared_ptr<PlayBall> playBall,
               std::shared_ptr<PlayerOne> playerOne)
    : keyInput_(keyInput), playBall_(move(playBall)),
      playerOne_(move(playerOne)) {
  QTimer *game_clock = new QTimer(this);
  connect(game_clock, &QTimer::timeout, this, &Engine::ProcessTimeout);
  // 60 fps = 16 ms
  game_clock->start(16);

  InitialBallPositions();
}

void Engine::InitialBallPositions() {
  // Player One initial position
  playerOne_->SetX(rv::InitialXPosition);
  playerOne_->SetY(rv::InitialYPosition);

  // Player Two initial position
  //  ballPosition_->SetP1X((rv::playAreaWidth / 2) - (rv::ballDiameter / 2));
  //  ballPosition_->SetP1Y(rv::playAreaHeight - rv::ballDiameter);

  // Play ball initial position
  //  ballPosition_->SetP1X((rv::playAreaWidth / 2) - (rv::ballDiameter / 2));
  //  ballPosition_->SetP1Y(rv::playAreaHeight - rv::ballDiameter);
}

void Engine::ProcessTimeout() { MovePlayerOne(); }

void Engine::MovePlayerOne() {
  // Check if any key is pressed
  if (keyInput_->IsWPress()) {
    if (!playerOne_->IsJumping()) {
      playerOne_->SetJump(true);
      playerOne_->SetFall(false);
    }
  }

  // Skip redrawing if no move
  if (!playerOne_->IsJumping() && !keyInput_->IsAPress() &&
      !keyInput_->IsDPress()) {
    return;
  }

  // Left movement
  if (keyInput_->IsAPress()) {
    playerOne_->SetX(playerOne_->getX() - 3);
  }

  // Right movement
  if (keyInput_->IsDPress()) {
    playerOne_->SetX(playerOne_->getX() + 3);
  }

  // Jump movements
  if (playerOne_->IsJumping()) {
    // If going down
    if (playerOne_->IsFalling()) {
      playerOne_->SetY(playerOne_->getY() + 3);
      if (playerOne_->IsBallOnTheGround()) {
        playerOne_->SetJump(false);
      }
    }
    // If going Up
    else {
      playerOne_->SetY(playerOne_->getY() - 3);
      if (playerOne_->IsBallOnMaxJump()) {
        playerOne_->SetFall(true);
      }
    }
  }

  playerOne_->Paint();
}
