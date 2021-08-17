#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QFont>
#include <QMenuBar>
#include <QStatusBar>
#include <QHBoxLayout>
#include <QString>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    setFixedSize(800, 600);
    setWindowTitle("LeNet number prediction");

    QHBoxLayout *scribbleLayout = new QHBoxLayout();
    scribbleArea = new ScribbleArea;
    scribbleArea->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    scribbleArea->setMinimumSize(550, 550);
    scribbleArea->setMaximumSize(550, 550);
    scribbleLayout->addWidget(scribbleArea);

    QHBoxLayout *predictedDigit = new QHBoxLayout();
    QLabel *labelDigit = new QLabel("Result:");
    resultDigit = new QLabel("");
    labelDigit->setFont(QFont("Arial", 20, 3));
    resultDigit->setFont(QFont("Arial", 20, 3));
    resultDigit->setStyleSheet("QLabel { color : red; }");
    predictedDigit->addWidget(labelDigit);
    predictedDigit->addWidget(resultDigit);

    QHBoxLayout *predictedProb = new QHBoxLayout();
    QLabel *labelProb = new QLabel("Probability:");
    resultProb = new QLabel("");
    labelProb->setFont(QFont("Arial", 20, 3));
    resultProb->setFont(QFont("Arial", 20, 3));
    resultProb->setStyleSheet("QLabel { color : red; }");
    predictedProb->addWidget(labelProb);
    predictedProb->addWidget(resultProb);

    QVBoxLayout *resultLayout = new QVBoxLayout();
    resultLayout->addLayout(predictedDigit);
    resultLayout->addLayout(predictedProb);

    QWidget *result = new QWidget();
    result->setLayout(resultLayout);

    QVBoxLayout *infoLayout = new QVBoxLayout();
    predictButton = new QPushButton("&Predict");
    clearButton = new QPushButton("&Clear");
    predictButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    predictButton->setMinimumSize(200, 60);
    predictButton->setMaximumSize(200, 60);
    clearButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    clearButton->setMinimumSize(200, 60);
    clearButton->setMaximumSize(200, 60);
    infoLayout->addWidget(result);
    infoLayout->addWidget(predictButton);
    infoLayout->addWidget(clearButton);
    infoLayout->setAlignment(Qt::AlignLeft);

    QHBoxLayout *mainLayout = new QHBoxLayout();
    mainLayout->addLayout(scribbleLayout);
    mainLayout->addLayout(infoLayout);

    QWidget *window = new QWidget();
    window->setLayout(mainLayout);

    setCentralWidget(window);

    // Create actions and menus
    createActions();
    createMenus();
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Open an about dialog
void MainWindow::about()
{
    // Window title and text to display
    QMessageBox::about(this, tr("About LeNet digit prediction"),
            tr("For futher information, please contact me via email."
               "<p><b>Email:</b> <a href='mailto:huydung.ng.179@gmail.com'>huydung.ng.179@gmail.com</a>  </p>"));
}

void MainWindow::setClassifier(std::string modelPath)
{
    std::cout << modelPath << std::endl;
    classifier = new DigitPrediction(modelPath);
}

void MainWindow::predict()
{
    classifier->predict(scribbleArea->getImage());
    resultDigit->setText(QString::number(classifier->digit));
    resultProb->setText(QString::number(round(classifier->prob*100)/100));
}

void MainWindow::clear()
{
    resultDigit->setText(QString(""));
    resultProb->setText(QString(""));
}

// Define menu actions that call functions
void MainWindow::createActions()
{
    // Create pen color action and tie to QMainWindow::predict()
    connect(predictButton, SIGNAL(clicked()), this, SLOT(predict()));

    // Create clear screen action and tie to QMainWindow::clearImage()
    connect(clearButton, SIGNAL(clicked()),
            scribbleArea, SLOT(clearImage()));
    connect(clearButton, SIGNAL(clicked()),
            this, SLOT(clear()));


    // Create about action and tie to QMainWindow::about()
    aboutAct = new QAction(tr("&About"), this);
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));
}

// Create the menubar
void MainWindow::createMenus()
{
    // Attach all actions to Help
    helpMenu = new QMenu(tr("&Help"), this);
    helpMenu->addAction(aboutAct);

    // Add menu items to the menubar
    menuBar()->addMenu(helpMenu);
}
