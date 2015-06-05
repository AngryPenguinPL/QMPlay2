#include <QCommonStyle>
#include <QTimer>

#include <DockWidget.hpp>
#include <InDockW.hpp>

class QMenu;

class VideoDock : public DockWidget
{
	Q_OBJECT
public:
	VideoDock();

	void fullScreen( bool );
	inline void setLoseHeight( int lh )
	{
		iDW.setLoseHeight( lh );
	}

	inline void updateIDW()
	{
		iDW.update();
	}
private:
	inline QWidget *internalWidget()
	{
		return ( widget() == &iDW ) ? iDW.widget() : widget();
	}

	void dragEnterEvent( QDragEnterEvent * );
	void dropEvent( QDropEvent * );
	void mouseMoveEvent( QMouseEvent * );
	void mouseDoubleClickEvent( QMouseEvent * );
	void mousePressEvent( QMouseEvent * );
	void wheelEvent( QWheelEvent * );
	void leaveEvent( QEvent * );
	void enterEvent( QEvent * );
	bool event( QEvent * );

	QTimer hideCursorTim;
	InDockW iDW;
	QMenu *popupMenu;
	QCommonStyle commonStyle;
#ifndef Q_OS_MAC
	int pixels;
#endif
	bool cantpopup, is_floating;
	double touchZoom;
private slots:
	void popup( const QPoint & );
	void hideCursor();
	void resizedIDW( int, int );
	void updateImage( const QImage & );
	void visibilityChanged( bool );
signals:
	void resized( int, int );
	void itemDropped( const QString &, bool );
};
