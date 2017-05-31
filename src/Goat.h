/*
 * Goat.h
 *
 *  Created on: Mar 30, 2015
 */

#ifndef GOAT_H_
#define GOAT_H_

#include <utils/Log.h>
#include <sys/types.h>

#ifdef DEBUG_LOCAL
#include "utils/RefBase.h"
#else
#include <utils/RefBase.h>
#endif

namespace android {

class Goat: public LightRefBase<Goat> {
public:
	Goat() {
		ALOGD("Goat::Goat constructor invoked this=%p \n", this);
	}

	~Goat() {
		ALOGD("Goat::Goat destructor invoked this=%p \n", this);
	}
};
};

#endif /* GOAT_H_ */
