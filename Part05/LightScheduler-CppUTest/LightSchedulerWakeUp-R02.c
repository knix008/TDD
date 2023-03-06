static void processEventsDueNow(Time *time, ScheduledLightEvent *event)
{
    Day today = time->dayOfWeek;
    int minuteOfDay = time->minuteOfDay;
    if (event->id != UNUSED)
    {
        Day day = event->day;
        /* if (isEventDueNow()) */
        if ((day == EVERYDAY) || (day == today) || (day == WEEKEND && (today == SATURDAY || today == SUNDAY)) ||
            (day == WEEKDAY && (today >= MONDAY && today <= FRIDAY)))
        {
            if (minuteOfDay == event->minuteOfDay + event->randomMinutes)
            {
                /* operateLight(); */
                if (event->event == TURN_ON)
                    LightController_TurnOn(event->id);
                else if (event->event == TURN_OFF)
                    LightController_TurnOff(event->id);
                /* resetRandomize(); */
                if (event->randomize == RANDOM_ON)
                    event->randomMinutes = RandomMinute_Get();
                else
                    event->randomMinutes = 0;
            }
        }
    }
}