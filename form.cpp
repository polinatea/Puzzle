#include "form.h"
#include "ui_form.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFont>
Form::Form(QWidget *parent) : game(NULL),
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);

    layout = new QVBoxLayout(this);
    settingsLayout = new QHBoxLayout;

    /* создаем кнопки */
    QPushButton* newgame = new QPushButton("Start new game", this);
    QPushButton* exitgame = new QPushButton("Exit", this);

    /* Устанавливаем размер кнопок */
    exitgame->setFixedWidth(301);
    exitgame->setFixedHeight(70);
    newgame->setFixedWidth(301);
    newgame->setFixedHeight(70);

    /* Устанавливаем стиль кнопок */
    newgame->setStyleSheet("font: bold;background-color: #80c342 ;font-size: 36px;height: 48px;width: 120px;color:white;");
    exitgame->setStyleSheet("font: bold;background-color: #c31d00;font-size: 36px;height: 48px;width: 120px;color:white;");

    /* Соединяем сигнал со слотом */
    connect(newgame, SIGNAL(clicked()), this, SLOT(newGame()));
    connect(exitgame, SIGNAL(clicked()), this, SLOT(exitGame()));

    /* Размещаем виджеты по горизонтали слева направо */
    settingsLayout->addWidget(newgame);
    settingsLayout->addWidget(exitgame);

    /* Устанавливаем поля вокруг макета */
    layout->setContentsMargins(2, 2, 2, 2);

    /* Добавляем макет в конец поля */
    layout->addLayout(settingsLayout);

    /* Сигнал начала игры */
    newGame();

    /* Применяем размещение */
    setLayout(layout);
}

Form::~Form()
{
    delete ui;
}

void Form::newGame()
{
    if(game) //удаляем старое поле
    {
        layout->removeWidget(game);  // удаляем виджет из макета
        delete game;
    }

    game = new Game(/*4, */this); //рисуем новое поле

    /* Добавляем виджет в компоновщик */
    layout->addWidget(game);

    /* Обновляем компоновщик */
    layout->update();

    game->hide();
    game->show();

    /* Меняем размер окна*/
    resize(sizeHint());
}

void Form::exitGame()
{
    MainWindow *f = new MainWindow();
    f->show();
    this->close();
}


