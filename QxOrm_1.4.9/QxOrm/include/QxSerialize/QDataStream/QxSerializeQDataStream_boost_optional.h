/****************************************************************************
**
** https://www.qxorm.com/
** Copyright (C) 2013 Lionel Marty (contact@qxorm.com)
**
** This file is part of the QxOrm library
**
** This software is provided 'as-is', without any express or implied
** warranty. In no event will the authors be held liable for any
** damages arising from the use of this software
**
** Commercial Usage
** Licensees holding valid commercial QxOrm licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Lionel Marty
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file 'license.gpl3.txt' included in the
** packaging of this file. Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met : http://www.gnu.org/copyleft/gpl.html
**
** If you are unsure which license is appropriate for your use, or
** if you have questions regarding the use of this file, please contact :
** contact@qxorm.com
**
****************************************************************************/

#ifdef _QX_ENABLE_BOOST
#ifndef _QX_SERIALIZE_QDATASTREAM_BOOST_OPTIONAL_H_
#define _QX_SERIALIZE_QDATASTREAM_BOOST_OPTIONAL_H_

#ifdef _MSC_VER
#pragma once
#endif

/*!
 * \file QxSerializeQDataStream_boost_optional.h
 * \author Lionel Marty
 * \ingroup QxSerialize
 * \brief Provide a Qt QDataStream serialization method (save/load) for type boost::optional<T>
 */

#include <QtCore/qdatastream.h>

template <typename T>
QDataStream & operator<< (QDataStream & stream, const boost::optional<T> & t)
{
   qint8 iHasData = (t ? 1 : 0);
   stream << iHasData;
   if (t) { stream << (* t); }
   return stream;
}

template <typename T>
QDataStream & operator>> (QDataStream & stream, boost::optional<T> & t)
{
   qint8 iHasData = 0;
   stream >> iHasData;
   if (iHasData) { t = T(); stream >> (* t); }
   else { t = boost::none; }
   return stream;
}

#endif // _QX_SERIALIZE_QDATASTREAM_BOOST_OPTIONAL_H_
#endif // _QX_ENABLE_BOOST
