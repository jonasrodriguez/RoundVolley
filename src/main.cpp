#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickWindow>

#include "logic/KeyInput.h"
#include "logic/Positions.h"
#include "views/BallPosition.h"

int main(int argc, char *argv[]) {
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

  QGuiApplication app(argc, argv);

  // Keyboard input filtering
  KeyInput *ki = new KeyInput;
  app.installEventFilter(ki);

  QQmlApplicationEngine engine;

  // Ball position logic
  Positions *positions = new Positions(ki);

  // Ball position view
  BallPosition ballPosition(positions);
  engine.rootContext()->setContextProperty("ballPosition", &ballPosition);

  engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));
  if (engine.rootObjects().isEmpty())
    return -1;

  // QObject::connect(&app, &QCoreApplication::aboutToQuit, [&]() {
  // business_logic->ShutDown(); });

  return app.exec();
}
