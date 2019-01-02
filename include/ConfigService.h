#ifndef CONFIGSERVICE_H
#define CONFIGSERVICE_H

#include <QList>
#include <QMap>
#include <QObject>
#include <QString>
#include <QJsonArray>

#define V2RAY_CONFIG_AUTO_CONNECT_KEY           "autoConnect"
#define V2RAY_CONFIG_CORE_PATH_KEY              "corePath"
#define V2RAY_CONFIG_CURRENT_SECTION_KEY        "currentWorkSection"
#define V2RAY_CONFIG_SECTION_KEY                "sections"
#define V2RAY_CONFIG_SECTION_TAG_KEY            "tag"
#define V2RAY_CONFIG_SECTION_CONFIG_PATH_KEY    "configPath"

typedef QMap<QString, QString> Section;
typedef QList<Section*> SectionList;

class ConfigService : QObject
{
    Q_OBJECT

public:
    static ConfigService *getInstance(QObject *parent = nullptr);
    bool loadFromJson(QString filePath, QString &errDes);
    bool releaseDefaultJson();
    bool getAutoConnect() const;
    const QString &getCorePath() const;
    const QString &getCurrentSection() const;
    const SectionList &getSections();

private:
    explicit ConfigService(QObject *parent = nullptr);
    ~ConfigService();
    void clearSections();

    static ConfigService *singleInstance;
    bool autoConnect;
    QString corePath;
    QString currentSection;
    QJsonArray sectionArray;
    SectionList sections;
};

Q_DECLARE_METATYPE(Section*)

#endif // CONFIGSERVICE_H
