﻿#ifndef CONTENTDEVICE_H
#define CONTENTDEVICE_H
#include <qglobal.h>

#ifdef Q_OS_ANDROID
#include <QIODevice>
#include <QUrl>

#include <QtAndroidExtras/QAndroidJniObject>
#include <QtAndroidExtras/QAndroidJniEnvironment>

class ContentDevice : public QIODevice
{
	Q_OBJECT

    Q_PROPERTY(QUrl fileName READ fileName WRITE setFileName NOTIFY fileNameChanged)
    Q_PROPERTY(qint64 size READ size)
    Q_ENUMS(OpenMode)
public :
	explicit ContentDevice(QObject *parent = nullptr);
	explicit ContentDevice(const QUrl &url, QObject *parent = nullptr);
	explicit ContentDevice(const QAndroidJniObject &context, const QUrl &url, QObject *parent = nullptr);
public Q_SLOTS:
	void setContext(const QAndroidJniObject &context);

	bool isSequential() const override;
    bool open(OpenMode mode = QIODevice::ReadOnly) override;
	void close() override;
	qint64 bytesAvailable() const override;
	void flush();

    QUrl fileName() const;
    qint64 size() const;
public Q_SLOTS:
    void setFileName(QUrl url);

Q_SIGNALS:
    void fileNameChanged(QUrl url);

protected:
	qint64 readData(char *data, qint64 maxlen) override;
	qint64 writeData(const char *data, qint64 len) override;

private:
	QAndroidJniObject _context;
	QUrl _url;

	QAndroidJniObject _stream;

	bool checkJniError(QAndroidJniEnvironment &env);
};

#endif //Q_OS_ANDROID

#endif // CONTENTDEVICE_H
