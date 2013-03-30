#include "ceventmanager.h"
#include <QDebug>

CEventManager::CEventManager(QObject *parent) : QObject(parent)
{
	initDefaultKeymap();
	recordState = false;
	playbackState = false;
	player = new ScriptPlayer();
	QObject::connect(player, SIGNAL(inputEvent(QVariant)),this,SLOT(processEvent(QVariant)));
	QObject::connect(player, SIGNAL(done()),this,SLOT(scriptFinished()));
	recording = new std::vector<autoplay_event>();
}

CEventManager::~CEventManager(){
	delete player;
}

void CEventManager::processEvent(QVariant qv)
{
	struct autoplay_event ae = qv.value<autoplay_event>();
	time_event = ae.time.tv_sec * 1000000 + ae.time.tv_usec;
	if(time_last_event == 0)time_last_event = time_event;
	ae.delay = time_event - time_last_event;
	time_last_event = time_event;
	qDebug() << "type:"<< ae.type << ", code:" << ae.code << ", value:" << ae.value << ", delay:" << ae.delay;
	if(ae.type == EV_REL){
		if(ae.code == REL_X){
			emit mouseMove(ae.value,0);
		}
		if(ae.code == REL_Y){
			emit mouseMove(0,ae.value);
		}
		if(recordState)recording->push_back(ae);
	}
	if(ae.type == EV_KEY){
		if(ae.code == KEY_F1 && ae.value == 1){
			recordState = !recordState;
			qDebug() << "record state:" << recordState;
			if(recordState){
				recording->clear();
			}
		}else
		if(ae.code == KEY_F2 && ae.value == 1){
			playbackState = !playbackState;
			qDebug() << "playback state:" << playbackState;
			if(playbackState){
				player->play(recording);
			}
			if(!playbackState){
				player->halt();
			}
		}else{
			if(keymap.find(ae.code) != keymap.end()){
				emit keyEvent(keymap[ae.code],ae.value);
			}
			if(mousemap.find(ae.code) != mousemap.end()){
				emit mouseClick(mousemap[ae.code],ae.value);
			}
			if(recordState)recording->push_back(ae);
		}
	}
}

void CEventManager::scriptFinished()
{
	playbackState = false;
	qDebug() << "script finished";
}

void CEventManager::initDefaultKeymap()
{
	keymap[KEY_ESC] = ( 41  | 0x4000 );
	keymap[KEY_1] = '1';
	keymap[KEY_2] = '2';
	keymap[KEY_3] = '3';
	keymap[KEY_4] = '4';
	keymap[KEY_5] = '5';
	keymap[KEY_6] = '6';
	keymap[KEY_7] = '7';
	keymap[KEY_8] = '8';
	keymap[KEY_9] = '9';
	keymap[KEY_0] = '0';
	keymap[KEY_MINUS] = ( 45  | 0x4000 );
	keymap[KEY_EQUAL] = ( 46  | 0x4000 );
	keymap[KEY_BACKSPACE] = ( 42  | 0x4000 );
	keymap[KEY_TAB] = ( 43  | 0x4000 );
	keymap[KEY_Q] = 'q';
	keymap[KEY_W] = 'w';
	keymap[KEY_E] = 'e';
	keymap[KEY_R] = 'r';
	keymap[KEY_T] = 't';
	keymap[KEY_Y] = 'y';
	keymap[KEY_U] = 'u';
	keymap[KEY_I] = 'i';
	keymap[KEY_O] = 'o';
	keymap[KEY_P] = 'p';
	keymap[KEY_LEFTBRACE] = ( 47  | 0x4000 );
	keymap[KEY_RIGHTBRACE] = ( 48  | 0x4000 );
	keymap[KEY_ENTER] =  ( 40  | 0x4000 );
	keymap[KEY_LEFTCTRL] = ( 0x01 | 0x8000 );
	keymap[KEY_A] = 'a';
	keymap[KEY_S] = 's';
	keymap[KEY_D] = 'd';
	keymap[KEY_F] = 'f';
	keymap[KEY_G] = 'g';
	keymap[KEY_H] = 'h';
	keymap[KEY_J] = 'j';
	keymap[KEY_K] = 'k';
	keymap[KEY_L] = 'l';
	keymap[KEY_SEMICOLON] = ( 51  | 0x4000 );
	keymap[KEY_APOSTROPHE] = ( 52  | 0x4000 );
	keymap[KEY_GRAVE] = ( 53  | 0x4000 );
	keymap[KEY_LEFTSHIFT] = ( 0x02 | 0x8000 );
	keymap[KEY_BACKSLASH] = ( 49  | 0x4000 );
	keymap[KEY_Z] = 'z';
	keymap[KEY_X] = 'x';
	keymap[KEY_C] = 'c';
	keymap[KEY_V] = 'v';
	keymap[KEY_B] = 'b';
	keymap[KEY_N] = 'n';
	keymap[KEY_M] = 'm';
	keymap[KEY_COMMA] = ( 54  | 0x4000 );
	keymap[KEY_DOT] = ( 55  | 0x4000 );
	keymap[KEY_SLASH] = ( 56  | 0x4000 );
	keymap[KEY_RIGHTSHIFT] = ( 0x20 | 0x8000 );
	keymap[KEY_KPASTERISK] = ( 85  | 0x4000 );
	keymap[KEY_LEFTALT] = ( 0x04 | 0x8000 );
	keymap[KEY_SPACE] = ( 44  | 0x4000 );
	keymap[KEY_CAPSLOCK] = ( 57  | 0x4000 );
	keymap[KEY_F1] = ( 58  | 0x4000 );
	keymap[KEY_F2] = ( 59  | 0x4000 );
	keymap[KEY_F3] = ( 60  | 0x4000 );
	keymap[KEY_F4] = ( 61  | 0x4000 );
	keymap[KEY_F5] = ( 62  | 0x4000 );
	keymap[KEY_F6] = ( 63  | 0x4000 );
	keymap[KEY_F7] = ( 64  | 0x4000 );
	keymap[KEY_F8] = ( 65  | 0x4000 );
	keymap[KEY_F9] = ( 66  | 0x4000 );
	keymap[KEY_F10] = ( 67  | 0x4000 );
	keymap[KEY_F11] = ( 68  | 0x4000 );
	keymap[KEY_F12] = ( 69  | 0x4000 );
	keymap[KEY_NUMLOCK] = ( 83  | 0x4000 );
	keymap[KEY_SCROLLLOCK] = ( 71  | 0x4000 );
	keymap[KEY_KP7] = ( 95  | 0x4000 );
	keymap[KEY_KP8] = ( 96  | 0x4000 );
	keymap[KEY_KP9] = ( 97  | 0x4000 );
	keymap[KEY_KPMINUS] = ( 86  | 0x4000 );
	keymap[KEY_KP4] = ( 92  | 0x4000 );
	keymap[KEY_KP5] = ( 93  | 0x4000 );
	keymap[KEY_KP6] = ( 94  | 0x4000 );
	keymap[KEY_KPPLUS] = ( 87  | 0x4000 );
	keymap[KEY_KP1] = ( 89  | 0x4000 );
	keymap[KEY_KP2] = ( 90  | 0x4000 );
	keymap[KEY_KP3] = ( 91  | 0x4000 );
	keymap[KEY_KP0] = ( 98  | 0x4000 );
	keymap[KEY_KPDOT] = ( 99  | 0x4000 );
	keymap[KEY_KPENTER] = ( 88  | 0x4000 );
	keymap[KEY_RIGHTCTRL] = ( 0x10 | 0x8000 );
	keymap[KEY_KPSLASH] = ( 84  | 0x4000 );
	keymap[KEY_LEFTMETA] = ( 0x08 | 0x8000 );
	keymap[KEY_COMPOSE] = ( 0x80 | 0x8000 );

	mousemap[BTN_LEFT] = 0;
	mousemap[BTN_RIGHT] = 1;
	mousemap[BTN_MIDDLE] = 2;
}
