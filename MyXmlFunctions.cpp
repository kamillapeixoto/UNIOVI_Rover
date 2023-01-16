#include "MyXmlFunctions.h"

// Funcion que Crea un String con las Tags en el formato XML
QString XmlCreateString(const QString& xml_tag, int xml_value){

    QString ret;


        ret = "<" + xml_tag + ">" + QString::number(xml_value) + "</" + xml_tag + ">";

    return ret;

}



// Funcion que Crea un String con el Tag de Inicio o de Fin de un Texto Xml
QString XmlCreateTag(const QString& xml_tag, bool is_start_tag){

    QString ret;

    if (is_start_tag)
        ret = "<" + xml_tag + ">";      // Tag de Inicio
    else
        ret = "</" + xml_tag + ">";     // Tag de Fin

    return ret;

}


// Funcion que Extrae una Variable de Tipo String de un Texto en Formato Xml
QString XmlGetStr(const QString& xml_str, const QString& xml_tag){

    QString ret;

    // Crear Tag de Inicio y de Fin
    QString tagOpen = XmlCreateTag(xml_tag, true);
    QString tagClose = XmlCreateTag(xml_tag, false);

    // Calcular los Indices de los Tag en el Texto
    int iStart = xml_str.indexOf(tagOpen);
    int iEnd = xml_str.indexOf(tagClose);

    // Calcular Indice del Fin del Tag de Inicio
    iStart += tagOpen.length();

    // Calcular el Espacio que Ocupa la Variable
    int length_to_copy = iEnd - iStart;

    // Obtener la Variable
    ret = xml_str.mid(iStart, length_to_copy);

    return ret;

}


// Funcion que Extrae una Variable de Tipo Int de un Texto en Formato Xml
int XmlGetInt(const QString& xml_str, const QString& xml_tag){

    int ret;

    // Extraer el Contenido del Texto Xml
    QString contents = XmlGetStr(xml_str, xml_tag);

    contents = contents.trimmed();  // Eliminar Espacios al Principio y al Final

    ret = contents.toInt();         // Conversion a Entero

    return ret;

}


// Funcion que Extrae una Variable de Tipo Float de un Texto en Formato Xml
float XmlGetFloat(const QString& xml_str, const QString& xml_tag){

    float ret;

    // Extraer el Contenido del Texto Xml
    QString contents = XmlGetStr(xml_str, xml_tag);

    contents = contents.trimmed();  // Eliminar Espacios al Principio y al Final

    ret = contents.toFloat();       // Conversion a Real

    return ret;

}


// Funcion que Extrae una Tabla de Valores Reales de un Texto en Formato Xml
QVector<float> XmlGetVector(const QString& xml_str, const QString& xml_tag){

    QVector<float> ret;

    // Extraer el Contenido del Texto Xml
    QString contents = XmlGetStr(xml_str, xml_tag);

    contents = contents.trimmed();  // Eliminar Espacios al Principio y al Final

    // Si se Encuentra una Tabla
    if (contents.startsWith("[") && contents.endsWith("]")){

        // Eliminar los Corchetes
        contents = contents.mid(1, contents.length() - 2);

        // Separar Mediante Comas
        QStringList fields = contents.split(",");

        // Para cada Elemento
        for (int i = 0; i < fields.count(); i++){

            // Convertir a Float y Añadir a la Tabla Resultado
            float value = fields[i].toFloat();
            ret.append(value);

        }
    }

    return ret;

}
