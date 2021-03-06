# version 1
# all: chap3
# 	$(MAKE) -C chap3/

# clean: chap3
# 	$(MAKE) clean -C chap3/

# version 2
TOPTARGETS := all clean

# either of the below 2 will work
# SUBDIRS := $(wildcard */)
# SUBDIRS := $(wildcard */.)
SUBDIRS := cpp-basic-plural

$(TOPTARGETS) : $(SUBDIRS)
$(SUBDIRS) :
	$(MAKE) -C $@ $(MAKECMDGOALS)

# these targets need to be exercised
# irrespective of the target exist or updated recently
.PHONY : $(TOPTARGETS) $(SUBDIRS)
