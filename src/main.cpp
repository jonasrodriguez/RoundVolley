#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickWindow>

#include <memory>

#include "logic/Engine.h"
#include "logic/KeyInput.h"

#include "views/PlayBall.h"
#include "views/PlayerOne.h"

int main(int argc, char *argv[]) {
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

  QGuiApplication app(argc, argv);

  // Keyboard input filtering
  KeyInput *ki = new KeyInput;
  app.installEventFilter(ki);

  QQmlApplicationEngine engine;

  // Balls Views
  std::shared_ptr<PlayerOne> playerOne(new PlayerOne);
  engine.rootContext()->setContextProperty("playerOne", playerOne.get());

  std::shared_ptr<PlayBall> playBall(new PlayBall);
  engine.rootContext()->setContextProperty("playBall", playBall.get());

  // Start game engine
  Engine game_engine(ki, playBall, playerOne);

  engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));
  if (engine.rootObjects().isEmpty())
    return -1;

  // QObject::connect(&app, &QCoreApplication::aboutToQuit, [&]() {
  // business_logic->ShutDown(); });

  return app.exec();
}
