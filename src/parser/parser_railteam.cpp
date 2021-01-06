/****************************************************************************
**
**  This file is a part of Fahrplan.
**
**  This program is free software; you can redistribute it and/or modify
**  it under the terms of the GNU General Public License as published by
**  the Free Software Foundation; either version 2 of the License, or
**  (at your option) any later version.
**
**  This program is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
**  GNU General Public License for more details.
**
**  You should have received a copy of the GNU General Public License along
**  with this program.  If not, see <http://www.gnu.org/licenses/>.
**
****************************************************************************/

#include "parser_railteam.h"

ParserRailteam::ParserRailteam(QObject *parent)
    : ParserHafasBinary(parent)
{
    baseXmlUrl = "http://railteam.hafas.de/bin/query.exe";
    baseSTTableUrl = "http://railteam.hafas.de/bin/stboard.exe/en";
    baseUrl = "http://railteam.hafas.de/bin/query.exe";
    baseBinaryUrl = "http://railteam.hafas.de/bin/query.exe/en";
    STTableMode = 1;
}

QStringList ParserRailteam::getTrainRestrictions()
{
    QStringList result;
    result.append(tr("All"));
    result.append(tr("All without ICE, TGV"));
    return result;
}

QString ParserRailteam::getTrainRestrictionsCodes(int trainrestrictions)
{
    QString trainrestr = "1111111111010000";
    if (trainrestrictions == 0) {
        trainrestr = "1111111111010000"; //ALL
    } else if (trainrestrictions == 1) {
        trainrestr = "0111111111010000"; //All without ICE, TGV
    } 
    return trainrestr;
}
