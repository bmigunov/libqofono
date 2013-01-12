/****************************************************************************
**
** Copyright (C) 2013 Jolla Ltd.
** Contact: lorn.potter@jollamobile.com
**

**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QOFONOCONNECTIONCONTEXT_H
#define QOFONOCONNECTIONCONTEXT_H

#include <QObject>
#include "dbustypes.h"

class QOfonoConnectionContextPrivate;

class QOfonoConnectionContext : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool active READ active WRITE setActive NOTIFY activeChanged)
    Q_PROPERTY(QString accessPointName READ accessPointName WRITE setAccessPointName NOTIFY accessPointNameChanged)
    Q_PROPERTY(QString type READ type WRITE setType NOTIFY nameChanged)
    Q_PROPERTY(QString username READ username WRITE setUsername NOTIFY usernameChanged)
    Q_PROPERTY(QString password READ password WRITE setPassword NOTIFY passwordChanged)
    Q_PROPERTY(QString protocol READ protocol WRITE setProtocol NOTIFY protocolChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString messageProxy READ messageProxy WRITE setMessageProxy NOTIFY messageProxyChanged)
    Q_PROPERTY(QString messageCenter READ messageCenter WRITE setMessageCenter NOTIFY messageCenterChanged)
    Q_PROPERTY(QVariantMap settings READ settings NOTIFY settingsChanged)
    Q_PROPERTY(QVariantMap IPv6Settings READ IPv6Settings NOTIFY IPv6SettingsChanged)

    Q_PROPERTY(QString contextPath READ contextPath WRITE setContextPath)

public:
    explicit QOfonoConnectionContext(QObject *parent = 0);
    ~QOfonoConnectionContext();

    void setContextPath(const QString &idPath);
    QString contextPath() const;

    bool active() const;
    void setActive(bool);

    QString accessPointName() const;
    void setAccessPointName(const QString &);

    QString type() const;
    void setType(const QString &);

    QString username() const;
    void setUsername(const QString &);

    QString password() const;
    void setPassword(const QString &);

    QString protocol() const;
    void setProtocol(const QString &);

    QString name() const;
    void setName(const QString &);

    QString messageProxy() const;
    void setMessageProxy(const QString &);

    QString messageCenter() const;
    void setMessageCenter(const QString &);

    QVariantMap settings() const;
    QVariantMap IPv6Settings() const;


Q_SIGNALS:
    void activeChanged(const bool);
    void accessPointNameChanged(const QString &apn);
    void nameChanged(const QString &name);
    void typeChanged(const QString &type);
    void usernameChanged(const QString &uname);
    void passwordChanged(const QString &pw);
    void protocolChanged(const QString &proto);
    void messageProxyChanged(const QString &proxy);
    void messageCenterChanged(const QString &msc);
    void settingsChanged(const QVariantMap&);
    void IPv6SettingsChanged(const QVariantMap&);

public slots:


private slots:
    void propertyChanged(const QString &property,const QDBusVariant &value);

private:
    QOfonoConnectionContextPrivate *d_ptr;
};

#endif // QOFONOCONNECTIONCONTEXT_H