#ifndef DECLARATIVEDRAGDROPEVENT_H
#define DECLARATIVEDRAGDROPEVENT_H

#include <QObject>
#include <QGraphicsSceneDragDropEvent>

#include "DeclarativeMimeData.h"

class DeclarativeDragDropEvent : public QObject
{
	Q_OBJECT
	Q_PROPERTY(int x READ x)
	Q_PROPERTY(int y READ y)
	Q_PROPERTY(int buttons READ buttons)
	Q_PROPERTY(int modifiers READ modifiers)
	Q_PROPERTY(DeclarativeMimeData* data READ data)
	Q_PROPERTY(Qt::DropActions possibleActions READ possibleActions)
	Q_PROPERTY(Qt::DropAction proposedAction READ proposedAction)

public:

	DeclarativeDragDropEvent(QGraphicsSceneDragDropEvent* e, QObject* parent = 0);

	int x() const { return m_x; }
	int y() const { return m_y; }
	int buttons() const { return m_buttons; }
	int modifiers() const { return m_modifiers; }
	DeclarativeMimeData* data() { return &m_data; }
	Qt::DropAction proposedAction() const { return m_event->proposedAction(); }
	Qt::DropActions possibleActions() const { return m_event->possibleActions(); }

public slots:
	void accept(int action);

private:
	int m_x;
	int m_y;
	Qt::MouseButtons m_buttons;
	Qt::KeyboardModifiers m_modifiers;
	DeclarativeMimeData m_data;
	QGraphicsSceneDragDropEvent* m_event;
};

#endif // DECLARATIVEDRAGDROPEVENT_H
