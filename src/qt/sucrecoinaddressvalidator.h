// Copyright (c) 2011-2014 The Bitcoin Core developers
// Copyright (c) 2017 The Sucrecoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef SUCRECOIN_QT_SUCRECOINADDRESSVALIDATOR_H
#define SUCRECOIN_QT_SUCRECOINADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class SucrecoinAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit SucrecoinAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

/** Sucrecoin address widget validator, checks for a valid sucrecoin address.
 */
class SucrecoinAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit SucrecoinAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // SUCRECOIN_QT_SUCRECOINADDRESSVALIDATOR_H
