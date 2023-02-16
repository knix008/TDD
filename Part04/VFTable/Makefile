DIRS = LightController \
       LightControllerSpy \
	   LightDriver \
	   LightDriverSpy

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