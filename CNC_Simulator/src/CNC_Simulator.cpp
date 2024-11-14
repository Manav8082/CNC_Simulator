#include "CNC_Simulator.h"
#include <QGridLayout>
#include <QFileDialog>
#include "OBJReader.h"
#include "PathCreator.h"
using namespace std;

void CNC_Simulator::setupUi()
{
    loadFile = new QPushButton("Load File", this);
    simulate = new QPushButton("Simulate", this);
    openglWindow = new OpenGlWidget(this);

    QGridLayout* layout = new QGridLayout(this);

    layout->addWidget(loadFile, 0, 0, 1, 2);
    layout->addWidget(simulate, 0, 2, 1, 2);
    layout->addWidget(openglWindow, 1, 0, 1, 3);

    QWidget* centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    centralWidget->setLayout(layout);
}

OpenGlWidget::Data CNC_Simulator::convertTrianglulationToGraphicsObject(const Triangulation& inTriangulation)
{
    OpenGlWidget::Data data;
    for (Triangle triangle : inTriangulation.Triangles)
    {
        for (Point point : triangle.Points())
        {
            data.vertices.push_back(inTriangulation.uniqueNumbers[point.X()]);
            data.vertices.push_back(inTriangulation.uniqueNumbers[point.Y()]);
            data.vertices.push_back(inTriangulation.uniqueNumbers[point.Z()]);
        }

        Point normal = triangle.Normal();

        for (size_t i = 0; i < 3; i++)
        {
            data.normals.push_back(inTriangulation.uniqueNumbers[normal.X()]);
            data.normals.push_back(inTriangulation.uniqueNumbers[normal.Y()]);
            data.normals.push_back(inTriangulation.uniqueNumbers[normal.Z()]);
        }
    }
    return data;
}

CNC_Simulator::CNC_Simulator(QWidget *parent)
    : QMainWindow(parent)
{
    setupUi();

    connect(loadFile, &QPushButton::clicked, this, &CNC_Simulator::onLoadFileClick);
    connect(simulate, &QPushButton::clicked, this, &CNC_Simulator::onSimulateClick);
}

CNC_Simulator::~CNC_Simulator()
{}

void CNC_Simulator::onSimulateClick()
{
    PathCreator pc;
    vector<vector<SurfacePoint>> vectorOfPoints = pc.createPath(inTri, 0.866000, -0.866000);
    OpenGlWidget::Data data = convertTrianglulationToGraphicsObject(inTri);
    
    vector<SurfacePoint> pts;
    for (auto vec : vectorOfPoints)
    {
        for (auto point : vec)
        {
            pts.push_back(point);
        }
    }

    openglWindow->setData(pts);
}

void  CNC_Simulator::onLoadFileClick()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open File"), "", tr("files (*.stl *.obj)"));

    if (!fileName.isEmpty())
    {
        inputFilePath = fileName;
        readFile(inputFilePath);
    }
    else
    {
        msgBox.setText("No file was selected");
        msgBox.exec();
    }
}

void CNC_Simulator::readFile(const QString& inFileName)
{
    if (inFileName.endsWith(".obj", Qt::CaseInsensitive))
    {
        OBJReader reader;
        reader.read(inFileName.toStdString(), inTri);
    }
    /*else if (inFileName.endsWith(".stl", Qt::CaseInsensitive))
    {
        STLReader reader;
        reader.read(inFileName.toStdString(), inTri);
    }*/
}
