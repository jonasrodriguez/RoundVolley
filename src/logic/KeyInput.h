#pragma once

#include <QObject>

class KeyInput : public QObject {
  Q_OBJECT
public:
  explicit KeyInput(QObject *parent = nullptr);

public:
  bool eventFilter(QObject *object, QEvent *event) override;

  bool IsWPress() const;
  bool IsAPress() const;
  bool IsDPress() const;

  bool IsUpPress();
  bool IsLeftPress();
  bool IsRightPress();

private:
  bool w_key_press;
  bool a_key_press;
  bool d_key_press;
  bool up_key_press;
  bool left_key_press;
  bool right_key_press;
};
