#include "Figure.h"

Figure::Figure(int size, int offsetX, int offsetY) :
    m_size(size),
    m_offsetX(offsetX),
    m_offsetY(offsetY),
    m_isDragging(false),
    m_previousX(0),
    m_previousY(0)
{
}

void Figure::moveTo(int x, int y)
{
    m_offsetX = x - m_size / 2;
    m_offsetY = y - m_size / 2;
}

void Figure::startDragging(int x, int y)
{
    m_isDragging = true;
    m_previousX = x;
    m_previousY = y;
}

void Figure::drag(int x, int y)
{
    if (m_isDragging)
    {
        m_offsetX += x - m_previousX;
        m_offsetY += y - m_previousY;
        m_previousX = x;
        m_previousY = y;
    }
}

bool Figure::isDragging() const
{
    return m_isDragging;
}

void Figure::stopDragging()
{
    m_isDragging = false;
}