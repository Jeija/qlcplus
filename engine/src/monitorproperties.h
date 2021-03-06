/*
  Q Light Controller Plus
  monitorproperties.h

  Copyright (c) Massimo Callegari

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0.txt

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
*/

#ifndef MONITORPROPERTIES_H
#define MONITORPROPERTIES_H

#include <QPointF>
#include <QFont>
#include <QSize>
#include <QHash>

class QDomDocument;
class QDomElement;

#define KXMLQLCMonitorProperties "Monitor"

class MonitorProperties
{
public:
    MonitorProperties();

    enum DisplayMode { DMX, Graphics };
    enum ChannelStyle { DMXChannels, RelativeChannels };
    enum ValueStyle { DMXValues, PercentageValues };
    enum GridUnits { Meters, Feet };

    void setFont(QFont font) { m_font = font; }
    QFont font() const { return m_font; }

    void setDisplayMode(DisplayMode mode) { m_displayMode = mode; }
    DisplayMode displayMode() const { return m_displayMode; }

    void setChannelStyle(ChannelStyle style) { m_channelStyle = style; }
    ChannelStyle channelStyle() const { return m_channelStyle; }

    void setValueStyle(ValueStyle style) { m_valueStyle = style; }
    ValueStyle valueStyle() const { return m_valueStyle; }

    void setGridSize(QSize size) { m_gridSize = size; }
    QSize gridSize() const { return m_gridSize; }

    void setGridUnits(GridUnits units) { m_gridUnits = units; }
    GridUnits gridUnits() const { return m_gridUnits; }

    void setFixturePosition(quint32 fid, QPointF pos);
    QList <quint32> fixtureItemsID() const { return m_fixtureItems.keys(); }
    QPointF fixturePosition(quint32 fid) const { return m_fixtureItems[fid]; }

private:
    QFont m_font;
    DisplayMode m_displayMode;
    ChannelStyle m_channelStyle;
    ValueStyle m_valueStyle;
    QSize m_gridSize;
    GridUnits m_gridUnits;
    QHash <quint32, QPointF> m_fixtureItems;

    /*********************************************************************
     * Load & Save
     *********************************************************************/
public:
    /**
     * Load the Monitor properties from the given XML node.
     *
     * @param root An XML subtree containing the Monitor properties
     * @return true if the properties were loaded successfully, otherwise false
     */
    bool loadXML(const QDomElement& root);

    /**
     * Save the Monitor properties into an XML document, under the given
     * XML element (tag).
     *
     * @param doc The master XML document to save to.
     * @param wksp_root The workspace root element
     */
    bool saveXML(QDomDocument* doc, QDomElement* wksp_root) const;
};

#endif // MONITORPROPERTIES_H
