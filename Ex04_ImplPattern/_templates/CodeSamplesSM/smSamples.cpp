#include <iostream>

using namespace std;
class IReactive;
enum processResult { notProcessed, processed };
enum eventID {INIT_EVENT, TURNON_EVENT, TURNOFF_EVENT, PLAYPAUSE_EVENT, TM1000_EVENT};
enum tmID {tm1000};
class Event
{
public:
    Event(eventID id)
    {

    }

    eventID getID()
    {
        return 0;
    }
};
class Timeout : Event
{
public:
    Timeout(tmID tmid, eventID evID, int duration) : Event(evID)
    {
    }
};

class MP3Player : IReactive
{
private:
    enum smState {STATE_OFF, STATE_ON,
                  STATE_PAUSE, STATE_PLAY,
                  STATE_WAIT, STATE_INCR};
    smState state, onState, playState;

public:
    processResult playProcessEvent(Event* ev)
    {
        processResult result = unProcessed;
        smState lastState = state;
        switch (state)
        {
        case STATE_WAIT:
            if (ev->getID() == TM1000_EVENT)
            {
                playState = STATE_ON;
            }
            break;
        case STATE_INCR:
            if (ev->getID() == TURNOFF_EVENT)
            {
                state = STATE_OFF;
            }
            break;
        }

        if (lastState != state)
        {
            result = processed;
            if (lastState == STATE_OFF && state == STATE_ON)
            {
                cout << "player switched on" <<endl;
            }
            if (lastState == STATE_ON && state == STATE_OFF)
            {
                cout << "player switched off" <<endl;
            }
        }
        return result;
    }

    processResult onProcessEvent(Event* ev)
    {
        processResult result = notProcessed;
        smState lastState = state;
        switch (onstate)
        {
        case STATE_PAUSE:
            if (ev->getID() == PLAYPAUSE_EVENT)
            {
                onstate = STATE_PLAY;
            }
            break;
        case STATE_PLAY:
            if (playProcessEvent() == notProcessed)
            {
                if (ev->getID() == PLAYPAUSE_EVENT)
                {
                    onstate = STATE_PAUSE;
                }
            }
            break;
        }

        if (lastState != onstate)
        {
            result = processed;
            if (lastState == STATE_PAUSE && state == STATE_PLAY)
            {
                cout << "player now playing" <<endl;
            }
            if (lastState == STATE_PLAY && state == STATE_PAUSE)
            {
                cout << "player now paused" <<endl;
            }
        }
        return result;
    }

    processResult processEvent(Event* ev)
    {
        processResult result = notProcessed;
        smState lastState = state;
        switch (state)
        {
        case STATE_OFF:
            if (ev->getID() == TURNON_EVENT)
            {
                state = STATE_ON;
            }
            break;
        case STATE_ON:
            if (onProcessEvent(ev) == notProcessed)
            {
                if (ev->getID() == TURNOFF_EVENT)
                {
                    state = STATE_OFF;
                }
            }
            break;
        }

        if (lastState != state)
        {
            result = processed;
            if (lastState == STATE_OFF && state == STATE_ON)
            {
                cout << "player switched on" <<endl;
            }
            if (lastState == STATE_ON && state == STATE_OFF)
            {
                cout << "player switched off" <<endl;
            }
        }
        return result;
    }

};



/*
class SOmeSM : IReactive
{
private:
    enum smState { STATE_INIT, STATE_A, STATE_B };
    smState state, lastState;
public:
    void initialize()
    {
        state = lastState = STATE_INIT;
    }

    processState nestedProcessEvent(Event* ev)
    {
        processState result = notProcessed;
        smState lastState = state;
        //transition switch
        //...
        //action switch
        if (lastState != state)
        {
           result = processed;
           //do something
        }
        return result;
    }
    processState processEvent(Event* ev)
    {
        processState result = notProcessed;
        smState lastState = state;
        //the transition switch
        switch (state)
        {
            case STATE_INIT:
                if (ev->getID() == EVENT_INIT)
                {
                    state = STATE_A;
                }
                break;
            case STATE_A:
                if (nestedProcessEvent(ev) == notProcessed)
                {
                    if (ev->getID() == EVENT_XY)
                    {
                        //...
                    }
                }
                //...
                break;
            case STATE_B:
 ›               //...
                break;
            default:
                assert (true); //must NEVER happen!
        }

        //the action switch
        if (lastState != state)
        {
            //we processed the event
            result = processed;
            //detect what to do
            if (oldstate == STATE_INIT && state = STATE_A)
            {
                doInitStateExitAction();
                doStateAEntryction();
            }
            //...
        }
        return result;
    }
private:
    void doInitStateExitAction()
    {
        //...
    }
    void doStateAEntryction()
    {
        //...
    }
};
*/

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

