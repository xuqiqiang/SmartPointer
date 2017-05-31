/*
 * Base.h
 *
 *  Created on: Mar 30, 2015
 */

#ifndef BASE_H_
#define BASE_H_

#include <utils/Log.h>

namespace android {

class Base {
public:
	Base() {
		ALOGD("Sheep::Base constructor invoked \n");
	}
	virtual ~Base() {
		ALOGD("Sheep::Base destructor invoked \n");
	}

private:
	Base(const Base& o);
	Base& operator=(const Base& o);
};

class BaseClass: public Base {
public:
	BaseClass() {
		ALOGD("Sheep::BaseClass constructor invoked \n");
	}

	~BaseClass() {
		ALOGD("Sheep::BaseClass destructor invoked \n");
	}
	BaseClass(const BaseClass& o);
	BaseClass& operator=(const BaseClass& o);
};
};

#endif /* BASE_H_ */
