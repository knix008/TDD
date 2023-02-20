DIRS = FakeTimeService \
       LightController \
       LightControllerSpy \
	   LightDriver \
	   LightDriverSpy \
	   LightScheduler \
	   LightScheduler-R01
	   
.PHONY: all clean

all:
	@for directory in $(DIRS); \
	do \
		$(MAKE) -C $$directory; \
	done

clean:
	@for directory in $(DIRS); \
	do \
		$(MAKE) -C $$directory clean; \
	done