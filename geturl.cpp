#include "geturl.h"
#include "ui_geturl.h"

GetUrl::GetUrl(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GetUrl)
{
    ui->setupUi(this);
}

GetUrl::~GetUrl()
{
    delete ui;
}

void GetUrl::on_btn_open_clicked()
{

        /*QProcess process;
        QString filePath = "E:\\";
        filePath.replace("/", "\\"); // 只能识别 "\"
        QString cmd = QString("explorer.exe /select,\"%1\"").arg(filePath);
        qDebug() << cmd;
        process.startDetached(cmd);*/
        //QString file_path = QFileDialog::getExistingDirectory(this, "请选择文件路径...", "./");
        QString files = QFileDialog::getOpenFileName(
                                this,
                                "Select one or more files to open",
                                "d:/",
                                "Text files (*.txt)");
        //qDebug() << files;
        ui->lineEdit->setText(files);
        QFile file(files);


              //while (!file.atEnd()) {
                  //QByteArray line = file.readLine();
                  //qDebug() << line;
              //}
}



void GetUrl::on_parse_btn_clicked()
{
    QString filename = ui->lineEdit->text();
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
              return;
    QString lines;
    unsigned n = 0;
    if ((lines = ui->lineEdit_2->text()) != "") {

        qDebug() << lines.toInt();
        while (!file.atEnd() && n++ < lines.toUInt()) {
            QByteArray line = file.readLine();
            ui->textEdit->append(get_url(line));
        }
    } else if ((lines = ui->lineEdit_3->text()) != "") {
        while (!file.atEnd()) {
            QByteArray line = file.readLine();
            if (++n == lines.toUInt()) {
                //get_url(line);
                ui->textEdit->append(get_url(line));
            }
        }
    } else if (ui->lineEdit_4->text() != "" && ui->lineEdit_5->text() != "") {
        unsigned min, max;
        min = ui->lineEdit_4->text().toUInt();
        max = ui->lineEdit_5->text().toUInt();
        while (!file.atEnd()) {
            QByteArray line = file.readLine();
            n++;
            if (n <= max && n >= min)
                ui->textEdit->append(get_url(line));
        }
    } else {
        while (!file.atEnd()) {
            QByteArray line = file.readLine();
            ui->textEdit->append(get_url(line));
        }
    }

}



QString GetUrl::get_url(QString line) {
    QString pre = "rtsp";
    QString suffix = "</Url>";
    line.indexOf(pre);
    int n1, n2;
    n1 =line.indexOf(pre);
    n2 = line.indexOf(suffix);
    QString url = line.mid(n1, n2 - n1);
    //qDebug() << url;
    url.replace("&amp;", "&");
    return url;
}

void GetUrl::on_pushButton_clicked()
{
    ui->textEdit->clear();
}
