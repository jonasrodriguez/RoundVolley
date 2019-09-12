#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickWindow>

int main(int argc, char *argv[]) {
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

  QGuiApplication app(argc, argv);

  QQmlApplicationEngine engine;

  engine.load(QUrl(QStringLiteral("qrc:/mainWindow")));
  if (engine.rootObjects().isEmpty())
    return -1;

  // QObject::connect(&app, &QCoreApplication::aboutToQuit, [&]() {
  // business_logic->ShutDown(); });

  return app.exec();
}
