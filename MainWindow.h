#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

/* MainWindow
 * code for the main window and docking widgets.
 */

#include <QtGui>
#include <QDockWidget>
#include <QFileDialog>
#include <QtWidgets>
#include <QColorDialog>
#include <Quarter/QuarterWidget.h>
#include <QActionGroup>
#include <QKeySequence>
//#include "ColourBarForm.h"
#include "BrainQuarter.h"
#include "ResourceForm.h"
// #include "TagForm.h"

using namespace SIM::Coin3D::Quarter;

class MainWindow : public QMainWindow {
	Q_OBJECT
public:
	// constructor
	MainWindow();
	// destructor
	virtual ~MainWindow();

	// opens file based on extension
// 	QFile nullfile(".db");
// 	bool openFile(QFile &filename, bool cylinder_flag=false, char* dbfile=NULL);
	bool openFile(QFile &filename);
	void saveTagFileFunc(QFile &filename);
	

	
public slots:
	// prompts user for filename from file dialog
        void openFileFromDialog();
        // exits the application
        void quitApplication();
// 		void getTagFilename();
		void saveTagFromDialog();
		void createTagFunc();
		void addTagFunc();
        void setTagOptionFromDialog0(){viewer->setTagOpt(0);};
        void setTagOptionFromDialog1(){viewer->setTagOpt(1);};
        void setTagOptionFromDialog2(){viewer->setTagOpt(2);};
		void verboseStatus(); 


//		void setTagOptionFromDialog(int tagopt);
private:
	// set up the actions (file open, etc.)
	void createActions();
	// set up the menu
	void createMenus();
        // create the colourbars if they don't already exist
        void initColourbars();
/*	//creat buttons to create a new tag point or save tags in a file	
	void createTagbuttons();*/
	
	QMenu *fileMenu;
        QAction *openAction;
	QAction *saveTagAction;
        QAction *quitAction;
		
	QMenu *tagMenu;
	QActionGroup *tagGroup;
	QAction *surfaceAction;
	QAction *midpointAction;
	QAction *backsurfaceAction;
	
	QMenu *outMenu;
	QAction *verboseAction; 	//to be used in ResourceForm definition and by BrainQuarter, GeometryScene and textureFileItem
	

// 	QPushButton *createTagbutton;
// 	QPushButton *saveTagFilebutton;
	
	// holds the main viewer application
	BrainQuarter *viewer;
	// holds the widget to display the colour bar
	//ColourBarForm *colourBar;
	// dock for the colour bar widget
	//QDockWidget *colourBarDock;
	// tree to keep track of open resources
	//QTreeView *treeview;
	ResourceForm *resourceForm;
// 	TagForm *tagForm;
	// dock to hold the tree view
	QDockWidget *resourceDock;
// 	QDockWidget *tagDock;
	//void sampleTreeSetup();
	QVector <float> tagsVect;
	float *Tagpoint;
	double Tagsize;


};

#endif /*MAINWINDOW_H_*/
