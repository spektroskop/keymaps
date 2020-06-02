.PHONY: all update unlink unlink_user

QMK_HOME := $(PWD)/qmk_firmware

all: compile

define make-keyboard
$(PWD)/qmk_firmware/keyboards/$(1)/keymaps/spektroskop-$(3):
	ln -s $(PWD)/maps/$(3) $(PWD)/qmk_firmware/keyboards/planck/keymaps/spektroskop-$(3)

compile-$(3): $(PWD)/qmk_firmware/users/spektroskop $(PWD)/qmk_firmware/keyboards/planck/keymaps/spektroskop-$(3)
	qmk compile -kb $(2) -km spektroskop-$(3)

flash-$(3): $(PWD)/qmk_firmware/users/spektroskop $(PWD)/qmk_firmware/keyboards/planck/keymaps/spektroskop-$(3)
	qmk flash -kb $(2) -km spektroskop-$(3)

unlink-$(3):
	rm -f $(PWD)/qmk_firmware/keyboards/$(1)/keymaps/spektroskop-$(3)

compile_targets += compile-$(3)
unlink_targets += unlink-$(3)
endef

init:
	git submodule init
	git submodule update

setup:
	qmk setup

update:
	git submodule foreach git pull origin master
	git submodule foreach make git-submodule

$(PWD)/qmk_firmware/users/spektroskop:
	ln -s $(PWD)/user $(PWD)/qmk_firmware/users/spektroskop

unlink-user:
	rm -f $(PWD)/qmk_firmware/users/spektroskop

$(eval $(call make-keyboard,planck,planck/ez,planck-36-gap))

compile: $(compile_targets)

unlink: unlink-user $(unlink_targets)
