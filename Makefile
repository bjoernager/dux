.PHONY: dux test

dux:
	$(MAKE) -C dux

test: dux
	$(MAKE) -C dux-test