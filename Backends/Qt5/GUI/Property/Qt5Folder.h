#ifndef QT5FOLDER_H_
#define QT5FOLDER_H_

#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>
#include <GUI/Property/Folder.h>

namespace GUI {
namespace Property {

class Qt5Folder : public QObject, public Folder {
	Q_OBJECT

	public:
		typedef std::shared_ptr<Qt5Folder> Ptr;
		typedef std::weak_ptr<Qt5Folder>   WPtr;

	public:
		Qt5Folder(std::string label);
		virtual ~Qt5Folder();

		void show();
		void hide();
		bool visible() const;
		void enable();
		void disable();
		bool enabled() const;

		fs::path value() const;
		void setValue(fs::path value);

		void setLabel(std::string label);

		QWidget* widget();

	public slots:
		void buttonClicked();

	protected:
		QWidget*      m_outer;
		QWidget*      m_inner;
		QVBoxLayout*  m_vBox;
		QHBoxLayout*  m_hBox;
		QLabel*       m_labelWidget;
		QLineEdit*    m_lineEdit;
		QPushButton*  m_button;
};


} // Property
} // GUI

#endif /* QT5FOLDER_H_ */
