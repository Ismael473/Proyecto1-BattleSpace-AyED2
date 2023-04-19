#ifndef BUTTON_H
#define BUTTON_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

/*!
 * \brief The Button class
 * \param no recibe parametros
 */
class Button:public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    // Constructor
    Button(QString name, QGraphicsItem* parent = NULL);

    //Metodos
    void mousePressEvent(QGraphicsSceneMouseEvent *event); //Esta funcion se usa cuando se da click sobre un boton
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

signals:
    void clicked();
private:
    QGraphicsTextItem * text;
};

#endif // BUTTON_H
