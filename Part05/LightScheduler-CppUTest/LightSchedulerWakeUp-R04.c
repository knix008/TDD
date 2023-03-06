static bool isInUse(ScheduledLightEvent *event)
{
    return event->id != UNUSED;
}

static void operateLight(ScheduledLightEvent *event)
{
    if (event->event == TURN_ON)
        LightController_On(event->id);
    else if (TURN_OFF == event->event)
        LightController_Off(event->id);
}

static void resetRandomize(ScheduledLightEvent *event)
{
    if (event->randomize == RANDOM_ON)
        event->randomMinutes = RandomMinute_Get();
    else
        event->randomMinutes = 0;
}

static bool isEventDueNow(Time *time, ScheduledLightEvent *event)
{
    int todaysMinute = event->minuteOfDay + event->randomMinutes;
    Day day = event->day;

    if (!Time_MatchesMinuteOfDay(time, todaysMinute))
        return false;

    if (!Time_MatchesDayOfWeek(time, day))
        return false;

    return true;
}

static void processEventsDueNow(Time *time, ScheduledLightEvent *event)
{
    if (isInUse(event))
    {
        if (isEventDueNow(time, event))
        {
            operateLight(event);
            resetRandomize(event);
        }
    }
}

void LightScheduler_WakeUp(void)
{
    int i;
    Time time;

    TimeService_GetTime(&time);

    for (i = 0; i < MAX_EVENTS; i++)
    {
        processEventsDueNow(&time, &eventList[i]);
    }
}