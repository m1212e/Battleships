#ifndef ANIMATEDQPUSHBUTTON_H
#define ANIMATEDQPUSHBUTTON_H

#include <QPushButton>
#include <QThread>
#include <QPropertyAnimation>

class AnimatedQPushButton : public QPushButton
{
    Q_OBJECT
    Q_PROPERTY(int BackgroundColor READ color WRITE setColor)

public:
    enum ButtonColor { red, green, white };
    AnimatedQPushButton(QWidget *parent = nullptr, ButtonColor predefinedColor = white);
    AnimatedQPushButton(const QString &text, QWidget *parent = nullptr, ButtonColor predefinedColor = white);
    AnimatedQPushButton(const QIcon &icon, const QString &text, QWidget *parent = nullptr, ButtonColor predefinedColor = white);

    virtual void enterEvent(QEvent *event);
    virtual void leaveEvent(QEvent *event);

    void updatePredefinedColor();
    QColor transferPredefinedColor();

    void setColor(int color);
    int color();

    ButtonColor getPredefinedColor() const;
    void setPredefinedColor(const ButtonColor &value);

    int getAnimationProgress() const;
    void setAnimationProgress(int value);

public slots:
    void fadeIn();
    void fadeOut();

private:
    QPropertyAnimation bganimation;
    ButtonColor predefinedColor;
    QString masterStyleSheet = "AnimatedQPushButton { "
                               "border: 1px solid #8f8f91;"
                               "border-radius: 6px;"
                               "background-color: transparent;"
                               "}";
    int animationProgress;
};

#endif // ANIMATEDQPUSHBUTTON_H
