#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox.h>
#include <QProcess>
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  ui->checkBox->setChecked(true);//默认打钩

}

MainWindow::~MainWindow()
{
  delete ui;

}




void MainWindow::on_pushButton_clicked()
{
    if(ui->checkBox->isChecked())
      {
        QProcess::execute("defaults write com.apple.finder AppleShowAllFiles -bool true");
        QProcess::execute("killall Finder");
        //QMessageBox::information(this, "Done!","Success! Now, you can see hidden files.");
      }
    else
      {
        QProcess::execute("defaults write com.apple.finder AppleShowAllFiles -bool false");
        QProcess::execute("killall Finder");
        //QMessageBox::information(this, "Done!","Success! Now, you can't see hidden files.");
      }

}

void MainWindow::on_actionDoes_Not_Work_triggered()
{
  QMessageBox::information(this, "Help","If you don't see the results, you may:<p><li>1.Refresh \"<b>Finder</b>\".</li><li>2.Relaunch \"<b>Finder</b>\".</li><p>If that doesn't work, Could you please report the bug to me?  <a href=\"mailto:zhenghanecho@gmail.com\">E-Mail Link</a></p><p>Thanks for supporting!</p>");
}


void MainWindow::on_actionAbout_us_triggered()
{
  QMessageBox::information(this, "About","<p>Ultrasilicon:</p><li><a href=\"mailto:zhenghanecho@gmail.com\">E-Mail: zhenghanecho@gmail.com</a></li><li>Hangzhou Foreign Languages School</li><li>By <i>Tim Zheng</i></li>");
}





