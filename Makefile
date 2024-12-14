SUBDIRS = model controller view

CFLAGS = -I./model -I./controller -I./view

all: $(SUBDIRS) main

$(SUBDIRS):
	$(MAKE) -C $@

main: model/model.o controller/controller.o view/view.o
	$(CC) $(CFLAGS) model/model.o controller/controller.o view/view.o main.c -o main

clean:
	$(RM) main
	for dir in $(SUBDIRS); do $(MAKE) -C $$dir clean; done
