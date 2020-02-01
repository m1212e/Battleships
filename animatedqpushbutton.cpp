#include "animatedqpushbutton.h"

#include <iostream>
#include <QGraphicsOpacityEffect>

using namespace std;

AnimatedQPushButton::AnimatedQPushButton(QWidget *parent, ButtonColor predefinedColor): bganimation(this, "BackgroundColor"), predefinedColor(predefinedColor)
{
    this->setParent(parent);
    this->setStyleSheet(masterStyleSheet);

    bganimation.setDuration(400);
    bganimation.setEasingCurve(QEasingCurve::OutQuad);

    updatePredefinedColor();
}

AnimatedQPushButton::AnimatedQPushButton(const QString &text, QWidget *parent, ButtonColor predefinedColor): AnimatedQPushButton(parent, predefinedColor)
{
    this->setText(text);
}

AnimatedQPushButton::AnimatedQPushButton(const QIcon &icon, const QString &text, QWidget *parent, ButtonColor predefinedColor): AnimatedQPushButton(text, parent, predefinedColor)
{
    this->setIcon(icon);
}


void AnimatedQPushButton::enterEvent(QEvent *event)
{
    if (bganimation.state() == QAbstractAnimation::Running) {
        bganimation.stop();
    }

    bganimation.setStartValue(0);
    bganimation.setEndValue(100);
    bganimation.start();


}

void AnimatedQPushButton::leaveEvent(QEvent *event)
{
    if (bganimation.state() == QAbstractAnimation::Running) {
        bganimation.stop();
    }

    bganimation.setStartValue(getAnimationProgress());
    bganimation.setEndValue(0);
    bganimation.start();
}

void AnimatedQPushButton::updatePredefinedColor()
{
    switch (predefinedColor) {
    case 0: {
        this->setStyleSheet(masterStyleSheet
                            + "AnimatedQPushButton { "
                              "border-color: #FF3628;"
                              "color: #FF3628;"
                              "}");
        break;
    }
    case 1: {
        this->setStyleSheet(masterStyleSheet
                            + "AnimatedQPushButton { "
                              "border-color: #40CF27;"
                              "color: #40CF27;"
                              "}");
        break;
    }
    default: {
        this->setStyleSheet(masterStyleSheet
                            + "AnimatedQPushButton { "
                              "border-color: #8f8f91;"
                              "color: #8f8f91;"
                              "}");
        break;
    }
    }
    update();
}

QColor AnimatedQPushButton::transferPredefinedColor()
{
    switch (predefinedColor) {
    case 0: {
        return QColor("#FF3628");
    }
    case 1: {
        return QColor("#40CF27");
    }
    default: {
        return QColor("#8f8f91");
    }
    }
}

void AnimatedQPushButton::setColor(int color)
{
    setAnimationProgress(color);

    QString colorString = QString("rgba(" + QString::number(transferPredefinedColor().red()) + ", "
                                  + QString::number(transferPredefinedColor().green()) + ", "
                                  + QString::number(transferPredefinedColor().blue()) + ", "
                                  + QString::number(color) + ")");

    if (color == 1) {
        return;
    }

    setStyleSheet(masterStyleSheet
                            + "AnimatedQPushButton { " +
                              "color: " + transferPredefinedColor().name() + ";" +
                              "border-color: " + transferPredefinedColor().name() + ";" +
                              "background-color: " + colorString + ";" +
                              "}");

    update();
}

int AnimatedQPushButton::color()
{
    return -1;
}

AnimatedQPushButton::ButtonColor AnimatedQPushButton::getPredefinedColor() const
{
    return predefinedColor;
}

void AnimatedQPushButton::setPredefinedColor(const ButtonColor &value)
{
    predefinedColor = value;
    updatePredefinedColor();
}

int AnimatedQPushButton::getAnimationProgress() const
{
    return animationProgress;
}

void AnimatedQPushButton::setAnimationProgress(int value)
{
    animationProgress = value;
}

void AnimatedQPushButton::fadeIn()
{
    QGraphicsOpacityEffect *eff = new QGraphicsOpacityEffect(this);
    setGraphicsEffect(eff);
    QPropertyAnimation *a = new QPropertyAnimation(eff, "opacity");
    a->setDuration(300);
    a->setStartValue(0);
    a->setEndValue(1);
    a->start(QPropertyAnimation::DeleteWhenStopped);
}

void AnimatedQPushButton::fadeOut()
{
    QGraphicsOpacityEffect *eff = new QGraphicsOpacityEffect(this);
    setGraphicsEffect(eff);
    QPropertyAnimation *a = new QPropertyAnimation(eff, "opacity");
    a->setDuration(300);
    a->setStartValue(1);
    a->setEndValue(0);

    connect(a, SIGNAL(finished()), this, SLOT(deleteLater()));
    a->start(QPropertyAnimation::DeleteWhenStopped);
}
