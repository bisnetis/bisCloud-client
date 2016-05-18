/*
 * Copyright (C) by Klaas Freitag <freitag@owncloud.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 */

#include <QtCore>

#include "activitydata.h"


namespace OCC
{

bool operator<( const Activity& rhs, const Activity& lhs ) {
    return rhs._dateTime.toMSecsSinceEpoch() > lhs._dateTime.toMSecsSinceEpoch();
}

bool operator==( const Activity& rhs, const Activity& lhs ) {
    return (rhs._type == lhs._type && rhs._id== lhs._id && rhs._accName == lhs._accName);
}

Activity::Identifier Activity::ident() const {
    return Identifier( _id, _accName );
}

/* ==================================================================== */

ActivityList::ActivityList()
    :_lastId(0)
{

}

void ActivityList::setAccountName( const QString& name )
{
    _accountName = name;
}

QString ActivityList::accountName() const
{
    return _accountName;
}

int ActivityList::lastId() const
{
    return _lastId;
}

}
