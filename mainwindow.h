#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QtWidgets>
#include <QtCharts>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QSplineSeries *mSeries = new QSplineSeries();
    QSplineSeries *mSeries2 = new QSplineSeries();
    QDateTime curDateTIme = QDateTime::currentDateTime();

    QChartView *chartView;
};
#endif // MAINWINDOW_H
