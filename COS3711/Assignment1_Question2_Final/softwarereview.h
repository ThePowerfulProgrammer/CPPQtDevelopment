#ifndef SOFTWAREREVIEW_H
#define SOFTWAREREVIEW_H

#include <QObject>
#include <QString>
#include <QDate>

class SoftwareReview : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString softwareName READ softwareName WRITE setSoftwareName)
    Q_PROPERTY(QDate reviewDate READ reviewDate WRITE setReviewDate)
    Q_PROPERTY(bool isRecommended READ isRecommended WRITE setIsRecommended)

public:

    explicit SoftwareReview(QObject *parent = 0) : QObject(parent) {}

    QString softwareName() const { return m_softwareName; }
    void setSoftwareName(const QString &softwareName) { m_softwareName = softwareName; }

    QDate reviewDate() const { return m_reviewDate; }
    void setReviewDate(const QDate &reviewDate) { m_reviewDate = reviewDate; }

    bool isRecommended() const { return m_isRecommended; }
    void setIsRecommended(bool isRecommended) { m_isRecommended = isRecommended; }

signals:

public slots:

private:
    QString m_softwareName;
    QDate m_reviewDate;
    bool m_isRecommended;

};

#endif // SOFTWAREREVIEW_H
