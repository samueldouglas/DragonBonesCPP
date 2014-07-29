﻿#ifndef __DBCC_EVENT_DISPATCHER_H__
#define __DBCC_EVENT_DISPATCHER_H__

#include "../dragonBones/DragonBonesHeaders.h"
#include "cocos2d.h"

NAME_SPACE_DRAGON_BONES_BEGIN
class DBCCEventDispatcher : public IEventDispatcher
{
public:
    cocos2d::EventDispatcher *eventDispatcher;
    
public:
    DBCCEventDispatcher()
    {
    }
    virtual ~DBCCEventDispatcher()
    {
        dispose();
    }
    virtual void dispose() override
    {
        if (eventDispatcher)
        {
            eventDispatcher->removeAllEventListeners();
            eventDispatcher->release();
            eventDispatcher = nullptr;
        }
    }
    
    virtual void dispatchEvent(EventData *eventData) override
    {
        if (eventDispatcher)
        {
            if (eventData->animationState)
            {
                cocos2d::log("animation: %s eventType: %s", eventData->animationState->name.c_str(), eventData->getStringType().c_str());
            }
            eventDispatcher->dispatchCustomEvent(eventData->getStringType(), eventData);
        }
    }
    
    virtual bool hasEvent(EventData::EventDataType eventDataType) const override
    {
        return eventDispatcher != nullptr;
    }
    
private:
    DRAGON_BONES_DISALLOW_COPY_AND_ASSIGN(DBCCEventDispatcher);
};
NAME_SPACE_DRAGON_BONES_END

#endif  // __DBCC_EVENT_DISPATCHER_H__