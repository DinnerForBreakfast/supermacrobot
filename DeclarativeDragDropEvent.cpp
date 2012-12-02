#include "DeclarativeDragDropEvent.h"

DeclarativeDragDropEvent::DeclarativeDragDropEvent(QGraphicsSceneDragDropEvent* e, QObject* parent) :
	QObject(parent),
	m_event(e),
	m_x(e->pos().x()),
	m_y(e->pos().y()),
	m_buttons(e->buttons()),
	m_modifiers(e->modifiers()),
	m_data(e->mimeData())
{

}


void DeclarativeDragDropEvent::accept(int action)
{
	m_event->setDropAction( (Qt::DropAction) action );
	m_event->accept();
}
