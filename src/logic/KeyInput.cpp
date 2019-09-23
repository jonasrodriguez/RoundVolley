#include "KeyInput.h"
#include <QDebug>
#include <QEvent>
#include <QKeyEvent>

KeyInput::KeyInput(QObject *) {}

bool KeyInput::eventFilter(QObject *object, QEvent *event) {
  if (event->type() == QEvent::Type::KeyPress) {
    QKeyEvent *key = static_cast<QKeyEvent *>(event);
    switch (key->key()) {
    case Qt::Key_W:
      qDebug() << "Key W!";
      emit P1MoveUp();
      return true;
    case Qt::Key_A:
      qDebug() << "Key A!";
      emit P1MoveLeft();
      return true;
    case Qt::Key_S:
      qDebug() << "Key S!";
      emit P1MoveDown();
      return true;
    case Qt::Key_D:
      qDebug() << "Key D!";
      emit P1MoveRight();
      return true;
    default:
      qDebug() << __FUNCTION__ << ":" << object << " - " << event->type();
      return QObject::eventFilter(object, event);
    }
  }
  return false;
}
