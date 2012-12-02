#ifndef DECLARATIVEDRAGAREA_H
#define DECLARATIVEDRAGAREA_H

#include <QtDeclarative/QDeclarativeItem>
#include <QtDeclarative/QDeclarativeComponent>
#include "DeclarativeMimeData.h"

class DeclarativeDragArea : public QDeclarativeItem
{
	Q_OBJECT
	Q_PROPERTY(QDeclarativeComponent* delegate READ delegate WRITE setDelegate NOTIFY delegateChanged RESET resetDelegate)
	Q_PROPERTY(QDeclarativeItem* source READ source WRITE setSource NOTIFY sourceChanged RESET resetSource)
	Q_PROPERTY(QDeclarativeItem* target READ source NOTIFY targetChanged)
	Q_PROPERTY(DeclarativeMimeData* data READ data CONSTANT)
	Q_PROPERTY(bool enabled READ isEnabled WRITE setEnabled NOTIFY enabledChanged) //TODO: Should call setAcceptDrops()
	Q_PROPERTY(Qt::DropActions supportedActions READ supportedActions WRITE setSupportedActions NOTIFY supportedActionsChanged)
	Q_PROPERTY(Qt::DropAction defaultAction READ defaultAction WRITE setDefaultAction NOTIFY defaultActionChanged)


public:
	DeclarativeDragArea(QDeclarativeItem *parent=0);
	~DeclarativeDragArea();

	QDeclarativeComponent *delegate() const;
	void setDelegate(QDeclarativeComponent* delegate);
	void resetDelegate();

	QDeclarativeItem* target() const;
	QDeclarativeItem* source() const;
	void setSource(QDeclarativeItem* source);
	void resetSource();

	bool isEnabled() const;
	void setEnabled(bool enabled);

	//supported actions
	Qt::DropActions supportedActions() const;
	void setSupportedActions(Qt::DropActions actions);

	//default action
	Qt::DropAction defaultAction() const;
	void setDefaultAction(Qt::DropAction action);

	DeclarativeMimeData* data() const;

signals:
	void delegateChanged();
	void sourceChanged();
	void targetChanged();
	void dataChanged();
	void enabledChanged();
	void drop(int action);
	void supportedActionsChanged();
	void defaultActionChanged();

protected:
	void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
	void mousePressEvent(QGraphicsSceneMouseEvent *) {}
	void mouseReleaseEvent(QGraphicsSceneMouseEvent *) {}

private:
	QDeclarativeComponent* m_delegate;
	QDeclarativeItem* m_source;
	QDeclarativeItem* m_target;
	DeclarativeMimeData* const m_data;
	bool m_enabled;
	Qt::DropActions m_supportedActions;
	Qt::DropAction m_defaultAction;
};

#endif // DECLARATIVEDRAGAREA_H
