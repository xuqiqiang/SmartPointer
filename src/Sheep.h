/*
 * Sheep.h
 *
 *  Created on: Mar 30, 2015
 */

#ifndef SHEEP_H_
#define SHEEP_H_

#include <utils/Log.h>

#ifdef DEBUG_LOCAL
#include "utils/RefBase.h"
#else
#include <utils/RefBase.h>
#endif

namespace android {

class Sheep: public RefBase {
private:
	sp<Sheep> mMaster;
	wp<Sheep> mStudent;
public:
	Sheep() {
		// extendObjectLifetime(1);
		ALOGD("Sheep::Sheep constructor invoked this=%p \n", this);
	}

	virtual void speak() {
		ALOGD("Sheep::%s, Sheep speak: baa~ baa~ baa~ \n", __FUNCTION__);
	}

	void onFirstRef() {
		ALOGD("Sheep::%s, object=%p \n", __FUNCTION__, this);
	}
	void onLastStrongRef(const void* id) {
		ALOGD("Sheep::%s, id=%p \n", __FUNCTION__, id);
	}
	bool onIncStrongAttempted(uint32_t flags, const void* id) {
		ALOGD("Sheep::%s, id=%p flags=%d \n", __FUNCTION__, id, flags);
		return true;
	}
	void onLastWeakRef(const void* id) {
		ALOGD("Sheep::%s, id=%p \n", __FUNCTION__, id);
	}

	virtual ~Sheep() {
		ALOGD("Sheep::Sheep destructor invoked this=%p \n", this);
	}

	void setMaster(sp<Sheep> master) {
		mMaster = master;
	}

	void setStudent(sp<Sheep> student) {
		mStudent = student;
	}
};

class WhiteSheep: public Sheep {
public:
	WhiteSheep() {
		extendObjectLifetime(OBJECT_LIFETIME_WEAK);
		ALOGD("Sheep::WhiteSheep constructor invoked this=%p \n", this);
	}
	void speak() {
		ALOGD("Sheep::%s, WhiteSheep speak: baa baa baa----- \n", __FUNCTION__);
	}

private:
	virtual ~WhiteSheep() {
		ALOGD("Sheep::WhiteSheep destructor invoked this=%p \n", this);
	}
};
};

#endif /* SHEEP_H_ */
