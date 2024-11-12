#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_CNC_Simulator.h"

class CNC_Simulator : public QMainWindow
{
    Q_OBJECT

public:
    CNC_Simulator(QWidget *parent = nullptr);
    ~CNC_Simulator();

private:
    Ui::CNC_SimulatorClass ui;
};
