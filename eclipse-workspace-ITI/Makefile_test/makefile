include makeConfiguration.mk

allObjs = $(allSrcs:.c=.o)
allDeps = $(allSrcs:.c=.d)

$(FinalTargetName) : CFLAG = -Wall
$(allObjs): CFLAG = -c -Wall
$(allDeps): CFLAG = -MM
all: $(allDeps)
			$(MAKE) $(FinalTargetName)

$(FinalTargetName) : $(allObjs)
	$(CC) $(CFLAG) $^ -o $@
$(allObjs) : %.o : %.c
	$(CC) $(CFLAG) $< -o $@

-include Dependencies\*.d

$(allDeps) : %.d : %.c
	$(CC) $(CFLAG) $< -o $@
	@cp	$@ Dependencies\

.PHONY: clean link onlyCompile depend

clean: 
	#edit this rule to delete generated files 
	rm $(FinalTargetName) $(allObjs) $(allDeps) Dependencies/* 
link: 
	#edit this rule to only link without compiling
	$(CC) $(CFLAG) $(allObjs) -o $(FinalTargetName) 
onlyCompile:$(allObjs)
    #edit this rule to only compile without linking
depend:	$(allDeps)