#include "DeclarativeDropArea.h"
#include <QGraphicsSceneDragDropEvent>
#include <QMimeData>

DeclarativeDropArea::DeclarativeDropArea(QDeclarativeItem *parent)
	: QDeclarativeItem(parent),
	m_enabled(true)
{
	setAcceptDrops(m_enabled);
}

void DeclarativeDropArea::dragEnterEvent(QGraphicsSceneDragDropEvent *event) {
	DeclarativeDragDropEvent dde(event, this);
	emit dragEnter(&dde);
}

void DeclarativeDropArea::dragLeaveEvent(QGraphicsSceneDragDropEvent *event)
{
	DeclarativeDragDropEvent dde(event, this);
	emit dragLeave(&dde);
}

void DeclarativeDropArea::dropEvent(QGraphicsSceneDragDropEvent *event)
{
	DeclarativeDragDropEvent dde(event, this);
	emit drop(&dde);
}

bool DeclarativeDropArea::isEnabled() const
{
	return m_enabled;
}

void DeclarativeDropArea::setEnabled(bool enabled)
{
	if (enabled == m_enabled) {
		return;
	}

	m_enabled = enabled;
	setAcceptDrops(m_enabled);
	emit enabledChanged();
}
