#ifndef GETURL_H
#define GETURL_H

#include <QMainWindow>
#include <QProcess>
#include <QDebug>
#include <QFileDialog>
namespace Ui {
class GetUrl;
}


class GetUrl : public QMainWindow
{
    Q_OBJECT

public:
    explicit GetUrl(QWidget *parent = nullptr);
    ~GetUrl();

private slots:
    void on_btn_open_clicked();

    void on_parse_btn_clicked();
    QString get_url(QString line);
    void on_pushButton_clicked();

private:
    Ui::GetUrl *ui;
};

#endif // GETURL_H
