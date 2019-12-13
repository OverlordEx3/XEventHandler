/*
 * event_handler.c
 *
 *  Created on: Dec 13, 2019
 *      Author: ebeke
 */
#include <stdbool.h>

#ifndef SYS_MALLOC
#define SYS_MALLOC(x)		malloc(x)
#endif

#ifndef SYS_FREE
#define SYS_FREE(x)			free((void*)(x))
#endif

#ifndef SYS_FREE
#define SYS_FREE(x)			free((void*)(x))
#endif

#define SEM_TYPE	void*
#define PRIVATE		static
#ifndef NULL
#define NULL 		((void*)0)
#endif

typedef void (*ListenerCallback_t)(int type, void* eventArgs);

struct Listener {
	SEM_TYPE waitLock;
	ListenerCallback_t eventCallback;
};

struct Event {
	int type;
	void* args;
	struct Event* next;
};

struct EventType {
	int type;
	struct Listener* eventListeners;
};

enum EventStatus_e {
	NOT_SUBSCRIBED,
	NOT_LISTENING,
	EMPTY,
	AVAILABLE,
	FULL,
};

PRIVATE struct EventType* eventTypeList = NULL;
PRIVATE struct Event* eventList = NULL;

PRIVATE void addEventTypeToList(int type)
{

}

void xRegisterEvent(int eventType)
{

}

void xRaiseEvent(int event, void* args)
{

}

void xListenEvent(int type, ListenerCallback_t eventCallback)
{

}

void xSubscribeEvent(int type)
{

}

void xUnsubscribeEvent(int type)
{

}

void xEnableNotify(int type)
{

}

void xDisableNotify(int type)
{

}

void xDisableAllEvents(void)
{

}

void xEnableAllEvents(void)
{

}

void xWaitForEvent(int type, unsigned long int timeout)
{

}

static void xEventHandlerTask(void* args)
{
	for( ; ; )
	{

	}
}

void xEventHandlerStart(void)
{

}

void xEventHandlerStop(void)
{

}

void xEventHandlerNew(void)
{

}
