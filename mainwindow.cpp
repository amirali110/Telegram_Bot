#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QTimer>
#include <QEventLoop>
#include <QNetworkReply>
#include <QNetworkProxy>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>


void MainWindow::fin(QString symbol1,QString symbol2,QString symbol3,QString symbol4,QString symbol5,QString symbol6,QString symbol7,QString symbol8){


QNetworkAccessManager acc;
QNetworkRequest req;
QEventLoop event1;
QJsonDocument doc;
QJsonObject obj;



    req.setUrl(QUrl("https://api3.binance.com/api/v3/ticker/price?symbol="+symbol1));
    QNetworkReply *rep1=acc.get(req);
    connect(rep1,SIGNAL(finished()),&event1,SLOT(quit()));
    event1.exec();

    doc=QJsonDocument::fromJson(rep1->readAll());
    obj=doc.object();
    QString price1=obj.value("price").toString();





    req.setUrl(QUrl("https://api3.binance.com/api/v3/ticker/price?symbol="+symbol2));
    QNetworkReply *rep2=acc.get(req);
    connect(rep2,SIGNAL(finished()),&event1,SLOT(quit()));
    event1.exec();

    doc=QJsonDocument::fromJson(rep2->readAll());
    obj=doc.object();
    QString price2=obj.value("price").toString();




    req.setUrl( (QUrl("https://api3.binance.com/api/v3/ticker/price?symbol="+symbol3)));
    QNetworkReply *rep3=acc.get(req);
    connect(rep3,SIGNAL(finished()),&event1,SLOT(quit()));
    event1.exec();

    doc=QJsonDocument::fromJson(rep3->readAll());
    obj=doc.object();
    QString price3=obj.value("price").toString();




    req.setUrl( (QUrl("https://api3.binance.com/api/v3/ticker/price?symbol="+symbol4)));
    QNetworkReply *rep4=acc.get(req);
    connect(rep4,SIGNAL(finished()),&event1,SLOT(quit()));
    event1.exec();

    doc=QJsonDocument::fromJson(rep4->readAll());
    obj=doc.object();
    QString price4=obj.value("price").toString();




   req.setUrl( (QUrl("https://api3.binance.com/api/v3/ticker/price?symbol="+symbol5)));
   QNetworkReply *rep5=acc.get(req);
   connect(rep5,SIGNAL(finished()),&event1,SLOT(quit()));
   event1.exec();

   doc=QJsonDocument::fromJson(rep5->readAll());
   obj=doc.object();
   QString price5=obj.value("price").toString();




   req.setUrl( (QUrl("https://api3.binance.com/api/v3/ticker/price?symbol="+symbol6)));
   QNetworkReply *rep6=acc.get(req);
   connect(rep6,SIGNAL(finished()),&event1,SLOT(quit()));
   event1.exec();

   doc=QJsonDocument::fromJson(rep6->readAll());
   obj=doc.object();
   QString price6=obj.value("price").toString();




   req.setUrl( (QUrl("https://api3.binance.com/api/v3/ticker/price?symbol="+symbol7)));
   QNetworkReply *rep7=acc.get(req);
   connect(rep7,SIGNAL(finished()),&event1,SLOT(quit()));
   event1.exec();

   doc=QJsonDocument::fromJson(rep7->readAll());
   obj=doc.object();
   QString price7=obj.value("price").toString();




   req.setUrl( (QUrl("https://api3.binance.com/api/v3/ticker/price?symbol="+symbol8)));
   QNetworkReply *rep8=acc.get(req);
   connect(rep8,SIGNAL(finished()),&event1,SLOT(quit()));
   event1.exec();

   doc=QJsonDocument::fromJson(rep8->readAll());
   obj=doc.object();
   QString price8=obj.value("price").toString();


//------------------------------------------------------------------------------------------------- CRYPTO


    ui->text->setFontPointSize(10);
    ui->text->append(symbol1+":"+price1);
    ui->text->append(symbol2+":"+price2);
    ui->text->append(symbol3+":"+price3);
    ui->text->append(symbol4+":"+price4);
    ui->text->append(symbol5+":"+price5);
    ui->text->append(symbol6+":"+price6);
    ui->text->append(symbol7+":"+price7);
    ui->text->append(symbol8+":"+price8);
    ui->text->append(QDateTime::currentDateTime().toString());



    QString first_emoji="\x31\xE2\x83\xA3";

    QEventLoop event2;
    QNetworkAccessManager acc2;
    QNetworkRequest req2;                                                                      //Im so sorry for The following line   :)

    req2.setUrl(QUrl("https://api.telegram.org/bot<yourbottoken>/sendMessage?chat_id=<yourchannelusername>&text="+first_emoji+symbol1+": "+price1+"\xF0\x9F\x92\xB2"+'\n'+"\x32\xE2\x83\xA3"+symbol2+": "+price2+"\xF0\x9F\x92\xB2"+'\n'+"\x33\xE2\x83\xA3"+symbol3+": "+price3+"\xF0\x9F\x92\xB2"+'\n'+"\x34\xE2\x83\xA3"+symbol4+": "+price4+"\xF0\x9F\x92\xB2"+'\n'+"\x35\xE2\x83\xA3"+symbol5+": "+price5+"\xF0\x9F\x92\xB2"+'\n'+"\x36\xE2\x83\xA3"+symbol6+": "+price6+"\xF0\x9F\x92\xB2"+'\n'+"\x37\xE2\x83\xA3"+symbol7+": "+price7+"\xF0\x9F\x92\xB2"+'\n'+"\x38\xE2\x83\xA3"+symbol8+": "+price8+"\xF0\x9F\x92\xB2"+'\n'+'\n'+'\n'+"\xF0\x9F\x95\x92"+QDateTime::currentDateTime().toString()+'\n'+"-------------------------------------"+'\n'+'\n'+'\n'+'\n'+"\xF0\x9F\x93\x88"+"@Crypto_Price_Get"+'\n'));         //Post request to telegram servers (send message)

    QNetworkReply * rep10=acc2.post(req2,QByteArray(NULL));
    connect(rep10,SIGNAL(finished()),&event2,SLOT(quit()));
    event2.exec();



    ui->text->append(rep10->readAll());
    ui->text->append("----------------------------------------------------------------------------------------------------------");



}



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

  
}


MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{


    ui->text->append("Started !");
    ui->text->append(QDateTime::currentDateTime().toString());
    ui->text->append("*");
    ui->text->append("*");
    ui->text->append("*");
    ui->text->append("*");
    ui->text->append("*");

  QTimer *timer = new QTimer(this);


  connect(timer,&QTimer::timeout,this,[=](){MainWindow::fin("BTCUSDT","ETHUSDT","XRPUSDT","XRPBTC","BNBUSDT","ADAUSDT","LINKUSDT","XLMUSDT");});

  timer->start(300000);



}







