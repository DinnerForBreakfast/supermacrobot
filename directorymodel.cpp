#include "directorymodel.h"

class DirectoryModelPrivate {
public:
    QDir dir;
    QFileInfoList list;
};

DirectoryModel::DirectoryModel(QObject *parent) : QAbstractListModel(parent){
    d = new DirectoryModelPrivate();
    QHash<int, QByteArray> roles;
    roles[FileNameRole] = "fileName";
    roles[FilePathRole] = "filePath";
    setRoleNames(roles);

	qDebug()<<QDir::currentPath();
	d->dir.setPath(QDir::currentPath().append("/apps"));
    d->dir.setFilter(QDir::Dirs | QDir::NoDotAndDotDot);
    d->dir.entryList();
    d->list = d->dir.entryInfoList();

}

DirectoryModel::~DirectoryModel(){
    delete d;
}

QVariant DirectoryModel::data(const QModelIndex &index, int role) const{
    QVariant qv;
    QFileInfo info = d->list.at(index.row());
    if(role == FileNameRole){
        qv = info.fileName();
    }
    if(role == FilePathRole){
        qv = info.filePath();
    }
    return qv;
}

int DirectoryModel::rowCount(const QModelIndex &parent = QModelIndex()) const{
    Q_UNUSED(parent);
    return d->list.count();
}

void DirectoryModel::classBegin(){}

void DirectoryModel::componentComplete(){
    //QMetaObject::invokeMethod(this, "refresh", Qt::QueuedConnection);
}

QUrl DirectoryModel::getFolder() const{
    return d->dir.currentPath();
}

void DirectoryModel::setFolder(const QUrl &folder){
    d->dir.setPath(folder.toString());
    emit folderChanged();
}
