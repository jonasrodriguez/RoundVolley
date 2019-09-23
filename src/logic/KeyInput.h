#pragma once

#include <QObject>

class KeyInput : public QObject {
  Q_OBJECT
public:
  explicit KeyInput(QObject *parent = nullptr);

signals:
  void P1MoveUp();
  void P1MoveDown();
  void P1MoveLeft();
  void P1MoveRight();

public:
  bool eventFilter(QObject *object, QEvent *event) override;
};
