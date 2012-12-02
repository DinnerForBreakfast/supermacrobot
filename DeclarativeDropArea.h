#ifndef DECLARATIVEDROPAREA_H
#define DECLARATIVEDROPAREA_H

#include <QtDeclarative/QDeclarativeItem>
#include "DeclarativeDragDropEvent.h"

class DeclarativeDropArea : public QDeclarativeItem
{
	Q_OBJECT
	Q_PROPERTY(bool enabled READ isEnabled WRITE setEnabled NOTIFY enabledChanged)

public:
	DeclarativeDropArea(QDeclarativeItem *parent=0);
	bool isEnabled() const;
	void setEnabled(bool enabled);

signals:
	void dragEnter(DeclarativeDragDropEvent* event);
	void dragLeave(DeclarativeDragDropEvent* event);
	void drop(DeclarativeDragDropEvent* event);
	void enabledChanged();

protected:
	void dragEnterEvent(QGraphicsSceneDragDropEvent *event);
	void dragLeaveEvent(QGraphicsSceneDragDropEvent *event);
	void dropEvent(QGraphicsSceneDragDropEvent *event);

private:
	bool m_enabled;
};

#endif

