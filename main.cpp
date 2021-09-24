#include <QtCore/QCoreApplication>
#include <QXmlQuery>
#include <QDebug>
#include <QFile>
#include <QDomDocument>

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    QXmlQuery query;

    QFile file("data/test/test.xml");

    qDebug() << file.open(QIODevice::ReadOnly);

    QDomDocument doc;

    // qDebug() << doc.setContent(file.readAll(), false);

    qDebug() << query.setFocus(&file);

    // query.setQuery("doc('../data/test/test.xml')//*[@showRestricted='true']");

    query.setQuery("string(/Area/@id)");

    QString output;

    query.evaluateTo(&output);

    qDebug() << output.simplified();

    query.setQuery("//*[@showRestricted='true']");

    query.evaluateTo(&output);

    qDebug() << output;

    return a.exec();
}
