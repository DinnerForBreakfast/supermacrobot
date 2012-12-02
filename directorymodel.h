#ifndef DIRECTORYMODEL_H
#define DIRECTORYMODEL_H

#include <qdeclarative.h>
#include <QUrl>
#include <QFileSystemModel>
#include <QDebug>

class DirectoryModelPrivate;

class DirectoryModel : public QAbstractListModel,public QDeclarativeParserStatus{
    Q_OBJECT
    Q_INTERFACES(QDeclarativeParserStatus)

    Q_PROPERTY(QUrl folder READ getFolder WRITE setFolder NOTIFY folderChanged)


public:
    DirectoryModel(QObject *parent = 0);
    ~DirectoryModel();
    QVariant data(const QModelIndex &index, int role) const;
    int rowCount(const QModelIndex &parent) const;
//    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

    QUrl getFolder() const;
    void setFolder(const QUrl &folder);

    enum Roles { FileNameRole = Qt::UserRole+1, FilePathRole = Qt::UserRole+2 };

    virtual void classBegin();
    virtual void componentComplete();

private:
    DirectoryModelPrivate *d;

signals:
    void folderChanged();

public slots:

};

QML_DECLARE_TYPE(DirectoryModel)

#endif // DIRECTORYMODEL_H
