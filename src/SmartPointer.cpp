//============================================================================
// Name        : SmartPointer.cpp
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <utils/Log.h>
#include <sys/types.h>

#ifdef DEBUG_LOCAL
#include "utils/RefBase.h"
#else
#include <utils/RefBase.h>
#endif

#include "Base.h"
#include "Goat.h"
#include "Sheep.h"

using namespace android;

void testSheep() {
	ALOGD("Sheep::------------------testSheep start--------------------------");
	Sheep* pSheep = new Sheep();
	ALOGD("Sheep:: No refs, strong count=%d, weak count=%d \n",
			pSheep->getStrongCount(), pSheep->getWeakRefs()->getWeakCount());
	{
		ALOGD("Sheep::in sp scope ------------\n");
		sp<Sheep> spSheep(pSheep);
		ALOGD("Sheep:: After strong ref, strong count=%d, weak count=%d \n",
				pSheep->getStrongCount(),
				pSheep->getWeakRefs()->getWeakCount());
		{
			ALOGD("Sheep::in wp scope ------------\n");
			wp<Sheep> wpSheep(pSheep);
			ALOGD("Sheep:: After weak ref, strong count=%d, weak count=%d \n",
					pSheep->getStrongCount(),
					pSheep->getWeakRefs()->getWeakCount());
			ALOGD("Sheep::out wp scope ------------\n");
		}
		ALOGD("Sheep:: release weak ref, strong count=%d, weak count=%d \n",
				pSheep->getStrongCount(),
				pSheep->getWeakRefs()->getWeakCount());
		ALOGD("Sheep::out sp scope ------------\n");
	}
	ALOGD("Sheep::--------------------testSheep end--------------------------");
}

void testPromote() {
	ALOGD("Sheep:: -------------testPromote begin------------\n");
	{
		Sheep* pSheep = new Sheep();
		ALOGD("Sheep:: No refs, strong count=%d, weak count=%d \n",
				pSheep->getStrongCount(),
				pSheep->getWeakRefs()->getWeakCount());
		wp<Sheep> wpSheep(pSheep);
		ALOGD("Sheep:: After weak ref, strong count=%d, weak count=%d \n",
				pSheep->getStrongCount(),
				pSheep->getWeakRefs()->getWeakCount());
		sp<Sheep> spSheep = wpSheep.promote();
		ALOGD("Sheep:: After promote, strong count=%d, weak count=%d \n",
				pSheep->getStrongCount(),
				pSheep->getWeakRefs()->getWeakCount());
	}
	ALOGD("Sheep:: -------------testPromote   end------------\n");
}

void testLightRef() {
	ALOGD("Goat::--------------------testGoat begin--------------------------");
	Goat* pGoat = new Goat();
	ALOGD("Goat:: before sp ref, mCount=%d", pGoat->getStrongCount());
	{
		ALOGD("Sheep::in sp scope ------------\n");

		sp<Goat> spGoat(pGoat);
		ALOGD("Goat:: After sp ref, mCount=%d", pGoat->getStrongCount());
		ALOGD("Sheep::out sp scope ------------\n");
	}
	ALOGD("Goat::--------------------testGoat end--------------------------");
}

void testForceSet() {
	ALOGD("Sheep:: -------------testForceSet begin------------\n");
	{
		sp<Sheep> spSheep(new Sheep());
		spSheep.force_set(new Sheep());
	}
	ALOGD("Sheep:: -------------testForceSet end------------\n");
}

void testStrongRefStrong() {
	ALOGD("Sheep:: -------------testStrongRefStrong begin------------\n");
	sp<Sheep> spSheepA = new Sheep();
	sp<Sheep> spSheepB = new Sheep();
	spSheepA->setMaster(spSheepB);
	spSheepB->setMaster(spSheepA);
	ALOGD("Sheep:: -------------testStrongRefStrong end------------\n");
}

void testWeakRefWeak() {
	ALOGD("Sheep:: -------------testWeakRefWeak begin------------\n");
	sp<Sheep> spSheepA = new Sheep();
	sp<Sheep> spSheepB = new Sheep();
	spSheepA->setStudent(spSheepB);
	spSheepB->setStudent(spSheepA);
	ALOGD("Sheep:: -------------testWeakRefWeak end------------\n");
}

void testStrongRefWeak() {
	ALOGD("Sheep:: -------------testWeakRefWeak begin------------\n");
	sp<Sheep> spSheepA = new Sheep();
	{
		sp<Sheep> spSheepB = new Sheep();
		spSheepA->setMaster(spSheepB);
		spSheepB->setStudent(spSheepA);
	}
	ALOGD("Sheep:: -------------testWeakRefWeak end------------\n");
}

int main() {
	ALOGD("Sheep:: -------------main begin------------\n");
	//testSheep();
	//testPromote();
	//testLightRef();
	//testForceSet();
	//testStrongRefStrong();
	testWeakRefWeak();
	testStrongRefWeak();
	ALOGD("Sheep:: -------------main   end------------\n");
	return 0;
}
