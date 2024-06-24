#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

        qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));

        // X axis (timeline method)
        QDateTimeAxis * AxisX = new QDateTimeAxis();
        AxisX->setTitleText("Time (minute: second)");                                  // X -axis display title
        AxisX->setGridLineVisible(false);                                   // Hide the background grid x axis frame line
        AxisX->setFormat("mm:ss");                                          // x axis format
        AxisX->setLabelsAngle(0);                                           // The text displayed in the x axis
        AxisX->setTickCount(10);                                            // Number of points on the axis
        AxisX->setRange(curDateTIme, curDateTIme.addSecs(10));              // scope

        // Y axis
        QValueAxis *AxisY = new QValueAxis();
        AxisY->setTitleText("angle");                                         // Y axis display title
        AxisY->setRange(0, 20);                                             // scope
        AxisY->setTickCount(11);                                            // Number of points on the axis
        AxisY->setGridLineVisible(false);                                   // Hide the background grid y -axial frame line

        // Chart
        QChart *chart = new QChart();
        chart->setAnimationOptions(QChart::SeriesAnimations);               // Animation method

        // Chart view
        chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);                   // Anti -sawtooth drawing
        chartView->chart()->addSeries(mSeries);                             // Add a line segment
        chartView->chart()->addSeries(mSeries2);                            // Add a line segment
        chartView->chart()->setTheme(QtCharts::QChart::ChartThemeBlueNcs);  // Set the topic
        chartView->chart()->setTitle("Activity angle data");                           // Set the title
        chartView->chart()->addAxis(AxisX, Qt::AlignBottom);                // Set the X -axis position
        chartView->chart()->addAxis(AxisY, Qt::AlignLeft);                  // Set the y -axis position

        // line segment 1
        mSeries->setPen(QPen(Qt::red, 0.6, Qt::SolidLine));                 // Set the line segment PEN
        mSeries->attachAxis(AxisX);                                         // The X -axis attached to the line segment
        mSeries->attachAxis(AxisY);                                         // The y -axis attached to the line segment
        mSeries->setName("algorithm");                                            // Line segment name, in the legend, display
        for(unsigned short index=0;index<=10;++index)
        {
            QDateTime temp_AddTimePos = curDateTIme.addSecs(index);
            if(temp_AddTimePos >= curDateTIme.addSecs(11)){return;}
            mSeries->append(temp_AddTimePos.toMSecsSinceEpoch(), qrand()%18+2);
        }

        // line segment 2
        mSeries2->setPen(QPen(Qt::blue, 0.6, Qt::SolidLine));
        mSeries2->attachAxis(AxisY);
        mSeries2->attachAxis(AxisX);
        mSeries2->setName("Measurement");
        for(unsigned short index=0;index<=10;++index)
        {
            QDateTime temp_AddTimePos = curDateTIme.addSecs(index);
            if(temp_AddTimePos >= curDateTIme.addSecs(11)){return;}
            mSeries2->append(temp_AddTimePos.toMSecsSinceEpoch(), qrand()%18);
        }

        // Legend
        chart->legend()->setVisible(true);                                  // Legend display
        chart->legend()->setAlignment(Qt::AlignTrailing);                   // Label to live downwards

        // Throw the chart into qwidget
        setCentralWidget(chartView);
}

MainWindow::~MainWindow()
{
    delete ui;
}

