#ifndef STRUCTS_H
#define STRUCTS_H
#include <QVector>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "Collections.h"

struct town
{
    int idx;
    int armor;
    int armor_capacity;
    int products;
    int products_capacity;
    QString name;
    QString player_idx;
    int point_idx;
    int population;
    int population_capacity;
    int level;
    int price;
};

struct player
{
    QString idx;
    bool in_game;
    QString name;
    int rating;
    int home_idx;
    int home_post_idx;
    QString player_idx;
};

struct train
{
    QString player_idx;
    int idx;
    int goods;
    int goods_capacity;
    int goods_type;
    int line_idx;
    int position;
    int speed;
    int level;
    int price;
};

struct market
{
  QString name;
  int idx;
  int point_idx;
  int goods;
  int goods_capacity;
  int replenishment;
  int type;
  int mark;
};

struct post
{
  int idx;
  int point_idx;
  int type;
};

struct game
{
    QString gameName;
    int numberOfPlayers;
    int numberOfTurns;
    GameState gameState;
};

class Player
{
private:
    player playerData;
    QVector<train> playerTrains;
public:
    Player(){}
    ~Player(){}
    void Pars(QJsonDocument doc);
    player getPlayerData();
    QVector <train> getPlayerTrains();
    void setTrains(QVector <train> Trains);
};

class Map0 //если будет нужно позже я добавлю те пункты, пока что их предназначение в это мире не ясно
{
private:
    QVector <int> pointsOfGraph;
    QVector <QVector <int> > Table;
public:
    Map0(){}
    ~Map0(){}
    void Pars(QJsonDocument doc);
    QVector <int> getterPointsOfgraph();
    QVector <QVector <int> > getterTable();
};

class Map1
{
private:
    QVector <post> Posts;
    QVector <market> Markets;
    QVector <market> Storages;
    QVector <town> Towns;
    QVector <train> AllTrains;
    int tick;
    int population;
    int products;
    int armor;
    int level;
    int price;
public:
    Map1(){}
    void Pars(QJsonDocument doc);
    QVector <post> getterPosts();
    QVector <market> getterMarkets();
    QVector <market> getterStorages();
    int getTick();
    QVector <train> getTrains();
    town getHome(QString player_idx);
    ~Map1(){}
};

class ExistingGames
{
private:
    QVector <game> games;
public:
    ExistingGames(){}
    ~ExistingGames(){}
    void Pars(QJsonDocument doc);
    QVector <game> getGames();
};

#endif // STRUCTS_H
