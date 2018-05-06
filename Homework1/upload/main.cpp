#include <nana/gui.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/button.hpp>

int main()
{
    using namespace nana;

    //Define a form.
    form fm;

    //Define a label and display a text.
    label lab{fm, "Hello, <bold blue size=16>Nana C++ Library</>"};
    lab.format(true);

    //Define a button and answer the click event.
	button btn{ fm, "Quit" };
    btn.events().click([&fm]{
		nana::msgbox m(fm,"Quit?",nana::msgbox::yes_no);
		m << "Do you really want to exit?";
		switch (m.show())
		{
			case msgbox::pick_yes:
				m.clear();
				fm.close();
				break;
			case msgbox::pick_no:
				break;
		}
    });


    //Layout management
    fm.div("vert <><<><weight=80% text><>><><weight=24<><button><>><>");
    fm["text"]<<lab;
    fm["button"] << btn;
    fm.collocate();
	
    //Show the form
    fm.show();

    //Start to event loop process, it blocks until the form is closed.
    exec();
}