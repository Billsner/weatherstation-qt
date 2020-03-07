#include "downloadmanager.hpp"

DownloadManager::DownloadManager() :mLogging("onlineservices.DownloadManager")
{

}

DownloadManager::~DownloadManager()
{

}

void DownloadManager::movetoThread(QThread *thread)
{
    manager.moveToThread(thread);
}

void DownloadManager::init()
{
    connect(&manager, SIGNAL(finished(QNetworkReply*)),
            SLOT(downloadFinished(QNetworkReply*)));
}

void DownloadManager::triggertimer(void)
{

}

void DownloadManager::doDownload(const QUrl &url)
{
    QNetworkRequest request(url);
    QNetworkReply *reply = manager.get(request);

#if QT_CONFIG(ssl)
    connect(reply, SIGNAL(sslErrors(QList<QSslError>)),
            SLOT(sslErrors(QList<QSslError>)));
#endif

    currentDownloads.append(reply);
}

QString DownloadManager::saveFileName(const QUrl &url)
{
    QString path = url.path();
    QString basename = QFileInfo(path).fileName();

    if (basename.isEmpty())
    {
        basename = "download";
    }
    QDir::setCurrent(QCoreApplication::applicationDirPath());
    QDir cfgfolder("download");
    if(!cfgfolder.exists())
    {
        QDir appfolder("");
        if(!appfolder.mkdir("download"))
        {
            mLogging <= "saveFileName: error create folder";
        }
    }
    else
    {
        mLogging <= "saveFileName: folder exist";
    }

    if (QFile::exists(basename))
    {
        // already exists, don't overwrite
        int i = 0;
        basename += '.';
        while (QFile::exists(basename + QString::number(i)))
        {
            ++i;
        }
        basename += QString::number(i);
        (mLogging << "saveFileName: file exist ") <= basename.toStdString();
    }
    else
    {
        (mLogging <= "saveFileName: file not exist ")  <= basename.toStdString();;
    }

    return basename;
}

bool DownloadManager::saveToDisk(const QString &filename, QIODevice *data)
{
    QDir::setCurrent(QCoreApplication::applicationDirPath());
    QDir cfgfolder("download");
    if(!cfgfolder.exists())
    {
        QDir appfolder("");
        if(!appfolder.mkdir("download"))
        {
            mLogging <= "saveToDisk: error create folder";
        }
    }
    QFile file("./download/" + filename);
    if (!file.open(QIODevice::WriteOnly))
    {
        (mLogging << "Could not open " << qPrintable(filename) << " for writing: ") <= qPrintable(file.errorString());
        return false;
    }

    file.write(data->readAll());
    file.close();

    return true;
}

bool DownloadManager::isHttpRedirect(QNetworkReply *reply)
{
    int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    return (statusCode == 301 || statusCode == 302 || statusCode == 303
           || statusCode == 305 || statusCode == 307 || statusCode == 308);
}

void DownloadManager::sslErrors(const QList<QSslError> &sslErrors)
{
#if QT_CONFIG(ssl)
    for (const QSslError &error : sslErrors)
    {
        (mLogging << "SSL error: ") <= qPrintable(error.errorString());
    }
#else
    Q_UNUSED(sslErrors);
#endif
}

void DownloadManager::downloadFinished(QNetworkReply *reply)
{
    QUrl url = reply->url();
    if (reply->error())
    {
        (mLogging << "Download of " << url.toEncoded().constData() << " failed: ") <= qPrintable(reply->errorString());
    }
    else
    {
        if (isHttpRedirect(reply))
        {
            mLogging <= "Request was redirected.";
        }
        else
        {
            QString filename = saveFileName(url);
            if (saveToDisk(filename, reply))
            {
                (mLogging << "Download of " << url.toEncoded().constData() << " succeeded (saved to " << qPrintable(filename)) <= " )";
            }
        }
    }

    currentDownloads.removeAll(reply);
    reply->deleteLater();

    if (currentDownloads.isEmpty())
    {
        mLogging <= "all downloads finished";
    }
}
