#include <QFile>

class GUIFunctions
{
public:
    static QString GetStyle(const QString& stylePath)
    {
        QString style;
        QFile styleFile(stylePath);

        if (styleFile.open(QFile::ReadOnly))
            style = styleFile.readAll();

        // TODO: Exception control
        return style;
    }
};