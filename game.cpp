#include "game.h"

game::game(QWidget *parent)
{
    //Creating a scene and setting the background
    myScene = new QGraphicsScene();
    myScene->setSceneRect(0,0,1200,900);
    setScene(myScene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1200,900);
    setBackgroundBrush(QBrush(QImage(":/images/background.png")));


    //Creating my player
    myPlayer = new player();
    myPlayer->setFlag(QGraphicsItem::ItemIsFocusable);
    myPlayer->setFocus();
    myPlayer->setPos(600,700);

    //Adding the player to the scene
    myScene->addItem(myPlayer);

    //Showing the score
    myScore = new score();
    myScene->addItem(myScore);

    //Showing health
    myHealth = new health();
    myHealth->setPos(myHealth->x(),myHealth->y()+25);
    myScene->addItem(myHealth);

    //Spawning enemies
    myTimer = new QTimer();
    connect(myTimer,SIGNAL(timeout()),myPlayer,SLOT(spawn()));
    myTimer->start(1500);

    //Spawning life
    QTimer *lifeTimer = new QTimer();
    connect(lifeTimer,SIGNAL(timeout()),myPlayer,SLOT(spawnLife()));
    lifeTimer->start(15000);

    //Including background music
    bgMusic = new QMediaPlayer();
    bgMusic->setMedia(QUrl("qrc:/sounds/bgMusic.mp3"));
    if(bgMusic->state() == QMediaPlayer::PlayingState){

    }else if (bgMusic->state() == QMediaPlayer::StoppedState){

        bgMusic->play();
    }

}

void game::closeAll()
{
   bgMusic->stop();
   myTimer->stop();

}

