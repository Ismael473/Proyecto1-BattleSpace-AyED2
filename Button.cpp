#include "Button.h"
#include <QGraphicsTextItem>
#include <QBrush>

/*!
 * \brief Button::Button
 * \param name, el nombre que lleva el boton
 * \param parent
 */
Button::Button(QString name, QGraphicsItem *parent): QGraphicsRectItem(parent)
{
    setRect(0,0,200,50); // Se crea el rectangulo que contendra al boton
    QBrush brush; // Se usa para poder colocarle color al boton
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkBlue);
    setBrush(brush);


    text = new QGraphicsTextItem(name,this); // Es el texto que lleva el boton
    int xPos = rect().width()/2 - text->boundingRect().width()/2;
    int yPos = rect().height()/2 - text->boundingRect().height()/2;
    text->setPos(xPos,yPos);

    // Con esto nos aseguramos de que el boton reacciones a los eventos de mouse
    setAcceptHoverEvents(true);
}

/*!
 * \brief Button::mousePressEvent
 * \param event, el click del mouse
 * \return no retorna nada
 */
void Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit clicked();
}

/*!
 * \brief Button::hoverEnterEvent
 * \param event, cuando el mouse se posiciona sobre el boton
 * \return no retorna nada
 */
void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::blue);
    setBrush(brush);
}
/*!
 * \brief Button::hoverLeaveEvent
 * \param event, cuando el mouse se aleja del boton
 * \return no retorna nada
 */
void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkBlue);
    setBrush(brush);
}


