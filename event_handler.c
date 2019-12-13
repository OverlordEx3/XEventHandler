
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
	struct EventType* next;
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
	struct EventType* newEventType = NULL;
	struct EventType* auxList = NULL;

	newEventType = SYS_MALLOC(sizeof(struct EventType));

	newEventType->type = type;
	newEventType->eventListeners = NULL;
	newEventType->next = NULL;

	if(eventTypeList == NULL)
	{
		/* Empty list. Register first one */
		eventTypeList = newEventType;
		return;
	}

	auxList = eventTypeList;
	while(auxList->next != NULL)
	{
		auxList = auxList->next;
	}

	/* Register new type at the end of the list */
	auxList->next = newEventType;
}

PRIVATE void removeEventTypeFromList(int type)
{
	struct EventType* auxList = eventTypeList;
	struct EventType* prevInList = eventTypeList;

	while(auxList != NULL)
	{
		if(type == auxList->type)
		{
			prevInList->next = auxList->next;
			/* Remove listeners */
			//TODO
			SYS_FREE(auxList);
			break;
		}
		auxList = auxList->next;
		prevInList = auxList;
	}
}

void xRegisterEvent(int eventType)
{
	addEventTypeToList(eventType);
}

void xUnregisterEvent(int eventType)
{
	removeEventTypeFromList(eventType);
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
