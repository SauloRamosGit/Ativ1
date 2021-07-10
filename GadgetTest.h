#ifndef GADGETTEST_H
#define GADGETTEST_H

#include <QObject>
#include <QVariant>
#include <QMetaEnum>

namespace gadget{

Q_NAMESPACE

enum class PlayerType {
    NO_TYPE = 0,
    TANK,
    CHARACTER,
    SHIP
};
Q_ENUM_NS(PlayerType)



struct P2D {
    Q_GADGET
    Q_PROPERTY(float m_x MEMBER m_x)
    Q_PROPERTY(float m_y MEMBER m_y)
public:
    float m_x;
    float m_y;
};


struct Player {
    Q_GADGET

    Q_PROPERTY(gadget::PlayerType m_playerType MEMBER m_playerType )
    Q_PROPERTY(float m_speed MEMBER m_speed)
    Q_PROPERTY(quint16 m_ammunition MEMBER m_ammunition)
    Q_PROPERTY(bool m_active MEMBER m_active)
    Q_PROPERTY(quint8 m_numberOfCoordinates MEMBER m_numberOfCoordinates)
    Q_PROPERTY(P2D *m_coordinates MEMBER m_coordinates)
public:
    PlayerType m_playerType;
    float m_speed;
    quint16 m_ammunition;
    bool m_active;
    quint8 m_numberOfCoordinates = 3;
    P2D *m_coordinates;

};

};
Q_DECLARE_METATYPE(gadget::P2D)
Q_DECLARE_METATYPE(gadget::Player)





#endif // GADGETTEST_H
