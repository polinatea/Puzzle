#include "Game.h"
#include "MainWindow.h"
#include <QGridLayout>
#include <QPoint>
#include <QPushButton>
#include <ctime>
#include "QMessageBox"


Game::Game(QWidget*)
{
    grid = new QGridLayout(this);

    /* Расстояние между виджетами */
    grid->setHorizontalSpacing(2);
    grid->setVerticalSpacing(2);

    /* размер границ */
    grid->setContentsMargins(1, 1, 1, 1);


    /* Для разных чисел в рандоме */
    srand (time(NULL));

    /* Присваиваем картинки */
    for(int i=0;i<15;i++){
        if(i==0)px[i]=new QPixmap(":/tusya/1.jpg");    else if(i==7)px[i]=new QPixmap(":/tusya/8.jpg");
        else if(i==1)px[i]=new QPixmap(":/tusya/2.jpg");    else if(i==8)px[i]=new QPixmap(":/tusya/9.jpg");
        else if(i==2)px[i]=new QPixmap(":/tusya/3.jpg");    else if(i==9)px[i]=new QPixmap(":/tusya/10.jpg");
        else if(i==3)px[i]=new QPixmap(":/tusya/4.jpg");    else if(i==10)px[i]=new QPixmap(":/tusya/11.jpg");
        else if(i==4)px[i]=new QPixmap(":/tusya/5.jpg");    else if(i==11)px[i]=new QPixmap(":/tusya/12.jpg");
        else if(i==5)px[i]=new QPixmap(":/tusya/6.jpg");    else if(i==12)px[i]=new QPixmap(":/tusya/13.jpg");
        else if(i==6)px[i]=new QPixmap(":/tusya/7.jpg");    else if(i==13)px[i]=new QPixmap(":/tusya/14.jpg");
        else if(i==14)px[i]=new QPixmap(":/tusya/15.jpg");
    }
    //
    int n;

    do
    {

        /* Очищаем список */
        numbers.clear();

        /* Для каждого элемента от 0 до 15 */
        for(int i = 0; i < 15; i++)
        {
            do n = rand() % 15 + 1; // генерируем числа от 1 до 15
            while(numbers.contains(n)); // проверка, содержится ли в списке значение
            numbers << n; // заносим в список
        }

        n = 0;

    } while(n%2 == 1);

    /* устанавливаем края в заданные координаты */
    do path.setY(rand() % 4);
    while(n%2 != path.y()%2);

    path.setX(rand() % 4);

    n = 0;

    /* Заполняем ячейки игрового поля */
    for(int y = 0; y < 4; ++y) // строка
        for(int x = 0; x < 4; ++x) // столбец
        {
            if(path.x() == x && path.y() == y)
                continue;

            createButton(NULL, numbers[n++], x, y);
        }
    setLayout(grid);
}

void Game::move()
{
    int x, y, rs, cs;
    QPushButton* clickedBtn = static_cast<QPushButton*>(sender());
    grid->getItemPosition(grid->indexOf(clickedBtn), &y, &x, &rs, &cs);

    if((path.x() == x && (path.y() == y+1 || path.y() == y-1))
            || (path.y() == y && (path.x() == x+1 || path.x() == x-1))) // Можно ли двигать кнопку?
    {
        // удаляем кнопку со старого места
        grid->removeWidget(clickedBtn);
        // и добавляем на свободную ячейку
        createButton(clickedBtn, 0, path.x(), path.y());
        // и обновляем координаиы свободной ячейки
        path = QPoint(x, y);
        checkGameOver(); // проверка на конец игры
    }
}

void Game::checkGameOver()
{
    Q_ASSERT(grid->count() == numbers.size());

    int i=1, n=0;

    for(int y = 0; y < grid->rowCount(); ++y) // строка
        for(int x = 0; x < grid->columnCount(); ++x) // столбец
        {
            if(grid->itemAtPosition(y, x) == 0)
                continue;
            n = numbers.indexOf(i++);
            if(buttons[n] != (QPushButton*)grid->itemAtPosition(y, x)->widget())
                return;
        }

    /* Проверяем, если свободна последняя ячейка... */
    if(path.y() == grid->rowCount()-1 && path.x() == grid->columnCount()-1)
    { /* то игра окончена */
        /* блокируем все кнопки */
        for(QList<QPushButton*>::const_iterator it = buttons.begin(); it != buttons.end(); ++it)
            (*it)->setDisabled(true);
        QMessageBox::information(this, "message", "YOU ARE WIN!");
    }
}

void Game::createButton(QPushButton* b, int no, int x, int y) // Создание кнопки
{
    QPushButton* btn = b;
    if(!btn)
    {
        btn = new QPushButton();
        buttons << btn;
        connect(btn, SIGNAL(clicked()), this, SLOT(move()));
        btn->setFixedSize(150,150);

        QIcon ButtonIcon(*px[no-1]);
        btn->setIcon(ButtonIcon);
        btn->setIconSize(QSize(150,150));

    }
    grid->addWidget(btn, y, x);
}
