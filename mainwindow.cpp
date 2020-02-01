#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "animatedqpushbutton.h"
#include "board.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    qApp->setStyleSheet("QMainWindow { background-color: #333333}");

    QPixmap cursor_pixmap = QPixmap(":/Assets/Cursor.png");
    QCursor cursor_default = QCursor(cursor_pixmap, cursor_pixmap.width()/2, cursor_pixmap.height()/2);
    setCursor(cursor_default);

    QPixmap pixmap(":/Assets/Fullscreen.png");
    QIcon ButtonIcon(pixmap);
    ui->fullscreenButton->setIcon(ButtonIcon);
    ui->fullscreenButton->setIconSize(pixmap.rect().size());
    ui->fullscreenButton->setStyleSheet("QPushButton { background-color: rgba(220,160,140,0);}");

    ui->startButton->setPredefinedColor(AnimatedQPushButton::ButtonColor::green);
    ui->exitButton->setPredefinedColor(AnimatedQPushButton::ButtonColor::red);

    connect(ui->startButton, SIGNAL(clicked()), ui->startButton, SLOT(fadeOut()));
    connect(ui->startButton, SIGNAL(clicked()), ui->exitButton, SLOT(fadeOut()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_fullscreenButton_clicked()
{
    if(isFullScreen()){
        showNormal();
        QPixmap pixmap(":/Assets/Fullscreen.png");
        QIcon ButtonIcon(pixmap);
        ui->fullscreenButton->setIcon(ButtonIcon);
        ui->fullscreenButton->setIconSize(pixmap.rect().size());
    } else {
        showFullScreen();
        QPixmap pixmap(":/Assets/ExitFullscreen.png");
        QIcon ButtonIcon(pixmap);
        ui->fullscreenButton->setIcon(ButtonIcon);
        ui->fullscreenButton->setIconSize(pixmap.rect().size());
    }
}

void MainWindow::on_startButton_clicked()
{
    Board *b = new Board(8, 5, this);
    static_cast<QGridLayout *>(layout())->addWidget(b);
    Board *b = new Board(8, 5, this);
    layout()->addWidget(b);

    static_cast<QGridLayout *>(ui->gridLayout_2)->addWidget(b, 1, 0, Qt::AlignCenter);
    
    for (QWidget *o : findChildren<QWidget *>()) {
        std::cout << o->objectName().toStdString() << std::endl;
    }
    static_cast<QGridLayout *>(ui->gridLayout)->addWidget(b, 0, 1, Qt::AlignCenter);
}
