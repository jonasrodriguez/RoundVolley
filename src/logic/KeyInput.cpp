#include "KeyInput.h"
#include <QDebug>
#include <QEvent>
#include <QKeyEvent>

KeyInput::KeyInput(QObject *) {
  w_key_press = false;
  a_key_press = false;
  d_key_press = false;
  up_key_press = false;
  left_key_press = false;
  right_key_press = false;
}

bool KeyInput::eventFilter(QObject *object, QEvent *event) {
  if (event->type() == QEvent::Type::KeyPress) {
    QKeyEvent *key = static_cast<QKeyEvent *>(event);
    switch (key->key()) {
    case Qt::Key_W:
      w_key_press = true;
      return true;
    case Qt::Key_A:
      a_key_press = true;
      return true;
    case Qt::Key_D:
      d_key_press = true;
      return true;
    default:
      qDebug() << __FUNCTION__ << ":" << object << " - " << event->type();
      return QObject::eventFilter(object, event);
    }
  } else if (event->type() == QEvent::Type::KeyRelease) {
    QKeyEvent *key = static_cast<QKeyEvent *>(event);
    switch (key->key()) {
    case Qt::Key_W:
      w_key_press = false;
      return true;
    case Qt::Key_A:
      a_key_press = false;
      return true;
    case Qt::Key_D:
      d_key_press = false;
      return true;
    default:
      qDebug() << __FUNCTION__ << ":" << object << " - " << event->type();
      return QObject::eventFilter(object, event);
    }
  }
  return false;
}

// Player One keys
bool KeyInput::IsWPress() const { return w_key_press; };
bool KeyInput::IsAPress() const { return a_key_press; };
bool KeyInput::IsDPress() const { return d_key_press; };

// Player Two keys
bool KeyInput::IsUpPress() { return up_key_press; };
bool KeyInput::IsLeftPress() { return left_key_press; };
bool KeyInput::IsRightPress() { return right_key_press; };
