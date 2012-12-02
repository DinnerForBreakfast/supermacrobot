#ifndef DECLARATIVEMIMEDATA_H
#define DECLARATIVEMIMEDATA_H

#include <QMimeData>
#include <QColor>
#include <QUrl>
#include <QDeclarativeItem>

class DeclarativeMimeData : public QMimeData
{
	Q_OBJECT

	Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)
	Q_PROPERTY(QString html READ html WRITE setHtml NOTIFY htmlChanged)
	Q_PROPERTY(QUrl url READ url WRITE setUrl NOTIFY urlChanged) //TODO: use QDeclarativeListProperty<QUrls> to return the whole list instead of only the first url
	Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)
	Q_PROPERTY(QDeclarativeItem* source READ source WRITE setSource NOTIFY sourceChanged)
	//TODO: Image property

public:
	DeclarativeMimeData() : QMimeData() {}
	DeclarativeMimeData(const QMimeData* copy);

	QUrl url() const;
	void setUrl(const QUrl &url);

	QColor color() const;
	void setColor(const QColor &color);

	QDeclarativeItem* source() const;
	void setSource(QDeclarativeItem* source);

	/*
	QString text() const;				//TODO: Reimplement this to issue the onChanged signals
	void setText(const QString &text);
	QString html() const;
	void setHtml(const QString &html);
	*/

signals:
	void textChanged();		//FIXME not being used
	void htmlChanged();		//FIXME not being used
	void urlChanged();
	void colorChanged();
	void sourceChanged();

private:
	QDeclarativeItem* m_source;

};

#endif // DECLARATIVEMIMEDATA_H
