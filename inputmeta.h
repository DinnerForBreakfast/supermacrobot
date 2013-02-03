#ifndef INPUTMETA_H
#define INPUTMETA_H

#include <linux/input.h>
#include <QtCore/QMetaType>
#include <stdint.h>

struct autoplay_event : input_event {
	uint64_t delay;
};

Q_DECLARE_METATYPE(autoplay_event)
Q_DECLARE_METATYPE(input_event)

#endif // INPUTMETA_H
