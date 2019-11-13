#pragma once

namespace rv {

static const int playAreaWidth = 630;
static const int playAreaHeight = 600;
static const int ballDiameter = 100;
static const int maxBallJump = 250;

static const double InitialXPosition = (playAreaWidth / 2) - (ballDiameter / 2);
static const double InitialYPosition = playAreaHeight - ballDiameter;

} // namespace rv
