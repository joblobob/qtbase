/****************************************************************************
**
** Copyright (C) 2014 Governikus GmbH & Co. KG.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtNetwork module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl-3.0.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or (at your option) the GNU General
** Public license version 3 or any later version approved by the KDE Free
** Qt Foundation. The licenses are as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-2.0.html and
** https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QSSLPRESHAREDKEYAUTHENTICATOR_H
#define QSSLPRESHAREDKEYAUTHENTICATOR_H

#include <QtNetwork/qtnetworkglobal.h>
#include <QtCore/QString>
#include <QtCore/QSharedDataPointer>
#include <QtCore/QMetaType>

QT_BEGIN_NAMESPACE

class QSslPreSharedKeyAuthenticatorPrivate;

class QSslPreSharedKeyAuthenticator
{
public:
    Q_NETWORK_EXPORT QSslPreSharedKeyAuthenticator();
    Q_NETWORK_EXPORT ~QSslPreSharedKeyAuthenticator();
    Q_NETWORK_EXPORT QSslPreSharedKeyAuthenticator(const QSslPreSharedKeyAuthenticator &authenticator);
    Q_NETWORK_EXPORT QSslPreSharedKeyAuthenticator &operator=(const QSslPreSharedKeyAuthenticator &authenticator);

#ifdef Q_COMPILER_RVALUE_REFS
    QSslPreSharedKeyAuthenticator &operator=(QSslPreSharedKeyAuthenticator &&other) Q_DECL_NOTHROW { swap(other); return *this; }
#endif

    void swap(QSslPreSharedKeyAuthenticator &other) Q_DECL_NOTHROW { qSwap(d, other.d); }

    Q_NETWORK_EXPORT QByteArray identityHint() const;

    Q_NETWORK_EXPORT void setIdentity(const QByteArray &identity);
    Q_NETWORK_EXPORT QByteArray identity() const;
    Q_NETWORK_EXPORT int maximumIdentityLength() const;

    Q_NETWORK_EXPORT void setPreSharedKey(const QByteArray &preSharedKey);
    Q_NETWORK_EXPORT QByteArray preSharedKey() const;
    Q_NETWORK_EXPORT int maximumPreSharedKeyLength() const;

private:
    friend Q_NETWORK_EXPORT bool operator==(const QSslPreSharedKeyAuthenticator &lhs, const QSslPreSharedKeyAuthenticator &rhs);
    friend class QSslSocketBackendPrivate;
    friend class QDtlsPrivateOpenSSL;

    QSharedDataPointer<QSslPreSharedKeyAuthenticatorPrivate> d;
};

inline bool operator!=(const QSslPreSharedKeyAuthenticator &lhs, const QSslPreSharedKeyAuthenticator &rhs)
{
    return !operator==(lhs, rhs);
}

Q_DECLARE_SHARED(QSslPreSharedKeyAuthenticator)

QT_END_NAMESPACE

Q_DECLARE_METATYPE(QSslPreSharedKeyAuthenticator)
Q_DECLARE_METATYPE(QSslPreSharedKeyAuthenticator*)

#endif // QSSLPRESHAREDKEYAUTHENTICATOR_H
