#ifndef GADGETTEST_H
#define GADGETTEST_H

#include <QObject>
#include <QVariant>

struct P2D {
    Q_GADGET
    Q_PROPERTY(float m_x READ getm_x)
    Q_PROPERTY(float m_y READ getm_y)
public:
    float m_x;
    float m_y;

    float getm_x () const { return m_x ; }
    float getm_y () const { return m_y ; }
};Q_DECLARE_METATYPE(P2D)

enum class PlayerType {
    NO_TYPE = 0,
            TANK,
            CHARACTER,
            SHIP
};
Q_DECLARE_METATYPE(PlayerType)

struct Player {
    Q_GADGET

    Q_PROPERTY(PlayerType m_playerType MEMBER m_playerType )
    Q_PROPERTY(float m_speed READ getm_speed)
    Q_PROPERTY(quint16 m_ammunition READ getm_ammunition)
    Q_PROPERTY(bool m_active READ getm_active)
    Q_PROPERTY(quint8 m_numberOfCoordinates READ getm_numberOfCoordinates)
    Q_PROPERTY(P2D *m_coordinates READ getm_coordinates)
public:
    PlayerType m_playerType;
    float m_speed;
    quint16 m_ammunition;
    bool m_active;
    quint8 m_numberOfCoordinates = 10;
    P2D *m_coordinates;

    float getm_speed () const { return m_speed; }
    quint16 getm_ammunition () const { return m_ammunition ; }
    bool getm_active () const { return m_active ; }
    quint8 getm_numberOfCoordinates () const { return m_numberOfCoordinates ; }
    P2D * getm_coordinates () const { return m_coordinates ; }
    PlayerType getm_playerType() const { return m_playerType; }

};

Q_DECLARE_METATYPE(Player)

//Q_ENUM(PlayerType)
//Q_DECLARE_METATYPE(PlayerType)
class GadgetTest : public QObject
{

    Q_OBJECT

public:
    GadgetTest();


    //  Q_ENUM(PlayerType)

signals:





};
#endif // GADGETTEST_H
