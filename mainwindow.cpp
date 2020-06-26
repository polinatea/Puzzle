#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "form.h"
#include "ui_form.h"
#include <QPixmap>
#include <QSoundEffect>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    MainWindow::ui->lbTusya->setStyleSheet("QLabel{"
                                           "    color:black;"
                                           "}");
    /* Добавляем изображение */
    QPixmap pic(":/tusya/tusya.png");
    MainWindow::ui->lbTusya->setScaledContents(true);
    MainWindow::ui->lbTusya->setPixmap(pic);
    MainWindow::ui->pushButton->setStyleSheet("font: bold;background-color: #80c342 ;font-size: 25px;height: 48px;width: 120px;color:white;");
    MainWindow::ui->pushButton_4->setStyleSheet("font: bold;background-color: #c31d00;font-size: 25px;height: 48px;width: 120px;color:white;");
    MainWindow::ui->pushButton_2->setStyleSheet("font: bold;background-color: #fbf11c;font-size: 25px;height: 48px;width: 120px;color:white;");
}

MainWindow::~MainWindow()
{

    delete ui;
}


/* Кнопка выхода из игры */
void MainWindow::on_pushButton_4_clicked()
{
    /* Добавляем звук нажатия кнопки */
    effect.setSource(QUrl::fromLocalFile(":/tusya/CLUCK.wav"));
    effect.setVolume(0.50f);
    effect.play();

    close();
}

/* Кнопка старт */
void MainWindow::on_pushButton_clicked() // Старт.
{
    /* Добавляем звук нажатия кнопки */
    effect.setSource(QUrl::fromLocalFile(":/tusya/CLUCK.wav"));
    effect.setVolume(0.50f);
    effect.play();
    // Set up click handling etc.

    Form *f = new Form();

    f->show();
    f->setFixedSize(f->size());

    //    this->close();
}



void MainWindow::on_pushButton_2_clicked()
{
    /* Добавляем звук нажатия кнопки */
    effect.setSource(QUrl::fromLocalFile(":/tusya/CLUCK.wav"));
    effect.setVolume(0.50f);
    effect.play();
    QMessageBox::information(this, "Как играть?",
                             "Вам дано изображение, в начале игры его части перемешиваются"
                             "\nВаша задача - собрать изображение"
                             "\nДелать это можно лишь путем перемещения на пустую клетку другой,"
                             "\nсоседней с ней клетки (расположенной слева, справа, сверху или снизу от пустой). "
                             "Последняя клетка – пустая."
                             "\nЧтобы начать игру, нажмите кнопку Start "
                             "\nЧтобы выйти из игры, нажмите кнопку Exit"
                             );
}
