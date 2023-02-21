DIRS = Time \
       FakeTimeService \
       LightController \
       LightControllerSpy \
	   LightDriver \
	   LightDriverSpy \
	   LightScheduler \
	   LightSchedulerRefactoredTest 
	   
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

coverage: 
	@for directory in $(DIRS); \
	do \
		$(MAKE) -C $$directory coverage; \
	done

cclean:
	@for directory in $(DIRS); \
	do \
		$(MAKE) -C $$directory cclean; \
	done