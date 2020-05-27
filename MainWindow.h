#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "MainDisplay.h"

#include <mitkStandaloneDataStorage.h>
#include <mitkImage.h>

#include <QMainWindow>

class ThumbnailListWidget;

class MainWindow : public QMainWindow
{
	Q_OBJECT
public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();

signals:
	void fileLoaded(const QString& fileAbsolutePath);

private:
	void setupLayout();
	void setupMenus();

	void openFileDialog();
	void loadImage(const QString filePath);

private:
	mitk::StandaloneDataStorage::Pointer m_DataStorage;
	mitk::Image::Pointer m_FirstImage;

	QMenu *m_FileMenu;
	MainDisplay *m_MainDisplay;
	ThumbnailListWidget *m_ThumbnailListWidget;
};
#endif // MAINWINDOW_H