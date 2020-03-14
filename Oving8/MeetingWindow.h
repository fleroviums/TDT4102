#pragma once
#include "std_lib_facilities.h"
#include "Meeting.h"
#include "Graph.h"
#include "Window.h"
#include "GUI.h"
using namespace Graph_lib;

class MeetingWindow : public Window{
    public:
        MeetingWindow(Point xy, int w, int h, const string& title);
        static void cb_quit(Address, Address pw);
        static void cb_newPers(Address, Address pw);
        Vector_ref<Person> getPeople();
        // Callback

        // Callback-functions
        void quit() { cout << ti + ": quit()-callback\n"; hide(); }
        void newPers();


    private:
        static constexpr int pad = 50;
        static constexpr int fieldPad = 100;
        static constexpr int btnW = 100;
        static constexpr int btnH = 50;
        static constexpr int fieldW = 200;
        static constexpr int fieldH = 50;

        static constexpr Point nameInPos{ pad, pad };
        static constexpr Point mailInPos{ pad, nameInPos.y + fieldH + pad };
        static constexpr Point newPersPos{ pad, mailInPos.y + fieldH + pad };

        Button quitBtn;

        Button newPersBtn;
        In_box personName;
        In_box personEmail;
        string ti;
        Vector_ref<Person> people;

};


