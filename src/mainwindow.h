#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QAction>
#include <QPushButton>
#include "scribblearea.h"
#include "digitprediction.h"
#include "string.h"
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class ScribbleArea;
class DigitPrediction;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setClassifier(std::string modelPath);

private slots:
    void about();
    void predict();
    void clear();

private:

    ScribbleArea *scribbleArea;
    DigitPrediction *classifier;
    QLabel *resultProb;
    QLabel *resultDigit;

    QPushButton *predictButton;
    QPushButton *clearButton;
    QMenu *helpMenu;
    QAction *clearScreenAct;
    QAction *aboutAct;
    void createActions();
    void createMenus();
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

