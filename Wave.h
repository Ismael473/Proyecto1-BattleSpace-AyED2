#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

/*!
 * \brief The Wave class
 */
class Wave: public QGraphicsTextItem{
public:
    Wave(QGraphicsItem * parent=0);
    void aumentar();
    int getWave();
private:
    int wave;
};

#endif // SCORE_H
