#include "turnRatioIntervalItemConfiguration.h"

turnRatioIntervalItemConfiguration::turnRatioIntervalItemConfiguration() : abstractTurnRatioItemConfiguration()
{
    // Fill vector of colors
    vectorOfColor.push_back(Qt::red);
    vectorOfColor.push_back(Qt::green);
    vectorOfColor.push_back(Qt::blue);
    vectorOfColor.push_back(Qt::cyan);
    vectorOfColor.push_back(Qt::magenta);
    vectorOfColor.push_back(Qt::yellow);
    vectorOfColor.push_back(Qt::gray);
    vectorOfColor.push_back(Qt::black);
    vectorOfColor.push_back(Qt::darkRed);
    vectorOfColor.push_back(Qt::darkGreen);
    vectorOfColor.push_back(Qt::darkBlue);
    vectorOfColor.push_back(Qt::darkCyan);
    vectorOfColor.push_back(Qt::darkMagenta);
    vectorOfColor.push_back(Qt::darkYellow);
    vectorOfColor.push_back(Qt::darkGray);
    vectorOfColor.push_back(Qt::lightGray);
}

const QColor &turnRatioIntervalItemConfiguration::getPlotEdgeColor(int index)
{
    return vectorOfColor.at(index % 16);
}

