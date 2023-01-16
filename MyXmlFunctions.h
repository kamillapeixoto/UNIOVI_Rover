#ifndef MYXMLFUNCTIONS_H
#define MYXMLFUNCTIONS_H

#include <QString>
#include <QVector>

QString XmlCreateString(const QString& xml_tag, int xml_value);

QString XmlCreateTag (const QString& xml_tag, bool is_start_tag);
QString XmlGetStr(const QString& xml_str, const QString& xml_tag);
int XmlGetInt(const QString& xml_str, const QString& xml_tag);
float XmlGetFloat(const QString& xml_str, const QString& xml_tag);
QVector<float> XmlGetVector(const QString& xml_str, const QString& xml_tag);

#endif // MYXMLFUNCTIONS_H
